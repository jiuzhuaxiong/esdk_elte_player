/********************************************************************
    filename	: 	IVSPlayerDataType.h
    author		:	z00201790
    created		:	2012/10/23
    description	:	�ṩIVS���ſ����ݽṹ�������롢�ص���
    copyright	:	Copyright (C) 2011-2015
    history		:	2012/10/23 ��ʼ�汾;
 *********************************************************************/
#ifndef IVS_PLAYER_DATA_TYPE_H
#define IVS_PLAYER_DATA_TYPE_H

#include <windows.h>
#include "hwsdk.h"
#include "ivs_error.h"

#pragma pack(push, 1)

#define IVS_TRUE 1

//ͼƬ��ʽ
#define PLAYER_PICTURE_FORMAT_JPEG 0         //JPEG��ʽ
#define PLAYER_PICTURE_FORMAT_BMP 1         //BMP��ʽ

//����ȡֵ��Χ
#define PLAYER_AUDIO_MIN_VOLUM 0                //��С����
#define PLAYER_AUDIO_MAX_VOLUM 100              //�������

//��־�ļ���С
#define MIN_LOG_FILE_SIZE 100             //��С100KB
#define MAX_LOG_FILE_SIZE 100000          //���100MB

//��־����
#define MIN_LOG_LEVEL 0
#define MAX_LOG_LEVEL 8
#define IVS_LOG_LEVEL_EMERGENCY 0    //ϵͳ������
#define IVS_LOG_LEVEL_ALERT 1    //�������̲�ȡ�ж�������ϵͳ������
#define IVS_LOG_LEVEL_CRITICAL 2    //���ش���
#define IVS_LOG_LEVEL_ERR 3    //һ�����
#define IVS_LOG_LEVEL_WARNING 4    //����
#define IVS_LOG_LEVEL_NOTICE 5    //��Ҫ��������Ϣ
#define IVS_LOG_LEVEL_INFO 6    //һ���������Ϣ
#define IVS_LOG_LEVEL_DEBUG 7    //������Ϣ

#define DISK_WARNING_SPACE_MB 500   //���̸澯�ռ�

#define MIN_INPUT_SOURCE_BUFFER_SIZE (50 * 1024)         //��С������������
#define MAX_INPUT_SOURCE_BUFFER_SIZE (10 * 1024 * 1024)  //��������������

//�ļ��㲥����
#define VOICE_FILE_BROADCAST 0          //�ļ������㲥
#define VOICE_REAL_BROADCAST 1          //ʵʱ�����㲥

//��������
#define VOICE_TALKBACK  0				//�����Խ�
#define VOICE_BROADCAST 1				//�����㲥
#define VOICE_NO_CIRCLE_BROADCAST 0     //��ѭ�������㲥
#define VOICE_IS_CIRCLE_BROADCAST 1		//ѭ�������㲥

// ������Ҫ�ĳ���
#define RTCP_PACKET_VERSION     2
#define RTCP_LEN_BASE           4
//#define RTCP_INVALID_PT         0xFF
#define SDES_ITEM_TYPE_SIZE     1
#define SDES_ITEM_LEN_SIZE      1
#define SDES_ITEM_END_SIZE      2

//RTCP_PACKET_TYPE
#define RTCP_PACKET_SR   200           // RTCP Sender report
#define RTCP_PACKET_RR   201           // RTCP Receiver report
#define RTCP_PACKET_SDES 202           // RTCP Source description packet
#define RTCP_PACKET_BYE  203           // RTCP Bye packet
#define RTCP_PACKET_APP  204           // RTCP App packet

#define PLAYER_AUDIO_SAMPLE_PER_SECOND 8000           //��Ƶ����Ƶ��

#define DECODER_FRAME_COUNT (100)
#define VIDEO_BUF_EX_COUNT  (20)

/*****************************ͨ��ģ��*********************************/

// ģ����;
typedef void * IVS_HANDLE;

//����ͨ��������0--127��;
#define PLAYER_TOTAL_CHANNEL_NUM 128         //����ͨ��������0--127��

// ������������,RTP����֡����;
typedef enum SourceType
{
    SOURCE_RTP,         // RTP����;
    SOURCE_FRAME,        // ֡����;
	SOURCE_FILE         // �ļ�����
} SOURCE_TYPE;

// ý������;
typedef enum tagStreamType
{
    STREAM_VIDEO = 0,       // ��Ƶ;
    STREAM_AUDIO            // ��Ƶ;
}STREAM_TYPE;

// ��Ƶ����ģʽ
typedef enum tagVideoDecodeMode
{
    DECODE_MODE_NONE = 0,
    DECODE_SW_HICILICON,    // ��˼���
    DECODE_HW_INTEL,        // Ӣ�ض�Ӳ��
    DECODE_SW_INTEL,        // Ӣ�ض����
    DECODE_HW_NVDIA,        // Ӣΰ��Ӳ��
    DECODE_SW_NVDIA,        // Ӣΰ�����
} VIDEO_DECODE_MODE;

// �ļ�����;
typedef enum tagFileType
{
    FILE_TYPE_MP4 = 0,           // Mp4�ļ�
    FILE_TYPE_AVI                // AVI�ļ�
} FILE_TYPE;

typedef enum
{
	H264_NALU_TYPE_UNDEFINED = 0,
	H264_NALU_TYPE_SLICE = 1,
	H264_NALU_TYPE_DPA   = 2,
	H264_NALU_TYPE_DPB   = 3,
	H264_NALU_TYPE_DPC   = 4,
    H264_IDR_NALU_TYPE   = 5,
    H264_SEI_NALU_TYPE   = 6,
    H264_SPS_NALU_TYPE   = 7,
    H264_PPS_NALU_TYPE   = 8,
    H264_NALU_TYPE_AUD   = 9,
    H264_NALU_TYPE_EOSEQ = 10,
    H264_NALU_TYPE_EOSTREAM = 11,
    H264_NALU_TYPE_FILL   = 12,

    H264_NALU_TYPE_STAP_A = 24,
    H264_NALU_TYPE_STAP_B = 25,
    H264_NALU_TYPE_MTAP16 = 26,
    H264_NALU_TYPE_MTAP24 = 27,
    H264_NALU_TYPE_FU_A = 28,
    H264_NALU_TYPE_FU_B = 29,
    H264_NALU_TYPE_END
} H264_NALU_TYPE; //lint !e751


/*
 * ý�����ԣ���SDP��Ϣ�н���
 */
typedef struct {
	unsigned int  type;
    unsigned char rtpmap;     // RTP PayLoad
	unsigned int  samplerate; // ������
} MEDIA_ATTR;


/*****************************************************************************
�������ƣ�PLAYER_EXCEPTION_CALLBACK()
�����������ص����������쳣��Ϣ
���������ulPort       ͨ����
ulMsgType    �쳣��Ϣ����
pHandle      �����쳣����Ӧ���͵ľ��
pUserData    �û�����
�����������
�� �� ֵ�� ULONG
*****************************************************************************/
typedef  IVS_VOID (CALLBACK * PLAYER_EXCEPTION_CALLBACK)(IVS_ULONG  ulChannel,     // ͨ����;
                                                         IVS_INT32  iMsgType,      // �쳣��Ϣ����;
                                                         IVS_VOID*  pParam,        // ��Ӧ�쳣����Ϣ������չΪ�ṹ��ָ��;
                                                         IVS_VOID*  pUser);        // �û�����;


/*****************************************************************************
�������ƣ�PLAYER_EVENT_CALLBACK()
�����������ص����������¼���Ϣ
���������ulChannel    ͨ����
          iMsgType     �¼���Ϣ����
          pParam       ��Ӧ�¼�����Ϣ������չΪ�ṹ��ָ��
          pUser        �û�����
�����������
�� �� ֵ�� ULONG
*****************************************************************************/
typedef  IVS_VOID (CALLBACK * PLAYER_EVENT_CALLBACK)(IVS_ULONG  ulChannel,
                                                     IVS_INT32  iMsgType,
                                                     IVS_VOID*  pParam,
                                                     IVS_VOID*  pUser);

/*****************************ƴ֡ģ�鿪ʼ*********************************/


// ��֡�ص��ṹ��
typedef struct
{
    int             StreamType;     //�������ͣ���Ƶ/��Ƶ���ο�STREAM_TYPE
    char*           Frame;          //������
    unsigned int    Size;           //���ݳ���
    int             FrameType;      //֡�������ͣ�SPS��PPS��IDR��P
    unsigned int    TimeStamp;      //ʱ���
    IVS_UINT64      TimeTick;       //����ʱ���
	unsigned long   WaterMarkValue; //ˮӡ���� ��0��ʾ��ˮӡ����
} RAW_FRAME_INFO;

// ������ܶ��󣬰��򵥼��ܣ�֡�򵥼��ܻ���֡���Ӽ���
typedef enum
{
	NO_DEC_TYPE = -1,
    IPC_ENCRYPT_SIMPLE = 0,
    IPC_ENCRYPT_SIMPLE_HEADER = 1,
    IPC_ENCRYPT_AES256 = 2,
    IPC_ENCRYPT_AES256_PARTIAL = 3
} DECRYP_TYPE;

typedef enum tagWaterMarkType
{
	WATER_MARK = 0,                 //ʹ������ˮӡ
	WATER_MARK_NULL = 1,            //��ʹ������ˮӡ
}WATER_MARK_TYPE_E;

typedef struct  
{
	unsigned short  uAllPacketNum;   //��Ӧ�յ���ȫ������
	unsigned short  uLostPacketNum;  //δ�յ��İ���
}REC_PACKET_INFO;



typedef struct
{
	unsigned int uVideoCodeRate;
	unsigned int uAvgVideoCodeRate;

	unsigned int uAudioCodeRate;
	unsigned int uAvgAudioCodeRate;

	unsigned int uFrameListSize;
	unsigned int uUsedMemBlockNum;

}CODE_RATE_INFO;

// ��֡�ص�
typedef IVS_VOID (CALLBACK * REASSM_CALLBACK)(IVS_RAW_FRAME_INFO* pstRawFrameInfo,
											  IVS_CHAR*           pFrame,
											  IVS_UINT32          uFrameSize,
                                              REC_PACKET_INFO*    pstRecPacketInfo,
                                              IVS_VOID*       pUser);

/*****************************ƴ֡ģ�����*****************************/

/*****************************����ģ��*********************************/
typedef struct tagVideoParam
{
    IVS_VIDEO_DEC_TYPE VideoFormat;      // ��Ƶ�����ʽ
    IVS_BOOL       HardwareDec;           // ����Ӳ���־
    //VIDEO_DECODE_MODE   VideoDecodeMode;  // ��Ƶ����ģʽ
} VIDEO_PARAM, *pVIDEO_PARAM;

typedef struct tagAudioParam
{
    IVS_AUDIO_DEC_TYPE AudioFormat; // ��Ƶ�����ʽ
    IVS_UINT32      SampleRate;  // ��Ƶ������
    IVS_UINT32      Channels;    // ��Ƶ������
    IVS_UINT32      BitRate;     // ��Ƶ������
} AUDIO_PARAM, *pAUDIO_PARAM;

typedef struct
{
    unsigned long ulExceptionCode;
    unsigned long long ullTimeStamp;
    unsigned long ulReseved1;
    unsigned long ulReseved2;
} WATER_MARK_EXCEPTION_DATA;

typedef struct  
{
    int iExceptionCode;
    unsigned long ulReseved1;
    unsigned long ulReseved2;
    unsigned long ulReseved3;
}VOICE_EXCEPTION_DATA;

typedef IVS_VOID (CALLBACK * DECODER_CALLBACK)(IVS_INT32   iStreamType,
                                               IVS_VOID*   pFrameInfo,
                                               IVS_VOID*   pUser);

/*****************************��Ⱦģ��*********************************/

//typedef int RENDER_SPEED;

//��ʾ����
#define DISPLAY_ASPECT_RATIO_FULLSCREEN 0  //����
#define DISPLAY_ASPECT_RATIO_ORIGINAL 1  //ԭʼ����
#define DISPLAY_ASPECT_RATIO_NONSPECIFIC 2  //δָ����ʹ�õ�ǰֵ

/*
 * ��Ƶ��Ⱦ������
 */
typedef enum
{
    VOUT_GDIDRAW = 1,
    VOUT_DDRAW   = 2,
    VOUT_D3DDRAW = 3,
} VOUT_DRAW_TYPE;

/* ���������� */
typedef enum
{
    RENDER_MODE_REALTIME = 0, // ʵʱģʽ
    RENDER_MODE_SMOOTH  = 1,  // ����ģʽ
    RENDER_MODE_REVERSE = 2, // ����ģʽ
} RENDER_MODE;


typedef enum {
	STREAM_REALTIME     = 0, // ʵʱ��Ƶ
	STREAM_LOCALFILE    = 1, // �����ļ�
	STREAM_REMOTEFILE   = 2  // ƽ̨�ļ� 
} STREAM_MODE;


// ������Ϣ
typedef struct
{
    unsigned int       Frames; // �Ѿ�����֡��
	unsigned long long PalyTime; //����
    float              FrameRate;
    unsigned int  Width;
    unsigned int  Height;
	long          VideoStatus;
	long          AudioStatus;
	unsigned long Reserved1;
	unsigned long Reserved2;
} MEDIA_INFO;

// ����ҵ�񲼾����ͣ�����ǽģ�⣩
typedef enum
{
    DRAW_NORMAL  = 1,
    DRAW_SPLIT   = 2,
    DRAW_JOINT   = 3,
    DRAW_ZOOMIN  = 4,
	DRAW_PARTIAL = 5,
} LAYOUT_TYPE;

// ������ʾ, ��һ·��Ƶ�ָ�ɶ��������Ⱦ
typedef struct
{
    unsigned int row;  // ���ڲ��� row * col
    unsigned int col;
    unsigned int x;    // ��������ʾ����Ƶ����(x,y)
    unsigned int y;
} LAYOUT_DRAW_SPLIT;

// �����ʾ������·��Ƶ�����ͬһ����������Ⱦ
typedef struct
{
    unsigned int row;  // ���Ų��� row * col
    unsigned int col;
    unsigned int x;    // ��·��Ƶ����λ��(x, y)
    unsigned int y;
} LAYOUT_DARW_JOINT;

// ������ʾ
typedef struct
{} LAYOUT_DRAW_NORMAL;

// �ֲ��Ŵ󲥷�ҵ��
// ������������ʾ�������������Ļ��ʾ�ľֲ��Ŵ�
typedef struct
{
    RECT Base;  // ��Ƶ��ռ���д��ھ���
    RECT Zoom;  // ����ѡ�ķŴ�������
} LAYOUT_DRAW_ZOOMIN;

// ��ʾ�ֲ�ͼƬ 
// ����Ϊ�ٷֱ�
typedef struct 
{ 
	unsigned int left;   
	unsigned int top;
	unsigned int right;
	unsigned int bottom;
}LAYOUT_DRAW_PARTIAL;


// ��Ⱦͳ�Ʋ���������DEBUG
typedef struct 
{
	unsigned long InFrames;
	unsigned long DropFrames;
	unsigned long InFrameRate;
	unsigned long OutFrames;
	unsigned long SkipFrames;
	double        OutFrameRate;
	unsigned int  Width;
	unsigned int  Height;
    unsigned long VListSz;
	unsigned long AListSz;
	unsigned int  uLastRtpStamp;
	unsigned long long PlayedTime;
	unsigned long long FrameTick;
} RENDER_STATIS;

/* ���Żص� */
typedef IVS_VOID (CALLBACK * DISPLAY_CALLBACK)(IVS_UINT32 nType, IVS_UCHAR *pBuf,
                                               IVS_UINT32 nWidth, IVS_UINT32 nHeight,
                                               IVS_UINT32 nTimeStamp, IVS_VOID *pUser);

/* ��ͼ�ص� */
typedef IVS_VOID (CALLBACK * DRAW_CALLBACK)(HDC hDc, RECT *rc, IVS_UINT64 FrameID, IVS_VOID *pUser);

/* ���Ž����ص� */
typedef IVS_VOID (CALLBACK * PLAYEND_CALLBACK)(IVS_VOID *pUser);


/*****************************����¼��ģ��*********************************/

typedef struct 
{
	time_t tmDownLoadBeg;
	time_t tmDwonLoadEnd;
	int    bReportFinish;
} DOWNLOAD_PARAM;


typedef struct {
	unsigned int FileSize;
	unsigned int TimeSpan;
	unsigned int DiskWarnMB;
	unsigned int DiskFullMB;
	char         Directory[MAX_PATH]; 
} RECORD_CONFIG;

#pragma pack(pop)

#endif //IVS_PLAYER_DATA_TYPE_H

