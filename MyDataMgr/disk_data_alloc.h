#pragma once
#include "mymmapw.h"

//�����ļ����ڴ�������
//�ڴ�ṹ
//MAGIC|clean_pos_|DataFileInfo|...|DATA
//|-----------64k(����)------------|
#define  MYDATA_ALLOC_LENGTH	 1024*10240	//һ���Է���10MB

class disk_data_alloc
{
public:
	int init(const char *filename);
	const char* filename();
	long long filesize();
	void* get_clean_pos_end() {return clean_pos_+1;};
	long long get_clean_pos() {return *clean_pos_;}
	void *relative_alloc(int size);
	template <typename T>
	T * get_absolute_pos(T * relative_pos)
	{
		long long offset = (long long)relative_pos;
		if (offset >= real_offset_ && offset < real_offset_ + MYDATA_ALLOC_LENGTH)//ע������ҵı߽�
			return (T*)((unsigned char*)body_.addr()+offset-real_offset_);
		real_offset_ = offset/granularity_*granularity_;
		size_t length = MYDATA_ALLOC_LENGTH;
		int ret = body_.map(length, 4, real_offset_);
		if (ret)
			return 0;
		return (T*)((unsigned char*)body_.addr()+offset-real_offset_);
	}
	size_t get_granularity() {return granularity_;}
private:
	long long *clean_pos_;	//δ�������λ��
	mymmap head_;
	mymmap body_;
	static size_t granularity_;
	long long real_offset_;//�ڴ�ƫ��ӳ���ƫ����
};

