#ifndef P2PVIDEOCALL_STATUSINDICATOR_H
#define P2PVIDEOCALL_STATUSINDICATOR_H

#include "sdk_export.h"
#include "common.h"
#include <string>
/**
   定义群组显示数据结构
**/
typedef enum {
	P2Pvideocall_IND_STATUS_UNKNOWN=3000,
/*------------信令面状态-----------*/
    P2Pvideocall_IND_STATUS_INITIATED,
    P2Pvideocall_IND_STATUS_RECEIVED,
    P2Pvideocall_IND_STATUS_ANSWERED,
    P2Pvideocall_IND_STATUS_PROCEEDING,
    P2Pvideocall_IND_STATUS_RINGING,
    P2Pvideocall_IND_STATUS_ACKED,
    P2Pvideocall_IND_STATUS_RELEASED,
    P2Pvideocall_IND_STATUS_HANGUPED,
    P2Pvideocall_IND_STATUS_HANGUPED_ACTIVE,
    P2Pvideocall_IND_STATUS_CANCELLED,
    P2Pvideocall_IND_STATUS_MONITOR,
    P2Pvideocall_IND_STATUS_PREMPTED,
    P2Pvideocall_IND_STATUS_RELEASED_BUSY,
    P2Pvideocall_IND_STATUS_PROHIBITED,
    P2Pvideocall_IND_STATUS_REMOTE_NOANSWER,
    P2Pvideocall_IND_STATUS_REMOTE_NOTFOUND,
    P2Pvideocall_IND_STATUS_LICENSE_LIMIT,
    P2Pvideocall_IND_STATUS_EMERGENCY,
	/*------------媒体面状态-----------*/
    P2Pvideocall_IND_STATUS_ACKED_MEDIAPLANE_ERROR,  //视频RTP流建立失败
    P2Pvideocall_IND_STATUS_ACKED_MEDIAPLANE_NOAUDIO, //视频伴音流建立失败
    P2Pvideocall_IND_STATUS_REMOTE_NOTCONNECTED,
    P2Pvideocall_IND_STATUS_REMOTE_NOTSUPPORTED
} P2pvideocall_Status_t;



class SDK_IMPORT_EXPORT P2pvideocallStatusIndicator
{
public:
    P2pvideocallStatusIndicator(MSISDN caller, MSISDN callee);
    P2pvideocallStatusIndicator(P2pvideocallStatusIndicator& copy);
    virtual ~P2pvideocallStatusIndicator();
    std::string datalog_str();

    void setStatus(P2pvideocall_Status_t status);
    void setPeers(MSISDN caller, MSISDN callee);
    void setPorts(int local_audio_port,int local_video_port, int remote_audio_port, int remote_video_port);
    void setRemoteIp(unsigned long Remote_ip);
    void setSoundMute(int muteflag);
    void setChannel(int ChannelId);
    void setUri(MSISDN UriId);
    void setUserCfm(int cfmid);
    void setCamera(int Cameraid);
    void setSoundPtype(Sound_t Ptype); 
    void setFmt(Fmt_type FmtVlaue);

    MSISDN getCaller();
    MSISDN getCallee();
    int getlocalaudioport();
    int getlocalvideoport();
    int getremoteaudioport();
    int getremotevideoport();
    unsigned long getRemoteIp();
    int getSoundMute();
    int getChannel();
    MSISDN getUri();
    int getUserCfm();
    int getCamera();
    Sound_t getSoundPtype();
    Fmt_type getFmt();
    P2pvideocall_Status_t getStatus();

private:
    MSISDN theCaller;
    MSISDN theCallee;
    P2pvideocall_Status_t theStatus;

    //SDP related information
    //for the case of media_bypass, upper layer need handle media setup
    int theLocal_port_audio;
    int theLocal_port_video;
    int theRemote_port_audio;
    int theRemote_port_video;
    unsigned long theRemote_ip_video;
    int sound_mute;
    MSISDN uri;
    int channel;
    int usercfm;
    int Camera;
    Sound_t soundpldtype;
    Fmt_type Fmt;
};

#endif // P2PVIDEOCALLSTATUS_INDICATOR_H
