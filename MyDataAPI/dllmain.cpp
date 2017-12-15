// dllmain.cpp : ���� DLL Ӧ�ó������ڵ㡣
#include "stdafx.h"
#include "ace/Init_ACE.h"
#include "ClientProtoHandler.h"
BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
					 )
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
		ACE::init();
		WSADATA   wsaData;
		WSAStartup( MAKEWORD(2,0), &wsaData);
		cln_proto_handler::init();
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
	case DLL_PROCESS_DETACH:
		ACE::fini();
		break;
	}
	return TRUE;
}

