// APITest.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "time.h"
#include "windows.h"
#include "MyDataAPI.h"
#include "MyDataCommon.h"
int _handle;
char* U2G(const char* utf8);
char* G2U(const char* gb2312);
int Operate();
int _tmain(int argc, _TCHAR* argv[])
{
	Operate();
	system("pause");
}
int Operate()
{
	printf("1.��ǩ�㵼��2.��ǩ�㵼��3.д������?");
	int select;
	scanf("%d", &select);
	if (select < 1 || select > 3)
	{
		printf("�������");
		return 0;
	}
	printf("����Ip:");
	char ip[32];
	scanf("%s", ip);
	printf("����˿ں�:");
	int port;
	scanf("%d", &port);
	int err = MyDataConnect(ip, port, &_handle);
	if (err)
	{
		printf("����ʧ��, %s", MyDataGetErrDesc(err));
		return 0;
	}
	if (select == 1)
	{
		printf("ѡ��Ҫ����ı�ID:");
		int tid;
		scanf("%d", &tid);
		printf("ѡ��Ҫ������ļ���:");
		char filename[32];
		scanf("%s", filename);
		printf("��ʼ����\n");
		PointInfo *pinfo;
		const int count = 5000;
		char pointname[32];
		char *pnames[count];
		FILE *f = fopen(filename, "r");
		if (f == NULL)
		{
			printf("�ļ���ʧ��\n");
			return 0;
		}
		fgets(pointname, sizeof(pointname), f);
		memset(pointname, 0, sizeof(pointname));
		int rnum = 0;
		while(1)
		{
			int i = 0;
			for (i = 0; i<count; i++)
			{
				if (fgets(pointname, sizeof(pointname), f) != NULL)
				{
					char* r = strchr(pointname, '\r');
					if (r != NULL)
					{
						*r = 0;
					}
					else
					{
						r = strchr(pointname, '\n');
						if (r != NULL)
							*r = 0;
					}
					char *uname = G2U(pointname);
					pnames[i] = uname;
				}
				else
				{
					break;
				}
			}
			if (i != 0)
			{
				int num = i;
				err = MyDataAddPoints(_handle, tid, pnames, &i);
				if (err)
				{
					printf("������ǩ��ʧ��, %s", MyDataGetErrDesc(err));
					return 0;
				}
				for (int j=0; j<num; j++)
					delete pnames[j];
			}
			else
			{
				break;
			}
			rnum += i;
		}
		printf("�������,������%d��ǩ��\n", rnum);
	}
	else if (select == 2)
	{
		printf("ѡ��Ҫ��ѯ�ı���:");
		char table_name[32];
		scanf("%s", table_name);
		int num = 0;
		char *utable_name = G2U(table_name);
		err = MyDataSearchPointsNum(_handle, utable_name, "", &num);
		if (err)
		{
			printf("��ѯʧ��, %s", MyDataGetErrDesc(err));
			return 0;
		}
		printf("����ѯ��%d����ǩ��\n", num);
		printf("׼������\n", num);
		PointInfo *pinfo;
		pinfo = new PointInfo[num];
		err = MyDataSearchPoints(_handle, utable_name, "", pinfo, &num);
		if (err)
		{
			printf("��ѯʧ��, %s", MyDataGetErrDesc(err));
			return 0;
		}
		printf("��ʼ����\n");
		char fname[64];
		sprintf(fname, "%lld.csv", time(0));
		FILE *f = fopen(fname, "w");
		fprintf(f, "��ǩ������\n");
		for (int i=0; i<num; i++)
		{
			char * gname = U2G(pinfo[i].name);
			fprintf(f, "%s\n", gname);
			delete gname;
		}
		fclose(f);
		printf("�������,�ļ���%s\n", fname);
	}
	else if (select == 3)
	{
		printf("ѡ��Ҫд���ı���:");
		char table_name[32];
		scanf("%s", table_name);
		int num = 0;
		char *utable_name = G2U(table_name);
		err = MyDataSearchPointsNum(_handle, utable_name, "", &num);
		if (err)
		{
			printf("��ѯʧ��, %s", MyDataGetErrDesc(err));
			return 0;
		}
		printf("����ѯ��%d����ǩ��\n", num);
		printf("׼��д��\n", num);
		PointInfo *pinfo;
		pinfo = new PointInfo[num];
		err = MyDataSearchPoints(_handle, utable_name, "", pinfo, &num);
		if (err)
		{
			printf("��ѯʧ��, %s", MyDataGetErrDesc(err));
			return 0;
		}
		if (num == 0)
		{
			printf("�ñ�û�б�ǩ��\n");
			return 0;
		}
		TableInfo tableinfo;
		err = MyDataGetTableByID(_handle, &tableinfo, pinfo[0].table_id);
		if (err)
		{
			printf("��ѯ��ʧ��, %s", MyDataGetErrDesc(err));
			return 0;
		}
		TypeInfo typeinfo;
		err = MyDataGetTypeByID(_handle, tableinfo.type_id, &typeinfo);
		if (err)
		{
			printf("��ѯ����ʧ��, %s", MyDataGetErrDesc(err));
			return 0;
		}
		printf("��ʼд��\n");
		Serializer *s;
		s = new Serializer[num];
		int *pids = new int[num];
		int *table_ids = new int[num];
		time_t *times = new time_t[num];
		for (int i=0; i<num; ++i)
		{
			pids[i] = pinfo[i].id;
			table_ids[i] = pinfo[i].table_id;
		}
		short shortvalue = 0;
		int intvalue = 0;
		long long llvalue = 0;
		float fvalue = 0;
		double dbalue = 0;
		char * stringvalue = G2U("�ַ�������");
		time_t t = time(0);
		HANDLE hTimeEvent = CreateWaitableTimer(NULL, FALSE, NULL);
		if (hTimeEvent == NULL)
		{
			printf("ʱ�����������ʧ��");
			return 0;
		}
		LARGE_INTEGER li;
		const int timer_units = 1000000;
		li.QuadPart = -(2*timer_units);
		if (SetWaitableTimer(hTimeEvent, &li, 1000, NULL, NULL, FALSE) == 0)
		{
			printf("ʱ�����������ʧ��");
			return 0;
		}

		while (1)
		{
			if (WaitForSingleObject(hTimeEvent, INFINITE) != WAIT_OBJECT_0)
			{
				Sleep(500);
			}
			t++;
			shortvalue++;
			intvalue++;
			llvalue++;
			fvalue += 0.1;
			dbalue += 0.1;
			for (int i=0; i<num; i++)
			{
				times[i] = t;
				MakeSerializer(_handle, typeinfo.id, false, s+i);
				for (int j=0; j<sizeof(typeinfo.type); j++)
				{
					if (typeinfo.type[j] == 0)
						break;
					switch (typeinfo.type[j])
					{
					case 1:
						WriteChar(s+i, '1');
						break;
					case 2:
						WriteShort(s+i, shortvalue);
						break;
					case 3:
						WriteInt(s+i, intvalue);
						break;
					case 4:
						WriteLongLong(s+i, llvalue);
						break;
					case 5:
						WriteFloat(s+i, fvalue);
						break;
					case 6:
						WriteDouble(s+i, dbalue);
						break;
					case 7:
						WriteString(s+i, stringvalue);
						break;
					}
				}
			}
			int t_num = num;
			err = WriteNewDatas(_handle, pids, table_ids, times, s, &t_num);

			if (err)
				printf("��ѯ����ʧ��, %s\n", MyDataGetErrDesc(err));
			else
				printf("д��ɹ�, ʱ��%lld\n", t);
		}

	}

	return 0;
}
//UTF-8��GB2312��ת��
char* U2G(const char* utf8)
{
	int len = MultiByteToWideChar(CP_UTF8, 0, utf8, -1, NULL, 0);
	wchar_t* wstr = new wchar_t[len+1];
	memset(wstr, 0, len+1);
	MultiByteToWideChar(CP_UTF8, 0, utf8, -1, wstr, len);
	len = WideCharToMultiByte(CP_ACP, 0, wstr, -1, NULL, 0, NULL, NULL);
	char* str = new char[len+1];
	memset(str, 0, len+1);
	WideCharToMultiByte(CP_ACP, 0, wstr, -1, str, len, NULL, NULL);
	if(wstr) delete[] wstr;
	return str;
}

//GB2312��UTF-8��ת��
char* G2U(const char* gb2312)
{
	int len = MultiByteToWideChar(CP_ACP, 0, gb2312, -1, NULL, 0);
	wchar_t* wstr = new wchar_t[len+1];
	memset(wstr, 0, len+1);
	MultiByteToWideChar(CP_ACP, 0, gb2312, -1, wstr, len);
	len = WideCharToMultiByte(CP_UTF8, 0, wstr, -1, NULL, 0, NULL, NULL);
	char* str = new char[len+1];
	memset(str, 0, len+1);
	WideCharToMultiByte(CP_UTF8, 0, wstr, -1, str, len, NULL, NULL);
	if(wstr) delete[] wstr;
	return str;
}