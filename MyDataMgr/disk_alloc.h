#pragma once
#include "mymmapw.h"
//�������ڴ�������
//�ڴ�ṹ
//MAGIC|clean_pos_|DATA

class disk_alloc : public mymmap
{
public:
	int init(const char *filename, size_t length, size_t expend_length, void (*callback)(void*) = NULL, void *callback_para = NULL);
	void *my_alloc(int size);
	void *my_relative_alloc(int size);
	bool isclean() {return *clean_pos_ == sizeof(int)*2;}
	void *data_addr() {return clean_pos_ + 1;}
	size_t get_expend_length() {return expend_length_;}
	template <typename T>
	inline T* get_absolute_pos(T* relative_pos) {return (T*)((unsigned char*)relative_pos + (int)base_addr_);} 
private:
	int *clean_pos_;			//δ�������λ��
	size_t expend_length_;		//�ļ���չ����
	void (*callback_)(void*);	//�ļ���չʱ�Ļص�
	void *callback_para_;
};

