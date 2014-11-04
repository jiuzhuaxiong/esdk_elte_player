/********************************************************************
filename    :    NetSourceCommon.h
author      :    s00191067
created     :    2012/11/01
description :    ����������Ĺ���ͷ�ļ�
copyright   :    Copyright (c) 2012-2016 Huawei Tech.Co.,Ltd
history     :    2012/11/01 ��ʼ�汾
*********************************************************************/
#ifndef NET_SOURCE_COMMON_H_
#define NET_SOURCE_COMMON_H_

//ȥ��map�澯
#pragma warning(disable : 4786 4503 4996)

//��׼��ͷ�ļ�
#include <string>
#include <sstream>
#include <map>
#include <WinSock2.h>
#include <windows.h>

#include "hwsdk.h"

//�˿ں�
#define NET_SOURCE_PORT_MIN_NUMBER 1024             //��С�˿ں�;
#define NET_SOURCE_PORT_MAX_NUMBER 65535            //���˿ں�;
#define NET_SOURCE_BEGIN_PORT 35000                 //��ʼ�˿ں�;
#define NET_SOURCE_END_PORT   39000                 //�����˿ں�;
#define NET_SOURCE_TOTAL_CHANNEL_NUM 128            //����ͨ��������0--127��;

#define NET_SOURCE_BIND_PORT_RETRY   3              //���԰󶨶˿ڵĴ���;
#define NET_SOURCE_UDP_SOCKET_NUM    4              //UDP socket����;

#define RECV_TOTAL_TIMEOUT_TIME     (30*1000)       //�����ܹ���ʱʱ�䣬��λΪ����
#define RECV_MEDIA_DATA_TIMEOUT     1               //����socket������ʱʱ�䣬��λΪ��
#define SEND_NAT_INTERVAL           (5*1000)       // ����NAT��Խ�ļ��ʱ�䣬��λΪ����

#define RTP_MEDIA_BUF_LEN           (16 * 1024)            //���պͻص�����������

// SOCKET �������;
typedef enum SocketType
{
    VIDEO_RTP_SOCKET = 0,
    VIDEO_RTCP_SOCKET,
    AUDIO_RTP_SOCKET,
    AUDIO_RTCP_SOCKET,
    MULTICAST_SOCKET
}SOCKET_TYPE;

//�˿ں�����
typedef enum PortType
{
    VIDEO_RTP_PORT = 0,
    VIDEO_RTCP_PORT,
    AUDIO_RTP_PORT,
    AUDIO_RTCP_PORT,
    MULTICAST_PORT
}PORT_TYPE;

//��IP
typedef enum StreamIPType
{
    LOCAL_RECV_STREAM_IP,   // ��������IP
    REMOTE_SEND_STREAM_IP   // Զ�˷���IP
}STREAM_IP_TYPE;

#define NET_RTP_MAX_SOCKET_BUFFER (1024 * 1024 * 2) //������1MB����Ƶsocket�Ļ�����


// �쳣�ص�����
typedef  IVS_VOID (CALLBACK *NET_EXCEPTION_CALLBACK)(IVS_ULONG  ulChannel,     // ͨ����;
                                                     IVS_INT32  iMsgType,      // �쳣��Ϣ����;
                                                     IVS_VOID*  pParam,        // ��Ӧ�쳣����Ϣ������չΪ�ṹ��ָ��;
                                                     IVS_VOID*  pUser);        // �û�����;

// ý�����ص�
typedef  IVS_VOID (CALLBACK *NET_DATA_CALLBACK)(IVS_CHAR    *pBuf,      // �ص�����;
                                                IVS_UINT32  uiSize,     // ���ݳ���;
                                                IVS_VOID    *pUser);    // �û�����;

#endif //NET_SOURCE_COMMON_H_
