#pragma once

#define MYDATA_OK					0x00000000
#define MYDATA_ERROR				-1

#define MYDATA_DATA_NOT_NEW			0xFFFF0101 //�������ݵ�ʱ����������µ�
#define MYDATA_DATA_TIME_EXIST		0xFFFF0102 //�������ݵ�ʱ����Ѵ���
#define MYDATA_DATA_NOT_EXIST		0xFFFF0103 //���ݲ�����
#define MYDATA_DATA_TOO_LONG		0xFFFF0104 //���ݳ���̫��
#define MYDATA_DATA_PAR_SUC			0xFFFF0105 //��������ʧ��
#define MYDATA_DATA_QUERY_END		0xFFFF0106 //��ȡ���ݽ���

#define MYDATA_NO_MEM				0xFFFF0201 //�ڴ����ʧ��
#define MYDATA_NET_TIMEOUT			0xFFFF0202 //���糬ʱ
#define MYDATA_RECV_FAIL			0xFFFF0203 //�������ʧ��
#define MYDATA_CRC_FAIL				0xFFFF0204 //CRCУ��ʧ��
#define MYDATA_ERROR_TYPE			0xFFFF0205 //��Ϣ���ʹ���
#define MYDATA_MSG_SER_FAIL			0xFFFF0206 //���л�ʧ��
#define MYDATA_SEND_FAIL			0xFFFF0207 //���緢��ʧ��
#define MYDATA_INVALIDE_HANDLE		0xFFFF0208 //��Ч�ľ��
#define MYDATA_HANDLE_CONFLICT		0xFFFF0209 //���ʹ�ó�ͻ
#define MYDATA_INVALIDE_PARA		0xFFFF0210 //��Ч�Ĳ���
#define MYDATA_CONNECT_FAIL			0xFFFF0211 //��������ʧ��

#define MYDATA_SQL_TYPE_FAIL 		0xFFFF0301 //��������ʧ��
#define MYDATA_SQL_TABLE_FAIL 		0xFFFF0302 //������ʧ��
#define MYDATA_SQL_TABLE_NOT_ALLOWD 0xFFFF0303 //����ر���ڣ�����ִ�в���
#define MYDATA_SQL_POINT_FAIL 		0xFFFF0304 //������ǩ��ʧ��
#define MYDATA_SQL_POINT_NOT_ALLOWD	0xFFFF0305 //����ر�ǩ����ڣ�����ִ�в���
#define MYDATA_SQL_POINT_END		0xFFFF0306 //��ǩ���ѯ����

#define MYDATA_CREATEFILE_FAIL		0xFFFF0401 //�����ļ�����ʧ��
#define MYDATA_DELETEFILE_FAIL		0xFFFF0402 //�����ļ�ɾ��ʧ��
#define MYDATA_FILEINIT_FAIL		0xFFFF0403 //�ļ�ӳ���ʼ��ʧ��
#define MYDATA_NO_EMPTY_FILE		0xFFFF0404 //û�п���ʷ�ļ�
#define MYDATA_NO_FIT_FILE			0xFFFF0405 //û�к��ʵ���ʷ�ļ�
#define MYDATA_INVALIDE_FILENAME	0xFFFF0406 //��ʷ�ļ������Ϸ�
#define MYDATA_FILE_CONFLICT		0xFFFF0407 //��ʷ�ļ���ͻ
#define MYDATA_REBUILD_INDEX_FAIL	0xFFFF0408 //�ؽ�����ʧ��

#define MYDATA_POINT_NOT_EXIST		0xFFFF0501 //ָ���ı�ǩ�㲻����
#define MYDATA_SERIAL_FAIL			0xFFFF0502 //���л������л�ʧ��
#define MYDATA_NAME_TOOLONG			0xFFFF0503 //���Ƴ��ȳ�������

#define MYDATA_PLUGIN_PREVENT		0xFFFF0601 //�����ֹ����