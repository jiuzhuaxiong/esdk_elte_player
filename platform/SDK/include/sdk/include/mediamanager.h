/********************************************************************
Copyright 2012,TD-Tech. Co., Ltd.
Filename:    meidamanager.h
Author:      Wang Kai
Created:     2012/09/14 16:00
Description: 定义调度台的媒体面接口，要求ＧＵＩ实现此文件中定义的接口，从而和ＡＰＰ交换媒体数据 其中
    MediaManager：　为一个工厂类接口，　负责生成VideoRenderer和VideoCapturer的具体实现类
    VideoRenderer： 为视频显示(或者输出）接口， 负责从APP传递视频帧数据到GUI
    VideoCapturer:  为视频捕获（或者输入）接口， 负责从GUI传递视频帧数据到APP
*********************************************************************/

#ifndef DC_MEDIAMANAGER_H
#define DC_MEDIAMANAGER_H

#include <string>
#include <vector>
#include <memory>
#include "sdk_export.h"

typedef enum {
    no_rotate =0,
    rotate_clockwise,   //90
    rotate_flip,        //180
    rotate_anticlockwise    //270

}Rotate_Type_t;

typedef unsigned char uint8_t;
typedef struct _YuvFrame{
        int w,h;
        uint8_t *planes[4]; /*we usually use 3 planes, 4th is for compatibility */
        int strides[4];	/*with ffmpeg's swscale.h */
}YuvFrame;

/******************************************************
//Abstract interface for render control (can be like RTSP-style render control)
// or render control such as rotate
*******************************************************/
class RenderControl {
 public:
    virtual void rotate(Rotate_Type_t rotate) =0;
};

class VideoCapturer {
 public:

};

/*************************************************
// Abstract interface for rendering VideoFrames.
//
****************************************************/
class VideoRenderer {
 public:

  // 设置视频帧尺寸.
  virtual void SetSize(int width, int height, int reserved) = 0;

  //设置视频帧对应的REsourceID
  virtual void SetResourceID(MSISDN logical, MSISDN physical) = 0;

  // 设置render所服务的videochannel
  virtual void SetVideoChannel(void* vc) = 0;

  // 绘制当前YUV视频帧.非const表示可能会修改YuvFrame的方向，对称性等
  virtual bool RenderYUVFrame(YuvFrame* frame, MSISDN physicalRid) = 0;
    virtual RenderControl* getRenderControl() = 0;
    virtual MSISDN getPhysical()=0;
    virtual MSISDN getLogical()=0;

    virtual void stopRendering()=0;
};

/******************************************************
//Abstract interface for capture control (mainly PTZ)
//Not yet started
*******************************************************/
class CaptureControl {
 public:

  // 查询是否支持PTZ control.
  virtual bool getPTZSupport() = 0;
  //设置capture control 对应的 ResourceID
  virtual bool SetResourceID(MSISDN rid) = 0;

  virtual bool doPTZcontrol(int cmdcode,int value) = 0;

};

/******************************************************************
// Abstract interface for construct video renderer and video capturer.
//
*******************************************************************/
class MediaManager {
 public:

    virtual bool isMultiResource(MSISDN resID) =0;
    virtual int getLogicalResid(MSISDN physicalResid) =0;
    virtual VideoRenderer* getRender(MSISDN resID) =0;
    virtual VideoRenderer* getRender4MultiResource(MSISDN resID) =0;
    virtual VideoRenderer* new_renderer4MultiResource(MSISDN resID) =0;

  // to construct one VideoRenderer object for a video resource.
  virtual VideoRenderer* new_renderer( MSISDN resID) = 0;

    // to Destruct one VideoRenderer object for a video resource.
    virtual void del_renderer( MSISDN resID) =0;

};

#endif // DC_MEDIAMANAGER_H
