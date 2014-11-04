/********************************************************************
filename    :    IVS_Player.h
author      :    s00191067
created     :    2012/11/12
description :    IVS���ſ�ӿ�
copyright   :    Copyright (c) 2012-2016 Huawei Tech.Co.,Ltd
history     :    2012/11/12 ��ʼ�汾
*********************************************************************/
#ifndef IVS_PLAYER_H
#define IVS_PLAYER_H

#include "IVSPlayerDataType.h"

#ifdef IVS_PLAYER_EXPORTS
#define IVS_PLAYER_API extern "C" __declspec(dllexport)
#else
#define IVS_PLAYER_API extern "C" __declspec(dllimport)
#endif

/*****************************************************************************
 �������ƣ�IVS_PLAY_Init
 ������������ʼ��;
 ���������const char* pLogPath = NULL
 ���������NA
 �� �� ֵ���ɹ�:IVS_SUCCEED;ʧ��:IVS_FAIL;
*****************************************************************************/
IVS_PLAYER_API IVS_INT32 __stdcall IVS_PLAY_Init(const char* pLogPath = NULL);

/*****************************************************************************
 �������ƣ�IVS_PLAY_UnInit
 ���������������;
 ���������NA
 ���������NA
 �� �� ֵ��NA
*****************************************************************************/
IVS_PLAYER_API IVS_VOID __stdcall IVS_PLAY_UnInit();

/*****************************************************************************
 �������ƣ�IVS_PLAY_GetChannel
 ������������ȡ���õ�ý��ͨ����;
 ���������NA
 ���������pChannel  ͨ����;
 �� �� ֵ���ɹ�:IVS_SUCCEED;ʧ��:IVS_FAIL;
*****************************************************************************/
IVS_PLAYER_API IVS_INT32 __stdcall IVS_PLAY_GetChannel(IVS_ULONG* pChannel);

/*****************************************************************************
 �������ƣ�IVS_PLAY_FreeChannel
 �����������ͷ�ָ����ý��ͨ����;
 ���������ulChannel  ͨ����;
 ���������NA
 �� �� ֵ���ɹ�:IVS_SUCCEED;ʧ��:IVS_FAIL;
*****************************************************************************/
IVS_PLAYER_API IVS_INT32 __stdcall IVS_PLAY_FreeChannel(IVS_ULONG ulChannel);

/***************************************************************************
 �� �� �� : IVS_PLAY_SetExceptionCallBack
 �������� : �����쳣�ص�����;
 ������� : cbExceptionCallBack         �쳣�ص�����;
            pUser                       �û�����;
 ������� : NA
 �� �� ֵ : �ɹ�:IVS_SUCCEED;ʧ��:IVS_FAIL;
***************************************************************************/
IVS_PLAYER_API IVS_VOID __stdcall IVS_PLAY_SetExceptionCallBack(
	                                  PLAYER_EXCEPTION_CALLBACK cbExceptionCallBack, 
                                      void* pUser
   								    );

/*****************************************************************************
 �������ƣ�IVS_PLAY_SetVideoDecodeType
 ����������������Ƶ��������;
 ���������ulChannel  ͨ����;
           uiVideoDecoderType ��Ƶ��������;
 ���������NA
 �� �� ֵ���ɹ�:IVS_SUCCEED;ʧ��:IVS_FAIL;
*****************************************************************************/
IVS_PLAYER_API IVS_INT32 __stdcall IVS_PLAY_SetVideoDecodeType(IVS_ULONG ulChannel, IVS_UINT32 uiVideoDecoderType);

/*****************************************************************************
 �������ƣ�IVS_PLAY_GetVideoDecodeType
 ������������ȡ��Ƶ��������;
 ���������ulChannel  ͨ����;                
 ���������pVideoDecoderType ��Ƶ��������;
 �� �� ֵ���ɹ�:IVS_SUCCEED;ʧ��:IVS_FAIL;
*****************************************************************************/
IVS_PLAYER_API IVS_INT32 __stdcall IVS_PLAY_GetVideoDecodeType(IVS_ULONG ulChannel, IVS_UINT32* pVideoDecoderType);

/*****************************************************************************
 �������ƣ�IVS_PLAY_SetAudioDecodeType()
 ����������������Ƶ��������;
 ���������ulChannel  ͨ����;
		   uiAudioDecoderType ��Ƶ��������;
 ���������NA
 �� �� ֵ���ɹ�:IVS_SUCCEED;ʧ��:IVS_FAIL;
*****************************************************************************/
IVS_PLAYER_API IVS_INT32 __stdcall IVS_PLAY_SetAudioDecodeType(IVS_ULONG ulChannel, IVS_UINT32 uiAudioDecoderType);

/*****************************************************************************
 �������ƣ�IVS_PLAY_GetAudioDecodeType()
 ������������ȡ��Ƶ��������;
 ���������ulChannel  ͨ����;                
 ���������uiAudioDecoderType ��Ƶ��������;
 �� �� ֵ���ɹ�:IVS_SUCCEED;ʧ��:IVS_FAIL;
*****************************************************************************/
IVS_PLAYER_API IVS_INT32 __stdcall IVS_PLAY_GetAudioDecodeType(IVS_ULONG ulChannel, IVS_UINT32* pAudioDecoderType);

/*****************************************************************************
 �������ƣ�IVS_PLAY_OpenStream
 ��������������ͨ��;
 ���������ulChannel  ͨ����;
           uiPlayeMode  ����ģʽ;
           uiStreamType ��������ʽ;
           bHardwareDec ����Ӳ���־��true������false������
 ���������NA
 �� �� ֵ���ɹ�:IVS_SUCCEED;ʧ��:IVS_FAIL;
 *****************************************************************************/
IVS_PLAYER_API IVS_INT32 __stdcall IVS_PLAY_OpenStream(IVS_ULONG ulChannel, IVS_UINT32 uiPlayeMode, IVS_UINT32 uiSourceType);

/*****************************************************************************
 �������ƣ�IVS_PLAY_CloseStream
 �����������ر���ͨ��;
 ���������ulChannel ͨ����;
 ���������NA
 �� �� ֵ���ɹ�:IVS_SUCCEED;ʧ��:IVS_FAIL;
*****************************************************************************/
IVS_PLAYER_API IVS_INT32 __stdcall IVS_PLAY_CloseStream(IVS_ULONG ulChannel);

/*****************************************************************************
 �������ƣ�IVS_PLAY_StartPlay
 ������������������;
 ���������ulChannel ͨ����;
 ���������NA
 �� �� ֵ���ɹ�:IVS_SUCCEED;ʧ��:IVS_FAIL;
*****************************************************************************/
IVS_PLAYER_API IVS_INT32 __stdcall IVS_PLAY_StartPlay(IVS_ULONG ulChannel);

/*****************************************************************************
 �������ƣ�IVS_PLAY_StopPlay
 ����������ֹͣ����;
 ���������ulChannel ͨ����;
 ���������NA
 �� �� ֵ���ɹ�:IVS_SUCCEED;ʧ��:IVS_FAIL;
*****************************************************************************/
IVS_PLAYER_API IVS_INT32 __stdcall IVS_PLAY_StopPlay(IVS_ULONG ulChannel);

/*****************************************************************************
 �������ƣ�IVS_PLAY_PausePlay
 ������������ͣ����
 ���������ulChannel ͨ����;
 ���������NA
 �� �� ֵ���ɹ�:IVS_SUCCEED;ʧ��:IVS_FAIL;
*****************************************************************************/
IVS_PLAYER_API IVS_INT32 __stdcall IVS_PLAY_PausePlay(IVS_ULONG ulChannel);

/*****************************************************************************
 �������ƣ�IVS_PLAY_ResumePlay
 �����������ָ�����
 ���������ulChannel ͨ����;
 ���������NA
 �� �� ֵ���ɹ�:IVS_SUCCEED;ʧ��:IVS_FAIL;
*****************************************************************************/
IVS_PLAYER_API IVS_INT32 __stdcall IVS_PLAY_ResumePlay(IVS_ULONG ulChannel);

/*****************************************************************************
 �������ƣ�IVS_PLAY_SetPlaySpeed
 �����������ָ�����
 ���������ulChannel ͨ����;
 ���������NA
 �� �� ֵ���ɹ�:IVS_SUCCEED;ʧ��:IVS_FAIL;
*****************************************************************************/
IVS_PLAYER_API IVS_INT32 __stdcall IVS_PLAY_SetPlaySpeed(IVS_ULONG ulChannel, double dSpeed);

/*****************************************************************************
 �������ƣ�IVS_PLAY_StepPalyForward
 ������������������ǰ��
 ���������ulChannel ͨ����;
 ���������pRemain ʣ��֡��
 �� �� ֵ���ɹ�:IVS_SUCCEED;ʧ��:IVS_FAIL;
*****************************************************************************/
IVS_PLAYER_API IVS_INT32 __stdcall IVS_PLAY_StepPlayForward(IVS_ULONG ulChannel, IVS_ULONG *pRemain);

/*****************************************************************************
 �������ƣ�IVS_PLAY_StepPalyBack
 �����������������ź���
 ���������ulChannel ͨ����;
 ���������pRemain ʣ��֡��
 �� �� ֵ���ɹ�:IVS_SUCCEED;ʧ��:IVS_FAIL;
*****************************************************************************/
IVS_PLAYER_API IVS_INT32 __stdcall IVS_PLAY_StepPlayBackward(IVS_ULONG ulChannel, IVS_ULONG *pRemain);

/*****************************************************************************
 �������ƣ�IVS_PLAY_StartPlayAudio
 ����������������Ƶ����;
 ���������ulChannel ͨ����;
 ���������NA
 �� �� ֵ���ɹ�:IVS_SUCCEED;ʧ��:IVS_FAIL;
*****************************************************************************/
IVS_PLAYER_API IVS_INT32 __stdcall IVS_PLAY_PlaySound(IVS_ULONG ulChannel);

/*****************************************************************************
 �������ƣ�IVS_PLAY_StopSound
 ����������ֹͣ��Ƶ����;
 ���������ulChannel ͨ����;
 ���������NA
 �� �� ֵ���ɹ�:IVS_SUCCEED;ʧ��:IVS_FAIL;
*****************************************************************************/
IVS_PLAYER_API IVS_INT32 __stdcall IVS_PLAY_StopSound(IVS_ULONG ulChannel);

/*****************************************************************************
 �������ƣ�IVS_PLAY_SetVolume
 ������������������;
 ���������ulChannel ͨ����;
           uiVolumeValue ����
 ���������NA
 �� �� ֵ���ɹ�:IVS_SUCCEED;ʧ��:IVS_FAIL;
*****************************************************************************/
IVS_PLAYER_API IVS_INT32 __stdcall IVS_PLAY_SetVolume(IVS_ULONG ulChannel,
                                                    IVS_UINT32 uiVolumeValue);

/*****************************************************************************
 �������ƣ�IVS_PLAY_GetVolume
 ������������ȡ����;
 ���������ulChannel ͨ����;
 ���������uiVolumeValue ����
 �� �� ֵ���ɹ�:IVS_SUCCEED;ʧ��:IVS_FAIL;
*****************************************************************************/
IVS_PLAYER_API IVS_INT32 __stdcall IVS_PLAY_GetVolume(IVS_ULONG ulChannel, IVS_UINT32* puiVolumeValue);

/*****************************************************************************
 �������ƣ�IVS_PLAY_SetRawFrameCallBack
 ���������������������ص�;
 ���������ulChannel           ͨ����;
           cbReassmCallBack  �ص�����ָ��;
           pUser             �û�����;
 ���������NA
 �� �� ֵ���ɹ�:IVS_SUCCEED;ʧ��:IVS_FAIL;
*****************************************************************************/
IVS_PLAYER_API IVS_INT32 __stdcall IVS_PLAY_SetRawFrameCallBack(IVS_ULONG ulChannel, REASSM_CALLBACK cbReassmCallBack, void *pUser);

/*****************************************************************************
 �������ƣ�IVS_PLAY_SetFrameCallBack
 �������������ý���֡���ݻص�;
 ���������ulChannel           ͨ����;
           cbReassmCallBack    �ص�����ָ��;
           pUser               �û�����;
 ���������NA
 �� �� ֵ���ɹ�:IVS_SUCCEED;ʧ��:IVS_FAIL;
*****************************************************************************/
IVS_PLAYER_API IVS_INT32 __stdcall IVS_PLAY_SetFrameCallBack(IVS_ULONG ulChannel, DECODER_CALLBACK fnDecoderCB, void *pUser);

/*****************************************************************************
 �������ƣ�IVS_PLAY_SetPlayWindow
 �������������ò��Ŵ��ھ��
 ���������ulChannel ͨ����;
           IVS_HANDLE�� ��Ⱦͨ�����
	       hWnd��          ��Ⱦ����
 ���������NA
 �� �� ֵ��int
****************************************************************************/
IVS_PLAYER_API IVS_INT32 __stdcall IVS_PLAY_SetPlayWindow(IVS_ULONG ulChannel, HWND hWnd);

/*****************************************************************************
 �������ƣ�IVS_PLAY_AddPlayWindow
 �������������ò��Ŵ��ھ��
 ���������ulChannel ͨ����;
	       IVS_HANDLE�� ��Ⱦͨ�����
	       hWnd��       ���ھ��
	       nType��      ��Ⱦ��������
	       pLayout��    ���ڲ��ֲ���
 ���������NA
 �� �� ֵ��int
****************************************************************************/
IVS_PLAYER_API IVS_INT32 __stdcall IVS_PLAY_AddPlayWindow(IVS_ULONG ulChannel, HWND hWnd, int nType, void *pLayout);

/*****************************************************************************
 �������ƣ�IVS_PLAY_AddPlayWindowPartial
 �������������Ӿֲ�ͼ�񲥷Ŵ���
 ���������ulChannel ͨ����;
	      IVS_HANDLE�� ��Ⱦͨ�����
	      hWnd��       ���ھ��
	      pPartial��   �ֲ�ͼƬ����
 ���������NA
 �� �� ֵ��int
****************************************************************************/
IVS_PLAYER_API IVS_INT32 __stdcall IVS_PLAY_AddPlayWindowPartial(IVS_ULONG ulChannel, HWND hWnd, LAYOUT_DRAW_PARTIAL *pPartial);

/*****************************************************************************
 �������ƣ�IVS_PLAY_UpdateWindowPartial
 �������������¾ֲ��Ŵ�Դ����
 ���������ulChannel ͨ����
	     IVS_HANDLE�� ��Ⱦͨ�����
	     hWnd��       ���ھ��
	     pPartial��   �ֲ�����
 ���������NA
 �� �� ֵ��int
****************************************************************************/
IVS_PLAYER_API IVS_INT32 __stdcall IVS_PLAY_UpdateWindowPartial(IVS_ULONG ulChannel, HWND hWnd, LAYOUT_DRAW_PARTIAL *pPartial);

/*****************************************************************************
 �������ƣ�IVS_PLAY_DelPlayWindow
 ����������ɾ�����Ŵ��ھ��
 ���������ulChannel ͨ����;
	       hWnd��    ���ھ��
 ���������NA
 �� �� ֵ��int
****************************************************************************/
IVS_PLAYER_API IVS_INT32 __stdcall IVS_PLAY_DelPlayWindow(IVS_ULONG ulChannel, HWND hWnd);

/*****************************************************************************
 �������ƣ�IVS_PLAY_SetDisplayAspectRatio
 ������������ͨ���ʹ���������Ƶ��ʾ����
 ���������ulChannel:    ͨ����;
	     IVS_HANDLE��   ��Ⱦͨ�����
	     hWnd��         ���ھ��
		 uiScale:       ��ʾ����
 ���������NA
 �� �� ֵ��IVS_INT32
****************************************************************************/
IVS_PLAYER_API IVS_INT32 __stdcall IVS_PLAY_SetDisplayAspectRatio(IVS_ULONG ulChannel, IVS_UINT32 uiScale);

/*****************************************************************************
 �������ƣ�IVS_PLAY_InputRtpData
 �����������򲥷ſ�����RTP��;
 ���������ulChannel    ͨ����;
           pBuf         ����;
		   ulSize       �����С;
 ���������NA
 �� �� ֵ���ɹ�:IVS_SUCCEED;ʧ��:IVS_FAIL;
 *****************************************************************************/
IVS_PLAYER_API IVS_INT32 __stdcall IVS_PLAY_InputRtpData(IVS_ULONG ulChannel, IVS_CHAR *pBuf, IVS_UINT32 uiSize);

/*****************************************************************************
 �������ƣ�IVS_PLAY_InputFrameData
 �����������򲥷ſ�����֡����(����Ƶ);
 ���������ulChannel    ͨ����;
           pstRawFrameInfo δ����֡������Ϣ;
		   pFrame       ֡����
		   uFrameSize   ֡���ݳ���
 ���������NA
 �� �� ֵ���ɹ�:IVS_SUCCEED;ʧ��:IVS_FAIL;
 *****************************************************************************/
IVS_PLAYER_API IVS_INT32 __stdcall IVS_PLAY_InputFrameData(IVS_ULONG ulChannel, IVS_RAW_FRAME_INFO* pstRawFrameInfo, IVS_CHAR* pFrame, IVS_UINT32 uFrameSize);

/*****************************************************************************
 �������ƣ�IVS_OpenFileStream
 �������������ļ�;
 ���������ulChannel    ͨ����;
 ���������pFileName    �ļ���;
 ���������NA
 �� �� ֵ���ɹ�:IVS_SUCCEED;ʧ��:IVS_FAIL;
*****************************************************************************/
IVS_PLAYER_API IVS_INT32 __stdcall IVS_PLAY_OpenFile(IVS_ULONG ulChannel, const IVS_CHAR* pFileName);

/*****************************************************************************
 �������ƣ�IVS_PLAY_SetFileTimeRange
 ���������������ļ�����ʱ�䷶Χ
 ���������ulChannel    ͨ����;
 ���������pFileName    �ļ���;
 ���������NA
 �� �� ֵ���ɹ�:IVS_SUCCEED;ʧ��:IVS_FAIL;
*****************************************************************************/
IVS_PLAYER_API IVS_INT32 __stdcall IVS_PLAY_SetFileTimeRange(IVS_ULONG ulChannel, 
	unsigned int beg, unsigned int end);

/*****************************************************************************
 �������ƣ�IVS_SetWaterMarkVerify()
 �������������ÿ���/ֹͣУ��ˮӡ
 ���������ulChannel ͨ����:  
         ��iStart 0-��ʼУ�飬1-ֹͣУ��
 ���������NA
 �� �� ֵ���ɹ�:IVS_SUCCEED;ʧ��:IVS_FAIL;
 *****************************************************************************/
IVS_PLAYER_API IVS_INT32 __stdcall IVS_PLAY_SetWaterMarkVerify(IVS_ULONG ulChannel, IVS_INT32 iStart);

/*****************************************************************************
 �������ƣ�IVS_PLAY_GetMediaInfo()
 ������������ȡ��Ƶ��������
 ���������ulChannel ͨ����:  
 ���������pMediaInfo ��Ƶ��������
 �� �� ֵ���ɹ�:IVS_SUCCEED;ʧ��:IVS_FAIL;
 *****************************************************************************/
IVS_PLAYER_API IVS_INT32 __stdcall IVS_PLAY_GetMediaInfo(IVS_ULONG ulChannel,IVS_MEDIA_INFO* pMediaInfo);

/*****************************************************************************
 �������ƣ�IVS_PLAY_GetLostPacketRate()
 ������������ȡ��ǰ����ʱ��
 ���������ulChannel ͨ����
 ���������puPlayTime ��ǰ����ʱ��
 �� �� ֵ���ɹ�:IVS_SUCCEED;ʧ��:IVS_FAIL;
 *****************************************************************************/
IVS_PLAYER_API IVS_INT32 __stdcall IVS_PLAY_GetPlayedTime(IVS_ULONG ulChannel,IVS_UINT64 *puPlayTime);

/*****************************************************************************
 �������ƣ�IVS_PLAY_GetCurrentFrameTick
 ������������ȡ��ǰ֡ʱ���
 ���������ulChannel ͨ����
 ���������pTick ��ǰʱ���
 �� �� ֵ���ɹ�:IVS_SUCCEED;ʧ��:IVS_FAIL;
 *****************************************************************************/
IVS_PLAYER_API IVS_INT32 __stdcall IVS_PLAY_GetCurrentFrameTick(IVS_ULONG ulChannel, IVS_UINT64 *pTick);

IVS_PLAYER_API IVS_INT32 __stdcall IVS_PLAY_SetPlayTime(IVS_ULONG ulChannel, time_t tm);

IVS_PLAYER_API IVS_INT32 __stdcall IVS_PLAY_SetDownLoadTimeSpan(IVS_ULONG ulChannel, time_t tmBeg, time_t tmEnd, IVS_BOOL bReportFinsh);


/*****************************************************************************
 �������ƣ�IVS_PLAY_SetPlayQualityMode()
 ��������������ʵ������ģʽ������������
 ���������ulChannel ͨ����
		   iPlayMode ����ģʽ �ο���IVS_PLAY_MODE
 ���������NA
 �� �� ֵ���ɹ�:IVS_SUCCEED;ʧ��:IVS_FAIL;
 *****************************************************************************/
IVS_PLAYER_API IVS_INT32 __stdcall IVS_PLAY_SetPlayQualityMode(IVS_ULONG ulChannel,IVS_INT32 iPlayQualityMode);

/*****************************************************************************
 �������ƣ�IVS_PLAY_HasHwDecAbility()
 �����������Ƿ�֧��GPUӲ�����
 ���������NA
 ���������NA
 �� �� ֵ��֧��:TRUE;��֧��:FALSE;
 *****************************************************************************/
IVS_PLAYER_API VIDEO_DECODE_MODE __stdcall IVS_PLAY_GetDecodeAbility();

/*****************************************************************************
 �������ƣ�IVS_PLAY_HasHwDecAbility()
 ��������������Ӳ���־
 ���������bHardwareDec��Ӳ���־������:TRUE;�ر�:FALSE;
 ���������NA
 �� �� ֵ��NA
 *****************************************************************************/
IVS_PLAYER_API IVS_VOID __stdcall IVS_PLAY_SetHardwareDec(IVS_BOOL bHardwareDec);

/*****************************************************************************
 �������ƣ�IVS_PLAY_ShowPlayStatis()
 �������������Ž�����ʾͳ����Ϣ
 ���������NA
 ���������NA
 �� �� ֵ���ɹ�:IVS_SUCCEED;ʧ��:IVS_FAIL;
 *****************************************************************************/
IVS_PLAYER_API IVS_INT32 __stdcall IVS_PLAY_ShowPlayStatis(IVS_ULONG ulChannel, IVS_BOOL enable);

/*****************************************************************************
 �������ƣ�IVS_PLAY_ResetData
 �����������������;
 ���������ulChannel    ͨ����;
 ���������NA
 �� �� ֵ���ɹ�:IVS_SUCCEED;ʧ��:IVS_FAIL;
 *****************************************************************************/
IVS_PLAYER_API IVS_VOID __stdcall IVS_PLAY_ResetData(IVS_ULONG ulChannel);

IVS_PLAYER_API IVS_VOID __stdcall IVS_PLAY_SetResetFlag(IVS_ULONG ulChannel, bool bIsReset);
/*****************************************************************************
 �������ƣ�IVS_PLAY_StartRecord
 ������������ʼ¼��
 ���������NA
 ���������NA
 �� �� ֵ���ɹ�:IVS_SUCCEED;ʧ��:IVS_FAIL;
 *****************************************************************************/
IVS_PLAYER_API IVS_INT32 IVS_PLAY_StartRecord(IVS_ULONG ulChannel, const char *pCamCode, const char *pCamName, 
	      const char *pName, const IVS_LOCAL_RECORD_PARAM *pParameter, bool bAssociatedAudio);

/*****************************************************************************
�������ƣ�IVS_PLAY_StopRecord
����������ֹͣ¼��
���������NA
���������NA
�� �� ֵ���ɹ�:IVS_SUCCEED;ʧ��:IVS_FAIL;
*****************************************************************************/
IVS_PLAYER_API  IVS_INT32 IVS_PLAY_StopRecord(IVS_ULONG ulChannel);

/*****************************************************************************
�������ƣ�IVS_PLAY_GetRecordStatis
������������ȡ¼����Ϣ
���������NA
���������NA
�� �� ֵ���ɹ�:IVS_SUCCEED;ʧ��:IVS_FAIL;
*****************************************************************************/
IVS_PLAYER_API IVS_INT32 IVS_PLAY_GetRecordStatis(IVS_ULONG ulChannel, 
	        IVS_UINT32 *pTime, IVS_UINT32 *pSpeed, IVS_UINT64 *pTotalSz);

/*****************************************************************************
 �������ƣ�IVS_PLAY_LocalSnapshot
 ��������������ץ�ĵ���ͼƬ
 ���������pSavePath			ͼƬ����·����
		 ulSnapshotFormat	ͼƬ��������
 ���������NA
 �� �� ֵ���ɹ�:IVS_SUCCEED;ʧ��:IVS_FAIL;
 *****************************************************************************/
IVS_PLAYER_API  IVS_INT32 IVS_PLAY_LocalSnapshot(IVS_ULONG ulChannel, const char *pSavePath, IVS_ULONG ulSnapshotFormat);

/*****************************************************************************
 �������ƣ�IVS_PLAY_LocalSnapshotRect
 ��������������ץ�ĵ���ͼƬ
 ���������pSavePath			ͼƬ����·����
		 ulSnapshotFormat	ͼƬ��������
 ���������NA
 �� �� ֵ���ɹ�:IVS_SUCCEED;ʧ��:IVS_FAIL;
 *****************************************************************************/
IVS_PLAYER_API  IVS_INT32 IVS_PLAY_LocalSnapshotRect(IVS_ULONG ulChannel, const char *pSavePath, IVS_ULONG ulSnapshotFormat, const IVS_RECT *Rct);


/*****************************************************************************
�������ƣ�IVS_PLAY_StopDecryptData
����������ֹͣ��Ƶ����
���������ulChannel   ͨ����;
���������NA
�� �� ֵ���ɹ�:IVS_SUCCEED;ʧ��:IVS_FAIL;
*****************************************************************************/
IVS_PLAYER_API  IVS_INT32 IVS_PLAY_StopDecryptData(IVS_ULONG ulChannel);

/*****************************************************************************
�������ƣ�IVS_PLAY_SetSecretKey
����������������Ƶ������Կ��ͳһ���RTP�����ݽ��н��ܣ�
���������ulChannel   ͨ����;
		  ulDecType   ���ܷ���
					  0:����(��ͷ����)
					  1:����(��ͷ����)
					  2:AES256(ȫ����)
					  3:AES256(��������)
		  pSecretKey  ��Կ
���������NA
�� �� ֵ���ɹ�:IVS_SUCCEED;ʧ��:IVS_FAIL;
*****************************************************************************/
IVS_PLAYER_API  IVS_INT32 IVS_PLAY_SetSecretKey(IVS_ULONG ulChannel,IVS_INT32 iDecType,const IVS_CHAR* pSecretKey);

/*****************************************************************************
 �������ƣ�IVS_PLAY_SetDrawCallBack
 �������������û�ͼ�ص�
 ���������NA
 ���������NA
 �� �� ֵ���ɹ�:IVS_SUCCEED;ʧ��:IVS_FAIL;
 *****************************************************************************/
IVS_PLAYER_API IVS_INT32 __stdcall IVS_PLAY_SetDrawCallBack(IVS_ULONG ulChannel, 
	                     DRAW_CALLBACK callback, void *pUser);

IVS_PLAYER_API IVS_INT32 __stdcall IVS_PLAY_SetDrawCallBackEx(IVS_ULONG ulChannel,
	                     HWND hWnd, DRAW_CALLBACK callback, void *pUser);

/*****************************************************************************
 �������ƣ�IVS_PLAY_SetDelayFrameNum
 ����������������ʱ�����֡��
 ���������ulChannel      ͨ����;
           uDelayFrameNum ��ʱ�����֡��;
 ���������NA
 �� �� ֵ���ɹ�:IVS_SUCCEED;ʧ��:IVS_FAIL;
 *****************************************************************************/
IVS_PLAYER_API IVS_INT32 __stdcall IVS_PLAY_SetDelayFrameNum(IVS_ULONG ulChannel, 
	                                                IVS_UINT32 uDelayFrameNum);

/*****************************************************************************
 �������ƣ�IVS_PLAY_SetVoiceVolume
 �������������������Խ�������
 ���������ulVolumeValue      ����ֵ����Χ�� MIN_WAVE_COEF(0) �� MAX_WAVE_COEF(100)
 �����������
 �� �� ֵ�� ULONG
*****************************************************************************/
IVS_PLAYER_API IVS_INT32 __stdcall IVS_PLAY_SetVoiceVolume(IVS_ULONG ulVolumeValue);

/*****************************************************************************
 �������ƣ�IVS_PLAY_GetVoiceVolume
 ������������ȡ�����Խ�������
 �����������
 ���������pVolumeValue       ����ֵ����Χ�� MIN_WAVE_COEF(0) �� MAX_WAVE_COEF(100)
 �� �� ֵ�� ULONG
*****************************************************************************/
IVS_PLAYER_API IVS_INT32 __stdcall IVS_PLAY_GetVoiceVolume(IVS_UINT32* pVolumeValue);

/*****************************************************************************
 �������ƣ�IVS_PLAY_SetMicVolume
 ����������������˷������
 ���������ulVolumeValue       ����ֵ�� ��Χ�� MIN_WAVE_COEF(0) �� MAX_WAVE_COEF(100)
 �����������
 �� �� ֵ�� ULONG
*****************************************************************************/
IVS_PLAYER_API IVS_INT32 __stdcall IVS_PLAY_SetMicVolume(IVS_UINT32 ulVolumeValue);

/*****************************************************************************
 �������ƣ�IVS_PLAY_GetMicVolume
 ������������ȡ��˷������
 �����������
 ���������pVolumeValue    ����ֵ�� ��Χ�� MIN_WAVE_COEF(0) �� MAX_WAVE_COEF(100)
 �� �� ֵ�� ULONG
*****************************************************************************/
IVS_PLAYER_API IVS_INT32 __stdcall IVS_PLAY_GetMicVolume(IVS_UINT32* pVolumeValue);

/*****************************************************************************
 �������ƣ�IVS_PLAY_SetVoiceProtocolType
 ����������������������Э��
 ���������ulVoiceProtocolType             ��������Э��
 �����������
 �� �� ֵ�� ULONG
*****************************************************************************/
IVS_PLAYER_API IVS_INT32 __stdcall IVS_PLAY_SetVoiceProtocolType(IVS_UINT32 uVoiceProtocolType);

/*****************************************************************************
 �������ƣ�IVS_PLAY_GetRecvVoiceAddr
 ������������ȡ���������ĵ�ַ��IP�Ͷ˿ںţ�
 ���������ulPort          ͨ����
 ���������pRecvVoiceIp    ����������IP
		   pRecvVoicePort  ���������Ķ˿ں�
 �� �� ֵ�� ULONG
*****************************************************************************/
//IVS_PLAYER_API IVS_INT32 IVS_PLAY_GetRecvVoiceAddr(IVS_ULONG* pRecvVoicePort);

/*****************************************************************************
 �������ƣ�IVS_PLAY_FreeRecvVoiceAddr
 �����������ͷŽ��������ĵ�ַ
 ���������ulPort             ͨ����
 �����������
 �� �� ֵ�� ULONG
*****************************************************************************/
//IVS_PLAYER_API IVS_INT32 IVS_PLAY_FreeRecvVoiceAddr();

/*****************************************************************************
 �������ƣ�IVS_PLAY_SetVoiceDecoderType
 ��������������������������
 ���������ulVoiceDecoderType             ������������
 �����������
 �� �� ֵ�� ULONG
*****************************************************************************/
IVS_PLAYER_API IVS_INT32 __stdcall IVS_PLAY_SetVoiceDecoderType(IVS_ULONG ulVoiceDecoderType);

/*****************************************************************************
 �������ƣ�IVS_PLAY_StartVoiceTalkback
 ������������ʼ�����Խ�         
 ���������pLocalIp     ����������IP��ַ
		   ulLocalPort  ���������Ķ˿�
		   pRemoteIp    Զ��������IP��ַ
		   ulRemotePort Զ�������Ķ˿�
 �����������
 �� �� ֵ�� ULONG
*****************************************************************************/
IVS_PLAYER_API IVS_INT32 __stdcall IVS_PLAY_StartVoiceTalkback(IVS_CHAR* pLocalIp, IVS_ULONG ulLocalPort, 
                                                IVS_CHAR* pRemoteIp, IVS_ULONG ulRemotePort);

/*****************************************************************************
 �������ƣ�IVS_PLAY_StopVoiceTalkback
 ����������ֹͣ�����Խ�         
 �����������
 �����������
 �� �� ֵ�� ULONG
*****************************************************************************/
IVS_PLAYER_API IVS_INT32 __stdcall IVS_PLAY_StopVoiceTalkback();

/*****************************************************************************
 �������ƣ�IVS_PLAY_StartVoiceBroadcast()
 ������������ʼ�����㲥        
 ���������pLocalIp        ����������IP��ַ
           ulLocalPort     ���������Ķ˿�
           ulBroadcastType �����㲥����(0Ϊʵʱ�㲥��1Ϊ�ļ��㲥)
           pFileName       �����㲥�ļ���(����·��)
           bCycle          �Ƿ�ѭ������(0��ѭ������ 1ѭ������,ʵʱ�㲥��֧��ѭ��)
 �����������
 �� �� ֵ�� IVS_INT32
*****************************************************************************/
IVS_PLAYER_API IVS_INT32 __stdcall IVS_PLAY_StartVoiceBroadcast(
                                                    const IVS_CHAR* pLocalIp,
                                                    IVS_ULONG ulLocalPort, 
								                    const IVS_CHAR* pRemoteIp,
                                                    IVS_ULONG ulRemotePort,
                                                    IVS_ULONG ulBroadcastType,
                                                    const IVS_CHAR* pFileName,
                                                    bool bCycle);

/*****************************************************************************
 �������ƣ�IVS_PLAY_StopVoiceBroadcast()
 ����������ֹͣ�����㲥         
 ���������pRemoteIp    �����豸IP
           ulRemotePort �����豸�˿ں�
 �����������
 �� �� ֵ�� IVS_INT32
*****************************************************************************/
IVS_PLAYER_API IVS_INT32 __stdcall IVS_PLAY_StopVoiceBroadcast(
                                                    IVS_CHAR* pRemoteIp,
                                                    IVS_ULONG ulRemotePort);

/*****************************************************************************
 �������ƣ�IVS_PLAY_GetSourceBufferRemain()
 ������������ȡδ����֡������ʣ���֡��         
 �����������
 �����������
 �� �� ֵ��IVS_INT32
*****************************************************************************/
IVS_PLAYER_API IVS_INT32 __stdcall IVS_PLAY_GetSourceBufferRemain(
                                                    IVS_ULONG ulChannel,
                                                    IVS_UINT32 &uBufferCount);

/***************************************************************************
 �� �� �� : IVS_PLAY_SetEventCallBack
 �������� : �����¼��ص�����;
 ������� : cbEventCallBack         �¼��ص�����;
            pUser                   �û�����;
 ������� : NA
 �� �� ֵ : �ɹ�:IVS_SUCCEED;ʧ��:IVS_FAIL;
***************************************************************************/
IVS_PLAYER_API IVS_VOID __stdcall IVS_PLAY_SetEventCallBack(PLAYER_EVENT_CALLBACK cbEventCallBack, void* pUser);

/*****************************************************************************
 �������ƣ�IVS_PLAY_SetMediaBufferLimit
 ��������������ý�建�����������ްٷֱ�
 ���������uiLowerLimit ���ްٷֱ�
           uiUpperLimit ���ްٷֱ�
 �����������
 �� �� ֵ�� IVS_VOID
*****************************************************************************/
IVS_PLAYER_API IVS_VOID __stdcall IVS_PLAY_SetMediaBufferLimit(IVS_UINT32 uiLowerLimit, 
                                                               IVS_UINT32 uiUpperLimit);

/*****************************************************************************
 �������ƣ�IVS_PLAY_StopNotifyBuffEvent
 ����������ֹ֪ͣͨ�������¼�
 ���������NA
 �����������
 �� �� ֵ�� IVS_VOID
*****************************************************************************/
IVS_PLAYER_API IVS_VOID __stdcall IVS_PLAY_StopNotifyBuffEvent(IVS_ULONG ulChannel);


/*****************************************************************************
 �������ƣ�IVS_PLAY_SetMeidaAttribute
 ��������������ý����Ϣ
 ���������NA
 �����������
 �� �� ֵ�� IVS_VOID
*****************************************************************************/
IVS_PLAYER_API IVS_INT32 __stdcall IVS_PLAY_SetMediaAttribute(IVS_ULONG ulChannel,
	                                                          const MEDIA_ATTR *pVideoAttr, 
                                                              const MEDIA_ATTR *pAudioAttr);

/*****************************************************************************
 �������ƣ�IVS_PLAY_SetWaitForVertiBlank
 �������������ô�ֱͬ��ʹ��
 ���������NA
 �����������
 �� �� ֵ�� IVS_INT32
*****************************************************************************/
IVS_PLAYER_API  IVS_INT32 __stdcall IVS_PLAY_SetWaitForVertiBlank(IVS_ULONG ulChannel, int bEnable);

/*****************************************************************************
 �������ƣ�IVS_PLAY_ReSetFlowContrlFlag
 ����������������ر�־
 ���������NA
 �����������
 �� �� ֵ�� IVS_VOID
*****************************************************************************/
IVS_PLAYER_API  IVS_VOID __stdcall IVS_PLAY_ReSetFlowContrlFlag(IVS_ULONG ulChannel);
#endif //IVS_PLAYER_H
