#pragma once
//MyData����������������Զ��壬���ǲ����ͷ���ֵ����PlugIn.h�е�Ҫ�󣬲���Ҫ�����ص�������ʵ��
//��������ò��գ����ʹ��˵��.txt

#ifdef __cplusplus
extern "C" {
#endif

#define DLL_API extern "C" __declspec(dllexport)

//�������ʱ�ĳ�ʼ���ص�
//����ֵΪtrue��������سɹ����������ʧ��
DLL_API bool InitCallBack();

//ʵʱ����д��ǰ�Ļص������������ж��Ƿ����д��������Ҳ���԰����ݷ�����������
//����ֵΪtrue��������д�����ݿ⣬����������
DLL_API bool WriteNewDataCallBack(int table_id, int point_id, time_t t, const char* data);

//�������ʱ������ͷ���Դ�Ļص�����
DLL_API void CloseCallBack();

#ifdef __cplusplus
}
#endif