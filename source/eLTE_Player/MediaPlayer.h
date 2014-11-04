/********************************************************************
filename    :    MediaPlayer.h
author      :    yubinbin wx200189
created     :    2014/07/01
description :    ý�岥���ࡣʹ��IVS MPģ��ʵ�ֱ�OCX����Ƶ���Ź���
copyright   :    Copyright (c) 2012-2016 Huawei Tech.Co.,Ltd
history     :    2014/07/01 ��ʼ�汾
*********************************************************************/

#ifndef __ELTE_OCX_MEDIA_PLAYER_H__
#define __ELTE_OCX_MEDIA_PLAYER_H__

#include "AudioPlayer.h"


//////////////////////////////////////////////////////////////////////////
struct FIXED_HEADER
{
	// byte 0
	unsigned char csrc_len  : 4;	// expect 0
	unsigned char extension : 1;	// expect 0
	unsigned char padding   : 1;	// expect 0
	unsigned char version   : 2;	// expect 2
	// byte 1
	unsigned char payload	: 7;	//
	unsigned char marker	: 1;	// expect 1
	// bytes 2, 3
	unsigned short seq_no;

	// bytes 4-7
	unsigned int timestamp;

	// bytes 8-11
	unsigned int ssrc;				// stream number is used here
};

// eLTE AMR
#define PAY_LOAD_TYPE_ELTE_AMR	114
//////////////////////////////////////////////////////////////////////////

class MediaPlayer
{
public:
	MediaPlayer(void);
	~MediaPlayer(void);

public:
	// ��ʼ��������
	int InitPlayerParam(IVS_CHAR* pLocalIP, IVS_UINT32 uiLocalVideoPort, IVS_UINT32 uiLocalAudioPort);
	// ȥ��ʼ��������
	int UninitPlayer();
	// ��ʼ����
	int StartPlayer(IVS_CHAR* pRemoteIP, IVS_UINT32 uiRemoteVideoPort, IVS_UINT32 uiRemoteAudioPort, HWND hVideoPlayer);
	// ֹͣ����
	int StopPlayer();
	// ������Ƶ
	int PlayAudio();
	// ֹͣ��Ƶ
	int StopAudio();
	// ����ץ�ĵ���ͼƬ
	int LocalSnapshot(const std::string& strResId, std::string& strSnapshotPath);
	// ��ʼ��ץͼ����
	void InitParam(int snapshotFormat, const std::string& savePath);
	// ��ʼ����������
	void InitParam(DWORD dwVolume);

	// ���ڹ���������
public:
	// ����ץͼ����
	void SetMediaPlayerResID(const std::string& strResId);
	// ���ò��Ų����������ǹ������л���Ƶ������IPʹ���ϴο�����Ƶʱʹ�õ�IP��
	void SetPlayerParam(IVS_UINT32 uiLocalVideoPort, IVS_UINT32 uiLocalAudioPort,
						IVS_UINT32 uiRemoteVideoPort, IVS_UINT32 uiRemoteAudioPort);
	// ��ʼ��������
	int StartPlayer(HWND hVideoPlayer);
	// ����ץ�ĵ���ͼƬ
	int LocalSnapshot(std::string& strSnapshotPath);
	// ��ȡ��ԴID
	int GetMediaPlayerResID() const;

public:
	// ý�����ص�
	// pBuf		�ص�����
	// uiSize	���ݳ���
	// pUser	�û�����
	static IVS_VOID CALLBACK NetDateCallBack(IVS_CHAR* pBuf, IVS_UINT32 uiSize, IVS_VOID* pUser);

	// �쳣�ص�����
	// ulChannel ͨ����
	// iMsgType �쳣��Ϣ����
	// pParam ��Ӧ�쳣����Ϣ������չΪ�ṹ��ָ��
	// pUser �û�����
	static IVS_VOID CALLBACK NetExceptionCallBack(IVS_ULONG ulChannel, IVS_INT32 iMsgType, IVS_VOID* pParam, IVS_VOID* pUser);

private:
	// ��ȡץͼ��
	std::string GetSnapshotPath(const std::string& strResId) const;
	// ��Ƶ�ж�
	BOOL IsNetDateAudio(char* pBuf, size_t bufSize, char* &pAmr, size_t& amrSize) const;

private:
	// �����������
	IVS_ULONG m_ulNetChannel;
	// ���������
	IVS_ULONG m_ulPalyerChannel;
	// ���ſ�ʼ��־
	BOOL m_bStartPlayer;
	// ץͼ��ʽ
	int m_snapshotFormat;
	// ץͼ����·��
	std::string m_savePath;
	// ��������Ƶ�����ڹر���Ƶ
	BOOL m_bAllowPlaySound;
	// ��ʼ����־
	static BOOL m_bInit;

private:
	// ��Ƶ������
	AudioPlayer m_AudioPlayer;

	// ���ڹ���������
private:
	// ��Ƶ��ԴID
	std::string m_strResId;
	// ����IP
	std::string m_strLocalIP;
	// Զ��IP
	std::string m_strRemoteIP;
	// ������Ƶ�˿�
	IVS_UINT32 m_uiLocalVideoPort;
	// ������Ƶ�˿�
	IVS_UINT32 m_uiLocalAudioPort;
	// Զ����Ƶ�˿�
	IVS_UINT32 m_uiRemoteVideoPort;
	// Զ����Ƶ�˿�
	IVS_UINT32 m_uiRemoteAudioPort;
};

#endif
