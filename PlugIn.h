#pragma once
#include <vector>
#include "Windows.h"
//������غ�ж�صļ���
//DllName:����Ķ�̬������
//Init:��Ӧ��InitFun
//Close:��Ӧ��CloseFun
//WriteNewDataPlugIn:��Ӧ��WriteNewDataFun

class PlugIn
{
public:
	//�������ʱ�ĳ�ʼ���ص�
	typedef bool (WINAPI *InitFun)();
	//ʵʱ����д��ǰ�Ļص������������ж��Ƿ����д��������Ҳ���԰����ݷ�����������
	typedef bool (WINAPI *WriteNewDataFun)(int table_id, int point_id, time_t t, const char* data);
	//�����������ͷ���Դ�Ļص�����
	typedef void (WINAPI *CloseFun)();

	void Init();
	~PlugIn(void);

	std::vector<HMODULE> DllModules_;
	std::vector<CloseFun> CloseFuns_;
	std::vector<WriteNewDataFun> WriteNewDataFuns_;
private:
	void Load(char* path, char *dllname, char *init_name, char *close_name, char *wnew_data_name);
};

