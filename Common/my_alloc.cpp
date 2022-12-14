#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include "my_alloc.h"

#define MALLOC_OVERHEAD 8 //分配过程中，需要保留一部分额外的空间
#define ALLOC_MAX_BLOCK_TO_DROP 4096 
#define ALLOC_MAX_BLOCK_USAGE_BEFORE_DROP 10 
#define ALIGN_SIZE(A) MY_ALIGN((A),sizeof(double))
#define MY_ALIGN(A,L) (((A) + (L) - 1) & ~((L) - 1))
#define ALLOC_ROOT_MIN_BLOCK_SIZE (MALLOC_OVERHEAD + sizeof(USED_MEM) + 8)
/* Define some useful general macros (should be done after all headers). */
#define MY_MAX(a, b) ((a) > (b) ? (a) : (b)) 
#define MY_MIN(a, b) ((a) < (b) ? (a) : (b)) 
/*
  Initialize memory root

  SYNOPSIS
    init_alloc_root()
      mem_root       - memory root to initialize
      block_size     - size of chunks (blocks) used for memory allocation
                       (It is external size of chunk i.e. it should include
                        memory required for internal structures, thus it
                        should be no less than ALLOC_ROOT_MIN_BLOCK_SIZE)
      pre_alloc_size - if non-0, then size of block that should be
                       pre-allocated during memory root initialization.

  DESCRIPTION
    This function prepares memory root for further use, sets initial size of
    chunk for memory allocation and pre-allocates first block if specified.
    Altough error can happen during execution of this function if
    pre_alloc_size is non-0 it won't be reported. Instead it will be
    reported as error in first alloc_root() on this memory root.
*/

void init_alloc_root(MEM_ROOT *mem_root, size_t block_size, size_t pre_alloc_size)
{
  mem_root->free= mem_root->used= mem_root->pre_alloc= 0;
  mem_root->min_malloc= 32;
  mem_root->block_size= block_size - ALLOC_ROOT_MIN_BLOCK_SIZE;
  mem_root->error_handler= 0;
  mem_root->block_num= 4;			/* We shift this with >>2 */
  mem_root->first_block_usage= 0;

#if !(defined(HAVE_purify) && defined(EXTRA_DEBUG))
  if (pre_alloc_size)
  {
    if ((mem_root->free= mem_root->pre_alloc=
	 (USED_MEM*) malloc(pre_alloc_size+ ALIGN_SIZE(sizeof(USED_MEM)))))
    {
      mem_root->free->size= pre_alloc_size+ALIGN_SIZE(sizeof(USED_MEM));
      mem_root->free->left= pre_alloc_size;
      mem_root->free->next= 0;
    }
  }
#endif
}


/*
  SYNOPSIS
    reset_root_defaults()
    mem_root        memory root to change defaults of
    block_size      new value of block size. Must be greater or equal
                    than ALLOC_ROOT_MIN_BLOCK_SIZE (this value is about
                    68 bytes and depends on platform and compilation flags)
    pre_alloc_size  new size of preallocated block. If not zero,
                    must be equal to or greater than block size,
                    otherwise means 'no prealloc'.
  DESCRIPTION
    Function aligns and assigns new value to block size; then it tries to
    reuse one of existing blocks as prealloc block, or malloc new one of
    requested size. If no blocks can be reused, all unused blocks are freed
    before allocation.
*/

void reset_root_defaults(MEM_ROOT *mem_root, size_t block_size,
                         size_t pre_alloc_size )
{
  mem_root->block_size= block_size - ALLOC_ROOT_MIN_BLOCK_SIZE;
#if !(defined(HAVE_purify) && defined(EXTRA_DEBUG))
  if (pre_alloc_size)
  {
    size_t size= pre_alloc_size + ALIGN_SIZE(sizeof(USED_MEM));
    if (!mem_root->pre_alloc || mem_root->pre_alloc->size != size)
    {
      USED_MEM *mem, **prev= &mem_root->free;
      /*
        Free unused blocks, so that consequent calls
        to reset_root_defaults won't eat away memory.
      */
      while (*prev)
      {
        mem= *prev;
        if (mem->size == size)
        {
          /* We found a suitable block, no need to do anything else */
          mem_root->pre_alloc= mem;
          return;
        }
        if (mem->left + ALIGN_SIZE(sizeof(USED_MEM)) == mem->size)
        {
          /* remove block from the list and free it */
          *prev= mem->next;
          {
            mem->left= mem->size;
            free(mem);
          }
        }
        else
          prev= &mem->next;
      }
      /* Allocate new prealloc block and add it to the end of free list */
      if ((mem= (USED_MEM *) malloc(size)))
      {
        mem->size= size; 
        mem->left= pre_alloc_size;
        mem->next= *prev;
        *prev= mem_root->pre_alloc= mem; 
      }
      else
      {
        mem_root->pre_alloc= 0;
      }
    }
  }
  else
#endif
    mem_root->pre_alloc= 0;
}


void *alloc_root(MEM_ROOT *mem_root, size_t length)
{
  size_t get_size, block_size;
  unsigned char* point;
  USED_MEM *next= 0;
  USED_MEM **prev;
  
  length= ALIGN_SIZE(length);
  if ((*(prev= &mem_root->free)) != NULL)
  {
    if ((*prev)->left < length &&
	mem_root->first_block_usage++ >= ALLOC_MAX_BLOCK_USAGE_BEFORE_DROP &&
	(*prev)->left < ALLOC_MAX_BLOCK_TO_DROP)
    {
      next= *prev;
      *prev= next->next;			/* Remove block from list */
      next->next= mem_root->used;
      mem_root->used= next;
      mem_root->first_block_usage= 0;
    }
    for (next= *prev ; next && next->left < length ; next= next->next)
      prev= &next->next;
  }
  if (! next)
  {						/* Time to alloc new block */
    block_size= mem_root->block_size * (mem_root->block_num >> 2);
    get_size= length+ALIGN_SIZE(sizeof(USED_MEM));
    get_size= MY_MAX(get_size, block_size);

    if (!(next = (USED_MEM*) malloc(get_size)))
    {
      if (mem_root->error_handler)
	(*mem_root->error_handler)();
      return NULL;                      /* purecov: inspected */
    }
    mem_root->block_num++;
    next->next= *prev;
    next->size= get_size;
    next->left= get_size-ALIGN_SIZE(sizeof(USED_MEM));
    *prev=next;
  }

  point= (unsigned char*) ((char*) next+ (next->size-next->left));
  /*TODO: next part may be unneded due to mem_root->first_block_usage counter*/
  if ((next->left-= length) < mem_root->min_malloc)
  {						/* Full block */
    *prev= next->next;				/* Remove block from list */
    next->next= mem_root->used;
    mem_root->used= next;
    mem_root->first_block_usage= 0;
  }
  return point;
}


/*
  Allocate many pointers at the same time.

  DESCRIPTION
    ptr1, ptr2, etc all point into big allocated memory area.

  SYNOPSIS
    multi_alloc_root()
      root               Memory root
      ptr1, length1      Multiple arguments terminated by a NULL pointer
      ptr2, length2      ...
      ...
      NULL

  RETURN VALUE
    A pointer to the beginning of the allocated memory block
    in case of success or NULL if out of memory.
*/

void *multi_alloc_root(MEM_ROOT *root, ...)
{
  va_list args;
  char **ptr, *start, *res;
  size_t tot_length, length;

  va_start(args, root);
  tot_length= 0;
  while ((ptr= va_arg(args, char **)))
  {
    length= va_arg(args, unsigned int);
    tot_length+= ALIGN_SIZE(length);
  }
  va_end(args);

  if (!(start= (char*) alloc_root(root, tot_length)))
    return NULL;                            /* purecov: inspected */

  va_start(args, root);
  res= start;
  while ((ptr= va_arg(args, char **)))
  {
    *ptr= res;
    length= va_arg(args, unsigned int);
    res+= ALIGN_SIZE(length);
  }
  va_end(args);
  return((void*) start);
}

/* Mark all data in blocks free for reusage */

void mark_blocks_free(MEM_ROOT* root)
{
  USED_MEM *next;
  USED_MEM **last;

  /* iterate through (partially) free blocks, mark them free */
  last= &root->free;
  for (next= root->free; next; next= *(last= &next->next))
  {
    next->left= next->size - ALIGN_SIZE(sizeof(USED_MEM));
  }

  /* Combine the free and the used list */
  *last= next=root->used;

  /* now go through the used blocks and mark them free */
  for (; next; next= next->next)
  {
    next->left= next->size - ALIGN_SIZE(sizeof(USED_MEM));
  }

  /* Now everything is set; Indicate that nothing is used anymore */
  root->used= 0;
  root->first_block_usage= 0;
}


/*
  Deallocate everything used by alloc_root or just move
  used blocks to free list if called with MY_USED_TO_FREE

  SYNOPSIS
    free_root()
      root		Memory root
      MyFlags		Flags for what should be freed:

        MY_MARK_BLOCKS_FREED	Don't free blocks, just mark them free
        MY_KEEP_PREALLOC	If this is not set, then free also the
        		        preallocated block

  NOTES
    One can call this function either with root block initialised with
    init_alloc_root() or with a zero()-ed block.
    It's also safe to call this multiple times with the same mem_root.
*/

void free_root(MEM_ROOT *root, int MyFlags)
{
  USED_MEM *next,*old;

  if (MyFlags & MY_MARK_BLOCKS_FREE)
  {
    mark_blocks_free(root);
    return;
  }
  if (!(MyFlags & MY_KEEP_PREALLOC))
    root->pre_alloc=0;

  for (next=root->used; next ;)
  {
    old=next; next= next->next ;
    if (old != root->pre_alloc)
    {
      old->left= old->size;
      free(old);
    }
  }
  for (next=root->free ; next ;)
  {
    old=next; next= next->next;
    if (old != root->pre_alloc)
    {
      old->left= old->size;
      free(old);
    }
  }
  root->used=root->free=0;
  if (root->pre_alloc)
  {
    root->free=root->pre_alloc;
    root->free->left=root->pre_alloc->size-ALIGN_SIZE(sizeof(USED_MEM));
    root->free->next=0;
  }
  root->block_num= 4;
  root->first_block_usage= 0;
}

/*
  Find block that contains an object and set the pre_alloc to it
*/

void set_prealloc_root(MEM_ROOT *root, char *ptr)
{
  USED_MEM *next;
  for (next=root->used; next ; next=next->next)
  {
    if ((char*) next <= ptr && (char*) next + next->size > ptr)
    {
      root->pre_alloc=next;
      return;
    }
  }
  for (next=root->free ; next ; next=next->next)
  {
    if ((char*) next <= ptr && (char*) next + next->size > ptr)
    {
      root->pre_alloc=next;
      return;
    }
  }
}


char *strdup_root(MEM_ROOT *root, const char *str)
{
  return strmake_root(root, str, strlen(str));
}


char *strmake_root(MEM_ROOT *root, const char *str, size_t len)
{
  char *pos;
  if ((pos=(char*)alloc_root(root,len+1)))
  {
    memcpy(pos,str,len);
    pos[len]=0;
  }
  return pos;
}


void *memdup_root(MEM_ROOT *root, const void *str, size_t len)
{
  char *pos;
  if ((pos=(char*)alloc_root(root,len)))
    memcpy(pos,str,len);
  return pos;
}
