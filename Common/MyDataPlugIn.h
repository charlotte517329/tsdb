#pragma once
#include "MyDataCommon.h"

#ifdef __cplusplus
extern "C" {
#endif

#ifdef MYDATA_EXPORTS
#define MYDATA_API extern "C" __declspec(dllexport)
#else
#define MYDATA_API extern "C" __declspec(dllimport)
#endif

//==============================================
//				����API������ǰ׺PlugIn��Ӧ�ɲ��ʹ�ã�����Ҫ��MyData��������
//==============================================

//���л��뷴���л��������ܳ���Ӧ��2048�ֽ����ڣ������л���д����ȡ���ݵ����࣬��ָ�����;���

/*
* ���ܣ������л�����ȡchar���ݣ�������Ƿ���ϱ�ǩ������Ҫ��
*/
MYDATA_API void PlugInReadChar(SerializerNoBuf* io, char *data);

/*
* ���ܣ������л�����ȡshort���ݣ�������Ƿ���ϱ�ǩ������Ҫ��
*/
MYDATA_API void PlugInReadShort(SerializerNoBuf* io, short *data);

/*
* ���ܣ������л�����ȡint���ݣ�������Ƿ���ϱ�ǩ������Ҫ��
*/
MYDATA_API void PlugInReadInt(SerializerNoBuf* io, int *data);

/*
* ���ܣ������л�����ȡlong long���ݣ�������Ƿ���ϱ�ǩ������Ҫ��
*/
MYDATA_API void PlugInReadLongLong(SerializerNoBuf* io, long long *data);

/*
* ���ܣ������л�����ȡfloat���ݣ�������Ƿ���ϱ�ǩ������Ҫ��
*/
MYDATA_API void PlugInReadFloat(SerializerNoBuf* io, float *data);

/*
* ���ܣ������л�����ȡdouble���ݣ�������Ƿ���ϱ�ǩ������Ҫ��
*/
MYDATA_API void PlugInReadDouble(SerializerNoBuf* io, double *data);

/*
* ���ܣ������л�����ȡstring���ݣ�������Ƿ���ϱ�ǩ������Ҫ��
*/
MYDATA_API void PlugInReadString(SerializerNoBuf* io, char* data);

#ifdef __cplusplus
}
#endif