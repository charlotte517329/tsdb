#pragma once

enum DataType
{
	DataChar = 1,
	DataInt16,
	DataInt32,
	DataInt64,
	DataFloat,
	DataDouble,
	DataString
};

#define IP_LENGTH 16
#define NAME_SIZE 32
#define TYPE_SIZE 16
#define MAX_DATA_SIZE 2048		//���ݵ�����С
#define TYPE_NAME 512

struct TypeInfo
{
	int id;
	char type[TYPE_SIZE];		//���DataType����ʾ���ͣ�����ʹ�õ���������ʱ����Ϊ0
	char name[NAME_SIZE];
	char type_names[TYPE_NAME];	//ÿ�����Ͷ�Ӧ�����ƣ�����֮����;����
};

struct TableInfo
{
	int id;
	int type_id;
	char name[NAME_SIZE];
};

struct PointInfo
{
	int id;
	int table_id;
	char name[NAME_SIZE];
};
//���л�������д����ʱʹ��
struct Serializer
{
	char type[TYPE_SIZE];
	int offset;				//type����λ��
	char buf[MAX_DATA_SIZE];
	int data_pos;			//bufд����ʼλ��
};
//���ʹ�õ����л���
struct SerializerNoBuf
{
	explicit SerializerNoBuf(const char* data):buf(data),data_pos(0){}
	const char *buf;
	int data_pos;			//bufд����ʼλ��
};

struct DataFileInfo
{
	time_t start_time;		
	time_t end_time;		
	long long file_size;	
	float using_rate;
	char filename[NAME_SIZE];		
};

//��С����
template<typename T>
class CommonGreatThan
{
public:
	int operator()(T a, T b)const
	{
		if (a > b) return 1;
		if (a < b) return -1;
		return 0;
	}
};
//�Ӵ�С
template<typename T>
class CommonLowThan
{
public:
	int operator()(T a, T b)const
	{
		if (a < b) return 1;
		if (a > b) return -1;
		return 0;
	}
};

class MyDataFun
{
public:
	virtual int MyDataCallBack(void*) = 0;
	void* data_;
};