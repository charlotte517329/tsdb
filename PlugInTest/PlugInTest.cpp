// PlugInTest.cpp : ���� DLL Ӧ�ó���ĵ���������
//

#include "stdafx.h"
#include "PlugInTest.h"
#include "MyDataPlugIn.h"

DLL_API bool InitCallBack()
{
	//�������ʱ����ʼ��д�������ֵ�����Ƿ���سɹ�
	return true;
}
DLL_API bool WriteNewDataCallBack(int table_id, int point_id, time_t t, const char* data)
{//д��ʵʱ����ǰ�Ĵ���д�������ֵ�����Ƿ�д�����ݿ�

	//���ܣ�����Ǳ�idΪ1�����ݣ������һ���������ͣ������Ǳ�1����������������д�����ݿ�
	if (table_id == 1)
	{
		SerializerNoBuf io(data);
		int i = 0;
		PlugInReadInt(&io, &i);
		if (i & 1)
			return false;
	}
	return true;
}
DLL_API void CloseCallBack()
{
	//�����˳�ʱ����Դ�ͷŵĴ���д����
}
