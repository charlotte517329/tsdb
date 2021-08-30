#pragma once
#include "MyDataCommon.h"
#include "MultiSkipListKVDisk.h"
#include "disk_data_alloc.h"
#include "StackDisk.h"
#define  BLOCK_SIZE  8192		//���С
#define  MAX_PATH 260
//���ݿ�ͷ
struct DataHead
{
	short dirty_;			//��ʹ�õĿ飬1Ϊ��ʹ�ã�0Ϊδʹ��
	short data_array_size_;	//DataEndArray�ĳ���
	int new_data_pos_;		//δʹ�õ������ʼ��ַ
	int data_id;			//��ǩ��id
};
//���ݿ�β
struct DataEndArray
{
	int datetime_;			//��¼��ʱ��
	int data_pos_;			//��¼����Ե�ַ
};

struct FileSet
{
	FileSet()
	{
		InitializeSRWLock(&rwlock_);
	}
	disk_data_alloc daa_;
	MultiSkipListMgr<time_t, void*, CommonLowThan<time_t>> index_mgr_;	//keyΪ��������ݵ�ʱ��
	StackDisk<DataHead*> skd_;											//����ɾ���Ŀ飬�Ա�����
	SRWLOCK rwlock_;													
};
typedef MultiSkipListKVDisk<time_t, void*, CommonLowThan<time_t>> DataIndex;

//�����ļ���Ϣ
struct DataFileInfoInner : public SerBase
{
	time_t start_time_;		//��ʷ�ļ���ʼʱ�䣬����ʷ�ļ�Ϊ-1
	time_t end_time_;		//��ʷ�ļ���ǰ����ʱ�䣬û��Ϊ-1
	long long file_size_;	//��ʼ�ļ���С
	FileSet *file_set_;		//��ʱ����
	char filename_[32];		//Ϊ�ļ��Ĵ���ʱ�䣬û�п��ļ����ļ���Ϊ""
};
//�����ѯ����
#define INDEX_EXPEND_LENGTH 1024	//�����ļ����ӳ���
#define DATAS_QUERY_BUFFER 100000	//���ݲ�ѯ��󻺴���


struct RLockGuard
{
	RLockGuard(SRWLOCK* lock):lock_(lock)
	{
		AcquireSRWLockShared(lock_);
	}
	~RLockGuard()
	{
		ReleaseSRWLockShared(lock_);
	}
	SRWLOCK *lock_;
};
#define RLOCKGUARD(lock) RLockGuard rg(&lock)
struct WLockGuard
{
	WLockGuard(SRWLOCK* lock):lock_(lock)
	{
		AcquireSRWLockExclusive(lock_);
	}
	~WLockGuard()
	{
		ReleaseSRWLockExclusive(lock_);
	}
	SRWLOCK *lock_;
};
#define WLOCKGUARD(lock) WLockGuard wg(&lock)