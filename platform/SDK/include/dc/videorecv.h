#ifndef VIDEORECV_H_
#define VIDEORECV_H_


#define RECV_SUCCESS       0
#define RECV_NOT_INIT     -1
#define RECV_DUPLICATE    -2
#define RECV_BINDSOCKFAIL -3


typedef void (*VideoRecvCallBack)(unsigned int local_ip, unsigned short local_port,
	                              unsigned char *frame, int frame_size);

__declspec(dllexport) int video_recv_init();

__declspec(dllexport) void video_recv_uninit();

__declspec(dllexport) int add_recv_task(unsigned int local_ip, unsigned short local_port, VideoRecvCallBack callback);

__declspec(dllexport) void del_recv_task(unsigned int local_ip, unsigned short local_port);

#endif