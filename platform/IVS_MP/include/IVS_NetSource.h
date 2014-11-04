/********************************************************************
	filename	: 	IVS_NetSource.h
	author		:	s00191067
	created		:	2011/10/28	
	description	:	IVS����������ӿ�
	copyright	:	Copyright (C) 2011-2015
	history		:	2011/10/28
*********************************************************************/
#ifndef IVS_NETSOURCE_H
#define IVS_NETSOURCE_H

#include "hwsdk.h"
#include "ivs_error.h"
#include "NetSourceCommon.h"

#ifdef IVS_NETSOURCE_EXPORTS
#define IVS_NETSOURCE_API extern "C" __declspec(dllexport)
#else
#define IVS_NETSOURCE_API extern "C" __declspec(dllimport)
#endif

/*****************************************************************************
 �������ƣ�IVS_NETSOURCE_Init
 ������������ʼ��;
 ���������const char* pLogPath = NULL
 ���������NA
 �� �� ֵ���ɹ�:IVS_SUCCEED;
           ʧ��:IVS_FAIL,PLAYER_RET_WSA_START_ERROR;
*****************************************************************************/
IVS_NETSOURCE_API IVS_INT32 __stdcall IVS_NETSOURCE_Init(const char* pLogPath);

/*****************************************************************************
 �������ƣ�IVS_NETSOURCE_UnInit
 �������������������;
 ���������NA
 ���������NA
 �� �� ֵ���ɹ�:IVS_SUCCEED ʧ��:IVS_FAIL;
*****************************************************************************/
IVS_NETSOURCE_API IVS_VOID __stdcall IVS_NETSOURCE_UnInit();

/*****************************************************************************
 �������ƣ�IVS_NETSOURCE_GetChannel
 ������������ȡ����ͨ��;
 ���������NA
 ���������pChannel 
 �� �� ֵ���ɹ�:IVS_SUCCEED ʧ��:IVS_FAIL;
*****************************************************************************/
IVS_NETSOURCE_API IVS_INT32 __stdcall IVS_NETSOURCE_GetChannel(IVS_ULONG* pChannel);

/*****************************************************************************
 �������ƣ�IVS_NETSOURCE_FreeChannel
 �����������ͷ�ָ��ͨ��;
 ���������ulChannel 
 ���������NA
 �� �� ֵ���ɹ�:IVS_SUCCEED ʧ��:IVS_FAIL;
*****************************************************************************/
IVS_NETSOURCE_API IVS_INT32 __stdcall IVS_NETSOURCE_FreeChannel(IVS_ULONG ulChannel);

/*****************************************************************************
 �������ƣ�IVS_NETSOURCE_SetProtocolType
 ��������������ý��������Э������;
 ���������ulChannel        ͨ����
           uiProtocolType Э������;
 ���������NA
 �� �� ֵ���ɹ�:IVS_SUCCEED ʧ��:IVS_FAIL;
*****************************************************************************/
IVS_NETSOURCE_API IVS_INT32 __stdcall IVS_NETSOURCE_SetProtocolType(IVS_ULONG ulChannel, IVS_UINT32 uiProtocolType);

/*****************************************************************************
 �������ƣ�IVS_NETSOURCE_GetProtocolType
 �������������ý��������Э������;
 ���������ulChannel  ͨ����;              
 ���������pProtocolType Э������;
 �� �� ֵ���ɹ�:IVS_SUCCEED ʧ��:IVS_FAIL;
*****************************************************************************/
IVS_NETSOURCE_API IVS_INT32 __stdcall IVS_NETSOURCE_GetProtocolType(IVS_ULONG ulChannel, IVS_UINT32* pProtocolType);

/*****************************************************************************
 �������ƣ�IVS_NETSOURCE_SetLocalRecvStreamIP
 �������������ñ��ؽ���������Ip��ַ;
 ���������ulChannel  ͨ����;   
           pLocalRecvStreamIp  ����������ip;
 ���������NA
 �� �� ֵ���ɹ�:IVS_SUCCEED ʧ��:IVS_FAIL;
*****************************************************************************/
IVS_NETSOURCE_API IVS_INT32 __stdcall IVS_NETSOURCE_SetLocalRecvStreamIP(IVS_ULONG ulChannel, IVS_CHAR* pLocalRecvStreamIp);

/*****************************************************************************
 �������ƣ�IVS_NETSOURCE_GetLocalRecvStreamIP
 �������������ñ��ؽ���������Ip��ַ;
 ���������ulChannel  ͨ����;   
 ���������pLocalRecvStreamIp  ����������ip;
 �� �� ֵ��NA
*****************************************************************************/
IVS_NETSOURCE_API IVS_INT32 __stdcall IVS_NETSOURCE_GetLocalRecvStreamIP(IVS_ULONG ulChannel, IVS_CHAR* pLocalRecvStreamIp);

/*****************************************************************************
 �������ƣ�IVS_NETSOURCE_GetLocalRecvStreamAddr
 ������������ȡ���ؽ��������ĵ�ַIP�Ͷ˿ں�;
 ���������ulChannel ͨ����;
 ���������pLocalRecvStreamVideoRtpPort ������Ƶ������RTP�˿ں�;
           pLocalRecvStreamAudioRtpPort ������Ƶ������RTP�˿ں�;
 �� �� ֵ���ɹ�:IVS_SUCCEED ʧ��:IVS_FAIL;
*****************************************************************************/
IVS_NETSOURCE_API IVS_INT32 __stdcall IVS_NETSOURCE_GetLocalRecvStreamPort(IVS_ULONG ulChannel, 
                                                                           IVS_UINT32* pLocalRecvStreamVideoRtpPort, 
                                                                           IVS_UINT32* pLocalRecvStreamAudioRtpPort);

/*****************************************************************************
 �������ƣ�IVS_NETSOURCE_SetLocalRecvStreamAddr
 �������������ñ��ؽ��������ĵ�ַIP�Ͷ˿ں�;
 ���������ulChannel ͨ����;
		   uiLocalRecvStreamVideoRtpPort ������Ƶ������RTP�˿ں�;
           uiLocalRecvStreamAudioRtpPort ������Ƶ������RTP�˿ں�;
 ���������NULL
 �� �� ֵ���ɹ�:IVS_SUCCEED ʧ��:IVS_FAIL;
*****************************************************************************/
IVS_NETSOURCE_API IVS_INT32 __stdcall IVS_NETSOURCE_SetLocalRecvStreamPort(IVS_ULONG ulChannel, 
                                                                           IVS_UINT32 uiLocalRecvStreamVideoRtpPort, 
                                                                           IVS_UINT32 uiLocalRecvStreamAudioRtpPort);


/*****************************************************************************
 �������ƣ�IVS_NETSOURCE_OpenNetStream
 ������������������;
 ���������ulChannel                         ͨ����;
		   pRemoteSendStreamIp               Դ�˷�������IP;
		   uiRemoteSendStreamVideoPort       Դ�˷�����Ƶ����RTP�˿ں�;
           uiRemoteSendStreamAudioPort       Դ�˷�����Ƶ����RTP�˿ں�;
 ���������NA
 �� �� ֵ���ɹ�:IVS_SUCCEED ʧ��:IVS_FAIL;
*****************************************************************************/
IVS_NETSOURCE_API IVS_INT32 __stdcall IVS_NETSOURCE_OpenNetStream(IVS_ULONG ulChannel, IVS_CHAR* pRemoteSendStreamIp, 
                                                                  IVS_UINT32 uiRemoteSendStreamVideoPort, 
                                                                  IVS_UINT32 uiRemoteSendStreamAudioPort);

/*****************************************************************************
 �������ƣ�IVS_NETSOURCE_CloseNetStream
 �����������ر�������;
 ���������ulChannel             ͨ����;
 ���������NA
 �� �� ֵ���ɹ�:IVS_SUCCEED ʧ��:IVS_FAIL;
*****************************************************************************/
IVS_NETSOURCE_API IVS_INT32 __stdcall IVS_NETSOURCE_CloseNetStream(IVS_ULONG ulChannel);


/*****************************************************************************
 �������ƣ�IVS_NETSOURCE_StartRecvStream
 ������������������;
 ���������ulChannel             ͨ����;
 ���������NA
 �� �� ֵ���ɹ�:IVS_SUCCEED ʧ��:IVS_FAIL;
*****************************************************************************/
IVS_NETSOURCE_API IVS_INT32 __stdcall IVS_NETSOURCE_StartRecvStream(IVS_ULONG ulChannel);


/***************************************************************************
 �� �� �� : IVS_NETSOURCE_SetExceptionCallBack
 �������� : �����쳣�ص�����;
 ������� : cbExceptionCallBack         �쳣�ص�����;
            pUser                       �û��������ص������з���;
 ������� : NA
 �� �� ֵ : NA
***************************************************************************/
IVS_NETSOURCE_API IVS_VOID __stdcall IVS_NETSOURCE_SetExceptionCallBack(NET_EXCEPTION_CALLBACK cbExceptionCallBack, 
                                                                        IVS_VOID* pUser);

/***************************************************************************
 �� �� �� : IVS_NETSOURCE_SetDataCallBack
 �������� : ����ý�����ص�����;
 ������� : ulChannel          ͨ����;
            cbDataCallBack    ý�����ص�����;
            pUser             �û��������ص������з���;
 ������� : NA
 �� �� ֵ : NA
***************************************************************************/
IVS_NETSOURCE_API IVS_VOID __stdcall IVS_NETSOURCE_SetDataCallBack(IVS_ULONG ulChannel, 
                                                                   NET_DATA_CALLBACK cbDataCallBack, 
                                                                   IVS_VOID* pUser);

/***************************************************************************
 �� �� �� : IVS_NETSOURCE_SetSessionInfo
 �������� : ����SessionUrl��SessionId;
 ������� : ulChannel          ͨ����;
           pSessionUrl       URL;
           pSessionId        IDֵ;
 ������� : NA
 �� �� ֵ : NA
***************************************************************************/
IVS_NETSOURCE_API IVS_VOID __stdcall IVS_NETSOURCE_SetSessionInfo(IVS_ULONG ulChannel, 
                                                                  IVS_CHAR* pSessionUrl, 
                                                                  IVS_CHAR* pSessionId);
#endif // IVS_NETSOURCE_H
