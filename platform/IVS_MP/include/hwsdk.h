#ifndef _HW_IVS_SDK_H_
#define _HW_IVS_SDK_H_

#pragma pack(push, 1)

// ���Ͷ���
typedef  int                IVS_INT32;
typedef  unsigned int       IVS_UINT32; 
typedef  void*				IVS_LPVOID;
typedef  long               IVS_LONG;
typedef  unsigned long      IVS_ULONG;

#ifdef _MSC_VER
typedef __int64             IVS_INT64;
typedef unsigned __int64    IVS_UINT64;
#else
typedef long long           IVS_INT64;
typedef unsigned long long  IVS_UINT64;
#endif 

typedef  int	            IVS_BOOL;
typedef  char               IVS_CHAR;
typedef  unsigned char      IVS_UCHAR;
typedef  float              IVS_FLOAT;
typedef  double             IVS_DOUBLE;

typedef  void               IVS_VOID;

typedef  short              IVS_SHORT;
typedef  unsigned short     IVS_USHORT;

#ifdef WIN32
#define __SDK_CALL __stdcall
#else
#define __SDK_CALL
#endif

#ifdef WIN32
#define __SDK_CALLBACK CALLBACK
#else
#define __SDK_CALLBACK
#endif

#ifndef WIN32

#ifndef TRUE
#define TRUE 1
#endif
#ifndef FALSE
#define FALSE 0
#endif

#ifndef BYTE
#define BYTE unsigned char
#endif

#define HWND void*

#endif

//����NULL
#ifndef NULL
#ifdef __cplusplus
#define NULL    0
#else
#define NULL    ((void *)0)
#endif
#endif



// ��Ϣ����(��Ϣ�ϱ�)
#define IVS_EVENT_AUTO_CONNECT_SUCCEED                  10001   // ���µ�¼�ɹ��¼��ϱ�
#define IVS_EVENT_KEEP_ALIVE_FAILED                     10002   // ����ʧ���¼��ϱ�
#define IVS_EVENT_REALPLAY_FAILED                       10003   // ʵʱ����쳣�¼��ϱ�
#define IVS_EVENT_RECORD_FAILED                         10004   // ¼���쳣�¼��ϱ�
#define IVS_EVENT_DOWNLOAD_FAILED                       10005   // ¼�������쳣�¼��ϱ�
#define IVS_EVENT_REMOTE_PLAYBACK_FAILED                10006   // Զ��¼��ط��쳣�¼��ϱ�
#define IVS_EVENT_LOCAL_PLAYBACK_FAILED                 10007   // ����¼��ط��쳣�¼��ϱ�
#define IVS_EVENT_TALKBACK_FAILED                       10008   // �����Խ��쳣�¼��ϱ�
#define IVS_EVENT_BROADCAST_FAILED		                10009   // �����㲥�쳣�¼��ϱ�
//#define IVS_EVENT_START_MULT_SNAPSHOT                   10010   // ��ʼ����ץ��
//#define IVS_EVENT_STOP_MULT_SNAPSHOT                    10011   // ����ץ���쳣ֹͣ
//#define IVS_EVENT_FINISHED_MULT_SNAPSHOT                10012   // ����ץ�����
#define IVS_EVENT_REPORT_ALARM                          10013   // �澯�ϱ�
#define IVS_EVENT_FILE_BROADCAST_END                    10014   // �����ļ��㲥�����¼��ϱ�

//#define IVS_EVENT_REMOTE_RECORD_STOP                    10015   // Զ��¼��ֹͣ
//#define IVS_EVENT_REPORT_DEVICE                         10016   // �豸״̬�ϱ�
#define IVS_EVENT_REPORT_ALARM_STATUS                   10017   // �澯״̬�ϱ�

#define IVS_EVENT_USER_OFFLINE                          10019   // �û�����֪ͨ
#define IVS_EVENT_RESUME_REALPLAY                       10020   // ����ʵ������
#define IVS_EVENT_RESUME_REALPLAY_OK                    10021   // �ָ�ʵ�����

#define IVS_EVENT_LOCAL_RECORD_SUCCESS                  10022   // ����¼��ɹ��¼�
#define IVS_EVENT_LOCAL_RECORD_EGENERIC                 10023   // ¼���ļ�д��ʧ���¼�
#define IVS_EVENT_DO_LINKAGE_ACTION                     10024   // �澯��������ִ��֪ͨ

#define IVS_EVENT_FIND_DEVICE                           10025   // ����ǰ���豸�¼�
#define IVS_EVENT_OMU_REPORT_ALARM                      10026   // OMU���豸��澯����CU�Ľӿ���Ϣ
#define IVS_EVENT_REPORT_WATERMARK_TIP                  10027   // ����ˮӡ�۸���ʾ��ֻ�д۸Ŀ�ʼʱ�䣩
#define IVS_EVENT_REPORT_WATERMARK_ALARM                10028   // ˮӡ�澯��¼����֪ͨ���д۸Ŀ�ʼʱ���ֹͣʱ�䣩

#define IVS_EVENT_PTZ_LOCK                              10029   // �ƾ������ϱ����ƾ������������ʱ��֪�ͻ��ˣ�

//#define IVS_EVENT_OTHER                               10030   // ����ģʽ
#define IVS_EVENT_MANUAL_RECORD_STATE                   10031   // �ֶ�¼��״̬֪ͨ
#define IVS_EVENT_STOP_LINKAGE_ACTION                   10032   // �澯��������ֹ֪ͣͨ
#define IVS_EVENT_DOWNLOAD_SUCCESS                      10033   // ¼����������¼��ϱ�
//#define IVS_EVENT_PWD_EXPIRE_DAYS                       10034   // �û������������
#define IVS_EVENT_PLAYER_BUFFER                         10035   // �ͻ��˻���֪ͨ
#define IVS_EVENT_PLAY_SOUND_FAILED                     10036   // ��·��������ʧ�ܣ����������Խ����ɿ�����·������

#define IVS_EVENT_PLAYER_WATER_MARK_EXCEPTION           10037   // ˮӡ�쳣�¼��ϱ�

#define IVS_EVENT_IA_BA_LEARNING_SCHEDULE_REPORT        10100   // ���ܷ���ѧϰ�����ϱ�
#define IVS_EVENT_IA_FR_SCHEDULE_REPORT                 10101   // ���ܷ�����������ע������ϱ�
#define IVS_EVENT_IA_PUSH_ALARM_LOCUS                   10102   // ���ܷ����켣����
#define IVS_EVENT_IA_DRAW_OVER                          10103   // ���ܷ�����ͼ����
#define IVS_EVENT_IA_ADDPLAN_SCHEDULE_REPORT            10104   // ���ܷ�����Ӽƻ������ϱ� 

#define IVS_EVENT_MODE_CRUISE_RECORD_OVER               10203   // ģʽ�켣¼�ƽ���֪ͨ

#define IVS_EVENT_LOGIN_FAILED                          10301   // �ͻ��˵�¼ʧ�ܣ����磬����ʱ����ı䣩

// ͨ�ó�������
#define IVS_TIME_LEN			20          // ʱ�䳤��
#define IVS_NAME_LEN			128			// ���Ƴ���
#define IVS_TICKET_LEN			64			// �����¼��Ticket����
#define IVS_PWD_LEN		        64			// ���볤��(���紫��ʹ������)
#define IVS_GROUP_CODE_LEN		64			// ���ų���
#define IVS_DESCRIBE_LEN		256			// ��������
#define IVS_IP_LEN				64			// IP����
#define IVS_URL_LEN				256			// URL����
#define IVS_FILE_NAME_LEN		256			// �ļ�����󳤶�
#define IVS_MAX_NAME_LIST_LEN   1024        // �����б���󳤶ȣ��ö��Ÿ���

// �û�
#define IVS_MACHINE_NAME_LEN	128			// PC����������
#define IVS_DOMAIN_LEN			64			// Windows��������
#define IVS_PHONE_NUMBER_LEN	64			// �绰������󳤶�
#define IVS_MAX_OPERATION_RIGHT	128			// ����Ȩ�޸�������
#define	IVS_EMAILE_LEN			128			// �û�Email����

// �豸��Ϣ
#define IVS_DEV_SERIALNO_LEN	64		    // �豸���кų���
#define IVS_DEV_CODE_LEN        64		    // �豸������󳤶�
#define IVS_DEVICE_GROUP_LEN    128         // �豸�������󳤶�
#define IVS_TAS_CODE_LEN        32          // TAS���볤��
#define IVS_NVR_CODE_LEN        32          // NVR���볤��
#define IVS_DOMAIN_CODE_LEN     32		    // �������󳤶�
#define IVS_DEV_MODEL_LEN	    32		    // �豸�ͺ���󳤶�

#define IVS_MRU_CODE_LEN        64          //MRU���䷽ʽ

#define IVS_MAX_STREAM_LIST_NUM      3           //������Ϣ�б����3��
#define IVS_MAX_ENCODE_LIST_NUM      2           //����������Ϣ�б����2��
#define IVS_MAX_RESOLUTION_LIST_NUM  30          //�ֱ����б����30��

// ��ݼ�
#define IVS_HOTKEY_CTRL         0x01
#define IVS_HOTKEY_SHIFT        0x02
#define IVS_HOTKEY_ALT          0x04
#define IVS_HOTKEY_WIN          0x08

#define IVS_VERSION_LEN  32      // �ͻ��˰汾�ų���
#define IVS_MD5_LEN      32      // MD5ֵ����
#define IVS_TOKEN_LEN      128      // MD5ֵ����



/*���쳣�ṹ��*/
typedef struct ST_STREAM_EXCEPTION_INFO
{
    IVS_INT32 iSessionID;       //��¼���صĻỰID
    IVS_ULONG ulHandle;         //���
    IVS_INT32 iExceptionCode;   //������
    IVS_INT32 iReseved1;        //����
    IVS_CHAR szDeviceCode[IVS_DEV_CODE_LEN];

}STREAM_EXCEPTION_INFO;

typedef enum 
{
    CU_LEFTTOP = 0, //CU���Ͻ�
    CU_LOGINABOUT,  //CU��¼/����
    MOBILE_PAD,     //�ƶ�PAD
    MOBILE_PHONE,   //�ƶ�Phone
    BS_LEFTTOP,     //BS���Ͻ�
    BS_LOGINABOUT   //BS��¼/����
}IVS_LOGO_TYPE;

typedef enum
{
    KEY_WEAK=0,
    KEY_MIDDLE,
    KEY_STRONG,
    KEY_STRONGER
}IVS_KEY_RELIABILITY;

// �˺�ǩ������
typedef enum
{
    USER_OFFLINE_LOCK=0,    // �˺ű�����Ա����
    USER_OFFLINE_DELETE=1,  // �˺ű�����Աɾ��
    USER_OFFLINE_SIGNOUT=2, // ��¼�Ự������Աǩ��
}IVS_USER_OFFLINE_TYPE;

// ʱ��Ƭ�νṹ
typedef struct
{
    IVS_CHAR	cStart[IVS_TIME_LEN];   // ��ʽ��yyyyMMddHHmmss
    IVS_CHAR	cEnd[IVS_TIME_LEN];     // ��ʽ��yyyyMMddHHmmss
}IVS_TIME_SPAN;

// ����¼���ļ��ϱ�֪ͨ
typedef struct
{
    IVS_CHAR    cCameraCode[IVS_DEV_CODE_LEN];      // ���������
    IVS_CHAR    cFileName[IVS_FILE_NAME_LEN];       // �ļ���
    IVS_CHAR    cFilePath[IVS_FILE_NAME_LEN];       // �ļ����·��
    IVS_CHAR    cOperationTime[IVS_TIME_LEN];       // ����ʱ��
    IVS_TIME_SPAN   stRecordTime;                   // ¼����ʼ������ʱ��
    IVS_UINT32  uiRecordType;                       // ¼�����ͣ�0-����¼��1-ƽ̨¼������
    IVS_BOOL    bIsEncrypt;                         // ¼���Ƿ���ܣ�0-�����ܣ�1-����    
}IVS_LOCAL_RECORD_SUCCESS_INFO;

// �û�����֪ͨ
typedef struct
{
    IVS_INT32   iSessionID;     // �����û���SessionID
    IVS_UINT32  uiOfflineType;  // �������ͣ�ֵ�ο� IVS_USER_OFFLINE_TYPE
}IVS_USER_OFFLINE_INFO;

// ����¼���ļ��ϱ�֪ͨ
typedef struct
{
    IVS_LONG    lErrorCode;     // ������
    IVS_ULONG   ulHandle;       // ���ž��
    IVS_CHAR    cReserve[32];   // �����ֶ�
}IVS_LOCAL_RECORD_EGENERIC;

// �������ݽṹ
typedef struct
{
	IVS_FLOAT	left;
	IVS_FLOAT	top;
	IVS_FLOAT	right;
	IVS_FLOAT	bottom;
}IVS_RECT_FLOAT;

typedef struct
{
	IVS_LONG	left;
	IVS_LONG	top;
	IVS_LONG	right;
	IVS_LONG	bottom;
}IVS_RECT;

typedef enum
{
	WIND_LAYOUT_1_1 = 11,   // ������1,����1
	WIND_LAYOUT_3_1 = 31,   // ������3,����1
	WIND_LAYOUT_3_2 = 32,   // ������3,����2
	WIND_LAYOUT_3_3 = 33,   // ������3,����3
	WIND_LAYOUT_4_1 = 41,   // ������4,����1
	WIND_LAYOUT_4_2 = 42,   // ������4,����2
	WIND_LAYOUT_4_3 = 43,   // ������4,����3
	WIND_LAYOUT_6_1 = 61,   // ������6,����1
	WIND_LAYOUT_6_2 = 62,   // ������6,����2
	WIND_LAYOUT_6_3 = 63,   // ������6,����3
    WIND_LAYOUT_6_4 = 64,   // ������6,����4
	WIND_LAYOUT_8_1 = 81,   // ������8,����1
	WIND_LAYOUT_9_1 = 91,   // ������9,����1
    WIND_LAYOUT_9_2 = 92,   // ������9,����2
	WIND_LAYOUT_10_1 = 101, // ������10,����1
	WIND_LAYOUT_10_2 = 102, // ������10,����2
	WIND_LAYOUT_12_1 = 121, // ������12,����1
	WIND_LAYOUT_12_2 = 122, // ������12,����2
	WIND_LAYOUT_13_1 = 131, // ������13,����1
	WIND_LAYOUT_13_2 = 132, // ������13,����2
	WIND_LAYOUT_16_1 = 161, // ������16,����1
	WIND_LAYOUT_16_2 = 162, // ������16,����2
	WIND_LAYOUT_17_1 = 171, // ������17,����1
	WIND_LAYOUT_20_1 = 201, // ������20,����1
	WIND_LAYOUT_25_1 = 251, // ������25,����1
	WIND_LAYOUT_26_1 = 261, // ������26,����1
	WIND_LAYOUT_36_1 = 361, // ������36,����1
	WIND_LAYOUT_49_1 = 491, // ������49,����1
	WIND_LAYOUT_64_1 = 641, // ������64,����1

	WIND_LAYOUT_CUSTOM_1 = 651, //�Զ��岼��1
	WIND_LAYOUT_CUSTOM_2 = 652, //�Զ��岼��2
	WIND_LAYOUT_CUSTOM_3 = 653, //�Զ��岼��3
	WIND_LAYOUT_CUSTOM_4 = 654, //�Զ��岼��4

    WIND_LAYOUT_TVW = 200,      // ����ǽ
}IVS_WIND_LAYOUT;

// OCX��������ť
const IVS_UINT32 IVS_TOOLBAR_SNAPSHOT       = 0x00000001;   // ץ��
const IVS_UINT32 IVS_TOOLBAR_LOCAL_RECORD   = 0x00000002;   // ����¼��
const IVS_UINT32 IVS_TOOLBAR_BOOKMARK       = 0x00000004;   // ��ǩ
const IVS_UINT32 IVS_TOOLBAR_ZOOM           = 0x00000008;   // �ֲ��Ŵ�
const IVS_UINT32 IVS_TOOLBAR_PLAY_RECORD    = 0x00000010;   // ��ʱ�ط�
const IVS_UINT32 IVS_TOOLBAR_PLAY_SOUND     = 0x00000020;   // ����
const IVS_UINT32 IVS_TOOLBAR_TALKBACK       = 0x00000040;   // �Խ�
const IVS_UINT32 IVS_TOOLBAR_VIDEO_TVW      = 0x00000080;   // ��Ƶ��ǽ
const IVS_UINT32 IVS_TOOLBAR_ALARM_WIN      = 0x00000100;   // ���ø澯����
const IVS_UINT32 IVS_TOOLBAR_PTZ            = 0x00000200;   // �ƾ�����
const IVS_UINT32 IVS_TOOLBAR_IA             = 0x00000400;   // �������ܷ���
const IVS_UINT32 IVS_TOOLBAR_OPEN_MAP       = 0x00000800;   // �򿪵��ӵ�ͼ
const IVS_UINT32 IVS_TOOLBAR_WINDOW_MAIN    = 0x00001000;   // һ���ศ
const IVS_UINT32 IVS_TOOLBAR_PLAY_QUALITY   = 0x00002000;   // ��������/��������
const IVS_UINT32 IVS_TOOLBAR_PTZ3D          = 0x00004000;   // 3D��λ
const IVS_UINT32 IVS_TOOLBAR_EXIT_PLAY_RECORD= 0x00008000;   // �˳���ʱ�طţ�������������

// OCX���ܷ���������
const IVS_UINT32 IVS_IA_TOOLBAR_DRAW_RECT       = 0x00000001;   // ����
const IVS_UINT32 IVS_IA_TOOLBAR_DRAW_POLYGON    = 0x00000002;   // �����
const IVS_UINT32 IVS_IA_TOOLBAR_ZOOM_IN         = 0x00000004;   // �Ŵ�
const IVS_UINT32 IVS_IA_TOOLBAR_ZOOM_OUT        = 0x00000008;   // ��С
const IVS_UINT32 IVS_IA_TOOLBAR_DRAW_MOVE       = 0x00000010;   // �ƶ�
const IVS_UINT32 IVS_IA_TOOLBAR_DISPLAY_MODE    = 0x00000020;   // ��Ļ��Ƶ��ʾ��ʽ
const IVS_UINT32 IVS_IA_TOOLBAR_PLAY            = 0x00000040;   // ������Ƶ
const IVS_UINT32 IVS_IA_TOOLBAR_DELETE          = 0x00000080;   // ɾ��

// ¼��״̬
const IVS_UINT32 IVS_RECORD_STATE_MANUAL        = 0x00000001;   // �ֶ�¼��
const IVS_UINT32 IVS_RECORD_STATE_ALARM         = 0x00000002;   // �澯¼��
const IVS_UINT32 IVS_RECORD_STATE_PLAN          = 0x00000004;   // �ƻ�¼��

// ��Ƶ��Ѳ���ڰ�ť״̬
const IVS_UINT32 IVS_CAMERA_SWITCH_BUTTON_NULL  = 0x00000000;   // ����Ѳ�����л���ť
const IVS_UINT32 IVS_CAMERA_SWITCH_BUTTON_LEFT  = 0x00000001;   // ��Ѳ�����л���ť
const IVS_UINT32 IVS_CAMERA_SWITCH_BUTTON_RIGHT = 0x00000002;   // ��Ѳ�����л��Ұ�ť

// �ƾ�������
typedef enum
{
    // ��̨ת�����ƣ�����ֹͣ���ϡ��¡����ҵ�
    PTZ_STOP = 1,
    PTZ_UP,
    PTZ_DOWN,
    PTZ_LEFT,
    PTZ_UP_LEFT,
    PTZ_DOWN_LEFT,
    PTZ_RIGHT,
    PTZ_UP_RIGHT,
    PTZ_DOWN_RIGHT,
    PTZ_AUTO,
    PTZ_PREFAB_BIT_RUN,
    PTZ_CRUISE_RUN,
    PTZ_CRUISE_STOP,
    PTZ_MODE_CRUISE_RUN,
    PTZ_MODE_CRUISE_STOP,
    PTZ_MENU_OPEN,
    PTZ_MENU_EXIT,
    PTZ_MENU_ENTER,
    PTZ_FLIP,
    PTZ_START,
    // ��ͷ���ƣ�������Ȧ�����š��۽�
    PTZ_LENS_APERTURE_OPEN,
    PTZ_LENS_APERTURE_CLOSE,
    PTZ_LENS_ZOOM_IN,
    PTZ_LENS_ZOOM_OUT,
    PTZ_LENS_FOCAL_NEAT,
    PTZ_LENS_FOCAL_FAR,
    PTZ_AUX_OPEN,
    PTZ_AUX_STOP,
    // ģʽ
    MODE_SET_START,
    MODE_SET_STOP,
    // ��ǿ����
    PTZ_FAST_LOCATE,
    PTZ_HORIZONTAL_SCAN,
    PTZ_VERTICAL_SCAN,
    PTZ_LOCK,
	PTZ_UNLOCK,
	PTZ_ABSOLUTE_MOVE,
	PTZ_DIRECTION_MOVE
	//end
}IVS_PTZ_CODE;

//�������̨λ����Ϣ
typedef struct{
	IVS_DOUBLE dX;		//�������̨ˮƽλ��
	IVS_DOUBLE dY;		//�������̨��ֱλ��
	IVS_DOUBLE dZ;		//������䱶����
}IVS_PTZ_POSITION_INFO;

//�������̨λ�÷�Χ���˶����ʷ�Χ��Ϣ
typedef struct{
	IVS_DOUBLE dXMax;		//�������̨ˮƽλ�����ֵ
	IVS_DOUBLE dXMin;		//�������̨ˮƽλ����Сֵ
	IVS_DOUBLE dYMax;		//�������̨��ֱλ�����ֵ
	IVS_DOUBLE dYMin;		//�������̨��ֱλ����Сֵ
	IVS_DOUBLE dZMax;		//������䱶�������ֵ
	IVS_DOUBLE dZMin;		//������䱶������Сֵ
	IVS_DOUBLE dVXMax;		//�������̨ˮƽ�ٶ����ֵ
	IVS_DOUBLE dVXMin;		//�������̨ˮƽ�ٶ���Сֵ
	IVS_DOUBLE dVYMax;		//�������̨��ֱ�ٶ����ֵ
	IVS_DOUBLE dVYMin;		//�������̨��ֱ�ٶ���Сֵ
	IVS_DOUBLE dVZMax;		//������䱶�ٶ����ֵ
	IVS_DOUBLE dVZMin;		//������䱶�ٶ���Сֵ
}IVS_PTZ_RANGE_INFO;

//�������̨����λ����Ϣ
typedef struct{
	IVS_CHAR cCameraCode[IVS_DEV_CODE_LEN];		//���������
	IVS_PTZ_POSITION_INFO stPTZPosition;		//�������̨λ����Ϣ
	IVS_PTZ_RANGE_INFO stPTZRange;				//�������̨λ�÷�Χ���˶����ʷ�Χ��Ϣ
}IVS_PTZ_ABSPOSITION;
//end

// OCX���ڹ�����ͼ��״̬
// Ѳ�����澯���ֶ�¼�񡢵�֡
typedef enum
{
    OCX_TITLEBAR_CRUISE = 0,  // Ѳ��
    OCX_TITLEBAR_WARNING= 1,  // �澯
    OCX_TITLEBAR_RECORD = 2,  // �ֶ�¼��
    OCX_TITLEBAR_FRAME  = 3,  // ��֡
}IVS_TITLEBAR_ICON;

// OCX���ڹ�������ť״̬
typedef enum
{
    OCX_TOOLBAR_STATUS_DISABLE= 0,  // �û�
    OCX_TOOLBAR_STATUS_NORMAL,      // ����
}IVS_TOOLBAR_STATUS;

// ��ҳ��Ϣ
typedef struct
{
	IVS_UINT32 uiFromIndex; // ��ʼ����
	IVS_UINT32 uiToIndex;   // ��������
}IVS_INDEX_RANGE;

// IP����
typedef enum
{
    IP_V4= 0,
    IP_V6= 1
}IVS_IP_TYPE;

// IP��Ϣ
typedef struct
{
	IVS_UINT32	uiIPType;				// IP���ͣ��ο� IVS_IP_TYPE
	IVS_CHAR	cIP[IVS_IP_LEN];		// IP��ַ
}IVS_IP;

typedef struct  
{
    IVS_UINT32	uiCUType;// �ͻ������ͣ�5-PC�ͻ��� 6-iPad 7-AndroidPhone 8-AndroidPad 9-iPhone
    IVS_CHAR	   cCUVersion[IVS_VERSION_LEN];// �ͻ��˰汾��
    IVS_CHAR     cReserve[64];// �����ֶ�
}IVS_CU_INFO;

// �ͻ�������
typedef enum
{
	CLIENT_PC       =0, // PC�ͻ���
	CLIENT_WEB      =1, // web�����
	CLIENT_MOBILE   =2, // �ƶ��ͻ���
	CLIENT_PC_CHILD =3, // PC�ͻ����ӽ���
    CLIENT_TV_WALL  =4 // ����ǽ����
}IVS_CLIENT_TYPE;

//������Ϣ
typedef struct
{
    IVS_BOOL	bIsUpgrade;//�Ƿ���Ҫ������0-��1-��
    IVS_CHAR	cSetupFileMd5[IVS_MD5_LEN];// ��װѹ����MD5ֵ,ios�ͻ���ʱΪ��
    IVS_UINT64      uiFileSize;     // ��װѹ������С���ֽ�����ios�ͻ���ʱΪ��
    // IVS_CHAR        cIosSetupUrl[IVS_URL_LEN];// ios�ͻ�������URL
    IVS_CHAR        cHttpURL[IVS_URL_LEN];//�ϴ������ļ���URL��Ϣ
    // IVS_CHAR        cToken[IVS_TOKEN_LEN];//�û�ƾ֤
    IVS_CHAR        cReserve[64];// �����ֶ�
}IVS_UPGRADE_INFO;

// ��½����
typedef enum
{
	LOGIN_BASIC= 0,			// ���������֤
	LOGIN_WINDOWS_CURRENT,  // Windows�������֤����ǰ�û�
	LOGIN_WINDOWS_OTHER     // Windows�������֤�������û�
}IVS_LOGIN_TYPE;

// �û���¼��Ϣ
typedef struct
{
	IVS_CHAR cUserName[IVS_NAME_LEN];		        // �û���
	IVS_CHAR pPWD[IVS_PWD_LEN];                     // �������ģ���¼����Ϊ0�������˺ţ�ʱ������Ϊ��

	IVS_IP	stIP;			                        // ��¼������IP
	IVS_UINT32 uiPort;		                        // ��¼�������˿�

	IVS_UINT32 uiLoginType;							// ��¼���ͣ��ο� IVS_LOGIN_TYPE 0�C���������֤,	1�CWindows�������֤����ǰ�û���2�CWindows�������֤�������û�
	IVS_CHAR cDomainName[IVS_DOMAIN_LEN];			// windows����
	IVS_CHAR cMachineName[IVS_MACHINE_NAME_LEN];	// PC������

    IVS_UINT32 uiClientType;						// �ͻ������ͣ��ο� IVS_CLIENT_TYPE 0-PC�ͻ���, 1-web�����, 2-�ƶ��ͻ���, 3-PC�ͻ����ӽ��̣�4-����ǽ����
    IVS_CHAR cReserve[32];                          //�����ֶ�
}IVS_LOGIN_INFO;

// �û������¼��Ϣ;
typedef struct
{
	IVS_CHAR cTicketID[IVS_TICKET_LEN];		        // TicketID;

	IVS_IP	stIP;			                        // ��¼������IP;
	IVS_UINT32 uiPort;		                        // ��¼�������˿�;

	IVS_UINT32 uiLoginType;							// ��¼���ͣ��ο� IVS_LOGIN_TYPE 0�C���������֤,	1�CWindows�������֤����ǰ�û���2�CWindows�������֤�������û�;
	IVS_CHAR cDomainName[IVS_DOMAIN_LEN];			// windows����;
	IVS_CHAR cMachineName[IVS_MACHINE_NAME_LEN];	// PC������;

	IVS_UINT32 uiClientType;						// �ͻ������ͣ��ο� IVS_CLIENT_TYPE 0-PC�ͻ���, 1-web�����, 2-�ƶ��ͻ���, 3-PC�ͻ����ӽ��̣�4-����ǽ����;
	IVS_CHAR cReserve[32];                          //�����ֶ�;
}IVS_LOGIN_INFO_EX;


// �����û���Ϣ
typedef struct
{
	IVS_UINT32	uiUserID;			                // �û�ID
	IVS_UINT32	uiUserOnlineID;		                // �����û���ϢID ��һ���û������Զ��ͬʱ��¼��
    IVS_CHAR    cUserName[IVS_NAME_LEN];            // ��¼�˺�
   	IVS_CHAR    cDomainName[IVS_DOMAIN_LEN];		// ��¼������Ϣ
    IVS_UINT32  uiClientType;					    // ��¼�ͻ������� ֵ�ο� IVS_CLIENT_TYPE
    IVS_IP	    stIP;			                    // ��¼�Ŀͻ���IP
    IVS_CHAR    cMachineName[IVS_MACHINE_NAME_LEN];	// PC������
	IVS_CHAR	cLoginTime[IVS_TIME_LEN];	        // �û���¼ʱ��
    IVS_CHAR    cReserve[64];                       // �����ֶ�
}IVS_ONLINE_USER;

typedef struct
{
	IVS_UINT32   uiTotal;               // �ܼ�¼��
	IVS_INDEX_RANGE stIndexRange;       // ��ҳ��Ϣ
	IVS_ONLINE_USER stOnlineUser[1];    // �����û���Ϣ
}IVS_ONLINE_USER_LIST;

// ���븴����Ҫ��
typedef struct
{
	IVS_BOOL	bCapital;		// ��д��ĸ���Ƿ�ѡ��
	IVS_BOOL	bLowercase;		// Сд��ĸ���Ƿ�ѡ��
	IVS_BOOL	bFigure;		// ���֣��Ƿ�ѡ��
	IVS_BOOL	bSpecialChar;	// �����ַ����Ƿ�ѡ��
    IVS_CHAR    cReserve[32];   // �����ֶ�
}IVS_PWD_CONSIST;

// �˻�����
typedef struct
{
	IVS_BOOL	bEnable;			// �Ƿ�����
	IVS_PWD_CONSIST	stPswConsist;	// ���븴����Ҫ��
	IVS_BOOL	bFirstModify;		// �״ε�¼�޸����룬�Ƿ�ѡ��
	IVS_BOOL	bCheckOldPwd;		// �޸�����ʱ��֤�����룬�Ƿ�ѡ��
	IVS_BOOL	bAccountNotFit;		// ����ܺ��ʺ�һ�����Ƿ�ѡ��
	IVS_BOOL	bAccountBackNotFit;	// ����ܺ��ʺŵĵ�дһ�����Ƿ�ѡ��
	IVS_BOOL	bDomainAccCheckPwd;	// Windows�����˺ŵ�¼��Ҫ�������룬�Ƿ�ѡ��
	IVS_UINT32	uiPwdMinLen;        // ���볤����Сֵ����ֵ��Χ��6-64λ��
	IVS_UINT32	uiPwdDifferentNum;	// �¾����벻��ͬ�ַ�����ֵ��Χ��0-���볤��
	IVS_UINT32	uiAccountLockNum;	// �˺�������ֵ��0��ʾ���������ƣ����999
	IVS_UINT32	uiAccountLockElapse;// �˺�����ʱ������ֵ��Χ��1-1440����

    IVS_UINT32	uiAccountLockInterval;  // �˺������������ֵ��Χ��0-999���ӣ�0��ʾ���Զ����㣬��������Ҫ����Ա�ֶ�����
    IVS_UINT32	uiPWDExpireTime;        // �������ʱ�䣬���봴�����޸ĺ�ʼ��ʱ����λ���죬��Χ��0-999
    IVS_UINT32	uiPWDExpireNotifyTime;  // �����������ʱ�䣬�������ʱ�䵽��ǰ��ʼ���ѣ���λ���죬��Χ��0-99
    IVS_BOOL	bPWDExpireForceNotify;  // �������ǿ���޸ģ��Ƿ�ѡ�С�0-��ǿ���޸ģ�1-ǿ���޸�
    IVS_CHAR    cReserve[64];           // �����ֶ�
}IVS_ROLE_ACCOUNT_RULE;

typedef enum
{
	// Ĭ�Ϲ����ɫ
	OR_MANAGER_DEVICE= 1,		// �豸�����豸������ɾ���ġ�������豸�������豸������豸�������ã��������߼��������ã����ʡ��ֱ��ʡ������ȣ��������������ã�OSD�����ȡ��Աȶȵȣ���
	OR_MANAGER_USER,			// �û������û�������ɫ����Ȩ�޹����û�ǩ�ˡ��澯���ģ������û���
	OR_MANAGER_RECORD,			// ¼�����¼��ռ䡢�ƻ����á�Ԥ¼����¼��¼��鵵������Ƶ�鵵��
	OR_MANAGER_RECORD_BACKUP,	// ¼�񱸷ݹ���ƽ̨��ǰ��¼�񱸷ݹ������ñ��ݲ��ԡ��ֶ�¼�񱸷�
	OR_MANAGER_IA,				// ���ܷ����������ܷ�����������
	//OR_MANAGER_STORAGE,		// �洢�����洢�ռ����
	OR_MANAGER_ALARM=7,			// �澯�����澯���ġ��������ԡ����������澯����
	OR_MANAGER_NET,				// ���ܣ��ͻ������ܣ����豸��澯֪ͨ��
    OR_RECORD_LOCK,				// ¼����������
    OR_RECORD_BOOKMARK=10,      // ¼����ǩ����
	//OR_TRANSPARENT_CHANNEL,	// ͸��ͨ��
    OR_MANAGER_OUT_DOMAIN=12,   // �������Ȩ��
    OR_MANAGER_MAP,             // ���ӵ�ͼ����Ȩ��

    // ����ҵ���ɫ
    OR_TV_WALL_HANDLE=20,       // ����ǽ����ǽʵ������ǽ�ط�
    OR_ALARM_HANDLE,		    // �澯�����澯ȷ�ϡ���ѯ�澯�������澯����������Ȩ�澯�����ظ澯��������
    OR_IA_HANDLE,			    // ���ܷ�������
    OR_DEFENCE_HANDLE,		    // ����������
    OR_WATERMARK_HANDLE,	    // ˮӡ�۸�У��
    OR_MOBILE_CAMERA,	        // �ֻ�ģ��ǰ��Ȩ��

    // һ��ҵ���ɫ
    OR_SNAPSHOT_MANAGER=40,	    // ƽ̨ץ�Ĺ���Ȩ�ޣ����á����ء�Ԥ����ɾ����
    OR_LOG_QUERY,			    // ��־��ѯ������
    OR_MAP,					    // ���ӵ�ͼ����
    OR_REALPLAY,			    // ��⡢�������ܷ���������ֲ��Ŵ���Ѳ/����Ѳ����Ѳ�ƻ������ֹ�����������
    OR_RECORD_PLAY,				// ƽ̨��ǰ��¼��طš��ֲ��Ŵ�ͬ���طš�¼���������������¼�񣩡�VCR���ơ�¼����ǩ
    OR_RECORD_DOWNLOAD,			// ƽ̨��ǰ��¼�����ء�¼�����
    OR_VOICE,				    // �������Խ��͹㲥
    OR_PTZ,					    // ��̨���ƣ���̨Ԥ��λ��Ѳ������̨���ơ�����λ���á���̨�ӽ�����3D��λ��������̨��������
    OR_RECORD_MANUAL,			// �ֶ�¼��ƽ̨��ǰ�ˡ������ֶ�¼��
    OR_SNAPSHOT_LOCAL,		    // ץ�Ĳ���(�������ء�ƽ̨)
}IVS_OPERATION_RIGHT;

// ƽ̨֧����������Ϣ
#define IVS_ABILITY_IA_FR   0x01    // ���ܷ���-����
#define IVS_ABILITY_IA_BA   0x02    // ���ܷ���-��Ϊ
#define IVS_ABILITY_IA_QD   0x04    // ���ܷ���-�������

// Ȩ������Ϣ
#define IVS_MAX_RIGHT_GROUP_NAME_LEN	64	// Ȩ�������Ӣ�������ȣ��������ɿͻ����Լ�ӳ��ʵ�֣�
typedef struct
{
    IVS_CHAR	cRightGroupName[IVS_MAX_RIGHT_GROUP_NAME_LEN];	// Ȩ��������
    IVS_CHAR	cRight[IVS_MAX_OPERATION_RIGHT];                // ��ɫȨ�����飺0-ûȨ�ޣ�1-��Ȩ�ޣ�Ȩ��ֵ�ο� IVS_OPERATION_RIGHT
    IVS_CHAR    cReserve[32];                                   // �����ֶ�
}IVS_OPERATION_RIGHT_GROUP;

// Ȩ�����б�
#define IVS_MAX_RIGHT_GROUP_NUM	8	// Ȩ����������
typedef struct
{
    IVS_UINT32   uiTotal;           // �ܼ�¼��
    IVS_INDEX_RANGE stIndexRange;   // ��ҳ��Ϣ
    IVS_OPERATION_RIGHT_GROUP stOperationRightGroup[1];    // Ȩ������Ϣ
}IVS_OPERATION_RIGHT_GROUP_LIST;

// ��ɫ����
typedef enum
{
    ROLE_TYPE_CUSTOM=0,     // �û��Զ����ɫ
    ROLE_TYPE_DEFAULT=1,    // ϵͳԤ��Ĭ�Ͻ�ɫ
    ROLE_TYPE_ADMIN=2,      // ��������Ա��ɫ
}IVS_ROLE_TYPE;

// ��ɫ
#define IVS_MAX_ROLE_INFO_NUM   128 // ����ɫ����
typedef struct
{
    IVS_CHAR	cDomainCode[IVS_DOMAIN_CODE_LEN];	// ��ɫ���������
	IVS_UINT32	uiRoleID;                           // ��ɫID
	IVS_CHAR	cRoleName[IVS_NAME_LEN];            // ��ɫ����
	IVS_CHAR	cRoleDescribe[IVS_DESCRIBE_LEN];    // ��ɫ����
    IVS_UINT32	uiRoleType;                         // ��ɫ���ͣ�ֵ�ο� IVS_ROLE_TYPE
	IVS_CHAR	cRight[IVS_MAX_OPERATION_RIGHT];    // ��ɫȨ�����飺0-ûȨ�ޣ�1-��Ȩ�ޣ�Ȩ��ֵ�ο� IVS_OPERATION_RIGHT
	IVS_ROLE_ACCOUNT_RULE	stAccountRule;          // �˺Ź���ID���ο� IVS_ROLE_ACCOUNT_RULE
    IVS_CHAR    cReserve[64];                       // �����ֶ�
}IVS_ROLE_INFO;

typedef struct
{
	IVS_UINT32   uiTotal;           // �ܼ�¼��
	IVS_INDEX_RANGE stIndexRange;   // ��ҳ��Ϣ
	IVS_CHAR cReserve[32];          // �����ֶ�
	IVS_ROLE_INFO stRoleInfo[1];    // ��ɫ��Ϣ
}IVS_ROLE_INFO_LIST;

// �û���
#define IVS_MAX_USER_GROUP_LEVEL	    4	// �û���㼶������
#define IVS_MAX_USER_GROUP_DESC_LEN 	256	// �û��鱸ע
typedef struct
{
    IVS_CHAR	cDomainCode[IVS_DOMAIN_CODE_LEN];	// �û������������
	IVS_UINT32	uiID;					            // �û���ID
	IVS_CHAR	cName[IVS_NAME_LEN];	            // �û�������
	IVS_UINT32	uiParentID;				            // ���û���ID
	IVS_UINT32	uiLevel;				            // �û���㼶�����֧��4�㣨�����������ڣ�
    IVS_CHAR	cGroupDesc[IVS_MAX_USER_GROUP_DESC_LEN];	// �û��鱸ע�����̿ɼ��ַ������ģ�0~64�ַ���ֵ����Ϊ��
    IVS_CHAR    cReserve[32];                       // �����ֶ�
}IVS_USER_GROUP;

//�û����б�
typedef struct
{
	IVS_UINT32   uiTotal;           // �ܼ�¼��
	IVS_INDEX_RANGE stIndexRange;   // ��ҳ��Ϣ
	IVS_CHAR cReserve[32];          //�����ֶ�
	IVS_USER_GROUP stUserGroup[1];  //�û����б�
}IVS_USER_GROUP_LIST;

// �˺�״̬
typedef enum
{
	ACCOUNT_STATUS_ACTIVE= 1,           // ����
	ACCOUNT_STATUS_STOPPED= 2,          // ͣ��
	ACCOUNT_STATUS_INVALID_LOGIN= 3,    // ��Ч��¼����
}IVS_ACCOUNT_STATUS;

// �û���Ϣ
typedef struct
{
    IVS_CHAR	cDomainCode[IVS_DOMAIN_CODE_LEN];	// �û����������
	IVS_UINT32	uiUserID;						// �û�ID��ϵͳ����
	IVS_BOOL	bFirstLogin;					// �Ƿ��ǵ�һ�ε�¼
	// ����û���Ҫ����Ϣ
	IVS_UINT32	uiRoleID;						// ��ɫID������Ա���ã��ṹ����ο� IVS_USER_ROLE
	IVS_UINT32	uiGroupID;						// �û���ID���ṹ����ο� IVS_USER_GROUP
	IVS_CHAR	cLoginName[IVS_NAME_LEN];		// ��¼�˺ţ���¼�˺ţ���ĸ��a-z��A-Z��,���֣��л��ߺ��»��ߣ�1~20���ַ�

	IVS_CHAR	cPWD[IVS_PWD_LEN];	// ��¼���룺��¼���룬���̿ɼ��ַ���1~16���ַ���
	IVS_CHAR	cPwdModifyDate[IVS_TIME_LEN];	// �����޸�����

	IVS_UINT32	uiUserType;						// �û����ͣ�0��IVS��ͨ�û���1��Windows���û�
	IVS_CHAR	cUserDomain[IVS_DOMAIN_LEN];	// Windows����
	IVS_UINT32	uiStatus;						// �û�״̬���ο� IVS_ACCOUNT_STATUS
	IVS_CHAR	cRegiterDate[IVS_TIME_LEN];		// ��������
	IVS_CHAR	cUserDesc[IVS_DESCRIBE_LEN];	// �û����������̿ɼ��ַ������ģ�0~64�ַ���
	IVS_UINT32	uiPTZLevel;						// �ƾ��������ȼ���0~9
	IVS_UINT32	uiMaxSessionCnt;				// ����¼��,��󳤶�3�ַ�������
	IVS_UINT32	uiMaxVideoCnt;					// �����Ƶ·������󳤶�3�ַ������� 
	IVS_CHAR	cLockTime[IVS_TIME_LEN];		// �˺ű�������ʱ��

	// ���˻�����Ϣ�����ڸ����޸�
	IVS_CHAR	cUserName[IVS_NAME_LEN];		// ��ʵ���������ֺ���ĸ��a-z��A-Z�������֣��л��ߺ��»��ߣ�1~20���ַ�
	IVS_CHAR	cEmail[IVS_EMAILE_LEN];			// ���䣬�ο�����163�������ơ�
	IVS_CHAR	cPhone[IVS_PHONE_NUMBER_LEN];	// �绰��0~25λ���֣��л���
	IVS_UINT32	uiSex;							// �Ա�0-Ů�ԣ�1-����
    IVS_UINT32	uiValidDateFlag;        //�Ƿ����˻���Чʱ��
    IVS_CHAR	cValidDateStart[IVS_TIME_LEN];   //�˻���Ч��ʼ����
    IVS_CHAR	cValidDateEnd[IVS_TIME_LEN];     //�˻���Ч��������

    IVS_CHAR    cReserve[64];                       // �����ֶ�
}IVS_USER_INFO;

typedef struct
{
	IVS_UINT32   uiTotal;           // �ܼ�¼��
	IVS_INDEX_RANGE stIndexRange;   // ��ҳ��Ϣ
	IVS_CHAR cReserve[32];          //�����ֶ�
	IVS_USER_INFO stUserInfo[1];    // �û���Ϣ
}IVS_USER_INFO_LIST;

// �豸�û���Ϣ
typedef struct
{
    IVS_UINT32	uiUserID;						// �û�ID��ϵͳ����
    IVS_CHAR	cLoginName[IVS_NAME_LEN];		// ��¼�˺ţ���¼�˺ţ���ĸ��a-z��A-Z��,���֣��л��ߺ��»��ߣ�1~20���ַ�
    IVS_CHAR	cUserName[IVS_NAME_LEN];		// ��ʵ���������ֺ���ĸ��a-z��A-Z�������֣��л��ߺ��»��ߣ�1~20���ַ�
	IVS_UINT32	uiGroupID;						// �û���ID���ṹ����ο� IVS_USER_GROUP
    IVS_CHAR	cReserve[8];
}IVS_DEVICE_USER_INFO;

// �豸�û��б�
typedef struct
{
    IVS_UINT32   uiTotal;           // �ܼ�¼��
    IVS_INDEX_RANGE stIndexRange;   // ��ҳ��Ϣ
    IVS_DEVICE_USER_INFO stDeviceUserInfo[1];    // �豸�û���Ϣ
}IVS_DEVICE_USER_INFO_LIST;

// ��ѯ����������
typedef enum
{
	QUERY_INVALID=0,	                // ��ѯ������

    QUERY_TIME=1,	                    // Ĭ�ϰ������ݿ��¼����ʱ���������

    QUERY_USER_ID=100,                  // �û�ID
    QUERY_LOGIN_NAME,                   // �û��ĵ�¼�˺�
    QUERY_USER_NAME,                    // �û���ʵ����
    QUERY_USER_STATUS,                  // �û�״̬
    QUERY_USER_NAME_TYPE,               // �û�״̬

    QUERY_CAMERA_CODE=200,              // ���������

	QUERY_DEV_NVR_CODE=300,				// �豸����NVR����
	QUERY_DEV_DEV_NAME,				    // �豸����
	QUERY_DEV_TYPE,					    // �����豸����
	QUERY_DEV_VENDOR_TYPE,			    // ���峧������
	QUERY_DEV_IP,					    // ������豸IP��ַ
	QUERY_DEV_ONLINE,				    // �Ƿ�����
    QUERY_DEV_SN,				        // �豸SN
    QUERY_DEV_MODEL_TYPE,               // �豸SN

    QUERY_DEV_GROUP_CODE=500,             // �豸�����
    QUERY_DEV_DOMAIN_CODE,              // �豸���������

    QUERY_RECORD_QUERY_TYPE=600,        // ¼���ѯ��ʽ��0-��ʱ�䣬1-����ǩ��2-��Ԥ��λ��3-��������Ϣ
	QUERY_RECORD_BOOKMARK_NAME,			// ��ǩ����ģ��ƥ��
	QUERY_RECORD_PTZ_PRESET_NAME,		// Ԥ��λ���ƣ�ģ��ƥ�䣬��ѯԤ��λ��ѯ¼��ʱ��Ч
	QUERY_RECORD_LOCK_DESC,				// ����������ģ��ƥ�䣬��ѯ����¼��ʱ��Ч
    QUERY_RECORD_LOCK_OPERATOR_TYPE,	// ���������û����ͣ���ѯ����¼��ʱ��Ч����0-�����û���1-��ǰ�û�
	QUERY_RECORD_METHOD,    	        // ���洢λ�ò�ѯ¼��ֵ�ο� IVS_RECORD_METHOD
	QUERY_RECORD_TYPE,			        // ֵ�ο� IVS_RECORD_TYPE
    QUERY_RECORD_ALARM_TYPE,            // ¼��澯����
    QUERY_RECORD_USER_DOMAIN,           // ¼������û���¼���������ǩ�������ȣ�

    QUERY_OPERATION_ACCOUNT=700,        // ����Ա�˺�
    QUERY_OPERATION_RESULT,             // ���������0-�ɹ���1��ʧ��
    QUERY_OPERATION_START_TIME,         // ��ʼʱ�䣬yyyyMMddhhmmss����ѯ����ʱ��
    QUERY_OPERATION_END_TIME,           // ����ʱ�䣬yyyyMMddhhmmss����ѯ����ʱ��
    QUERY_OPERATION_CODE,               // �������ܴ���
    QUERY_OPERATION_OBJECT_CODE,        // �����������

    QUERY_ALARM_CATEGORY=800,           // �澯���ͼ���
    QUERY_ALARM_TYPE,                   // �澯���ͣ�������ѡ������¼���ѯ��Ϊ0��ʾ���У�
    QUERY_ALARM_IN_TYPE,                // �澯Դ����
    QUERY_ALARM_LEVEL_ID,               // �澯����

    QUERY_ALARM_IN_CODES,               // �澯Դ���룻��ѡ���ö��š�,���ָ����޴�������Ϊ�ձ�ʾ����
    QUERY_ALARM_IN_NAME,                // �澯Դ����
    QUERY_ALARM_LEVEL_MIN,              // �澯��������
    QUERY_ALARM_LEVEL_MAX,              // �澯��������
    QUERY_ALARM_LEVEL_VALUE,            // �澯����ͬʱ���ݶ���澯�����Զ��š�,������
    QUERY_ALARM_STATUS,                 // �澯��Ϣ״̬����ѡ������,���ָ�޴�������Ϊ�ձ�ʾ����

    QUERY_ALARM_LOCATION_INFO,          // �澯��λ��Ϣ
    QUERY_ALARM_CONFIRM_OPERATOR,       // ȷ����ID����ѡ������,���ָ�޴�������Ϊ�ձ�ʾ����
    QUERY_ALARM_DESC,                   // �澯Դ������ģ����ѯ
    QUERY_ALARM_TYPE_LIST,              // �澯�����б��á�,���ָ���Ա�ʾͬʱ��ѯ����澯���ͣ�����¼���ѯ��
    QUERY_ALARM_TYPE_FILTER,            // ��Ҫ���˵ĸ澯��������Զ��Ÿ�����010201����Ϊ������    010202������ʶ��    010203���������

    QUERY_DICTIONARY_TYPE=1000,         // �ֵ����ͣ���ȷ��ѯ����ѡ
    QUERY_DICTIONARY_NAME,              // �ֵ����ƣ���ȷ��ѯ����ѡ
    QUERY_DICTIONARY_PARENT_ID,         // ���ڵ�ID����ȷ��ѯ����ѡ

    QUERY_OPERATOR_ID=1100,             //ִ�в�ѯ�������û�ID
    QUERY_NODE_CODE,				    // ��Ԫ����(���һ�β�һ����Ԫ�ģ����ֶα���)

    QUERY_WATERMARK_ALARM_STATUS=1300,  // ˮӡ�澯״̬��0x01-δȷ�� 0x02-��ȷ�� 0x04-�ѳ��������ֵ��ʾ��ѡ����0x07��ʾ��ѯ����״̬��0x06��ʾ��ѯ��ȷ�Ϻ��ѳ�����
    QUERY_WATERMARK_USERID_DOMAIN,      // ��ǰ�û����������

    // ����Ŀ¼����
    QUERY_SHARE_EXDOMAIN_CODE=1400,     // ��������룬��ȷ��ѯ����ѡ
    QUERY_SHARE_DIRECT,                 // �����򣬾�ȷ��ѯ����ѡ��1-����������� 2-�����������
    // DeviceType ���� QUERY_DEV_TYPE   // �����豸��Դ���ͣ���ȷ��ѯ��00�����豸 01������� 02�����������豸 03����������豸 99������
    QUERY_SHARE_PARENT_ID,              // ���豸���룬��ȷ��ѯ��
    QUERY_SHARE_DEVICE_ID,              // �豸�������룬��ȷ��ѯ��
    // DevName    ���� QUERY_DEV_DEV_NAME // �豸���ƣ�ģ����ѯ
    QUERY_SHARE_ISLATEST,               // �Ƿ��ѯ���£�0-��ֻ��ѯ���е����� 1-�ǣ����������ͬ���󣬲�ѯ���µ�����

}IVS_QUERY_FIELD_TYPE;

//��ѯ�Ľṹ��
#define IVS_QUERY_VALUE_LEN 2048    // ��ѯ�ֶδ�С
typedef struct
{
    IVS_UINT32  eFieID;                         //��ѯ�ֶε����� �ο� IVS_QUERY_FIELD_TYPE
    IVS_CHAR    cValue[IVS_QUERY_VALUE_LEN];    //�ֶε�ֵ
	IVS_BOOL    bExactQuery;                    // �Ƿ�ȷ��ѯ��0-��1-��
}IVS_QUERY_FIELD;

//����Ľṹ��
typedef struct
{
	IVS_BOOL    bEnableOrder;       // �Ƿ��������� 0 - ������ 1 - ����
	IVS_UINT32  eFieID;             //������ֶ� �ο� IVS_QUERY_FIELD_TYPE
    IVS_BOOL    bUp;                // �Ƿ�����0-����1-����
}IVS_ORDER_COND;

// ��ѯͨ�ø�ʽ
typedef struct 
{
    IVS_INDEX_RANGE stIndex;    // ��ѯ��Χ����
	IVS_ORDER_COND stOrderCond; // ������Ϣ
    IVS_INT32 iFieldNum;        // �ֶε�����Ϊ0��ʾ�޲�ѯ��������
    IVS_QUERY_FIELD stQueryField[1];
}IVS_QUERY_UNIFIED_FORMAT;

// �豸�������
typedef struct
{
	IVS_UINT32	uiSequence;             // �����������
	IVS_INT32	iResult;                // ���󷵻ش��루�������ʱ��
	IVS_CHAR cCode[IVS_DEV_CODE_LEN];   // �豸����
}IVS_RESULT_INFO;

// �豸������������б�
typedef struct
{
	IVS_UINT32	uiNum;          // ���صĲ����������
	IVS_RESULT_INFO	stInfo[1];
}IVS_RESULT_LIST;

// ������ƻ���Ϣ
#define IVS_MAX_CAMERA_PLAN_NUM     64  // ��������ƻ�������
typedef struct
{
    IVS_CHAR	cCameraCode[IVS_DEV_CODE_LEN];  // ����ͷ����
    IVS_INT32	iResult;                        // ���󷵻ش��루����ʱ��ȷ��ÿ��������Ƿ�ɹ����أ�
    IVS_BOOL    bSetPlan;                       // �Ƿ����üƻ� 0-δ���� 1-������
    IVS_CHAR    cReserve[32];                   // �����ֶ�
}IVS_CAMERA_PLAN_SET_INFO;

// ������ƻ���Ϣ�б�
typedef struct
{
    IVS_UINT32	uiNum;                      // ���صĲ����������
    IVS_CAMERA_PLAN_SET_INFO    stInfo[1];  // ������ƻ���Ϣ�б�
}IVS_CAMERA_PLAN_SET_INFO_LIST;

// ¼��ƻ�������
typedef enum
{
	DAY_TYPE_EVERYDAY = 0,	// ÿ�죨������ָ����ͬʱ���¼��
	DAY_TYPE_MONDAY=1,		// ��һ
	DAY_TYPE_TUESDAY,		// �ܶ�
	DAY_TYPE_WEDNESDAY,		// ����
	DAY_TYPE_THURSDAY,		// ����
	DAY_TYPE_FRIDAY,		// ����
	DAY_TYPE_SATURDAY,		// ����
	DAY_TYPE_SUNDAY,		// ����
}IVS_DAY_TYPE;

// �ط�ʱ����Ϣ
typedef struct
{
    IVS_CHAR    cPlayBackTime[IVS_TIME_LEN];        // ��ǰ�ط�ʱ�䣬��ʽΪyyyyMMddHHmmss
    IVS_CHAR    cPlayBackStartTime[IVS_TIME_LEN];   // ��ǰ��ʼʱ�䣬��ʽΪyyyyMMddHHmmss�������ļ�������Ϊ�գ�
    IVS_CHAR    cPlayBackEndTime[IVS_TIME_LEN];     // ��ǰ����ʱ�䣬��ʽΪyyyyMMddHHmmss�������ļ�������Ϊ�գ�
    IVS_CHAR    cReserve[64];                       // �����ֶ�
}IVS_PLAYBACK_TIME;

#define IVS_MAX_TIMESPAN_NUM    24  // ʱ����������
#define IVS_MAX_PLAN_INFO_NUM   7   // ���ƻ���Ϣ������һ��7�죩
// �ƻ�ʱ����Ϣ
typedef struct
{
	IVS_UINT32      uiDayType;								//���ڼ����ο� IVS_DAY_TYPE 0 �C ÿ�� 1 �C ��һ 2 �C �ܶ� 3 �C ���� 4 �C ���� 5 �C ���� 6 �C ���� 7 �C ����
	IVS_UINT32      uiTimeSpanInfoNum;						//ʱ�������
    IVS_CHAR        cReserve[32];                           // �����ֶ�
	IVS_TIME_SPAN   stTimeSpanInfo[IVS_MAX_TIMESPAN_NUM];   //ʱ�����Ϣ
}IVS_PLAN_INFO;

// ¼��ƻ�����
typedef enum
{
	RECORD_PLAN_WEEK=0,		// �ܼƻ�
	RECORD_PLAN_DAY=1,		// �ռƻ�
	RECORD_PLAN_ALLDAY=2,	// ȫ��¼��
}IVS_RECORD_PLAN_TYPE;

// ¼��洢λ��
typedef enum
{
	RECORD_METHOD_PLATFORM = 0,	// ƽ̨¼��
	RECORD_METHOD_PU,			// ǰ��¼��
    RECORD_METHOD_MBU,          // ���ݷ�����
    RECORD_METHOD_DISASTER_RECOVERY,    // ����¼��
}IVS_RECORD_METHOD;

// ¼��ƻ�
typedef struct
{
	IVS_UINT32	uiRecordMethod;         // ¼��洢λ�ã��ο� IVS_RECORD_METHOD
	IVS_BOOL	bEnableRecordPlan;      // �Ƿ�����¼��ƻ� 0-δ���ã�1-����
	IVS_UINT32	uiRecordPlanType;		// �ƻ���ʽ���ο� IVS_RECORD_PLAN_TYPE 0-(WEEK)�ܼƻ�,1(DAY)-�ռƻ�����һ�����ռƻ���ͬ��2-ȫ��¼��
    IVS_CHAR    cReserve[64];           // �����ֶ�

	IVS_UINT32	uiPlanInfoNum;			// ¼��ƻ���Ϣ�������ܼƻ�-7���ռƻ�-1��ȫ��¼��-0
	IVS_PLAN_INFO	stPlanInfo[IVS_MAX_PLAN_INFO_NUM];	// ¼��ƻ���Ϣ���ܼƻ�-���7���ƻ���Ϣ���ռƻ�-1һ���ƻ���Ϣ��ȫ��¼��-��
}IVS_RECORD_PLAN;

// ¼��ƻ�����
typedef enum
{
	PLAN_WEEK=0,	// �ܼƻ�
	PLAN_DAY=1,		// �ռƻ�
	PLAN_ALLDAY=2,	// ȫ��
}IVS_PLAN_TYPE;

// ���������ƻ�
typedef struct
{
	IVS_UINT32		uiAlarmAreaID;          // ����ID  
	IVS_BOOL		bEnablePlan;            // �Ƿ�����¼��ƻ� 0-δ���ã�1-����
	IVS_UINT32		uiRecordPlanType;		// �ƻ���ʽ���ο� IVS_PLAN_TYPE
    IVS_CHAR        cReserve[64];           // �����ֶ�

	IVS_UINT32		uiPlanInfoNum;			// �ƻ���Ϣ�������ܼƻ�-7���ռƻ�-1��ȫ��¼��-0
	IVS_PLAN_INFO	stPlanInfo[IVS_MAX_PLAN_INFO_NUM];	// ¼��ƻ���Ϣ���ܼƻ�-���7���ƻ���Ϣ���ռƻ�-1һ���ƻ���Ϣ��ȫ��¼��-��
}IVS_ALARM_AREA_PLAN;

// ����¼���ļ��ָʽ
typedef enum
{
    RECORD_SPLITE_TIME      =1,   // ��ʱ��ָ�
    RECORD_SPLITE_CAPACITY  =2,   // �������ָ�
}IVS_RECORD_SPLITE_TYPE;

// ����¼���ļ���������
typedef enum
{
    RULE_NAME_NUM_TIME=1,       // �������_���_ʱ�䣨��ʼʱ��-����ʱ�䣬YYYY-MM-DD-hh-mm-ss��
    RULE_NAME_TIME_NUM=2,       // �������_ʱ�䣨��ʼʱ��-����ʱ�䣬YYYY-MM-DD-hh-mm-ss��_���
    RULE_TIME_NAME_NUM=3,       // ʱ�䣨��ʼʱ��-����ʱ�䣬YYYY-MM-DD-hh-mm-ss��_�������_���
}IVS_RECORD_NAME_RULE;

// ����¼���ļ���ʽ
typedef enum
{
    IVS_FILE_MP4=1,       // MP4�ļ�
    IVS_FILE_AVI=2,       // AVI�ļ�
}IVS_RECORD_FILE_TYPE;

// ����¼�����
#define IVS_MIN_TIME_SPLITTER_VALUE     5       // ��Сʱ��ָ�ֵ��5����
#define IVS_MAX_TIME_SPLITTER_VALUE     720     // ���ʱ��ָ�ֵ��720����
#define IVS_MIN_SPACE_SPLITTER_VALUE    50      // ��С�����ָ�ֵ��50M
#define IVS_MAX_SPACE_SPLITTER_VALUE    3072    // ��������ָ�ֵ��3072M
#define IVS_MIN_RECORD_TIME             300     // ��С¼��ʱ����300����λ��
#define IVS_MAX_RECORD_TIME             43200   // ���¼��ʱ����43200����λ�루12Сʱ��
#define IVS_LOCAL_RECORD_PWD_LEN        36      // ����¼����������ֽ���������'\0'
typedef struct
{
    IVS_UINT32  uiRecordFormat;                 // ¼���ļ���ʽ���ο� IVS_RECORD_FILE_TYPE
    IVS_UINT32  uiSplitterType;                 // ¼��ָʽ���ο� IVS_RECORD_SPLITE_TYPE
    IVS_UINT32  uiSplitterValue;                // ¼��ָ�ֵ���ļ��ָʽ��ʱ��ʱ������ʱ�䣬��Ӧ��λΪ���ӣ�5-60���ӣ�ͬʱ�����ļ���С������2048MB�����ƣ��ļ��ָʽ������ʱ��������������Ӧ��λΪM��10-2048MB

    IVS_UINT32  uiDiskWarningValue;             // ����¼�񣬴��̿ռ�С�ڴ�ֵ�澯����λM�����С�����¼��ͨ���¼��ϱ���2-����¼��澯��
    IVS_UINT32  uiStopRecordValue;              // ����¼�񣬴��̿ռ�С�ڴ�ֵֹͣ¼�񣬵�λM�����С�����¼��ͨ���¼��ϱ���3-����¼�������ֹͣ��

    IVS_UINT32  uiRecordTime;                   // ¼��ʱ������λ�룬������300 ~ 43200��12Сʱ��

    IVS_BOOL    bEncryptRecord;                 // ¼���Ƿ����
    IVS_CHAR    cRecordPWD[IVS_LOCAL_RECORD_PWD_LEN];   // ����¼������

    IVS_UINT32  uiNameRule;                     // ¼���ļ��������򣬲ο� IVS_RECORD_NAME_RULE
    IVS_CHAR    cSavePath[IVS_FILE_NAME_LEN];   // ����¼����·���������ļ������Ȳ�����256�ֽ�
    IVS_CHAR    cReserve[64];                   // �����ֶ�
}IVS_LOCAL_RECORD_PARAM;

// ¼�����ز���
typedef struct
{
    IVS_UINT32  uiRecordFormat;                 // ¼���ļ���ʽ���ο� IVS_RECORD_FILE_TYPE
    IVS_UINT32  uiSplitterType;                 // ¼��ָʽ���ο� IVS_RECORD_SPLITE_TYPE
    IVS_UINT32  uiSplitterValue;                // ¼��ָ�ֵ���ļ��ָʽ��ʱ��ʱ������ʱ�䣬��Ӧ��λΪ���ӣ�5-60���ӣ�ͬʱ�����ļ���С������2048MB�����ƣ��ļ��ָʽ������ʱ��������������Ӧ��λΪM��1-2048MB

    IVS_UINT32  uiDiskWarningValue;             // ���̿ռ�С�ڴ�ֵ�澯����λM�����С�����¼��ͨ���¼��ϱ���2-����¼��澯��
    IVS_UINT32  uiStopRecordValue;              // ���̿ռ�С�ڴ�ֵֹͣ¼�񣬵�λM�����С�����¼��ͨ���¼��ϱ���3-����¼�������ֹͣ��

    IVS_UINT32  uiDownloadSpeed;                // ¼�������ٶȣ�255-�����٣�ȫ�٣���1-1���٣�ǰ��ֻ֧�֣�1��
    IVS_TIME_SPAN stTimeSpan;                   // ¼������ʱ���

    IVS_BOOL    bEncryptRecord;                 // ¼�������Ƿ����
    IVS_CHAR    cRecordPWD[IVS_LOCAL_RECORD_PWD_LEN];   // ¼����������

    IVS_UINT32  uiNameRule;                     // ¼���ļ��������򣬲ο� IVS_RECORD_NAME_RULE
    IVS_CHAR    cSavePath[IVS_FILE_NAME_LEN];   // ¼����·���������ļ������Ȳ�����256�ֽ�

    IVS_CHAR    cFileName[IVS_FILE_NAME_LEN];   // ����¼���ļ���������·��������Ϊ256�ֽڣ�������׺�ͽ������������¼���ļ���������֣�Ϊ��ʱ������uiNameRule�����������cSavePath��·��ȷ���ļ���
    IVS_CHAR    cReserve[64];                   // �����ֶ�
}IVS_DOWNLOAD_PARAM;

// ¼��������Ϣ
typedef struct
{
    IVS_UINT32  uiDownloadStatus;   // ����״̬��0-��ͣ 1-����
    IVS_UINT32  uiDownloadSpeed;    // �����ٶȣ���λKB/S
    IVS_UINT64  uiDownloadSize;     // �����ش�С����λKB
    IVS_UINT32  uiTimeLeft;         // ʣ������ʱ�䣺��λ��
    IVS_UINT32  uiProgress;         // ��ǰ���ؽ��ȣ�0-100����ʾ�ٷֱ�
}IVS_DOWNLOAD_INFO;

// ý�岥����Ϣ
typedef struct
{
	IVS_UINT32	uiWinID;                // ����ID
	IVS_UINT32	uiAudioStatus;          // ����״̬

	IVS_UINT32  uiVideoFrameRate;		// ��Ƶ��ǰ֡�ʣ���λ(fps)����Χ1-60

    IVS_UINT32	uiVideoBitrate;         //	��Ƶ��ǰ����
	IVS_UINT32	uiVideoAverageBitrate;  //	��Ƶƽ������

	IVS_UINT32	uiAudioBitRate;			// ��Ƶ��ǰ���ʣ���λ(kbps)
	IVS_UINT32	uiAudioAverageBitRate;	// ��Ƶƽ�����ʣ���λ(kbps)

	IVS_UINT32	uiVideoCodec;           // ��Ƶ�����ʽ���ο� IVS_VIDEO_DEC_TYPE
	IVS_UINT32	uiVideoWidth;           // ��Ƶ�����
	IVS_UINT32	uiVideoHeight;          // ��Ƶ�����
	IVS_FLOAT	fLossTolerance;         // ������

	IVS_UINT32	uiInfoLocationX;        // i��ť����Ļ�ϵ����½�X����
	IVS_UINT32	uiInfoLocationY;        // i��ť����Ļ�ϵ����½�Y����

    IVS_IP      stMediaSourceIP;        // ý�������Ͷ�IP
    IVS_CHAR    cReserve[64];           // �����ֶ�
}IVS_MEDIA_INFO;

// �洢����
typedef enum
{
	RECORD_MODE_FULL=0,					// ȫ���洢
	RECORD_MODE_FRAME_EXTRACTION=1,		// ��֡�洢
	RECORD_MODE_VIDEO_COMPRESS=2,		// �˶�������ܴ洢
}IVS_RECORD_MODE;

// Ԥ¼����
typedef enum
{
	PRERECORD_MODE_NONE=0,	// ��Ԥ¼
	PRERECORD_MODE_PLAT=1,	// ƽ̨Ԥ¼
	PRERECORD_MODE_PU=2,	// ǰ��Ԥ¼
}IVS_PRERECORD_MODE;

// ¼����ԣ�ʱ�䣩
#define IVS_MAX_PRERECORD_TIME	300     // ���Ԥ¼ʱ�䣬��λ����

typedef struct
{
	IVS_UINT32	uiRecordMode;				// �洢���ͣ��ο� IVS_RECORD_MODE

	IVS_UINT32	uiTime;						// ��Ƶ������������λ����
	IVS_UINT32	uiFrameExtractRecordTime;	// ��֡�洢��������λ����
	IVS_UINT32	uiAlarmTime;				// �и澯¼��洢��������λ����
	IVS_UINT32	uiKeyframeTime;				// �ؼ�֡��������λ����

	IVS_UINT32	uiBeforeAlarm;				// �˶���⾯ǰʱ�䣬��λ���루��Ƶ�鵵ʱ��Ч��
	IVS_UINT32	uiAfterAlarm;				// �˶���⾯��ʱ�䣬��λ���루��Ƶ�鵵ʱ��Ч��

	IVS_UINT32	uiPlanStreamType;			// �ƻ�¼��ʹ�õ������ο� IVS_STREAM_TYPE
	IVS_UINT32	uiAlarmStreamType;			// �澯¼��ʹ�õ������ο� IVS_STREAM_TYPE

	IVS_UINT32	uiAlarmRecordTTL;			// �澯¼�������ڣ��Ǹ�������0�C���ã�	�����C�����ڣ���λ����
	IVS_UINT32	uiManualRecordTTL;			// �ֶ�¼�������ڣ��Ǹ�������0�C���ã�	�����C�����ڣ���λ����

	IVS_UINT32	uiPreRecord;				// Ԥ¼���ã��ο� IVS_PRERECORD_MODE
	IVS_UINT32	uiPreRecordTime;			// Ԥ¼ʱ������λ���룬��Χ(1��IVS_MAX_PRERECORD_TIME)

	IVS_BOOL	bAssociatedAudio;			// ��·��Ƶ����ѡ�	0-������ 1-����

	IVS_CHAR	cReserve[32];
}IVS_RECORD_POLICY_TIME;

// ¼����ԣ�������
typedef struct
{
    IVS_UINT32	uiRecordMode;				// �洢���ͣ��ο� IVS_RECORD_MODE

    IVS_UINT32	uiBeforeAlarm;				// �˶���⾯ǰʱ�䣬��λ���루��Ƶ�鵵ʱ��Ч��
    IVS_UINT32	uiAfterAlarm;				// �˶���⾯��ʱ�䣬��λ���루��Ƶ�鵵ʱ��Ч��

    IVS_UINT32	uiPlanStreamType;			// �ƻ�¼��ʹ�õ������ο� IVS_STREAM_TYPE
    IVS_UINT32	uiAlarmStreamType;			// �澯¼��ʹ�õ������ο� IVS_STREAM_TYPE

    IVS_UINT32	uiAlarmRecordTTL;			// �澯¼�������ڣ��Ǹ�������0�C���ã�	�����C�����ڣ���λ����
    IVS_UINT32	uiManualRecordTTL;			// �ֶ�¼�������ڣ��Ǹ�������0�C���ã�	�����C�����ڣ���λ����

    IVS_UINT32	uiPreRecord;				// Ԥ¼���ã��ο� IVS_PRERECORD_MODE
    IVS_UINT32	uiPreRecordTime;			// Ԥ¼ʱ������λ���룬��Χ(1��IVS_MAX_PRERECORD_TIME)

    IVS_BOOL	bAssociatedAudio;			// ��·��Ƶ����ѡ�	0-������ 1-����

    IVS_UINT64	uiCapacity;                 // ������MBΪ��λ
    IVS_UINT32  uiFullPolicy;               // ¼��ռ���������ԣ�0-����������¼��  1-�����Ǽƻ�¼�� 2-��ֹͣ

    IVS_CHAR	cReserve[32];
}IVS_RECORD_POLICY_CAPACITY;

#define IVS_RECORD_TYPE_LEN      8	// ¼�����ͳ���
typedef enum
{
	//modify by zwx211831��ȥ�������ܷ���¼��	����Date��20140520
	RECORD_TYPE_ALARM=1,	// ��ͨ�澯¼��
	RECORD_TYPE_PLAN=2,		// �ƻ�¼��
	RECORD_TYPE_MANUAL=4,	// �ֶ�¼��
}IVS_RECORD_TYPE;

// ¼���֡����
typedef enum
{
	FRAME_EXTRACTION_0= 0,	// ����
	FRAME_EXTRACTION_1= 1,	// ����������֡һ�Σ�
	FRAME_EXTRACTION_2= 2,	// ����������֡���Σ�
	FRAME_EXTRACTION_3= 3,	// ����������֡���Σ�
}IVS_FRAME_EXTRACTION_TIMES;

// ¼���ǩ��Ϣ����ѯ��ʽΪ����ǩʱ��Ч
#define IVS_BOOKMARK_NAME_LEN 612
typedef struct
{
	IVS_UINT32	uiBookmarkID;                           // ¼���ǩID
    IVS_CHAR	cBookmarkName[IVS_BOOKMARK_NAME_LEN];   // ��ǩ�����������150�ַ�
	IVS_CHAR	cBookmarkTime[IVS_TIME_LEN];            // ��ǩʱ�䣺yyyyMMddHHmmss

	IVS_CHAR	cCameraCode[IVS_DEV_CODE_LEN];          // ����ͷ����
	IVS_CHAR	cCameraName[IVS_NAME_LEN];              // ����ͷ����

    IVS_CHAR	cUserDomain[IVS_DOMAIN_CODE_LEN];       // �����û����������
    IVS_UINT32  uiBookmarkCreatorID;                    // ������ǩ���û�ID
    IVS_CHAR    cBookmarkCreatorName[IVS_NAME_LEN];     // ������ǩ���û���

    IVS_CHAR	cNvrCode[IVS_NVR_CODE_LEN];             // NVR����
    IVS_CHAR	cMBUDomain[IVS_DOMAIN_CODE_LEN];        // ���ݷ���������뱸��¼���������д����ֶ�

    IVS_CHAR	cReserve[32];
}IVS_RECORD_BOOKMARK_INFO;

// ¼����ǩ�б�
typedef struct
{
	IVS_UINT32   uiTotal;                           // �ܼ�¼��
	IVS_INDEX_RANGE stIndexRange;                   // ��ҳ��Ϣ
	IVS_CHAR cRes[32];                              //�����ֶ�
	IVS_RECORD_BOOKMARK_INFO stBookmarkInfo[1];     // ¼����ǩ��Ϣ
}IVS_RECORD_BOOKMARK_INFO_LIST;

// ¼��������Ϣ����ѯ��ʽΪ������״̬ʱ��Ч
#define IVS_RECORD_LOCK_DESC_LEN 260
typedef struct
{
	IVS_UINT32	uiLockID;						        // ������¼ID
	IVS_CHAR	cLockTime[IVS_TIME_LEN];		        // ִ������������ʱ��
	IVS_TIME_SPAN	stLockTimeSpan;				        // ������¼��ʱ��
	IVS_CHAR	cLockDesc[IVS_RECORD_LOCK_DESC_LEN];	// ��������

	IVS_UINT32	uiOperatorID;						    // ִ�������������û�ID
	IVS_CHAR	cOperatorName[IVS_NAME_LEN];            // ִ�������������û���
    IVS_CHAR    cReserve[64];                           // �����ֶ�
}IVS_RECORD_LOCK_INFO;

// ¼��Ԥ��λ��Ϣ����ѯ��ʽΪ��Ԥ��λ��ѯʱ��Ч
#define IVS_RECORD_PTZ_PRESET_NAME_LEN 64
typedef struct
{
	IVS_UINT32	uiID;	// Ԥ��λID
	IVS_CHAR	cName[IVS_RECORD_PTZ_PRESET_NAME_LEN];	// Ԥ��λ����
    IVS_CHAR    cReserve[32];                           // �����ֶ�
}IVS_RECORD_PTZ_PRESET_INFO;

// ¼�������Ϣ
typedef struct
{
	IVS_CHAR	cRecordFileName[IVS_FILE_NAME_LEN];	    // ¼���ļ���

	IVS_UINT32	uiRecordMethod;		                    // ¼��洢λ�ã��ο� IVS_RECORD_METHOD
    IVS_CHAR	cNvrCode[IVS_NVR_CODE_LEN];             // NVR���룬����ƽ̨¼���������д����ֶΣ��ڲ�����
    IVS_CHAR	cMBUDomain[IVS_DOMAIN_CODE_LEN];        // ���ݷ���������뱸��¼���������д����ֶ�

	IVS_UINT32	uiRecordType;		                    // ¼�����ͣ��ο� IVS_RECORD_TYPE
    IVS_CHAR    cAlarmType[IVS_QUERY_VALUE_LEN];		// �澯���ͣ�¼������Ϊ�澯¼��ʱ��Ч��Ӣ���ַ�����
	IVS_TIME_SPAN	stTime;                             // ¼����ֹʱ��
	IVS_UINT32	uiFrameExtractionTimes;	                // ¼���֡�������ο� IVS_FRAME_EXTRACTION_TIMES
    
	IVS_RECORD_BOOKMARK_INFO	stBookmarkInfo;         // ¼���ǩ��Ϣ����ѯ��ʽΪ����ǩʱ��Ч
	IVS_RECORD_LOCK_INFO	    stLockInfo;		        // ������Ϣ����ѯ��ʽΪ������״̬ʱ��Ч
	IVS_RECORD_PTZ_PRESET_INFO	stPtzPresetInfo;        // ¼��Ԥ��λ��Ϣ����ѯ��ʽΪ��Ԥ��λ��ѯʱ��Ч
    IVS_CHAR    cReserve[64];                           // �����ֶ�
}IVS_RECORD_INFO;

// ¼����Ϣ�б�
typedef struct
{
	IVS_UINT32   uiTotal;               // �ܼ�¼��
	IVS_INDEX_RANGE stIndexRange;       // ��ҳ��Ϣ
	IVS_CHAR cRes[32];			        //�����ֶ�
	IVS_RECORD_INFO stRecordInfo[1];    // ¼�������Ϣ
}IVS_RECORD_INFO_LIST;

// �˶�����������Ϣ
typedef struct
{
    IVS_CHAR	StartTime[IVS_TIME_LEN];    // ͳ�Ƽ����ʼʱ�䣬���ʱ�׼ʱ��, ֻ��ʱ����
    IVS_CHAR	EndTime[IVS_TIME_LEN];      // ͳ�Ƽ������ʱ�䣬���ʱ�׼ʱ��, ֻ��ʱ����
    IVS_UINT64	uiMotionData;	            // [OUT]�ڲ�ѯʱ����ڰ�ʱ����ͳ�Ƶ��ƶ�����
    IVS_CHAR    cReserve[32];               // �����ֶ�
}IVS_MOTION_RANGE_DATA_INFO;

// �˶����������б�
typedef struct
{
    IVS_TIME_SPAN	stTime;			// [OUT]�˶�����������ֹʱ��
    IVS_UINT32		uiTimeInterval;	// [OUT]�˶���������ͳ��ʱ����

    IVS_UINT32  uiTotal;			// [OUT]�ܼ�¼��
    IVS_INDEX_RANGE stIndexRange;	// [IN]��ҳ��Ϣ
    IVS_MOTION_RANGE_DATA_INFO	stMotionRangeDataInfo[1];	// [OUT]�˶�����������Ϣ���ɶ���
}IVS_MOTION_RANGE_DATA_LIST;

// ͨ���豸���ͣ���ѯ�豸ʱ��ȡ��
typedef enum
{
	DEVICE_TYPE_MAIN=1,		// ���豸
	DEVICE_TYPE_CAMERA,		// ����ͷ�豸
	DEVICE_TYPE_VOICE,		// �����豸
	DEVICE_TYPE_ALARM,	    // �澯�豸��ͬʱ��ȡ�澯���롢�澯�����
    DEVICE_TYPE_SERIAL,	    // �����豸

    DEVICE_TYPE_EXTEND_ALARM=9,   // ����澯�豸
}IVS_DEVICE_TYPE;

// ���豸��̬����
typedef enum
{
	DEVICE_IPC= 1,	// �����
	DEVICE_DVS,		// DVS
	DEVICE_DVR,		// DVR
    DEVICE_ENVR,    // eNVR
}IVS_MAIN_DEVICE_TYPE;

// ���豸��̬����
typedef enum
{
	DEVICE_CAMERA= 1,	// ����ͷ
	DEVICE_ALARM_IN,	// �澯�������豸
	DEVICE_ALARM_OUT,	// �澯������豸
	DEVICE_AUDIO_IN,	// ��Ƶ�������豸
	DEVICE_AUDIO_OUT,	// ��Ƶ������豸
	DEVICE_SERIAL,		// �������豸
}IVS_CHANNEL_TYPE;

// ��������
typedef enum
{
    VENDOR_NONE=0,      // ������
	VENDOR_HUAWEI=1,	// ��Ϊ
	VENDOR_HIKVISION,	// ��������
	VENDOR_DAHUA,		// ��
	VENDOR_AXIS,		// ��Ѷ��
	VENDOR_BOSCH,		// Bosch
	VENDOR_SONY,		// ����
	VENDOR_PANASONIC	// ����
}IVS_VENDOR_TYPE;

// IPCλ����Ϣ
typedef struct
{
    IVS_DOUBLE	dLongitude;             // ��װ����	20	���12λС����-180~180
    IVS_DOUBLE	dLatitude;				// ��װγ��	20	���12λС����-180~180
	IVS_DOUBLE	dHeight;                // ��װ�߶�	5	��λm��0-99.99
	IVS_CHAR	cCameraLocation[IVS_DESCRIBE_LEN];	// �������װλ������
    IVS_CHAR    cReserve[32];                       // �����ֶ�
}IVS_CAMERA_POSITION;

//��������
typedef enum
{
	BITRATE_CBR = 0,	//������
	BITRATE_VBR			//������
}IVS_BITRATE_TYPE;

// �豸�����ַ��Ϣ
typedef struct
{
	IVS_IP		stIPV4;
	IVS_CHAR	cIPV4Gateway[IVS_IP_LEN];	// ipv4����
	IVS_IP		stIPV6;
	IVS_CHAR	cIPV6Gateway[IVS_IP_LEN];	// ipv6����
}IVS_DEV_IP_INFO;

// �豸״̬
typedef enum
{
	DEV_STATUS_OFFLINE= 0,	// ����
	DEV_STATUS_ONLINE,		// ����
	DEV_STATUS_SLEEP,		// ����
}IVS_DEV_STATUS;

// ��Ƶ��ʽ
typedef enum
{
	VIDEO_STANDART_NONE= 0,
	VIDEO_STANDART_PAL,
	VIDEO_STANDART_NTSC,
}IVS_VIDEO_STANDARD;

// �豸ʱ��ͬ����Ϣ
typedef struct
{
	IVS_UINT32	uiNtpType;		// NTPͬ����ʽ��0-DHCP��1-�ֶ�ָ��������

	IVS_IP		stNtpServerIP;	// NTP������IP����NTPͬ����ʽuiNtpTypeΪ1ʱ��Ч
	IVS_IP		stDnsIP;		// DNS��ַ����NTPͬ����ʽuiNtpTypeΪ1ʱ��Ч
	IVS_CHAR	cRes[32];
}IVS_NTP_INFO;

// ���豸�������
typedef struct
{
    IVS_IP		stPUIp;	        // ǰ��IP
	IVS_IP		stPUGateway;	// ǰ������(onvif�豸)
    IVS_UINT32  uiPUPort;       // �豸�˿�
	IVS_UINT32	uiMaxMtu;		// ���MTUֵ
    IVS_IP		stSubNetMask;   // ��������
    IVS_CHAR	cReserve[32];
}IVS_DEVICE_NET_CFG;

// �������ȫ����
typedef struct
{
    IVS_BOOL    bEnableMediaSecurity;       // �Ƿ�����ý�尲ȫ��0-�ر� 1-����
    IVS_BOOL    bEnableSecureStorage;       // �Ƿ����ð�ȫ�洢��0-�ر� 1-����
    IVS_UINT32  uiMediaSecurityAlgorithm;   // ý�尲ȫ�㷨��1-AES256 2-ý������
    IVS_CHAR	cReserve[32];
}IVS_MEDIA_SECURITY_CFG;

// �ɿ���������
typedef enum
{
    RELIABLE_TRANSMISSION_NONE,
    RELIABLE_TRANSMISSION_FEC,
    RELIABLE_TRANSMISSION_ARQ,
    RELIABLE_TRANSMISSION_HARQ,
}IVS_RELIABLE_TRANSMISSION_TYPE;

// �������չ����
typedef struct
{
    IVS_BOOL	bEnableWatermark;	        // �Ƿ�����ˮӡ��0-�ر� 1-����
    IVS_UINT32  uiReliableTransmission;     // �ɿ��������ͣ�ֵ�ο� IVS_RELIABLE_TRANSMISSION_TYPE
    IVS_UINT32  uiFECMatrix;                // �ɿ���������FECģʽ�£�����ģʽ 
    /*
    0:  5x5���� 
    1:  7x7���� 
    2:  8x4���� 
    3:  9x6���� 
    4:  10x4����
    5:  11x4����
    6:  12x6����
    7:  15x5����
    8:  18x6����
    9:  19x5����
    10: 24x7����
    11: 26x6����
    12: 34x1����
    */
    IVS_BOOL    bEnableBandwidthAdaptive;   // �Ƿ����ô�������Ӧ��0-�ر� 1-����
    IVS_BOOL    bEnableCache;               // �Ƿ����û��棺0-�ر� 1-����

    IVS_MEDIA_SECURITY_CFG stMediaSecurityCfg;  // ��ȫ��ز���
    IVS_CHAR	cReserve[32];
}IVS_CAMERA_EXTEND_CFG;

// �����FEC����
typedef struct
{
    IVS_UINT32  uiReliableTransmission;     // �ɿ��������ͣ�ֵ�ο� IVS_RELIABLE_TRANSMISSION_TYPE
    IVS_UINT32  uiDataDropPercent;           // �ɿ���������FECģʽ�£�������    1:  1%������   2:  2%������  3:  3%������   4:  4%������   5:  5%������
    IVS_CHAR	cReserve[32];
}IVS_CAMERA_FEC_CFG;

// �����ץ�Ĳ���
typedef struct
{
    IVS_UINT32  uiSnapCount;    // ץ����������Χ1-5
    IVS_UINT32  uiSnapInterval; // ץ��ʱ��������Χ1-5��
    IVS_CHAR	cReserve[8];
}IVS_CAMERA_SNAPSHOT_CFG;

// �����ǰ��¼����������
typedef struct
{
    IVS_UINT32	uiStreamType;	    // �������ͣ��ο� IVS_STREAM_TYPE
    IVS_CHAR	cReserve[8];
}IVS_CAMERA_RECORD_STREAM_CFG;

// ���豸��չ����
typedef struct
{
	IVS_BOOL	bEnableWatermark;	// �Ƿ�����ˮӡ 0���� 1:�ǣ���Ƶ���豸����
	IVS_BOOL	bEnableEncrypt;		// �Ƿ����ü��� 0: �� 1:�ǣ�
	IVS_BOOL	bEnableCache;		// �Ƿ�֧�ֻ��油¼ 0:�� 1:��
    IVS_CHAR    cReserve[32];       // �����ֶ�
}IVS_DEVICE_EXCFG;

// ���豸ͨ����Ϣ
typedef struct
{
	IVS_UINT32	uiMaxVideoNum;		// �����Ƶͨ����
	IVS_UINT32	uiMaxAudioInNum;	// �����Ƶ����ͨ����
	IVS_UINT32	uiMaxAudioOutNum;	// �����Ƶ���ͨ����
	IVS_UINT32  uiMaxAlarmInNum;	// ���澯����ͨ����
	IVS_UINT32  uiMaxAlarmOutNum;	// ���澯���ͨ����
	IVS_UINT32  uiMaxSerialNum;		// ��󴮿�ͨ����
    IVS_CHAR    cReserve[32];       // �����ֶ�
}IVS_DEVICE_CHANNEL_CFG;

// ���豸ʱ�����
typedef struct
{
    IVS_BOOL	    bEnableNtp;	    // �Ƿ�����NTPͬ����0-�����ã��ֶ�����ʱ�䣩��1-���ã��Զ�ͬ��ʱ�䣩
	IVS_NTP_INFO    stNTP;	        // NTP��Ϣ(�����ӿ�ʵ��) ʱ���������bEnableNtpֵΪ1���Զ�ͬ��ʱ��ʱ��Ч��
	IVS_INT32	    iTimezone;	    // �豸����ʱ������ʱ��ƫ������¼-50400~50400�� ����bEnableNtpֵΪ0���ֶ�����ʱ��ʱ��Ч��
	IVS_BOOL	    bEnableDst;	    // �Ƿ���������ʱ 0:������,1:���� ����bEnableNtpֵΪ0���ֶ�����ʱ��ʱ��Ч��
    IVS_CHAR        cReserve[32];   // �����ֶ�
}IVS_DEVICE_TIME_CFG;

// ͨ���豸��Ϣ��NVR/TAS�������豸 DVR/DVS/IPC��
#define IVS_MAX_VENDOR_TYPE_NAME_LEN    32  // ����������󳤶�
#define IVS_DEVICE_NAME_LEN             128 // ���豸���Ƴ���
typedef struct
{
	IVS_UINT32	uiType;									// ���豸���ͣ��ο� IVS_MAIN_DEVICE_TYPE
	IVS_CHAR	cSerialNumber[IVS_DEV_SERIALNO_LEN];	// ���к�(SN/IMEI)

	IVS_CHAR	cCode[IVS_DEV_CODE_LEN];	        // �豸����
	IVS_CHAR	cName[IVS_DEVICE_NAME_LEN];		    // �豸����

	IVS_CHAR	cParentCode[IVS_DEV_CODE_LEN];	    // ���豸���룬�����Ϊ�գ���ʾͨ��eNVR����
	IVS_CHAR	cDomainCode[IVS_DOMAIN_CODE_LEN];	// �����

    IVS_CHAR	cVendorType[IVS_MAX_VENDOR_TYPE_NAME_LEN];  // �豸�ṩ������: "HUAWEI" "HIK"

	IVS_CHAR	cModel[IVS_DEV_MODEL_LEN];	// �豸�ͺ�

	IVS_IP		stIP;						// �豸IP��Ϣ
	IVS_UINT32	uiPort;						// �豸���Ӷ˿�

	IVS_CHAR	cReserve[32];
}IVS_DEVICE_BASIC_INFO;

// �豸������Ϣ
typedef struct
{
	IVS_CHAR	cCode[IVS_DEV_CODE_LEN];	// �豸����
	IVS_CHAR	cNvrCode[IVS_NVR_CODE_LEN];	// �豸����NVR����, ��ʾ���豸����NVR����	

	IVS_UINT32	uiSequence;	// ���
	IVS_UINT32	uiResult;	// �������

    IVS_CHAR    cReserve[32];   // �����ֶ�
}IVS_DEVICE_OPER_RESULT;

// �豸�����б�
typedef struct
{
    IVS_UINT32	uiNum;
    IVS_DEVICE_OPER_RESULT	stCodeInfo[1];
}IVS_DEVICE_OPER_RESULT_LIST;

// �豸����
typedef struct
{
	IVS_CHAR cDevCode[IVS_DEV_CODE_LEN];	// �豸����
}IVS_DEVICE_CODE;

// ��֤����
typedef enum
{
	LOGINTYPE_NONE= 0,
	LOGINTYPE_HTTP_DIGEST,		// HTTP Digest
	LOGINTYPE_USERNAME_TOKEN,	// WS-Usernametoken Authentication
}IVS_LOGINTYPE;

// ���豸���ò���
#define IVS_MAX_PROTOCOLTYPE_NAME_LEN   64  // Э������������󳤶�
typedef struct
{
	IVS_DEVICE_BASIC_INFO	stDeviceInfo;	        // ���豸������Ϣ
	//
	IVS_CHAR	cProtocolType[IVS_MAX_PROTOCOLTYPE_NAME_LEN];		// ���豸Э������: "TEYES"-ǧ����   "ONVIF"  "HWSDK"-��ΪSDK "HIKSDK"-����SDK

	IVS_UINT32	iLoginType;			                // ��֤���ͣ��ο� IVS_LOGINTYPE ����ΪONVIFʱ��֤���Ϳ����ã���֤���������֣�0:None��1:HTTP Digest��2:WS-Usernametoken Authentication��

	IVS_BOOL	bEnableAlarm;		                // �豸�澯ʹ�� 1-���ã�ON�� 0-ͣ�ã�OFF���ο���IVS_VIDEO_STANDARD
	IVS_UINT32	uiVideoFormat;		                // ��Ƶ��ʽ 1-PAL 2-NTSC

	IVS_UINT32	uiDirectConnectFirst;	            // �Ƿ�ֱ�����ȣ� 0-��ֱ������ 1-ֱ������
	IVS_UINT32	uiMaxDirectConnectNum;	            // ���ֱ����Ŀ

	IVS_BOOL	bEnableSchedule;	                // �Ƿ����ü�Ⱥ���ȣ�0-��, 1-��(NVR CODE ��Ϊ��)
	IVS_CHAR	cNvrCode[IVS_NVR_CODE_LEN];			// �豸����NVR����, ��ʾ���豸����NVR����
	IVS_CHAR	cTasCode[IVS_TAS_CODE_LEN];			// �豸����TAS����, ���Ǳ�ͨ�����������DCG����ʱʹ��
	IVS_IP      stTasIP;                               // TASIP
	IVS_CHAR	cDevUser[IVS_NAME_LEN];				// �豸��¼�û���
	IVS_CHAR	cDevPasswd[IVS_PWD_LEN];		// �豸��¼����
	IVS_CHAR	cDevRegPasswd[IVS_PWD_LEN];	// �豸��ƽ̨ע������

    IVS_DEVICE_CHANNEL_CFG  stDeviceChannel;        // �豸ͨ����Ϣ

	IVS_CHAR	cReserve[32];
}IVS_DEVICE_CFG;

// ���豸������Ϣ
typedef struct
{
	IVS_UINT32	uiSequence;			// �豸��ţ�����Ӳ����ȣ�
	IVS_DEVICE_CFG	stDeviceCfg;	// ���豸���ò���
    IVS_CHAR    cReserve[32];       // �����ֶ�
}IVS_DEVICE_OPER_INFO;

// �������ʾ����
typedef struct
{
    IVS_UINT32	uiBrightness;	// ���ȣ���Χ��0-255
    IVS_UINT32	uiContrast;		// �Աȶȣ���Χ��0-255
    IVS_UINT32	uiHue;			// ɫ�ȣ���Χ��0-255
    IVS_UINT32	uiSaturation;	// ���Ͷȣ���Χ��0-255
    IVS_CHAR    cReserve[32];   // �����ֶ�
}IVS_CAMERA_DISPLAY_CFG;

// ���ⲹ������
typedef struct
{
    IVS_UINT32  uiBacklightMode;    // ���ⲹ��ģʽ 0-�رգ�1-����
    IVS_UINT32  uiBacklightLevel;   // ���ⲹ���ȼ� 0-3
    IVS_CHAR    cReserve[32];       // �����ֶ�
}IVS_BACKLIGHT;

// �ع����
typedef struct
{
    IVS_UINT32  uiExposureMode;     // �ع�ģʽ 0-�Զ���1-�ֶ�
    IVS_UINT32  uiExposurePriority; // �ع�����ģʽ 0-�������ȣ�1-֡������
    IVS_RECT_FLOAT    rectWindow;   // �عⴰ��
    IVS_UINT32  uiExposureTime;     // �ع�ʱ�䣨��λ΢��us��
    IVS_UINT32  uiExposureGain;     // �ع����棨��λdB��
    IVS_UINT32  uiExposureIris;     // ��Ȧ
    IVS_CHAR    cReserve[32];       // �����ֶ�
}IVS_EXPOSURE;

// �佹����
typedef struct
{
    IVS_UINT32  uiFocusMode;        // �佹ģʽ 0-�Զ���1-�ֶ�
    IVS_UINT32  uiFocusSpeed;       // �佹�ٶ�
    IVS_UINT32  uiNearLimit;        // ��С�佹��Χ
    IVS_UINT32  uiFarLimit;         // ���佹��Χ
    IVS_CHAR    cReserve[32];       // �����ֶ�
}IVS_FOCUS;

// ��̬����
typedef struct
{
    IVS_UINT32  uiWideDynamicMode;  // ��̬ģʽ 0-�رգ�1-����
    IVS_UINT32  uiWideDynamicLevel; // ��̬�ȼ� 0-20
    IVS_CHAR    cReserve[32];       // �����ֶ�
}IVS_WIDE_DYNAMIC;

// ��ƽ�����
typedef struct
{
    IVS_UINT32  uiWhiteBalanceMode; // ��ƽ��ģʽ 0-�Զ���1-�ֶ�
    IVS_UINT32  uiCrGain;           // ��ɫ����
    IVS_UINT32  uiCbGain;           // ��ɫ����
    IVS_CHAR    cReserve[32];       // �����ֶ�
}IVS_WHITE_BALANCE;

// ����������
typedef struct
{
    IVS_UINT32	uiStabilizationMode;	// ������ģʽ 0-�رգ�1-�򿪣�2-�Զ���3-��չ
    IVS_UINT32	uiStabilizationLevel;   // �������ȼ�
    IVS_CHAR    cReserve[32];           // �����ֶ�
}IVS_STABILIZATION;

// �����ͼ�����
typedef struct
{
    IVS_BACKLIGHT       stBacklight;        // ����
    IVS_EXPOSURE        stExposure;         // �ع�
    IVS_FOCUS           stFocus;            // �佹
    IVS_WIDE_DYNAMIC    stWideDynamic;      // ��̬
    IVS_WHITE_BALANCE   stWhiteBalance;     // ��ƽ��
    IVS_STABILIZATION   stStabilization;    // ������
    IVS_UINT32          uiIrCutFilter;      // ������� 0-�رգ�1-�򿪣�2-�Զ�
    IVS_UINT32          uiSharpness;        // ���
    IVS_CHAR            cReserve[32];       // �����ֶ�
}IVS_CAMERA_IMAGING_CFG;

// ǰ��OSDʱ��
typedef struct
{
    IVS_BOOL	bEnableOSDTime;     // �Ƿ���ʾʱ�䣺0-����ʾ��1-��ʾ
    IVS_UINT32	uiTimeFormat;       // ʱ����ʾ��ʽ����1: XXXX-XX-XX XX:XX:XX(��2009-09-09 09:09:09), 2: XXXX��XX��XX�� XX :XX :XX(2009��09��09�� 09 :09 :09��3: UTCʱ��
    IVS_FLOAT   fTimeX;             // ʱ��X���꣬�����Ͻ�Ϊԭ��
    IVS_FLOAT   fTimeY;             // ʱ��Y���꣬�����Ͻ�Ϊԭ��
    IVS_CHAR    cReserve[32];       // �����ֶ�
}IVS_OSD_TIME;

// ǰ��OSD����
#define IVS_MAX_OSD_TEXT_LEN	256 // OSD��������ֽ���
typedef struct
{
    IVS_BOOL	bEnableOSDName;                     // �Ƿ���ʾ���֣�0-����ʾ��1-��ʾ
    IVS_CHAR	cOSDNameText[IVS_MAX_OSD_TEXT_LEN]; // ��������
    IVS_RECT_FLOAT    rectText;                     // ��������

    IVS_BOOL	bEnableSwitch;		                // �Ƿ�����ʾ��0-�����棬1-����
    IVS_UINT32	uiSwitchInterval;                   // ������ʾʱ��������λΪ��

    IVS_BOOL	bEnableTextBlink;		            // �Ƿ�������˸��0-����˸��1-��˸
    IVS_BOOL	bEnableTextTranslucent;	            // �Ƿ�����͸����0-��͸����1-͸��
    IVS_UINT32	uiTextTranslucentPercent;           // ����͸���ȣ�0-100

    IVS_CHAR	cReserve[64];
}IVS_OSD_NAME;

// �����OSD����
typedef struct
{
    IVS_BOOL        bEnableOSD; // �Ƿ����ã�0-ͣ�� 1-����
    IVS_OSD_TIME    stOSDTime;  // OSDʱ����Ϣ
    IVS_OSD_NAME    stOSDName;  // OSD������Ϣ

    IVS_CHAR	cReserve[32];
}IVS_CAMERA_OSD_CFG;

// �˶����
#define IVS_MAX_MOTION_DETECTION_AREA_NUM   8   // �˶�����������
typedef struct
{
    IVS_BOOL    bMotionDetectionEnable;     // �豸�˶����澯ʹ�� 0-ͣ���˶���� 1-�����˶����
    IVS_BOOL    bPlatformMotionDetection;   // ƽ̨�˶����澯ʹ�� 0-ͣ���˶���� 1-�����˶����

    IVS_UINT32  uiDetectInterval;       // �˶�����ʱ�������ڸü���ڵ��˶�����Ϊͬһ���˶���ȡֵ��Χ��1~30�� ��λ:�� Ĭ��Ϊ��10��
    IVS_UINT32  uiSensitivity;          // �˶����������ȣ�����5����1-5������Խ�߱�ʾ������Խ��
    IVS_UINT32  uiAutoClearAlarmTime;   // �澯���ʱ����1-255����λ���롣Ĭ��Ϊ120�룬��ÿ��120����һ���Ƿ��ڸ澯״̬�����ϱ�

    IVS_UINT32  uiRectNum;              // ��Ч������Ϣ�ĸ���
    IVS_RECT_FLOAT    rectDetection[IVS_MAX_MOTION_DETECTION_AREA_NUM];   // �˶���������б�
        
    IVS_CHAR	cReserve[32];
}IVS_MOTION_DETECTION;

// ͼ���ڵ�
#define IVS_MAX_VIDEO_HIDE_AREA_NUM 5   // ���ͼ���ڵ��澯�������
#define IVS_MAX_VIDEO_HIDE_GUARD_TIME_NUM   12  // �����Ƶ�ڵ�����ʱ��θ���
typedef struct
{
    IVS_BOOL    bEnableVideoHide;       // 0-�ر���Ƶ�ڵ��澯��1-������Ƶ�ڵ��澯
    IVS_UINT32  uiSensitivity;          // ͼ���ڵ����������ȣ�����5����1-5������Խ�߱�ʾ������Խ��
    IVS_UINT32  uiAutoClearAlarmTime;   // �澯���ʱ����1-255����λ���롣Ĭ��Ϊ120�룬��ÿ��120����һ���Ƿ��ڸ澯״̬�����ϱ�

    IVS_UINT32  uiGuardTimeNum;                                         // ʵ�ʸ澯ʱ�����
    IVS_TIME_SPAN   stGuardTime[IVS_MAX_VIDEO_HIDE_GUARD_TIME_NUM];     // ��Ƶ�ڵ�����ʱ���

    IVS_UINT32  uiAreaNum;                              // ʵ�����õ�ͼ���ڵ��澯�������
    IVS_RECT_FLOAT    rectArea[IVS_MAX_VIDEO_HIDE_AREA_NUM];  // ͼ���ڵ��澯��������

    IVS_CHAR	cReserve[32];
}IVS_VIDEO_HIDE_ALARM;

// ��˽����
#define IVS_MAX_VIDEO_MASK_AREA_NUM 5   // �����˽�����������
typedef struct
{
    IVS_BOOL    bEnableVideoMask;       // 0-�ر���˽������1-������˽����

    IVS_UINT32  uiAreaNum;                              // ʵ�����õ�ͼ���ڵ��澯�������
    IVS_RECT_FLOAT    rectArea[IVS_MAX_VIDEO_MASK_AREA_NUM];  // ͼ���ڵ��澯��������

    IVS_CHAR	cReserve[32];
}IVS_VIDEO_MASK;

// �澯�������豸
#define IVS_ALARM_IN_NAME_LEN   260      // �澯�������豸���Ƴ���
typedef struct
{
    IVS_CHAR    cAlarmInName[IVS_ALARM_IN_NAME_LEN];    // �澯�����豸���ƣ����ֺ���ĸ��a-z��A-Z�������֣��л��ߺ��»��ߣ�1~20���ַ���
    IVS_UINT32  uiAlarmInChanIndex;                     // �澯����ͨ������
    IVS_UINT32  uiSwitchType;                           // �豸�������� 0-���� 1-���� 
    IVS_UINT32  uiAutoClearAlarmTime;                   // �澯���ʱ����1-255����λ���롣Ĭ��Ϊ120�룬��ÿ��120����һ���Ƿ��ڸ澯״̬�����ϱ������֡�

    IVS_CHAR	cReserve[32];
}IVS_ALARM_IN_CFG;

// �澯������豸
#define IVS_ALARM_OUT_NAME_LEN   128      // �澯������豸���Ƴ���
typedef struct
{
    IVS_CHAR    cAlarmOutName[IVS_ALARM_OUT_NAME_LEN];  // �澯����豸���ƣ����ֺ���ĸ��a-z��A-Z�������֣��л��ߺ��»��ߣ�1~20���ַ���
    IVS_UINT32  uiAlarmOutChanIndex;                    // �澯���ͨ������
    IVS_UINT32  uiSwitchType;                           // �豸�������� 0-���� 1-����
    IVS_UINT32  uiAlarmOutMode;                         // �澯���ģʽ��0-����̬��1-˫��̬    
    IVS_UINT32  uiHoldTime;                             // �ӳ�ʱ�䣬1��~600�룻Ĭ�ϣ�10�루����̬ʱ��Ч��

    IVS_CHAR	cReserve[32];
}IVS_ALARM_OUT_CFG;

typedef struct
{
    IVS_UINT32  uiPitch;        // ����
    IVS_UINT32  uiVolume;       // ����
    IVS_UINT32  uiInputType;    // ��������
    IVS_UINT32  uiDataFormat;   // ���ݸ�ʽ���ο� IVS_PAYLOAD_TYPE
    IVS_UINT32  uiSampleRate;   // ������
    IVS_UINT32  uiChannel;      // Ƶ��
    IVS_UINT32  uiGain;         // ����
    IVS_UINT32  uiSampleBits;   // ������

    IVS_CHAR	cReserve[32];
}IVS_AUDIO_PARAM;

// ��Ƶ���豸����
#define IVS_AUDIO_NAME_LEN   128      // ��Ƶ���豸���Ƴ���
typedef struct
{
    IVS_CHAR    cAudioName[IVS_AUDIO_NAME_LEN];     // ����ͨ�����ƣ����ֺ���ĸ��a-z��A-Z�������֣��л��ߺ��»��ߣ�1~20���ַ���
    IVS_UINT32  uiChannelType;                      // ͨ������ 0-�������� 1-�������
    IVS_UINT32  uiAudioIndex;                       // ����ͨ����������������

    IVS_AUDIO_PARAM stAudioParam;                   // ��Ƶ����

    IVS_CHAR	cReserve[32];
}IVS_AUDIO_CFG;

// �����豸��Ϣ
typedef struct
{
	IVS_CHAR	cDevGroupCode[IVS_DEVICE_GROUP_LEN];           // �豸�����
    IVS_CHAR    cAudioCode[IVS_DEV_CODE_LEN];       // ����ͨ�����볤��
    IVS_CHAR	cDomainCode[IVS_DOMAIN_CODE_LEN];	// ���������
    IVS_CHAR    cAudioName[IVS_AUDIO_NAME_LEN];     // ����ͨ�����ƣ����ֺ���ĸ��a-z��A-Z�������֣��л��ߺ��»��ߣ�1~20���ַ���
    IVS_UINT32  uiChannelType;                      // ͨ������ 0-�������� 1-�������

    IVS_CHAR	cReserve[32];
}IVS_AUDIO_BRIEF_INFO;

// �����豸�б���Ϣ
typedef struct
{
    IVS_UINT32   uiTotal;           // �ܼ�¼��
    IVS_INDEX_RANGE stIndexRange;   // ��ҳ��Ϣ
    IVS_CHAR cRes[32];              //�����ֶ�
    IVS_AUDIO_BRIEF_INFO stAudioBriefInfo[1];  // �����豸�б���Ϣ
}IVS_AUDIO_BRIEF_INFO_LIST;

// �澯�豸��Ϣ
#define IVS_AUDIO_CODE_LEN  64      // ����ͨ�����볤��
typedef struct
{
    //IVS_UINT32	uiDevGroupID;                       // �豸��ID
    IVS_CHAR	cDevGroupCode[IVS_DEVICE_GROUP_LEN];// �����豸�����
    IVS_CHAR    cAlarmCode[IVS_DEV_CODE_LEN];       // �澯�豸����
    IVS_CHAR	cDomainCode[IVS_DOMAIN_CODE_LEN];	// ���������
    IVS_CHAR    cAlarmName[IVS_ALARM_IN_NAME_LEN];  // ����ͨ�����ƣ����ֺ���ĸ��a-z��A-Z�������֣��л��ߺ��»��ߣ�1~20���ַ���
    IVS_UINT32  uiChannelType;                      // ͨ������ 0-�澯���� 1-�澯���
    IVS_CHAR    cParentCode[IVS_DEV_CODE_LEN];      // ���豸����
    IVS_BOOL	bIsExDomain;                        // �Ƿ�Ϊ�ⲿ�� 0-��  1-��

    IVS_CHAR	cReserve[32];
}IVS_ALARM_BRIEF_INFO;

// �澯�豸�б���Ϣ
typedef struct
{
    IVS_UINT32   uiTotal;           // �ܼ�¼��
    IVS_INDEX_RANGE stIndexRange;   // ��ҳ��Ϣ
    IVS_CHAR cRes[32];              //�����ֶ�
    IVS_ALARM_BRIEF_INFO stAlarmBriefInfo[1];  // �����豸�б���Ϣ
}IVS_ALARM_BRIEF_INFO_LIST;

typedef enum
{
    CONFIG_DEVICE_CFG=1,                    // ���豸�������� IVS_DEVICE_CFG
    CONFIG_DEVICE_NET_CFG,                  // ���豸������� IVS_DEVICE_NET_CFG
    CONFIG_DEVICE_TIME_CFG,                 // ���豸ʱ�������NTP��ʱ����IVS_DEVICE_TIME_CFG

    CONFIG_CAMERA_CFG,                      // ����������������� IVS_CAMERA_CFG
    CONFIG_CAMERA_STREAM_CFG,               // ����������������� IVS_CAMERA_STREAM_CFG
    CONFIG_CAMERA_DISPLAY_CFG,              // �����������ʾ�������� IVS_CAMERA_DISPLAY_CFG
    CONFIG_CAMERA_IMAGING_CFG,              // �����ͼ��������� IVS_CAMERA_IMAGING_CFG
    CONFIG_CAMERA_OSD_CFG,                  // �����OSD�������� IVS_CAMERA_OSD_CFG
    CONFIG_CAMERA_MOTION_DETECTION_CFG,     // ������˶����������� IVS_MOTION_DETECTION
    CONFIG_CAMERA_VIDEO_HIDE_ALARM_CFG,     // ������ڵ��澯�������� IVS_VIDEO_HIDE_ALARM
    CONFIG_CAMERA_VIDEO_MASK_CFG,           // �������˽������������ IVS_VIDEO_MASK
    CONFIG_CAMERA_AUDIO_CFG,                // �������Ƶ�������� IVS_AUDIO_CFG
    
    CONFIG_SERIAL_CHANNEL_CFG,              // ��������ڲ������� IVS_SERIAL_CHANNEL_CFG
    CONFIG_ALARM_IN_CFG,                    // �澯�������豸���� IVS_ALARM_IN_CFG
    CONFIG_ALARM_OUT_CFG,                   // �澯������豸���� IVS_ALARM_OUT_CFG
    
    CONFIG_DEVICE_PTZ_CFG,                  // ��̨�������� IVS_PTZ_CFG
    CONFIG_CAMERA_EXTEND_CFG,               // �������չ�������� IVS_CAMERA_EXTEND_CFG

    CONFIG_CAMERA_SNAPSHOT_CFG,             // �����ץ�Ĳ������� IVS_CAMERA_SNAPSHOT_CFG
    CONFIG_CAMERA_RECORD_STREAM_CFG,        // �����ǰ��¼���������� IVS_CAMERA_RECORD_STREAM_CFG
	CONFIG_CAMERA_FEC_CFG,                  // �����FEC���� IVS_CAMERA_FEC_CFG
}IVS_CONFIG_TYPE;

typedef enum
{
    DEVICE_ENCODE_CAPABILITY=1,             // �������������
}IVS_DEVICE_CAPABILITY_TYPE;

// ���������Э��
typedef enum
{
    DEVICE_PRO_TEYES = 0,	// ǧ����
    DEVICE_PRO_ONVIF,		// ONVIF
    DEVICE_PRO_HUAWEI,		// ��ΪSDK
    DEVICE_PRO_HIK,			// ����SDK
	DEVICE_PRO_T28181,		// T28181
    DEVICE_PRO_DHSDK		// DHSDK
}IVS_DEVICE_PROTOCOL;

// ��ѯ���豸�б���Ϣ��NVR/TAS�������豸 DVR/DVS/IPC��
typedef struct
{
	IVS_DEVICE_BASIC_INFO	stDeviceInfo;	// ���豸������Ϣ

    IVS_CHAR	cProtocolType[IVS_MAX_PROTOCOLTYPE_NAME_LEN];		// ���豸Э������: "TEYES"-ǧ����   "ONVIF"  "HWSDK"-��ΪSDK "HIKSDK"-����SDK

    IVS_UINT32	iLoginType;			// ��֤���ͣ��ο� IVS_LOGINTYPE ����ΪONVIFʱ��֤���Ϳ����ã���֤���������֣�0:None��1:HTTP Digest��2:WS-Usernametoken Authentication��

	IVS_BOOL	bEnableSchedule;	// �Ƿ����ü�Ⱥ���ȣ�0-��, 1-��(NVR CODE ��Ϊ��)
	IVS_UINT32	uiStatus;			// �豸״̬��0-���ߣ�1-���ߣ�2-���� �ο� IVS_DEV_STATUS

	IVS_CHAR	cReserve[32];
}IVS_DEVICE_BRIEF_INFO;

typedef struct
{
	IVS_UINT32   uiTotal;           // �ܼ�¼��
	IVS_INDEX_RANGE stIndexRange;   // ��ҳ��Ϣ
	IVS_CHAR cRes[32];              //�����ֶ�
	IVS_DEVICE_BRIEF_INFO stDeviceBriefInfo[1];  // ���豸�б���Ϣ
}IVS_DEVICE_BRIEF_INFO_LIST;

// ���豸��ϸ��Ϣ��DVR/DVS/IPC��
typedef struct
{
	IVS_DEVICE_CFG	stDeviceCfg;            // ���豸����
	IVS_DEVICE_EXCFG	stDeviceExCfg;	    // ���豸��չ���� 
	IVS_DEVICE_NET_CFG	stDeviceNetCfg;	    // ���豸�������
	IVS_DEVICE_CHANNEL_CFG	stChannelInfo;	// ͨ��������
	IVS_DEVICE_TIME_CFG	stTimeInfo;	        // ʱ�������NTP��ʱ����

	IVS_UINT32	uiStatus;			        // �豸״̬��0-���ߣ�1-���ߣ�2-���� �ο� IVS_DEV_STATUS

	IVS_CHAR	cReserve[32];
}IVS_DEVICE_INFO;

#define IVS_MAX_DEV_GROUP_NUM   5000    // ����豸����Ŀ
// �豸��
typedef struct
{
	IVS_UINT32	uiID;					// �豸��ID
	IVS_CHAR	cName[IVS_NAME_LEN];	// �豸������
	IVS_UINT32	uiParentID;				// ���豸��ID
	IVS_CHAR	cDomainCode[IVS_DOMAIN_CODE_LEN];	// �����
    IVS_CHAR	cReserve[32];
}IVS_DEV_GROUP;

typedef struct
{
    IVS_CHAR	cGroupCode[IVS_DEVICE_GROUP_LEN];           // �豸�����
    IVS_CHAR	cGroupName[IVS_NAME_LEN];	                // �豸������
    //IVS_UINT32	uiParentGroupID;                    // ���豸��ID
    IVS_CHAR	cParentGroupCode[IVS_DEVICE_GROUP_LEN];     // ���豸�����
    IVS_CHAR	cDomainCode[IVS_DOMAIN_CODE_LEN];	        // �����
    IVS_BOOL	bIsExDomain;	                            // �Ƿ��ⲿ���豸/��   0����1����
    IVS_CHAR	cReserve[32];
}IVS_DEVICE_GROUP;

// �豸���б�
typedef struct
{
    IVS_UINT32          uiTotal;				// �ܼ�¼��
    IVS_INDEX_RANGE     stIndexRange;			// ��ҳ��Ϣ
    IVS_DEVICE_GROUP    stDeviceGroup[1];		// �û��豸����Ϣ�б�
}IVS_DEVICE_GROUP_LIST;

// �豸���б�
typedef struct
{
	IVS_UINT32   uiTotal;				// �ܼ�¼��
	IVS_INDEX_RANGE stIndexRange;       // ��ҳ��Ϣ
	IVS_DEV_GROUP stDeviceGroup[1];		// �û��豸����Ϣ�б�
}IVS_DEV_GROUP_LIST;

// �豸������ͷ��Ϣ(�����ʹ��)
typedef struct
{
	IVS_CHAR	cCameraCode[IVS_DEV_CODE_LEN];          // ����ͷ����
	IVS_CHAR	cCameraDomainCode[IVS_DOMAIN_CODE_LEN];    // ����ͷ���������

	IVS_UINT32	uiDevGroupID;					// ����ͷ�����豸��ID
	//	IVS_CHAR	cDevGroupDomainCode[IVS_DOMAIN_CODE_LEN];	// �豸�����������
	IVS_CHAR	cReserve[64];
}IVS_DEV_GROUP_CAMERA;

// �豸��
typedef struct
{
	IVS_UINT32   uiTotal;				// �ܼ�¼��
	IVS_INDEX_RANGE stIndexRange;			// ��ҳ��Ϣ
	IVS_DEV_GROUP_CAMERA stDevGroupCamera[1];		// �豸������ͷ��Ϣ�б�
}IVS_DEV_GROUP_CAMERA_LIST;

// Ŀ���豸����Ϣ
typedef struct
{
	IVS_UINT32	uiID;                               // Ŀ���豸��ID
	IVS_CHAR	cDomainCode[IVS_DOMAIN_CODE_LEN];	// Ŀ�������
    IVS_CHAR	cReserve[32];
}IVS_TARGET_DEV_GROUP;

// �鲥��Ϣ
typedef struct
{
	IVS_IP		stIP;	// �鲥IP��ַ
	IVS_UINT32	uiPort;	// �鲥�˿�
	IVS_UINT32	uiTTL;  // (Time To Live ) ����ʱ��
    IVS_CHAR	cReserve[32];
}IVS_BROADCAST_INFO;

// ��̨����
typedef struct ST_PTZ_PARA
{
	IVS_UINT32  uiDecoderType;                          // ��̨����������
	IVS_UINT32  uiDecoderAddress;                       // ��̨��������ַ(1,2...) ����󳤶�4��������
	IVS_BOOL    bPosNegDirectControl;                   // ��������ƣ�ȡֵ��Χ��0-���� 1-����
	IVS_CHAR    cSerialCode[IVS_DEV_SERIALNO_LEN];      // ���ڱ���

	IVS_CHAR	cReserve[32];
}IVS_PTZ_CFG;

// ��̨���Ʒ�����Ϣ�ṹ��
typedef struct
{    
    IVS_UINT32  uiLockStatus;              // ��̨����״̬��0-������1-����    
    IVS_UINT32	uiUserID;			       // �û�ID    
    IVS_CHAR	cUserName[IVS_NAME_LEN];   // �û���¼�˺�    
    IVS_IP	    stIP;			           // ��¼�Ŀͻ���IP    
    IVS_UINT32  uiReleaseTimeRemain;       // �ͷ�ʱ��������Ϊ��λ    
    IVS_CHAR	cReserve[32];
}IVS_PTZ_CONTROL_INFO;

typedef enum
{
    IMAGING_QUALITY_HIGH=0,     // ͼ�������ߣ�Ĭ��ֵ
    IMAGING_QUALITY_MIDDLE=1,   // ͼ��������
    IMAGING_QUALITY_LOW=2,      // ͼ��������
}IVS_IMAGING_QUALITY;

// �ֱ���
#define IVS_RESOLUTION_LEN  	16	// �ֱ����ַ�������

// ��Ƶ����Ϣ
typedef struct
{
	IVS_UINT32	uiStreamType;	    // �������ͣ��ο� IVS_STREAM_TYPE
	IVS_UINT32	uiEncodeType;	    // �����ʽ���ο� IVS_VIDEO_DEC_TYPE
    IVS_UINT32	uiProfile;          // ����uiEncodeTypeȷ���������H.264���ο�IVS_H264_PROFILE�������MJPEG���ο�IVS_MJPEG_PROFILE
    IVS_UINT32	uiFrameInterval;	// I֡���
    IVS_CHAR	cResolution[IVS_RESOLUTION_LEN];    // �ֱ��ʣ��硰177*144��

    IVS_UINT32	uiPicQuality;	    // ͼ������ ��0-�� 1-�� 2-�ͣ� IVS_IMAGING_QUALITY

    IVS_UINT32	uiTransProtocol;    // ����Э�飺�ο� IVS_PROTOCOL_TYPE
    IVS_UINT32	uiPktProtocol;      // ���Э�飺�ο� IVS_PACK_PROTOCOL_TYPE
	IVS_UINT32	uiBitRateType;	    // �������ͣ��ο� IVS_BITRATE_TYPE
	IVS_UINT32	uiBitRate;		    // ���ʣ���λ(kbps)
	IVS_UINT32  uiFrameRate;		// ֡�ʣ���λ(fps)����Χ1-60

	IVS_CHAR	cReserve[32];
}IVS_STREAM_INFO;

// ��Ƶ���豸���ò���
#define IVS_MAX_STREAM_NUM	8
#define IVS_CAMERA_NAME_LEN 192 // ��������Ƴ���
typedef struct
{
    IVS_UINT32	uiVideoChannel;	                // ��Ƶ����ͨ����

	IVS_CHAR    cCameraCode[IVS_DEV_CODE_LEN];	// �豸����
	IVS_CHAR    cCameraName[IVS_CAMERA_NAME_LEN];		// ���������

	IVS_CAMERA_POSITION	stPosition;	            // ����ͷλ����Ϣ

	IVS_BOOL	bSupportBroadcast;		        // �Ƿ�֧���鲥 0: �� 1:��
	IVS_BROADCAST_INFO	stBroadcast;	        // �鲥��Ϣ

	IVS_BOOL	bEnableVoice;	                    // ��·��Ƶ�Ƿ�����	0-ͣ�� 1-����
    IVS_CHAR    cVoiceOutCode[IVS_DEV_CODE_LEN];    // ������󶨵���Ƶ���ͨ����ֻ��Ϊͬ���豸�ϵ���Ƶ���ͨ����

    // ���û��޸���Ϣ
    IVS_CHAR    cParentCode[IVS_DEV_CODE_LEN];  // ���豸����
    IVS_CHAR	cNvrCode[IVS_NVR_CODE_LEN];     // �豸����NVR����, ��ʾ���豸����NVR����

    IVS_UINT32	uiCameraType;	                // ��������� IVS_CAMERA_TYPE
    IVS_UINT32	uiCameraStatus;		            // �������չ״̬��1 �C ����	2 �C ��Ƶ��ʧ

	IVS_CHAR	cReserve[32];
}IVS_CAMERA_CFG;

// �����������Ϣ
typedef struct
{
    IVS_UINT32		uiStreamInfoNum;	// ��Ч��Ƶ����Ϣ��Ŀ
    IVS_STREAM_INFO	stStreamInfo[IVS_MAX_STREAM_NUM];	// ��Ƶ����Ϣ

    IVS_CHAR	cReserve[32];
}IVS_CAMERA_STREAM_CFG;

typedef enum
{
    CAMERA_FIX=0,       // �̶�ǹ�� 
    CAMERA_PTZ,         // ����̨ǹ�� 
    CAMERA_DOME,        // ���
    CAMERA_FIX_DOME,    // ����-�̶������
}IVS_CAMERA_TYPE;

// ��������
typedef enum
{
    SERIAL_RS232=0, // RS232
    SERIAL_RS485=1, // RS485
    SERIAL_RS422=2  // RS422
}IVS_SERIAL_TYPE;

// У������
typedef enum
{
    PARITY_TYPE_NONE=0,     // ��У��
    PARITY_TYPE_ODD=1,      // ��У��
    PARITY_TYPE_EVEN=2,     // żУ��
    PARITY_TYPE_MARK=3,     // ���У��
    PARITY_TYPE_SPACE=4,    // ��У��
}IVS_PARITY_TYPE;

// ��������
typedef enum
{
    FLOW_CONTROL_NONE=0,    // ������
    FLOW_CONTROL_SOFT=1,    // ������
    FLOW_CONTROL_HARD=2,    // Ӳ����
}IVS_FLOW_CONTROL_TYPE;

// �������豸��Ϣ
#define IVS_SERIAL_NAME_LEN 128  // �����豸���Ƴ���
typedef struct
{
    IVS_CHAR cSerialName[IVS_SERIAL_NAME_LEN];  // �����豸���ƣ����ֺ���ĸ��a-z��A-Z�������֣��л��ߺ��»��ߣ�1~20���ַ���
    IVS_UINT32  uiSerialIndex;                  // ��������
    IVS_UINT32  uiSerialType;                   // �������ͣ�ֵ�ο� IVS_SERIAL_TYPE
    IVS_UINT32  uiBaudRate;                     // ������(bps) (50, 75, 110, 150, 300, 600, 1200, 2400, 4800, 9600, 19200 38400, 57600, 115200)
    IVS_UINT32  uiDataBit;                      // ����λ ��5��6��7��8��
    IVS_UINT32  uiParity;                       // У�飬ֵ�ο�IVS_PARITY_TYPE��0����У�飬1����У�飬2��żУ�飬3: ���У�飬4:��У�飩
    IVS_UINT32  uiStopBit;                      // ֹͣλ ��1��2��
    IVS_UINT32  uiFlowControl;                  // ���أ�ֵ�ο� IVS_FLOW_CONTROL_TYPE

    IVS_CHAR	cReserve[32];
}IVS_SERIAL_CHANNEL_CFG;

// ���豸���豸ͨ������ѯ��
#define IVS_MAX_DEVICE_CHANNEL_NUM  256 //  �豸ͨ�������Ŀ
#define IVS_CHANNEL_NAME_LEN  128 //  ͨ�����Ƴ���
typedef struct
{
	IVS_CHAR	cChannelCode[IVS_DEV_CODE_LEN];	// ���豸����
	IVS_UINT32	uiChannelType;		            // ͨ�����ͣ��ο� IVS_CHANNEL_TYPE
    IVS_CHAR	cChannelName[IVS_CHANNEL_NAME_LEN];	// ͨ������
	IVS_CHAR	cReserve[32];
}IVS_DEV_CHANNEL_BRIEF_INFO;

// ���豸���豸�б�
typedef struct
{
    IVS_UINT32   uiTotal;				        // �ܼ�¼��
    IVS_INDEX_RANGE stIndexRange;			    // ��ҳ��Ϣ
    IVS_DEV_CHANNEL_BRIEF_INFO stDevChannelBriefInfo[1];   // ���豸���豸�б�
}IVS_DEV_CHANNEL_BRIEF_INFO_LIST;

// �û����豸��Ϣ
typedef struct
{
//	IVS_UINT32	uiDevGroupID;                               // �豸��ID
    IVS_CHAR	cDevGroupCode[IVS_DEVICE_GROUP_LEN];        // �豸�����
	IVS_CHAR	cDevGroupDomainCode[IVS_DOMAIN_CODE_LEN];	// �豸�������
    IVS_CHAR	cDevCode[IVS_DEV_CODE_LEN];	                // �豸����
    IVS_CHAR	cDevDomainCode[IVS_DOMAIN_CODE_LEN];	    // �豸�����
    IVS_BOOL	bIsExDomain;	                            // �Ƿ��ⲿ���豸/��   0����1����
	IVS_BOOL	bIsTotalGroup;	// 0���󶨵����豸���е��豸	1���������豸�飨�豸�����ݺ��Զ����������豸������ʱ��DevCode��DomainCode��ChanelTypeΪ��

    IVS_CHAR	cReserve[64];
}IVS_USER_DEVICE_INFO;

// �û����豸��Ϣ�б�
typedef struct
{
	IVS_UINT32   uiTotal;				        // �ܼ�¼��
	IVS_INDEX_RANGE stIndexRange;			    // ��ҳ��Ϣ
	IVS_USER_DEVICE_INFO stUserDeviceInfo[1];   // �û����豸��Ϣ�б�
}IVS_USER_DEVICE_INFO_LIST;

// �û����豸��Ϣ�б�
typedef enum
{
    NET_TYPE_LAN = 0,   // ����
    NET_TYPE_WAN = 1,   // ����
}IVS_NET_TYPE;

// ��Ƶ���豸�б��Ҫ��Ϣ����ѯ��Ƶ���豸�б�
typedef struct
{
	IVS_CHAR	cCode[IVS_DEV_CODE_LEN];	    // �豸����
	IVS_CHAR	cName[IVS_CAMERA_NAME_LEN];		// ���������

    IVS_CHAR	cDevGroupCode[IVS_DEVICE_GROUP_LEN];// �����豸�����
	IVS_CHAR	cParentCode[IVS_DEV_CODE_LEN];	    // ���豸����
	IVS_CHAR	cDomainCode[IVS_DOMAIN_CODE_LEN];	// �����
    IVS_CHAR	cDevModelType[IVS_DEV_MODEL_LEN];	// ���豸�ͺ�

    IVS_CHAR	cVendorType[IVS_MAX_VENDOR_TYPE_NAME_LEN];  // �豸�ṩ������: "HUAWEI" "HIK" "DAHUA"
    IVS_UINT32	uiDevFormType;                              // ���豸���ͣ��ο� IVS_MAIN_DEVICE_TYPE

	IVS_UINT32	uiType;								// ��������� IVS_CAMERA_TYPE
	IVS_CHAR	cCameraLocation[IVS_DESCRIBE_LEN];	// �������װλ������
	IVS_UINT32	uiCameraStatus;		                // �������չ״̬��1 �C ����	2 �C ��Ƶ��ʧ

	IVS_UINT32	uiStatus;			                // �豸״̬��0-���ߣ�1-���ߣ�2-���� �ο� IVS_DEV_STATUS

    IVS_UINT32  uiNetType;                          // �������� 0-����  1-����, �ο� IVS_NET_TYPE
    IVS_BOOL    bSupportIntelligent;                // �Ƿ�֧�����ܷ���  0-��֧�� 1-֧��

	IVS_BOOL	bEnableVoice;		                // ��·��Ƶ�Ƿ�����	0-ͣ�� 1-����
	IVS_CHAR	cNvrCode[IVS_NVR_CODE_LEN];	        // �豸����NVR����, ��ʾ���豸����NVR����

    IVS_CHAR    cDevCreateTime[IVS_TIME_LEN];       // �豸����ʱ��
    IVS_BOOL	bIsExDomain;                        // �Ƿ�Ϊ�ⲿ�� 0-��  1-��
    IVS_CHAR    cDevIp[IVS_IP_LEN];                 // ǰ��IP

	IVS_CHAR	cReserve[32];
}IVS_CAMERA_BRIEF_INFO;

// ��Ƶ���豸�б�
typedef struct
{
	IVS_UINT32   uiTotal;           // �ܼ�¼��
	IVS_INDEX_RANGE stIndexRange;   // ��ҳ��Ϣ
	IVS_CAMERA_BRIEF_INFO stCameraBriefInfo[1];
}IVS_CAMERA_BRIEF_INFO_LIST;

//��չ�Ĳ�ѯ������־����
typedef struct
{
	IVS_CHAR cLoginID[IVS_NAME_LEN];					//��¼OMU��ID
	IVS_CHAR cNVRCode[IVS_NVR_CODE_LEN];		//����ѯ��NVRCode
	IVS_CHAR cModuleName[IVS_DESCRIBE_LEN];	//ģ������,Ʃ��"SMU","SCU"��"OMU"��ѡһ
	IVS_CHAR cPortalClientIP[IVS_IP_LEN];					//�Ż��ͻ���IP
}IVS_QUERY_OPTLOG_EX;

// ������־
typedef struct
{
	IVS_CHAR    cAccount[IVS_NAME_LEN];                 //����Ա�˺�
	IVS_CHAR    cClientIp[IVS_IP_LEN];                  //�ͻ���IP
	IVS_UINT32  iGrade;                                 //��־����
	IVS_CHAR    cServiceCode[IVS_DESCRIBE_LEN];         //ҵ����룬IVSƽ̨д"IVS"
	IVS_CHAR    cModuleType[IVS_DESCRIBE_LEN];          //ģ������,Ʃ��"SMU","SCU"
	IVS_CHAR    cModuleCode[IVS_DEV_CODE_LEN];          //ģ��Ψһ���룬ָ��ǰģ���Ӧ�Ļ������
	IVS_CHAR    cOperationCode[IVS_DEV_CODE_LEN];       //������������Ψһ��ʾһ������
	IVS_CHAR    cOperationObjectCode[IVS_DESCRIBE_LEN]; //����������룬������ʾ���β���ʵʩ�Ķ���
	IVS_CHAR    cOccurTime[IVS_TIME_LEN];               //��־����ʱ��
	IVS_CHAR    cErrorCode[IVS_DESCRIBE_LEN];           //������
	IVS_UINT32  iResult;                                //�������
	IVS_CHAR    cAdditionalInfo[IVS_DESCRIBE_LEN];      //������Ϣ
    IVS_CHAR	cReserve[32];
}IVS_OPERATION_LOG_INFO;

// ������־�б�
typedef struct
{
	IVS_UINT32   uiTotal;           // �ܼ�¼��
	IVS_INDEX_RANGE stIndexRange;   // ��ҳ��Ϣ
	IVS_OPERATION_LOG_INFO stOperationInfo[1];
}IVS_OPERATION_LOG_LIST;

// ���ܴ���
typedef enum
{
	FUNC_LOGIN= 1,	// ��¼
	FUNC_MAIN_UI,	// ������
	FUNC_GROUP_MANAGER,	// ��֯����
	// �����..<eSpace IVS V100R001C02 �û��������ܺʹ����б�.xlsx>
}IVS_FUNCTION_CODE;

/////////////////////////////////////////////////�澯///////////////////////////////////////////
#define IVS_ALARM_DESCRIPTION_LEN 1024
#define IVS_ALARM_CODE_LEN		64
#define IVS_ALARM_NAME_LEN		260
#define IVS_NODE_TYPE_LEN       8

// �澯����
#define IVS_MAX_ALARM_LEVEL_NUM	20	// �澯����������
typedef struct 
{
	IVS_UINT32  uiAlarmLevelId;		// �澯����ID

	IVS_CHAR    cName[IVS_NAME_LEN];	// �澯��������,���ֺ���ĸ��a-z��A-Z�������֣��л��ߺ��»��ߣ�1~20���ַ�
	IVS_UINT32  uiValue;				// �澯����Ȩֵ,1~100
	IVS_CHAR    cColor[16];			    // �澯������ɫ,ʹ����ɫ�ַ�����ʾARGB,����#FFFF0000 ��ʾ��ɫ����͸��
	IVS_CHAR    cDescription[IVS_ALARM_DESCRIPTION_LEN];	// �澯��������,���̿ɼ��ַ������ģ�0~256���ַ�
	IVS_BOOL    bIsUserDefined;		    // �Ƿ�Ϊ�û��Զ��� 0-�񣬱�ʾ��ϵͳ���塱 1-��

	IVS_CHAR	cReserver[32];
}IVS_ALARM_LEVEL;

// �澯����
#define IVS_ALARM_TYPE_CATEGORY_LEN  8
typedef struct
{
    IVS_UINT32  uiID;                   // �澯ID
	IVS_CHAR cType[IVS_ALARM_CODE_LEN];	// �澯���ͱ���
	IVS_CHAR cName[IVS_ALARM_NAME_LEN];	// �澯�������ƣ����ֺ���ĸ��a-z��A-Z�������֣��л��ߺ��»��ߣ�1~64���ַ�

	IVS_UINT32	uiType;					// �澯Դ���� IVS_ALARM_IN_TYPE
	IVS_CHAR cCategory[IVS_ALARM_TYPE_CATEGORY_LEN];				// �澯�������
/*    
�澯�������֧���ļ����
01��ҵ����澯
0101��һ��ҵ��澯
0102�����ܷ����澯
010201����Ϊ�����澯
010202������ʶ��澯
0103������������澯
02���豸��澯
0201��һ���豸�澯
0202�����ܷ����澯
*/
    IVS_BOOL    bIsUserDefined;		    // �Ƿ�Ϊ�û��Զ��� 0-�񣬱�ʾ��ϵͳ���塱 1-��

	IVS_ALARM_LEVEL stAlarmLevel;	    // �澯����ID

    IVS_BOOL    bEnable;                // �Ƿ����� 0-�� 1-��
	IVS_CHAR	cReserver[32];
}IVS_ALARM_TYPE;

// �澯���ͷ�ҳ��ѯ�б�
typedef struct
{
	IVS_UINT32   iTotal;                // �ܼ�¼��
	IVS_INDEX_RANGE stIndexRange;       // ��ҳ��Ϣ
	IVS_CHAR cReserve[32];              //�����ֶ�
	IVS_ALARM_TYPE stSubscribeInfo[1];  // �澯������Ϣ�б�
}IVS_ALARM_TYPE_LIST;

typedef enum
{
	ALARM_IN_CAMERA=1,      // ����ͷ
	ALARM_IN_DI=2,          // �����������豸
    ALARM_IN_EXTERN_DI=9,   // ����������������
}IVS_ALARM_IN_TYPE;

// ����������豸
typedef struct
{
	IVS_CHAR cCode[IVS_ALARM_CODE_LEN];	// �������������
	IVS_CHAR cName[IVS_ALARM_NAME_LEN]; // �������������

	IVS_CHAR	cReserver[32];
}IVS_ALARM_OUT;

// �澯������Ϣ
typedef struct
{
	IVS_UINT32	uiOperatorID;	                // ������ID �ο� IVS_USER_INFO
    IVS_CHAR    cOperatorName[IVS_NAME_LEN];	// ��������
	IVS_CHAR    cOperateTime[IVS_TIME_LEN];		// �澯����ʱ��

    IVS_CHAR	cReserver[32];
    IVS_CHAR    cOperateInfo[IVS_ALARM_DESCRIPTION_LEN];	// �澯������Ա�������Ϣ
}IVS_ALARM_OPERATE_INFO;

// �澯״̬
typedef enum
{
	ALARM_STATUS_NO_OPERATE=0,	// δ����
	ALARM_STATUS_TOBE_CONFIRM,	// ��ȷ��
	ALARM_STATUS_CONFIRMED,	    // ��ȷ��
	ALARM_STATUS_CANCELED,	    // �ѳ���
	ALARM_STATUS_RECOVERED,	    // �ѻָ�
}IVS_ALARM_STATUS;

// �澯Դ�豸
typedef struct
{
	IVS_CHAR cAlarmInCode[IVS_ALARM_CODE_LEN];	// �澯Դ����
	IVS_CHAR cAlarmInName[IVS_ALARM_NAME_LEN];  // �澯Դ����
	IVS_UINT32	uiAlarmInType;					// �澯Դ���� IVS_ALARM_IN_TYPE

	IVS_UINT32	uiDeviceType;	                // �ο� IVS_CAMERA_TYPE �豸���ͣ�Ŀǰֻ������������豸���ͣ������豸���գ�
	IVS_BOOL	bOnline;		                // �Ƿ����ߣ�1-����	0-����
	IVS_BOOL	bEnable;		                // �Ƿ����ã�1-����	0-ͣ��
	IVS_CAMERA_POSITION	stLocation;		        // 	�豸��װλ�ã�����û��λ����Ϣ����ʾΪ��

	IVS_CHAR	cReserver[32];
}IVS_ALARM_IN;

// �澯Դ�豸�б�
typedef struct
{
    IVS_UINT32   iTotal;            // �ܼ�¼��
    IVS_INDEX_RANGE stIndexRange;   // ��ҳ��Ϣ
    IVS_CHAR cReserve[32];          //�����ֶ�
    IVS_ALARM_IN stAlarmInInfo[1];  // �澯Դ�豸�б�
}IVS_ALARM_IN_LIST;

// �澯�ϱ���Ϣ(�ͻ��˵�ģ���ϱ�ƽ̨)
#define IVS_ALARM_EX_PARAM_LEN  2048    // �澯�ϱ���չ����
#define IVS_ALARM_REPORT_ID_LEN 32      // �澯�ϱ�ID
#define IVS_ALARM_TYPE_LEN  64          // �澯���ͳ���
typedef struct 
{
    // �澯Դ�豸
    IVS_CHAR    cAlarmInCode[IVS_ALARM_CODE_LEN];	// �澯Դ����
    IVS_CHAR	cDevDomainCode[IVS_DOMAIN_CODE_LEN];// �豸���������
    IVS_CHAR    cAlarmType[IVS_ALARM_TYPE_LEN];		// �澯Դ���� Ӣ���ַ���
    IVS_CHAR    cOccurTime[IVS_TIME_LEN];           // �澯����ʱ�䣺yyyyMMddHHmmss
    IVS_CHAR    cReportTime[IVS_TIME_LEN];          // �澯�ϱ�ʱ�䣺yyyyMMddHHmmss
    
    IVS_BOOL    bAction;                                // 0-�澯���� 1-�澯
    IVS_CHAR    cAlarmID[IVS_ALARM_REPORT_ID_LEN];      // �澯ID�����澯�������롰�澯��ʱ�ĸ澯ID��ͬ

    IVS_UINT32  uiOccurNumber;                          // �澯����������Ĭ��ֵ1
    IVS_CHAR    cNvrCode[IVS_NVR_CODE_LEN];             // NVR���룬�����ڸ���NVR·��

    IVS_CHAR    cReserve[32];                           // �����ֶ�
    IVS_CHAR    cAlarmDesc[IVS_ALARM_DESCRIPTION_LEN];  // �澯������Ϣ�����̿ɼ��ַ������ģ�1024�ֽ�
    IVS_CHAR    cExtParam[IVS_ALARM_EX_PARAM_LEN];      // ��չ����
}IVS_ALARM_REPORT;

#define IVS_ALARM_LEVEL_COLOR_LEN   16
#define IVS_ALARM_CATEGORY_LEN   8

// ҵ��澯֪ͨ��Ϣ(ƽ̨֪ͨ�ͻ���)
typedef struct 
{
    IVS_UINT64	ullAlarmEventID;                    // �澯�¼�ID
    IVS_CHAR    cAlarmInCode[IVS_ALARM_CODE_LEN];	// �澯Դ����
    IVS_CHAR	cDevDomainCode[IVS_DOMAIN_CODE_LEN];// �豸���������
    IVS_UINT32  uiAlarmInType;					    // �澯Դ���� IVS_ALARM_IN_TYPE
    IVS_CHAR    cAlarmInName[IVS_ALARM_NAME_LEN];   // �澯Դ����

    IVS_UINT32  uiAlarmLevelValue;		        // �澯����Ȩֵ,1~100
    IVS_CHAR    cAlarmLevelName[IVS_NAME_LEN];	// �澯��������,���ֺ���ĸ��a-z��A-Z�������֣��л��ߺ��»��ߣ�1~20���ַ�
    IVS_CHAR    cAlarmLevelColor[IVS_ALARM_LEVEL_COLOR_LEN];			// �澯������ɫ,ʹ����ɫ�ַ�����ʾARGB,����#FFFF0000 ��ʾ��ɫ����͸��

    IVS_CHAR    cAlarmType[IVS_ALARM_TYPE_LEN];	    // �澯����
    IVS_CHAR    cAlarmTypeName[IVS_ALARM_NAME_LEN];	// �澯�������ƣ����ֺ���ĸ��a-z��A-Z�������֣��л��ߺ��»��ߣ�1~64���ַ�
    IVS_CHAR    cAlarmCategory[IVS_ALARM_CATEGORY_LEN];				// �澯�������

    IVS_CHAR    cOccurTime[IVS_TIME_LEN];       // �澯����ʱ�䣺yyyyMMddHHmmss
    IVS_UINT32 uiOccurNumber;		            // �澯��������
    IVS_UINT32  uiAlarmStatus;		            // �澯״̬ �ο� IVS_ALARM_STATUS

    IVS_BOOL	bIsCommission;	                // �Ƿ�Ϊ��Ȩ�澯��Ϣ��0-��1-��
    IVS_CHAR    cPreviewUrl[IVS_URL_LEN];	    // �ڴ�������ץ�Ļ������ܷ���ʱ��ͼƬԤ��URL

    IVS_BOOL	bExistsRecord;	                // �Ƿ���ڸ澯¼��0-��1-��
    IVS_CHAR    cNvrCode[IVS_NVR_CODE_LEN];     // NVR���룬�����ڸ���NVR·��

    IVS_CHAR	cReserver[32];                  // �����ֶ�
    IVS_CHAR    cAlarmDesc[IVS_ALARM_DESCRIPTION_LEN];	// �澯������Ϣ�����̿ɼ��ַ������ģ�0~256�ַ���
    IVS_CHAR    cExtParam[IVS_ALARM_EX_PARAM_LEN];      // ��չ����
}IVS_ALARM_NOTIFY;

// �澯��Ϣ���澯�¼���ѯ��
typedef struct 
{
    IVS_ALARM_NOTIFY        stAlarmNotify;      // �澯��Ϣ
    IVS_ALARM_OPERATE_INFO	stOperateInfo;	    // �澯������Ϣ
}IVS_ALARM_EVENT;

// �澯��Ϣ״̬֪ͨ
typedef struct 
{
    IVS_UINT64	ullAlarmEventID;                        // �澯�¼�ID
    IVS_CHAR    cAlarmInCode[IVS_ALARM_CODE_LEN];	    // �澯Դ����
    IVS_CHAR	cDevDomainCode[IVS_DOMAIN_CODE_LEN];    // �澯Դ�����
    IVS_CHAR    cAlarmType[IVS_ALARM_TYPE_LEN];	        // �澯����

    IVS_UINT32  uiOccurNumber;		            // �澯��������
    IVS_UINT32  uiAlarmStatus;		            // �澯״̬ �ο� IVS_ALARM_STATUS    

    IVS_CHAR	cReserve[32];                   // �����ֶ�

    IVS_ALARM_OPERATE_INFO	stOperateInfo;	    // �澯������Ϣ
}IVS_ALARM_STATUS_NOTIFY;

// �澯�ϱ���Ϣ��ҳ��ѯ�б�
typedef struct
{
    IVS_UINT32   iTotal;                    // �ܼ�¼��
    IVS_INDEX_RANGE stIndexRange;           // ��ҳ��Ϣ
    IVS_CHAR cReserve[32];                  //�����ֶ�
    IVS_ALARM_EVENT stSubscribeInfo[1];    // �澯֪ͨ��Ϣ
}IVS_ALARM_EVENT_LIST;

// �豸�澯֪ͨ��Ϣ(OMU�澯֪ͨ��Ϣ)
#define IVS_DEVICE_ALARM_LOCATION_INFO_LEN  256
#define IVS_NET_ELEMENT_ID_LEN  32
typedef struct 
{
    IVS_UINT64	ullAlarmEventID;                    // �澯�¼�ID
    IVS_CHAR    cAlarmInCode[IVS_ALARM_CODE_LEN];	// �澯Դ����
    IVS_UINT32  uiAlarmInType;					    // �澯Դ���� IVS_ALARM_IN_TYPE
    IVS_CHAR    cAlarmInName[IVS_ALARM_NAME_LEN];   // �澯Դ����
    IVS_CHAR    cNodeType[IVS_NODE_TYPE_LEN];       // �澯������Ԫ����,��30858

    IVS_UINT32  uiAlarmLevelValue;		        // �澯����Ȩֵ��ֻ�����֣�1-��ʾ��50-һ�㣻80-��Ҫ��100-������

    IVS_CHAR    cAlarmType[IVS_ALARM_CODE_LEN];	// �澯����
    IVS_CHAR    cAlarmCategory[IVS_ALARM_CATEGORY_LEN];				// �澯������� 01��ҵ����澯 02��������澯 03��״̬��澯

    IVS_CHAR    cOccurFirstTime[IVS_TIME_LEN];     // �澯�״η���ʱ�䣺yyyyMMddHHmmss���澯���Ƶĵ�һ�θ澯����ʱ�䣩
    IVS_CHAR    cOccurEndTime[IVS_TIME_LEN];       // �澯�����ʱ�䣺yyyyMMddHHmmss���澯���Ƶ����һ�θ澯����ʱ�䣩

    IVS_UINT32 uiOccurNumber;		            // �澯��������

    IVS_CHAR	cReserver[32];                  // �����ֶ�
    // �澯��λ��Ϣ����λ��Ϣ�ֶ��и�ʽҪ����Ҫ�ǡ��Զ��ŷָ��ļ�ֵ�ԡ�����ʽ��Ʃ�磺ip=10.137.97.123,hostname=linux,...����Ϊ�գ�����������
    IVS_CHAR    cLocationInfo[IVS_DEVICE_ALARM_LOCATION_INFO_LEN];
    IVS_CHAR    cNetEleID[IVS_NET_ELEMENT_ID_LEN];      // �澯����ģ���������ԪID

	IVS_CHAR    cNetName[IVS_NAME_LEN];                 // ������Ԫ����
    IVS_CHAR    cAlarmDest[IVS_ALARM_DESCRIPTION_LEN];  // �澯������Ϣ�����̿ɼ��ַ������ģ�0~256�ַ���
    IVS_CHAR    cExtParam[IVS_ALARM_EX_PARAM_LEN];      // ��չ����
}IVS_DEVICE_ALARM_NOTIFY;

// �豸�澯��Ϣ��ҳ��ѯ�б�
typedef struct
{
    IVS_UINT32   iTotal;                    // �ܼ�¼��
    IVS_INDEX_RANGE stIndexRange;           // ��ҳ��Ϣ
    IVS_CHAR cReserve[32];                  //�����ֶ�
    IVS_DEVICE_ALARM_NOTIFY stDeviceAlarmNotify[1];    // �澯֪ͨ��Ϣ
}IVS_DEVICE_ALARM_EVENT_LIST;

// �û�ID��Ϣ
typedef struct
{
    IVS_UINT32	uiUserID;	                        // ����Ȩ�û�ID
    IVS_CHAR	cDomainCode[IVS_DOMAIN_CODE_LEN];	// �û����������
}IVS_USER_ID_INFO;

// �澯��Ȩ
typedef struct 
{
    IVS_UINT64	ullAlarmEventID;	// �澯�¼�ID
    IVS_UINT32  uiUserNum;          // ����Ȩ�û���
    IVS_USER_ID_INFO    stUserInfo[1];  // ����Ȩ�û�ID�б�
}IVS_ALARM_COMMISSION;

// ����������
typedef enum
{
	SUBSCRIBER_TYPE_USER= 1,	// �û�����
	SUBSCRIBER_TYPE_DOMAIN= 2,	// ����������
}IVS_SUBSCRIBE_USER_TYPE;

// �澯��������Ϣ
typedef struct 
{
	IVS_UINT32	uiSubscriberType;	// ���������ͣ��ο� IVS_SUBSCRIBE_USER_TYPE
	IVS_UINT32	uiSubscriberId;		// ������ID���û�ID/��ID��

	IVS_CHAR	cReserve[32];
}IVS_ALARM_SUBSCRIBER;

// ���ķ�ʽ
typedef enum
{
	SUBSCRIBE_ALL= 1,       // ����
	SUBSCRIBE_BY_TYPE= 2,   // ���澯����
	SUBSCRIBE_BY_LEVEL= 3,  // ���澯����
}IVS_SUBSCRIBE_TYPE;

// �澯������Ϣ��һ���û����Զ��Ķ���澯Դ��ÿ���澯Դ���Զ��Ķ���澯���ͣ�
#define IVS_MAX_ALARM_TYPE_NUM  32  // ���澯���͸���
typedef struct 
{
	IVS_CHAR cCode[IVS_ALARM_CODE_LEN];	// �澯Դ����
	IVS_UINT32	uiSubscribeType;        // ���ķ�ʽ���ο� IVS_SUBSCRIBE_TYPE
	IVS_UINT32	uiAlarmLevelValueMin;	// �澯��������ֵ�����ķ�ʽΪ��3-���澯���𡱱��룬����Ϊ��
	IVS_UINT32	uiAlarmLevelValueMax;	// �澯��������ֵ�����ķ�ʽΪ��3-���澯���𡱱��룬����Ϊ��

	IVS_CHAR	cReserve[32];

	IVS_UINT32	uiAlarmTypeNumber;	// ʵ�ʸ澯���Ͷ��ĸ���
	IVS_ALARM_TYPE	stAlaryType[IVS_MAX_ALARM_TYPE_NUM];	// �澯��������
}IVS_ALARM_SUBSCRIBE_INFO;

// �澯������Ϣ��ҳ��ѯ�б�
typedef struct
{
	IVS_UINT32   iTotal;            // �ܼ�¼��
	IVS_INDEX_RANGE stIndexRange;   // ��ҳ��Ϣ
	IVS_CHAR cReserve[32];                          //�����ֶ�
	IVS_ALARM_SUBSCRIBE_INFO stSubscribeInfo[1];    // �澯������Ϣ
}IVS_ALARM_SUBSCRIBE_INFO_LIST;

typedef enum
{
	HELP_SOURCE_AREA= 1,	// ����
	HELP_SOURCE_TYPE= 2,	// �澯����
}IVS_ALARM_HELP_SOURCE;

// ������Ϣ
#define IVS_MAX_ALARM_IN_NUM	512	// ����������
typedef struct 
{
	IVS_UINT32	uiAlarmAreaID;	                    // ������ID
	IVS_CHAR	cAlarmAreaName[IVS_ALARM_NAME_LEN];	// ��������
	IVS_BOOL	bGuard;			                    // �Ƿ񲼷�	0-����	1-����
    IVS_CHAR	cReserve[32];

	IVS_UINT32      uiAlarmInNum;	                    // �����澯Դʵ�ʸ���
	IVS_ALARM_IN    stAlarmIn[IVS_MAX_ALARM_IN_NUM];	// �����澯Դ�б�
}IVS_ALARM_AREA;

// �澯������Ϣ��ҳ��ѯ�б�
typedef struct
{
	IVS_UINT32   iTotal;                // �ܼ�¼��
	IVS_INDEX_RANGE stIndexRange;       // ��ҳ��Ϣ
	IVS_CHAR cReserve[32];              //�����ֶ�
	IVS_ALARM_AREA stAlarmAreaInfo[1];  // �澯������Ϣ
}IVS_ALARM_AREA_LIST;

#define IVS_MAX_HELP_LEN	40960
// ������Ϣ
typedef struct 
{
	IVS_UINT32	uiSourceType;					// ������ϢԴ���ͣ��ο� IVS_ALARM_HELP_SOURCE
	IVS_UINT32	uiSourceId;						// ����/�澯����ID	
	IVS_CHAR	cSourceName[IVS_ALARM_NAME_LEN];// ����/�澯��������
	IVS_CHAR	cHelpInfo[IVS_MAX_HELP_LEN];	// ������Ϣ���ģ�֧��HTML�����֧��10000����
	IVS_CHAR	cUserName[IVS_NAME_LEN];		// ���°�����Ϣ�û���
	IVS_CHAR	cUpdateTime[IVS_TIME_LEN];		// �༭ʱ��
    IVS_CHAR	cReserve[64];
}IVS_HELP_INFO;

// ������Ϣ�б�
typedef struct
{
    IVS_UINT32   uiTotal;           // �ܼ�¼��
    IVS_INDEX_RANGE stIndexRange;   // ��ҳ��Ϣ
    IVS_HELP_INFO stHelpInfo[1];    // ������Ϣ
}IVS_HELP_INFO_LIST;

// ��������>�澯��������
typedef enum
{
    ACTION_TYPE_INTERACTIVE=1,      // �û�����
    ACTION_TYPE_PLATFORM_RECORD,    // ����¼��
    ACTION_TYPE_PU_RECORD,          // ����ǰ��¼��
    ACTION_TYPE_SNAP,               // ����ץ��
	ACTION_TYPE_PRESET=5,           // ����Ԥ��λ

	ACTION_TYPE_IO,                 // �������������
    ACTION_TYPE_LIVE,               // �����ͻ��˵���ʵ��
    ACTION_TYPE_TV,                 // ����ʵ����ǽ
    ACTION_TYPE_EMAIL,              // ����EMAIL
    ACTION_TYPE_SMS=10,             // ��������
	ACTION_TYPE_MMS,                // ��������
    ACTION_TYPE_BACKUP_RECORD,      // ����¼�񱸷�
}IVS_LINKAGE_ACTION_TYPE;

// ˮӡ�澯��Ϣ
typedef struct
{
    IVS_CHAR    cCameraCode[IVS_DEV_CODE_LEN]; // ���������
    IVS_UINT64  ullAlarmEventID;               // �澯ID
    IVS_CHAR    cStartTime[IVS_TIME_LEN];      // �澯��ʼʱ��
    IVS_CHAR    cEndTime[IVS_TIME_LEN];        // �澯����ʱ��
    IVS_CHAR	cReserve[32];
}IVS_ALARM_WATERMARK_INFO;

// ��������>ִ�з�֧
typedef enum
{
	ACTION_BRANCH_ALWAYS = 0,		// ����ִ��
	ACTION_BRANCH_AFTER_CONFIRM,	// ȷ�Ϻ�ִ��
	ACTION_BRANCH_AFTER_TIMEOUT,	// ��ʱδȷ��ִ��
}IVS_LINKAGE_ACTION_BRANCH;

// ��������>�豸��Ϣ
#define IVS_LINKAGE_DEV_PARAM_LEN     128  // �����豸������������
typedef struct
{
	IVS_CHAR	cDevCode[IVS_DEV_CODE_LEN];	            // �豸����
    IVS_CHAR    cDevDomainCode[IVS_DOMAIN_CODE_LEN];    // �豸���������
	IVS_CHAR    cParam[IVS_LINKAGE_DEV_PARAM_LEN];      // Ԥ��λ ��������
    IVS_CHAR	cReserve[32];
}IVS_LINKAGE_DEV_INFO;

// ��������>�û���Ϣ
typedef struct
{
	IVS_UINT32  uiUserId;       // �û�ID
    IVS_CHAR	cReserve[32];
}IVS_LINKAGE_USER_INFO;

// �澯-������-��
//	�����
//	�û�

// �澯����������������
#define IVS_LINKAGE_GLOBAL_PARAM_LEN        1024// ����ȫ�ֶ�����������
#define IVS_MAX_LINKAGE_ACTION_DEVICE_NUM   8   // ִ�ж������豸������
#define IVS_MAX_LINKAGE_ACTION_USER_NUM     32  // �澯����Ŀ���û���������
typedef struct
{
	IVS_UINT32 uiActionID;                                     // ��������ID
	IVS_UINT32 uiActionType;                                   // �澯�������ͣ� �ο� IVS_LINKAGE_ACTION_TYPE
	IVS_CHAR	cGlobalParam[IVS_LINKAGE_GLOBAL_PARAM_LEN];	   // ȫ�ֶ�������
	IVS_UINT32	uiActionBranch;                                // ִ�з�֧���ο� IVS_LINKAGE_ACTION_BRANCH
	IVS_UINT32  uiDevInfoNumber;                               // ִ�ж������豸ʵ�ʸ���
	IVS_LINKAGE_DEV_INFO stDevInfo[IVS_MAX_LINKAGE_ACTION_DEVICE_NUM];  // ִ�ж������豸�б�
	IVS_UINT32  uiUserInfoNumber;								// ִ�ж�����Ŀ��ʵ���û���
	IVS_UINT32 uiUserID[IVS_MAX_LINKAGE_ACTION_USER_NUM];		// ����Ŀ���û��б�
    IVS_CHAR	cReserve[32];
}IVS_LINKAGE_ACTION;

// �澯��������
typedef struct
{
	IVS_UINT32 uiID;                            // ��������ID
//	IVS_CHAR cLinkageName[IVS_ALARM_NAME_LEN];	// ������������
	IVS_CHAR cAlarmInCode[IVS_ALARM_CODE_LEN];	// �澯Դ����
	IVS_CHAR cAlarmType[IVS_ALARM_CODE_LEN];	// �澯���ͱ���
	IVS_CHAR cReserve[32];
	IVS_UINT32 uiActionNumber;                  // ������������
	IVS_LINKAGE_ACTION stAction[1];             // ���������б�
}IVS_LINKAGE_POLICY;

// �澯���������б�
typedef struct
{
    IVS_UINT32   uiTotal;               // �ܼ�¼��
    IVS_INDEX_RANGE stIndexRange;       // ��ҳ��Ϣ
    IVS_LINKAGE_POLICY stLinkagePolicy[1];  // �澯���������б�
}IVS_LINKAGE_POLICY_LIST;

// �澯��������ֹ֪ͣͨ
typedef struct 
{
    IVS_CHAR    cSrcDomainCode[IVS_DOMAIN_CODE_LEN];            // ����Դ����룬Ϊ��ѡ���������ֶ�ʱ��ʾΪ����
    IVS_UINT64	ullAlarmEventID;                                // �澯�¼�ID����SrcDomainCode���Ψһֵ
    IVS_UINT32  uiActionType;                                   // �澯�������ͣ� �ο� IVS_LINKAGE_ACTION_TYPE
    IVS_CHAR	cGlobalParam[IVS_LINKAGE_GLOBAL_PARAM_LEN];	    // ȫ�ֶ�������

    IVS_UINT32  uiDevInfoNumber;                                // ִ�ж������豸ʵ�ʸ���
    IVS_LINKAGE_DEV_INFO stDevInfo[IVS_MAX_LINKAGE_ACTION_DEVICE_NUM];  // ִ�ж������豸�б�
    IVS_UINT32  uiUserInfoNumber;								// ִ�ж�����Ŀ��ʵ���û���
    IVS_UINT32  uiUserID[IVS_MAX_LINKAGE_ACTION_USER_NUM];		// ����Ŀ���û��б�
    IVS_CHAR	cReserve[32];
}IVS_STOP_LINKAGE_ACTION;

// �ֶ�¼��״̬֪ͨ
typedef struct 
{
    IVS_CHAR    cCameraCode[IVS_DEV_CODE_LEN];      // ���������
    IVS_UINT32	uiUserID;                           // �û�ID
    IVS_UINT32	uiRecordMethod;                     // ¼��ʽ��ֵ�ο�IVS_RECORD_METHOD
    IVS_UINT32	uiManualRecordState;                // �ֶ�¼��״̬��0-ֹͣ1-����
    IVS_UINT32	uiNotifInfo;                        // ֹͣԭ��ֹͣʱ��Ч��0-�ֶ�ֹͣ 1-��ʱֹͣ 2-�쳣ֹͣ
    IVS_CHAR	cReserve[32];
}IVS_MANUAL_RECORD_STATUS_NOTIFY;

// ��������
typedef struct
{
//	char          Id[POLICYID_LEN + 1]; // ����ID
	unsigned char Type;        			// 0x00: ��ֹ��0x01: ������0x02: �¼�����(��һ�������ݿ�����ֵ)
	unsigned char Week;        			// �ܱ�־, 1 ~ 8�ֱ��Ӧ���� ~ ����
	unsigned char Once;        			// ��ʾ�ò���ִֻ��һ��
	IVS_CHAR	StartTime[IVS_TIME_LEN];// ��ʼʱ�䣬���ʱ�׼ʱ��, ֻ��ʱ����
	IVS_CHAR	EndTime[IVS_TIME_LEN];  // ����ʱ�䣬���ʱ�׼ʱ��, ֻ��ʱ����
	unsigned char isEnable;     		// �Ƿ����ã�0-δ���ã�1-����
    IVS_CHAR	cReserve[32];
}IVS_STRAT_PROPERTY;

// �ֵ���Ϣ
#define IVS_DICTIONARY_NAME_LEN     64      // �ֶ����Ƴ���
#define IVS_DICTIONARY_VALUE_LEN    256     // �ֵ�ֵ����
#define IVS_DICTIONARY_TYPE_LEN     32      // �ֵ����ͳ���
#define IVS_DICTIONARY_REMARK_LEN   256      // ��ע����
typedef struct
{
    IVS_UINT32  uiID;                                   // ��¼ΨһID
    IVS_CHAR    cDictName[IVS_DICTIONARY_NAME_LEN];     // �ֵ����ƣ�Ӣ����ĸ�ͷ��ţ�
    IVS_CHAR    cDictValue[IVS_DICTIONARY_VALUE_LEN];   // �ֵ�ֵ��֧�����ġ�Ӣ��
    IVS_CHAR    cDictType[IVS_DICTIONARY_TYPE_LEN];     // �ֵ�����
    IVS_UINT32  uiParentID;                             // ���ڵ�ID
    IVS_CHAR    cRemark[IVS_DICTIONARY_REMARK_LEN];     // ��ע

    IVS_CHAR cReserve[32];                              //�����ֶ�
}IVS_DICTIONARY_INFO;

// �ֵ���Ϣ�б�
typedef struct
{
    IVS_UINT32   uiTotal;                       // �ܼ�¼��
    IVS_INDEX_RANGE stIndexRange;               // ��ҳ��Ϣ
    IVS_DICTIONARY_INFO stDictionaryInfo[1];    // �ֵ���Ϣ
}IVS_DICTIONARY_INFO_LIST;

////////////////////////////////////////MLib��ص�ͷ�ļ�////////////////////////////////////////////
// ҵ������ ServiceType;
typedef enum
{
    SERVICE_TYPE_INVALID            = 0,
    SERVICE_TYPE_REALVIDEO          = 0x0001,   // ʵ��;
    SERVICE_TYPE_RECORD             = 0x0002,   // ƽ̨¼��;
    SERVICE_TYPE_DOWNLOAD           = 0x0003,   // ����¼������;
    SERVICE_TYPE_PLAYBACK           = 0x0004,   // ¼��ط�;
    SERVICE_TYPE_AUDIO_CALL         = 0x0005,   // ��Ƶ�Խ�;
    SERVICE_TYPE_AUDIO_BROADCAST    = 0x0006,   // ��Ƶ�㲥; 
    SERVICE_TYPE_PU_DOWNLOAD        = 0x0007,   // ǰ��¼������
    SERVICE_TYPE_PU_PLAYBACK        = 0x0008,   // ǰ��¼��ط�

    SERVICE_TYPE_REALVIDEO_BACKUP		= 0x0014,		// ʵ������
    SERVICE_TYPE_PLATRECORD_BACKUP		= 0x0015,		// ƽ̨¼�񱸷�
    SERVICE_TYPE_PURECORD_BACKUP		= 0x0016,		// ǰ��¼�񱸷�
    SERVICE_TYPE_BACKUPRECORD_PLAYBACK	= 0x0017,		// ¼�񱸷ݻط�
    SERVICE_TYPE_BACKUPRECORD_DOWNLOAD	= 0x0018,		// ¼�񱸷�����
    SERVICE_TYPE_DISASTEBACKUP_PLAYBACK = 0x0019,       // ����¼��ط�
    SERVICE_TYPE_DISASTEBACKUP_DOWNLOAD = 0x001A,       // ����¼������
    SERVICE_TYPE_PU_UPLOAD              = 0x001B,       // ǰ�˻��油¼

    SERVICE_TYPE_MAX
}IVS_SERVICE_TYPE;

// ��������;
typedef enum
{
    BROADCAST_UNICAST   = 0x0000,   // ����;
    BROADCAST_MULTICAST = 0x0001    // �鲥;
}IVS_BROADCAST_TYPE;

// ��������;
typedef enum
{
    MEDIA_TRANS     = 0x0000, // ��ת
    MEDIA_DIRECT    = 0x0001, // ֱ��;    
}IVS_MEDIA_TRANS_MODE;

// ����Э��;
typedef enum
{
    PROTOCOL_RTP_OVER_UDP = 0x0001, //RTP over UDP
    PROTOCOL_RTP_OVER_TCP = 0x0002, //RTP over TCP
    PROTOCOL_UDP          = 0x0003, //UDP
    PROTOCOL_TCP          = 0x0004  //TCP
}IVS_PROTOCOL_TYPE;

// ���Э������;
typedef enum
{
    PACK_PROTOCOL_ES     = 0x0001,
    PACK_PROTOCOL_PS     = 0x0002,
    PACK_PROTOCOL_TS     = 0x0003
}IVS_PACK_PROTOCOL_TYPE;

// ��Ƶ��������;
typedef enum
{
    VIDEO_DEC_H264              = 0x0001,
    VIDEO_DEC_MJPEG             = 0x0002,
    VIDEO_DEC_MPEG4             = 0x0003,  
    VIDEO_DEC_MPEG2             = 0x0004,
    VIDEO_DEC_AVS               = 0x0005
}IVS_VIDEO_DEC_TYPE;

// H264 Profile
typedef enum
{
    H264_PROFILE_BASELINE= 1,	// BP
    H264_PROFILE_EXTENDED,		// EP
    H264_PROFILE_MAIN,			// MP
    H264_PROFILE_HIGH,			// HP
}IVS_H264_PROFILE;

// MJPEG Profile
typedef enum
{
	MJPEG_PROFILE_SP= 1,	// SP
	MJPEG_PROFILE_ASP,		// ASP
}IVS_MJPEG_PROFILE;

// ��Ƶ��������;
typedef enum
{
    AUDIO_DEC_G711A             = 0x0001,
    AUDIO_DEC_G711U             = 0x0002,
    AUDIO_DEC_G726              = 0x0003 
}IVS_AUDIO_DEC_TYPE;

// ��������
typedef enum
{
    STREAM_TYPE_UNSPECIFIED=0,  // ��ָ����
    STREAM_TYPE_MAIN=1, // ������
    STREAM_TYPE_SUB1,	// ������1
    STREAM_TYPE_SUB2,	// ������2
}IVS_STREAM_TYPE;

// ý�����
typedef struct
{
    IVS_VENDOR_TYPE         DecoderCompany; // ���������̣�1-HUAWEI��Ĭ��Ϊ1
    IVS_STREAM_TYPE         StreamType;     // ��������,1-������ 2-������1 3-������2��Ĭ��Ϊ1
    IVS_PROTOCOL_TYPE       ProtocolType;   // Э�����ͣ�1-UDP 2-TCP��Ĭ��Ϊ1
    IVS_MEDIA_TRANS_MODE    TransMode;      // �Ƿ�ֱ������,0-�� 1-�ǣ�Ĭ��Ϊ0
    IVS_BROADCAST_TYPE      BroadCastType;  // �Ƿ�֧���鲥��0-��֧�� 1-֧�֣�Ĭ��Ϊ0 
    IVS_UINT32	            VideoDecType;   // ��Ƶ�����ʽ���ο� IVS_VIDEO_DEC_TYPE 1-H.264��Ĭ��Ϊ1
    IVS_AUDIO_DEC_TYPE      AudioDecType;   // ��Ƶ�����ʽ��1-PCMA 2-PCMU��Ĭ��Ϊ1
    IVS_CHAR	cReserve[64];
}IVS_MEDIA_PARA;


// ��Ƶ��������
typedef struct
{
    IVS_UINT32  VideoDecType;           // ��Ƶ�����ʽ���ο� IVS_VIDEO_DEC_TYPE

	IVS_UINT32  VideoCodeRate;          // ��Ƶ����
    IVS_UINT32  VideoAverageCodeRate;   // ��Ƶƽ������

	IVS_UINT32  VideoFPS;        // ��Ƶ֡��
	IVS_UINT32  VideoWidth;      // ��Ƶ��
	IVS_UINT32  VideoHeight;     // ��Ƶ��
	IVS_UINT32  CurrPlayTime;    // ��ǰ����ʱ��

	IVS_UINT32  Reserved1;       //����1
	IVS_UINT32  Reserved2;       //����2
}IVS_VEDIO_QUALITY_PARA;

// ��Ƶ��������
typedef struct
{	
	IVS_AUDIO_DEC_TYPE      AudioDecType;           // ��Ƶ���뷽ʽ
	IVS_UINT32              AudioCodeRate;          // ��Ƶ����
    IVS_UINT32              AudioAverageCodeRate;   // ��Ƶƽ������
    IVS_UINT32              AudioState;             // ��Ƶ״̬    0-�ر�  1-��

	IVS_UINT32              Reserved1;              // ����1
	IVS_UINT32              Reserved2;              // ����2
}IVS_AUDIO_QUALITY_PARA;

typedef enum
{
	DOMAIN_TYPE_STACK=1,	// �ѵ�
	DOMAIN_TYPE_CLUSTER=2,	// ��Ⱥ
    DOMAIN_TYPE_SINGLE=3,	// ����
}IVS_DOMAIN_TYPE;

// ��·����Ϣ
#define IVS_MAX_DOMAIN_ROUTE_NUM    128     // ��·������¼��
typedef struct
{
	IVS_UINT32	uiDomainType;                       // SMU����ģʽ���ο� IVS_DOMAIN_TYPE 1-�ѵ� 2-��Ⱥ 3-����
	IVS_BOOL	bIsAgent;	                        // �Ƿ����
	IVS_CHAR	cDomainCode[IVS_DOMAIN_CODE_LEN];	// �����
	IVS_CHAR	cDomainName[IVS_NAME_LEN];		    // ������
	IVS_IP		stIP;                               // ��IP
	IVS_UINT32	uiPort;                             // ��˿�
    IVS_UINT32	uiStatus;			                // �豸״̬��0-���ߣ�1-���ߣ�2-���� �ο� IVS_DEV_STATUS
	IVS_CHAR	cSuperDomain[IVS_DOMAIN_CODE_LEN];	// �ϼ������
    IVS_BOOL    bIsLocalDomain;                     // �Ƿ��� 0-���� 1-��
    IVS_CHAR	cReserve[64];
}IVS_DOMAIN_ROUTE;

// ��·����Ϣ�б�
// ϵͳ��·�������� 128
typedef struct
{
	IVS_UINT32   uiTotal;               // ϵͳʵ����·�ɸ���
	//IVS_INDEX_RANGE stIndexRange;     // ��ҳ��Ϣ
	IVS_DOMAIN_ROUTE stDomainRoute[1];  // ��·����Ϣ
}IVS_DOMAIN_ROUTE_LIST;

// ��Ƶ��ʾ����
typedef enum
{
    DISPLAY_SCALE_ORIGINAL=1,   // ԭʼ����
    DISPLAY_SCALE_FULL=2,       // ��������
}IVS_DISPLAY_SCALE;

// ��Ƶ����Ч��
typedef enum
{
    PLAY_QUALITY_FLUENCY=1,    // ��������
    PLAY_QUALITY_DEFINITION=2, // ����������
}IVS_PLAY_QUALITY_MODE;

// ���������Ϣ
typedef struct
{
    IVS_BOOL    bIsNeedWarning;     // �Ƿ���Ҫ��ʾ�û���0-����Ҫ��1-��Ҫ
    IVS_UINT32  uiRemainDays;       // ���뻹ʣ���������
    IVS_UINT32  uiExpiredDays;      // �����ѹ��ڵ�������ƽ̨�����ù��ڲ������˺ţ�
    IVS_CHAR    cReserve[32];
}IVS_PWD_EXPIRE_INFO;

typedef enum
{
    PAY_LOAD_NO_TYPE     = -1,
    PAY_LOAD_TYPE_PCMU   = 0,   // G711��u��
    PAY_LOAD_TYPE_PCM    = 1,
    PAY_LOAD_TYPE_G723   = 4,   // G723
    PAY_LOAD_TYPE_PCMA   = 8,   // G711��a��
    PAY_LOAD_TYPE_G722   = 9,   // G722

    PAY_LOAD_TYPE_G726   = 16,  // G726
    PAY_LOAD_TYPE_AAC    = 17,  // AAC

    PAY_LOAD_TYPE_MJPEG  = 26,  // MJPEG
    PAY_LOAD_TYPE_H264_1 = 96,  // H264(�Ǳ�׼����)
    PAY_LOAD_TYPE_AMR_MB = 97,  // AMR_NB
    PAY_LOAD_TYPE_MPEG4  = 98,  // MPEG4
    PAY_LOAD_TYPE_H264   = 99,  // H264
    PAY_LOAD_TYPE_AVS    = 100, // AVS
    PAY_LOAD_TYPE_MP3    = 101, // MP3
    PAY_LOAD_TYPE_3GPP   = 102,  // 3GPP
    PAY_LOAD_TYPE_TRACK  = 107,  // �켣
}IVS_PAYLOAD_TYPE;

/*****************************δ����ԭʼ���ݽṹ****************************/
typedef struct
{
    IVS_UINT32	uiStreamType;		// �����ʽ���ο���IVS_PAYLOAD_TYPE
    IVS_UINT32  uiFrameType;		// ֡�������ͣ�SPS��PPS��IDR��P����Ƶ������Ч��
    IVS_UINT32  uiTimeStamp;		// ʱ���
    IVS_UINT64  ullTimeTick;		// ����ʱ���
    IVS_UINT32  uiWaterMarkValue;	// ˮӡ���� ��0��ʾ��ˮӡ���ݣ���Ƶ������Ч��

    IVS_UINT32	uiWidth;			// �������
    IVS_UINT32	uiHeight;			// ��Ƶ�߶�

    IVS_UINT32	uiGopSequence;		// GOP����
}IVS_RAW_FRAME_INFO;

/*****************************�������ݽṹ*********************************/
typedef enum
{
	PICTURE_FORMAT_YUV420 = 0,
	PICTURE_FORMAT_YUV422,
	PICTURE_FORMAT_YUV444,
	PICTURE_FORMAT_YUV422V,
	PICTURE_FORMAT_YUV400,
	PICTURE_FORMAT_YV12,
	PICTURE_FORMAT_NV12,
    PICTURE_FORMAT_YUV422H,
}IVS_PICTURE_FORMAT;

typedef struct
{
	IVS_UCHAR*  pY;
	IVS_UCHAR*  pU;
	IVS_UCHAR*  pV;
	IVS_UINT32  uiPitch;            // ƽ����ڴ�ռ�ó���(Ҳ�������Stride)
	IVS_UINT32  uiWidth;            // �����
	IVS_UINT32  uiHeight;           // �����
	IVS_UINT32  uiPictureFormat;    // �����ʽ,�ο�IVS_PICTURE_FORMAT
	IVS_UINT32  uiTimeStamp;        // RTPʱ���
	IVS_UINT64  ullTimeTick;        // ʱ����Ϣ����λ����
    IVS_UINT32	uiGopSequence;		// GOP����
    IVS_CHAR	cReserve[32];
    IVS_UINT32  uiFrameType;        //֡����(I P)
}IVS_VIDEO_FRAME;

typedef struct
{
	IVS_UCHAR*  pFrame;         // ��Ƶ֡�׵�ַ
	IVS_UINT32  uiFrameSize;    // ��Ƶ֡����
	IVS_UINT32  uiSampleRate;   // ������
	IVS_UINT32  uiChannels;     // ��Ƶ������
	IVS_UINT32  uiBits;         // ��λ��
	IVS_UINT32  uiTimeStamp;    // RTPʱ���
	IVS_UINT64  ullTimeTick;    // ʱ����Ϣ����λ����
    IVS_UINT32  uiAudioFormat;  // ��Ƶ��ʽ��ֱ��ʹ��payload Type�����ֵ���ο� IVS_PAYLOAD_TYPE
    IVS_CHAR	cReserve[32];
}IVS_AUDIO_FRAME;

// ý��������;
typedef enum
{
    MEDIA_STREAM_VIDEO = 0,       // ��Ƶ;
    MEDIA_STREAM_AUDIO            // ��Ƶ;
}IVS_MEDIA_STREAM;

// �豸״̬;
typedef struct
{
    IVS_CHAR	cCode[IVS_DEV_CODE_LEN];	// �豸����
    IVS_UINT32	uiStatus;			        // IVS_DEV_STATUS
    IVS_IP		stIP;						// �豸IP��Ϣ
    IVS_UINT32	uiPort;						// �豸���Ӷ˿�
    IVS_CHAR	cReserve[32];
}IVS_DEVICE_STATE;

// �����Խ�����
typedef struct
{
    IVS_UINT32      uiProtocolType;     // Э�����ͣ�1-UDP
    IVS_BOOL        bDirectFirst;       // �Ƿ�ֱ�����ȣ�0-�� 1-�ǣ�Ĭ��Ϊ0
    IVS_CHAR	    cReserve[32];
}IVS_VOICE_TALKBACK_PARAM;

// Ԥ��λ��Ϣ
#define IVS_MAX_PRESET_NUM      256     // Ԥ��λ
#define IVS_PRESET_NAME_LEN     84      // Ԥ��λ����
typedef struct
{
    IVS_UINT32  uiPresetIndex;   // Ԥ��λ����
    IVS_CHAR    cPresetName[IVS_PRESET_NAME_LEN];   // Ԥ��λ���ƣ�1~20���ַ���
    IVS_CHAR	cReserve[32];
}IVS_PTZ_PRESET;

// ����λ��Ϣ
typedef struct
{
    IVS_UINT32  uiPresetIndex;          // Ԥ��λ����
    IVS_BOOL    bEnableGuardPosition;   // ���ñ�ʶ��0-�����ã�1-����
    IVS_UINT32  uiWaitTime;             // �Զ���λ�ȴ�ʱ����30��~3600��
    IVS_CHAR	cReserve[32];
}IVS_GUARD_POS_INFO;

// Ѳ������
typedef enum
{
    CRUISE_TRACK = 1,       // �켣Ѳ��
    CRUISE_MODE,            // ģʽѲ��
    CRUISE_HORIZONTAL,      // ˮƽѲ��
    CRUISE_VERTICAL,        // ��ֱѲ��
}IVS_CRUISE_TYPE;

// �ƾ�Ѳ���켣��
typedef struct
{
    IVS_UINT32  uiPresetIndex;  // Ԥ��λ����, ���20����
    IVS_UINT32  uiDwellTime;    // Ԥ��λͣ��ʱ�䣬��Ϊ��λ��1~3600�� 
    IVS_UINT32  uiSpeed;        // ��̨�ٶȣ�1~10 
    IVS_CHAR	cReserve[32];
}IVS_CRUISE_TRACK_POINT;

// �ƾ�Ѳ���켣
#define IVS_MAX_CURISE_TRACK_NUM    16  // ������������Ѳ���켣����
#define IVS_CURISE_TRACK_NAME_LEN   84  // �켣����
#define IVS_MAX_CURISE_TRACK_POINT  20  // Ѳ���켣Ԥ��λ������
typedef struct
{
    IVS_UINT32  uiCruiseNO;                                             // �켣����
    IVS_UINT32  uiCruiseType;                                           // Ѳ�����ͣ�ֵ�ο� IVS_CRUISE_TYPE
    IVS_CHAR    cTrackName[IVS_CURISE_TRACK_NAME_LEN];                  // �켣����
    IVS_UINT32  uiTrackPointNum;                                        // �켣�����
    IVS_CRUISE_TRACK_POINT  stTrackPoint[IVS_MAX_CURISE_TRACK_POINT];   // �켣���б�
    IVS_CHAR	cReserve[32];
}IVS_CRUISE_TRACK;

// ʱ��Ƭ�νṹ
typedef struct
{
    IVS_CHAR	cStart[IVS_TIME_LEN];   // ��ʽ��yyyyMMddHHmmss
    IVS_CHAR	cEnd[IVS_TIME_LEN];     // ��ʽ��yyyyMMddHHmmss
    IVS_UINT32  uiCruiseNO;             // �켣����
    IVS_UINT32  uiCruiseType;           // Ѳ�����ͣ�ֵ�ο� IVS_CRUISE_TYPE
    IVS_CHAR	cReserve[32];
}IVS_CRUISE_TIME_SPAN;

// Ѳ���ƻ���Ϣ
typedef struct
{
    IVS_UINT32      uiDayType;								//���ڼ����ο� IVS_DAY_TYPE 0 �C ÿ�� 1 �C ��һ 2 �C �ܶ� 3 �C ���� 4 �C ���� 5 �C ���� 6 �C ���� 7 �C ����
    IVS_UINT32      uiTimeSpanInfoNum;						//ʱ�������
    IVS_CRUISE_TIME_SPAN   stTimeSpanInfo[IVS_MAX_TIMESPAN_NUM];   //ʱ�����Ϣ
}IVS_CRUISE_PLAN_INFO;

// Ѳ���ƻ�
typedef struct
{
    IVS_BOOL	bEnable;        // �Ƿ����üƻ���0-ͣ�ã�1-����
    IVS_UINT32	uiPlanType;		// �ƻ���ʽ��0-(WEEK)�ܼƻ�,1(DAY)-�ռƻ�����һ�����ռƻ���ͬ
    IVS_CHAR	cReserve[32];
    IVS_UINT32	uiPlanInfoNum;			                // �ƻ���Ϣ�������ܼƻ�-7���ռƻ�-1
    IVS_CRUISE_PLAN_INFO	stPlanInfo[IVS_MAX_PLAN_INFO_NUM];	// �ƻ���Ϣ���ܼƻ�-���7���ƻ���Ϣ���ռƻ�-1һ���ƻ���Ϣ
}IVS_CRUISE_PLAN;

// ʱ��Ƭ�νṹ
typedef struct
{
    IVS_CHAR	cStart[IVS_TIME_LEN];   // ��ʽ��yyyyMMddHHmmss
    IVS_CHAR	cEnd[IVS_TIME_LEN];     // ��ʽ��yyyyMMddHHmmss
    IVS_UINT32  SnapInterval;           // ץ��ʱ����
}IVS_SNAPSHOT_TIME_SPAN;

// ץ�ļƻ���Ϣ
typedef struct
{
    IVS_UINT32      uiDayType;								//���ڼ����ο� IVS_DAY_TYPE 0 �C ÿ�� 1 �C ��һ 2 �C �ܶ� 3 �C ���� 4 �C ���� 5 �C ���� 6 �C ���� 7 �C ����
    IVS_UINT32      uiTimeSpanInfoNum;						//ʱ�������
    IVS_SNAPSHOT_TIME_SPAN   stTimeSpanInfo[IVS_MAX_TIMESPAN_NUM];   //ʱ�����Ϣ
}IVS_SNAPSHOT_PLAN_INFO;

// ץ�ļƻ�
typedef struct
{
    IVS_BOOL	bEnable;        // �Ƿ����üƻ���0-ͣ�ã�1-����
    IVS_UINT32	uiPlanType;		// �ƻ���ʽ��0-(WEEK)�ܼƻ�,1(DAY)-�ռƻ�����һ�����ռƻ���ͬ
    IVS_CHAR	cReserve[32];
    IVS_UINT32	uiPlanInfoNum;			                // �ƻ���Ϣ�������ܼƻ�-7���ռƻ�-1
    IVS_SNAPSHOT_PLAN_INFO	stPlanInfo[IVS_MAX_PLAN_INFO_NUM];	// �ƻ���Ϣ���ܼƻ�-���7���ƻ���Ϣ���ռƻ�-1һ���ƻ���Ϣ
}IVS_SNAPSHOT_PLAN;
const IVS_UINT32 IVS_SNAPSHOT_TYPE_IA       = 0x00000001;   // ���ܷ���ץ��
const IVS_UINT32 IVS_SNAPSHOT_TYPE_ALARM    = 0x00000002;   // �澯ץ��
const IVS_UINT32 IVS_SNAPSHOT_TYPE_MANUAL   = 0x00000004;   // �ֶ�ץ��(������ʱץ��)

// ץ��ͼƬ��ѯ��Ϣ
typedef struct
{
    IVS_TIME_SPAN   stTimeSpan;     // ץ��ͼƬʱ�䷶Χ
    IVS_INDEX_RANGE stIndexRange;   // ץ��ͼƬ������Ϣ
    IVS_UINT32      uiSnapType;     // ץ��ͼƬ���ͣ������ֵ������0x01 | 0x02=3��ʾ��ѯ���Ͱ������ܷ���ץ�ĺ͸澯ץ�ģ�ֵ�ο�IVS_SNAPSHOT_TYPE_IA
    IVS_CHAR	    cReserve[64];
}IVS_QUERY_SNAPSHOT_PARAM;

// ץ��ͼƬ��Ϣ
typedef struct
{
    IVS_CHAR    cCameraCode[IVS_DEV_CODE_LEN];      // ���������
    IVS_CHAR	cSnapTime[IVS_TIME_LEN];            // ץ��ͼƬʱ�䣬��ʽ��yyyyMMddHHmmss
    IVS_UINT32  uiSnapType;                         // ץ�����ͣ��ο�IVS_SNAPSHOT_TYPE_IA
    IVS_UINT32	uiPictureID;                        // ץ��ͼƬID
    IVS_CHAR    cPictureName[IVS_FILE_NAME_LEN];    // �ļ���
    IVS_UINT32	uiPictureSize;                      // ͼƬ�ļ���С
    IVS_CHAR    cPreviewUrl[IVS_URL_LEN];	        // ץ��ͼƬ����ͼURL
    IVS_CHAR    cPictureUrl[IVS_URL_LEN];	        // ץ��ͼƬURL
    IVS_CHAR    cReserve[32];
}IVS_SNAPSHOT_INFO;

// ץ��ͼƬ�б���Ϣ
typedef struct
{
    IVS_UINT32   uiTotal;                   // �ܼ�¼��
    IVS_INDEX_RANGE stIndexRange;           // ��ҳ��Ϣ
    IVS_SNAPSHOT_INFO stSnapshotInfo[1];    // ץ��ͼƬ��Ϣ
}IVS_SNAPSHOT_INFO_LIST;

// ʵ������
typedef struct
{
    IVS_UINT32      uiStreamType;       // �������ͣ�ֵ�ο� IVS_STREAM_TYPE
    IVS_UINT32      uiProtocolType;     // Э�����ͣ�1-UDP 2-TCP��Ĭ��Ϊ1
    IVS_BOOL        bDirectFirst;       // �Ƿ�ֱ�����ȣ�0-�� 1-�ǣ�Ĭ��Ϊ0
    IVS_BOOL        bMultiCast;         // �Ƿ��鲥��0-������1-�鲥��Ĭ��Ϊ0
    IVS_CHAR	    cReserve[32];
}IVS_REALPLAY_PARAM;

// ¼��طŲ���
typedef struct
{
    IVS_UINT32      uiProtocolType;     // Э�����ͣ�1-UDP 2-TCP��Ĭ��Ϊ1
    IVS_TIME_SPAN   stTimeSpan;         // ʵ������������ʱ��
    IVS_FLOAT       fSpeed;             // �ط�����
    IVS_CHAR	    cReserve[32];
}IVS_PLAYBACK_PARAM;

// ����¼��طŲ���
typedef struct
{
    IVS_UINT32      uiStartTime;        // �ط���ʼʱ�䣬��λ����
    IVS_UINT32      uiEndTime;          // �طŽ���ʱ�䣬��λ����
    IVS_FLOAT       fSpeed;             // �ط�����
    IVS_CHAR        cPWD[IVS_PWD_LEN];  // ¼�����루Ϊ�ձ�ʾ�����룩
    IVS_CHAR	    cReserve[32];
}IVS_LOCAL_PLAYBACK_PARAM;

// ý���ַ
typedef struct
{
    IVS_IP      stIP;		                    // ý����Ŀ��IP
    IVS_UINT32  uiAudioPort;                    // ý����Ŀ����Ƶ�˿�
    IVS_UINT32  uiVideoPort;                    // ý����Ŀ����Ƶ�˿�
    IVS_CHAR	cReserve[32];
}IVS_MEDIA_ADDR;

// ����ǽ����
#define IVS_TVWALL_DECODER_CODE_LEN     24  // ����ǽ����������
typedef struct
{
    IVS_CHAR    cDecoderCode[IVS_TVWALL_DECODER_CODE_LEN];  // ����ǽ����������
    IVS_UINT32  uiChannel;                                  // ������ͨ����
    IVS_CHAR	cReserve[32];
}IVS_TVWALL_PARAM;

// ˮӡ�澯ȷ����Ϣ
#define IVS_WATERMARK_ALARM_DESCRIPTION_LEN 1024
typedef struct
{
    IVS_CHAR    cCameraCode[IVS_DEV_CODE_LEN];                      // ���������
    IVS_UINT64	ullAlarmEventID;                                    // �澯�¼�ID
    IVS_CHAR    cConfirmInfo[IVS_WATERMARK_ALARM_DESCRIPTION_LEN];	// �澯������Ա�������Ϣ
    IVS_CHAR    cConfirmTime[IVS_TIME_LEN];				            // �澯����ʱ��    
    IVS_CHAR	cReserve[64];
}IVS_WATERMARK_ALARM_CONFIRM;

// ˮӡ�澯ȡ����Ϣ
typedef struct
{
    IVS_CHAR    cCameraCode[IVS_DEV_CODE_LEN];                      // ���������
    IVS_UINT64	ullAlarmEventID;                                    // �澯�¼�ID
    IVS_CHAR    cCancelInfo[IVS_WATERMARK_ALARM_DESCRIPTION_LEN];	// �澯������Ա�������Ϣ
    IVS_CHAR    cCancelTime[IVS_TIME_LEN];				            // �澯����ʱ��
    IVS_CHAR	cReserve[64];
}IVS_WATERMARK_ALARM_CANCEL;

// ˮӡ�澯��Ϣ
typedef struct
{
    IVS_UINT64	ullAlarmEventID;                                    // �澯�¼�ID
    IVS_CHAR    cAlarmType[IVS_ALARM_TYPE_LEN];		                // �澯���ͣ�ˮӡ�澯
    IVS_CHAR    cCheckoutOperator[IVS_NAME_LEN];	                // ˮӡУ����
    IVS_CHAR    cCameraCode[IVS_DEV_CODE_LEN];                      // ���������
    IVS_CHAR	cOccurStartTime[IVS_TIME_LEN];                      // ˮӡ�澯����ʱ�䣺YYYYMMDDHHMMSSmmm
    IVS_CHAR	cOccurStopTime[IVS_TIME_LEN];                       // ˮӡ�澯����ʱ�䣺YYYYMMDDHHMMSSmmm
    IVS_CHAR    cConfirmOperator[IVS_NAME_LEN];	                    // �澯ȷ����
    IVS_CHAR    cConfirmTime[IVS_TIME_LEN];	                        // �澯ȷ��ʱ��
    IVS_CHAR    cConfirmInfo[IVS_WATERMARK_ALARM_DESCRIPTION_LEN];	// �澯ȷ��������Ϣ�����̿ɼ��ַ������ģ�
    IVS_UINT32  uiWatermarkAlarmStatus;                             // ˮӡ�澯״̬��0x01-δȷ�� 0x02-��ȷ�� 0x04-�ѳ��������ֵ��ʾ��ѡ����0x07��ʾ��ѯ����״̬��0x06��ʾ��ѯ��ȷ�Ϻ��ѳ�����
    IVS_CHAR	cReserve[64];
}IVS_WATERMARK_ALARM_INFO;

typedef struct
{
    IVS_UINT32   uiTotal;                               // �ܼ�¼��
    IVS_INDEX_RANGE stIndexRange;                       // ��ҳ��Ϣ
    IVS_WATERMARK_ALARM_INFO stWatermarkAlarmInfo[1];   // ˮӡ�澯��Ϣ
}IVS_WATERMARK_ALARM_INFO_LIST;

// SFTP��Ϣ
#define IVS_FTP_ACCOUNT_LEN			64			// ���Ƴ���
typedef struct
{
    IVS_IP      stIP;		                    // ������IP
    IVS_UINT32  uiPort;		                    // �������˿�
    IVS_CHAR    cAccount[IVS_FTP_ACCOUNT_LEN];  // �������˺�
    IVS_CHAR    cPWD[IVS_PWD_LEN];              // �������˺ŵ�����
    IVS_CHAR	cReserve[32];
}IVS_FTP_INFO;

typedef struct
{
    IVS_FTP_INFO    stFTPInfo;                          // ftp��Ϣ
    IVS_CHAR        cMapFilePath[IVS_FILE_NAME_LEN];    // ���ӵ�ͼ·����Ϣ
    IVS_CHAR        cReserve[32];                       //�����ֶ�
}IVS_MAP_FTP_INFO;

/*�㲥ʧ���쳣�¼��ṹ��*/
typedef struct ST_BROADCAST_FAILED_INFO
{
    IVS_INT32 iSessionID;                             //��¼�ỰID
    IVS_CHAR cVoiceCode[IVS_DEV_CODE_LEN + 1];          //�㲥ʧ�ܵ������豸����
}BROADCAST_FAILED_INFO;

/*�ֱ�����Ϣ*/
typedef struct
{
	IVS_CHAR cResolution[IVS_FILE_NAME_LEN];   //�ֱ�����Ϣ
	IVS_CHAR cPFrameList[IVS_MAX_NAME_LIST_LEN]; //֡���б��Զ��ŷָ�
	IVS_CHAR cNFrameList[IVS_MAX_NAME_LIST_LEN]; //֡���б��Զ��ŷָ�
	IVS_CHAR cReserve[32]; //�����ֶ�
}IVS_RESOLUTION_INFO;

/*I֡��Ϣ*/
typedef struct
{
	IVS_INT32 iPMinIFrameInterval; //P����СI֡���
	IVS_INT32 iPMaxIFrameInterval; //P�����I֡���
	IVS_INT32 iNMinIFrameInterval; //N����СI֡���
	IVS_INT32 iNMaxIFrameInterval; //N�����I֡���
	IVS_CHAR cReserve[32]; //�����ֶ�
}IVS_IFRAME_INFO;

/*����������Ϣ*/
typedef struct
{
	IVS_CHAR cEncodeMode[IVS_DEV_MODEL_LEN];    // ��������
	IVS_CHAR cProfileList[IVS_MAX_NAME_LIST_LEN];   // Profile�б�,�Զ��ŷָ�
	IVS_CHAR cBitRateList[IVS_MAX_NAME_LIST_LEN];  //�����б�,�Զ��ŷָ�
	IVS_INT32 iRealNum;    // �б���������30��
	IVS_IFRAME_INFO stIFrameInfo;   //I֡��Ϣ
	IVS_RESOLUTION_INFO stResolution[IVS_MAX_RESOLUTION_LIST_NUM];        // �ֱ����б�
	IVS_CHAR cReserve[32]; //�����ֶ�
}IVS_ENCODEMODE_INFO;

/*�������ͽṹ��*/
typedef struct
{
	IVS_CHAR cStreamType[IVS_FILE_NAME_LEN];  //��������
	IVS_INT32 iRealNum;     // �б���������2��
	IVS_ENCODEMODE_INFO stEncodeMode[IVS_MAX_ENCODE_LIST_NUM]; //���������б�
	IVS_CHAR cReserve[32]; //�����ֶ�
}IVS_ST_STREAM_INFO;

/*����������б�ṹ��*/
typedef struct
{
	IVS_INT32 iRealNum;                   // �б���������3��
	IVS_ST_STREAM_INFO stStreamInfo[IVS_MAX_STREAM_LIST_NUM];  // ������Ϣ�б�
	IVS_CHAR cReserve[32]; //�����ֶ�
}IVS_STREAM_INFO_LIST;

/******************************************************************
 function   : EventCallBack
 description: �¼��ص�����(�¼�֪ͨ���쳣�ص���)
 input      : NA
 output     : iEventType    �¼�����;
              pEventBuf     �¼�����;
              uiBufSize     buf����;
              pUserData     �û�����;
 return     : IVS_VOID
*******************************************************************/
typedef IVS_VOID (__SDK_CALL * EventCallBack)(IVS_INT32 iEventType, IVS_VOID* pEventBuf, IVS_UINT32 uiBufSize, IVS_VOID* pUserData);

/******************************************************************
 function   : DownloadCallBackRaw
 description: ƴ֡�������ص�����(¼������)
 input      : NA
 output     : ulHandle      ���ž��;
              pRawFrameInfo ������֡���Ͳ���;
              pBuf          ֡����;
              uiBufSize     buf����;
              pUserData     �û�����;
 return     : IVS_VOID
*******************************************************************/
typedef IVS_VOID (__SDK_CALL * DownloadCallBackRaw)(IVS_ULONG ulHandle, IVS_RAW_FRAME_INFO* pRawFrameInfo, IVS_VOID* pBuf, IVS_UINT32 uiBufSize, IVS_VOID* pUserData);

/******************************************************************
 function   : RealPlayCallBackRaw
 description: ƴ֡�������ص�����(ʵ��)
 input      : NA
 output     : ulHandle      ���ž��;
              pRawFrameInfo ������֡���Ͳ���;
              pBuf          ֡����;
              uiBufSize     buf����;
              pUserData     �û�����;
 return     : IVS_VOID
*******************************************************************/
typedef IVS_VOID (__SDK_CALL * RealPlayCallBackRaw)(IVS_ULONG ulHandle, IVS_RAW_FRAME_INFO* pRawFrameInfo, IVS_VOID* pBuf, IVS_UINT32 uiBufSize, IVS_VOID* pUserData);

/******************************************************************
 function   : PlayBackCallBackRaw
 description: ƴ֡�������ص�����(¼��ط�)
 input      : NA
 output     : ulHandle      ���ž��;
              pRawFrameInfo ������֡���Ͳ���;
              pBuf          ֡����;
              uiBufSize     buf����;
              pUserData     �û�����;
 return     : IVS_VOID
*******************************************************************/
typedef IVS_VOID (__SDK_CALL * PlayBackCallBackRaw)(IVS_ULONG ulHandle, IVS_RAW_FRAME_INFO* pRawFrameInfo, IVS_VOID* pBuf, IVS_UINT32 uiBufSize, IVS_VOID* pUserData);

/******************************************************************
 function   : RealPlayCallBackFrame
 description: ��ȡ����������ص�����(ʵ��)
 input      : NA
 output     : ulHandle      ���ž��;
              uiStreamType  ֡����(��Ƶ����Ƶ���ο�IVS_MEDIA_STREAM);
              pFrameInfo    ֡���Ͳ���(��Ƶ���Ͳο�IVS_VIDEO_FRAME����Ƶ���Ͳο�IVS_AUDIO_FRAME);
              pUserData     �û�����;
 return     : IVS_VOID
*******************************************************************/
typedef IVS_VOID (__SDK_CALL * RealPlayCallBackFrame)(IVS_ULONG ulHandle, IVS_UINT32 uiStreamType, IVS_VOID* pFrameInfo, IVS_VOID* pUserData);

/******************************************************************
 function   : PlayBackCallBackFrame
 description: ��ȡ����������ص�����(¼��ط�)
 input      : NA
 output     : ulHandle      ���ž��;
              uiStreamType  ֡����(��Ƶ����Ƶ���ο�IVS_MEDIA_STREAM);
              pFrameInfo    ֡���Ͳ���(��Ƶ���Ͳο�IVS_VIDEO_FRAME����Ƶ���Ͳο�IVS_AUDIO_FRAME);
              pUserData     �û�����;
 return     : IVS_VOID
*******************************************************************/
typedef IVS_VOID (__SDK_CALL * PlayBackCallBackFrame)(IVS_ULONG ulHandle, IVS_UINT32 uiStreamType, IVS_VOID* pFrameInfo, IVS_VOID* pUserData);

// ��ͼ�ص�
typedef IVS_VOID (__SDK_CALL * DRAW_PROC)(IVS_VOID *hDc, IVS_VOID *rc, IVS_UINT64 ullFrameID, IVS_VOID *pUser);

#pragma pack(pop)

#endif //_HW_IVS_SDK_H_