#pragma once

#include "MyDataCommon.h"
#include "datas.pb.h"
#include "MyDataMgrCore.h"
#include "LogFilew.h"
#include "MultiSkipListKVDisk.h"
class MyDataConfig;
class DataFileMgr
{
public:
	~DataFileMgr();
	int Init(const char* datafile_mgr_name, MyDataConfig *config);
	int UnInit();
	int CreateFile(const char* filename, long long file_size, time_t start_time, time_t end_time);
	int TransformEmptyFile(time_t start_time);
	//���������ļ�������ʱ��
	int GetFileEndTime(const DataFileInfoInner *fileinfo, time_t *end_time);
	//��Ϣ����ʷ�ļ������ౣ�棬����������ʷ�ļ�ʱ���ָ���Ϣ��mgr_��
	void UpdateFileInfo(DataFileInfoInner *fileinfo);												
	int DeleteFile(const char* filename, time_t start_time);
	//������ʷ�ļ�
	int AddFile(const char* filename);																
	int GetFilesNum();
	void GetFileInfos(Datas::DataFileInfosReply &fileinfos);
	//�ؽ������Ϳ鱸���ļ�
	int ReBuildIndex(const char* filename, time_t start_time);										
	std::pair<time_t, DataFileInfoInner *> GetFile(time_t start_time);
	SkipListKVDisk<time_t, DataFileInfoInner, CommonLowThan<time_t>> &GetMgr() {return mgr_;}
	static const time_t _max_time;
	void AllocBlock(int data_id, FileSet *fileset, time_t t, DataIndex &index, DataHead *&data_head, DataEndArray *&data_end, DataHead *&real_data_head, DataEndArray *&real_data_end);

private:
	MyDataConfig *config_;
	int CreateFile(long long file_size);
	static unsigned int __stdcall AutoCreateFile(void* data); 
	SkipListKVDisk<time_t, DataFileInfoInner, CommonLowThan<time_t>> mgr_;		//key:��ʼʱ��
	static int _file_diff;														//�����ļ���
};

