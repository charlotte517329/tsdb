#ifndef API_COMMON_H_
#define API_COMMON_H_

#include <map>
#include <string>
#include "ace/SOCK_Stream.h"
#include "ace/Thread_Mutex.h"
#include "ace/Guard_T.h"
#include "datas.pb.h"
#include "MyDataError.h"
#include "MyDataCommon.h"
#include "my_alloc.h"


using std::map;
using std::string;

//api����Ϣ
class ClientInfo
{
public:
	ClientInfo(const char* ip, int port);
	~ClientInfo();
	ACE_SOCK_Stream& GetSocket() {return sock_;}
	int GetHandle() {return handle_;}
	bool IsConnect() {return isconnect_;}
	void IsConnect(bool con) {isconnect_ = con;}
	void CloseSock() {sock_.close();}
	int GetPort() {return port_;}
	char* GetIp() {return ip_;}
	void AddClientInfo();
	void RemoveClientInfo();
	MEM_ROOT* GetRoot();
	static int GetClientInfo(int handle, ClientInfo *&info);
	friend class ClientUseRef;
	Datas::WriteNewDatasQuery write_new_query_;
	Datas::WriteOldDatasQuery write_old_query_;
	Datas::ReadNewDatasQuery read_new_query_;
	Datas::ReadNewDatasReply read_new_reply_;
	Datas::ReadDatasReply read_reply_;
private:
	ACE_SOCK_Stream sock_;						//������ͨ�ŵ�socket
	char ip_[IP_LENGTH];						//����˵�ip
	int port_;									//����˵Ķ˿�
	int handle_;								//��socket��Ӧ�ľ�����ɿͻ���ʹ��
	int ref_;									//���ڼ�����Ƿ�����ʹ��
	MEM_ROOT root_;
	bool isconnect_;
	static int _max_handle;						//�������ɾ��
	static map<int, ClientInfo*> _handles;		//socket�����socket��ӳ��
	static ACE_Thread_Mutex _handles_mutex;		//����_handles����
};
//�ͻ��˾��ʹ�õ����ü�����
class ClientUseRef
{
public:
	ClientUseRef(ClientInfo* cinfo):cinfo_(cinfo)
	{
		++cinfo->ref_;
	}
	~ClientUseRef()
	{
		--cinfo_->ref_;
		free_root(cinfo_->GetRoot(), MY_MARK_BLOCKS_FREE);
	}
private:
	ClientInfo* cinfo_;
};
#define ClientScopeLock(pinfo) \
	ClientUseRef cref(pinfo)

void SafeCopy(const string &res, char* des, int len);
char *StrReplace(const char* res, char* des, char r, char d);
#endif /* API_COMMON_H_ */
