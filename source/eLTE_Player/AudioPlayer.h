#ifndef __ELTE_OCX_AUDIO_PLAYER_H__
#define __ELTE_OCX_AUDIO_PLAYER_H__

// PCM����
#include "OpencoreAmrnb.h"
#include <Mmsystem.h>
#pragma comment(lib, "Winmm.lib")


//////////////////////////////////////////////////////////////////////////
#define AUDIO_FRAME_DATA_SZ  512         //��Ƶ֡�ߴ�, FIX ME!!!!
#define WAVE_BUFF_SZ    (sizeof(WAVEHDR) + AUDIO_FRAME_DATA_SZ)
#define WAVE_RING_SZ    1024

typedef struct
{
	BOOL     bInUse;
	WAVEHDR  Hdr;
	char     WaveData[AUDIO_FRAME_DATA_SZ];
} WAVE_OUT_BUF;

//////////////////////////////////////////////////////////////////////////

class AudioPlayer
{
public:
	AudioPlayer(void);
	~AudioPlayer(void);

public:
	// ��ʼ������
	int WaveOutInit();
	// �˳�����
	int WaveOutExit();
	// ����PCM
	int WaveOutPlay(char* pAmr, unsigned int len);
	// ���ò�������
	int WaveOutSetVolume(DWORD dwVolume);
	// ��ȡ��������
	int WaveOutGetVolume(DWORD& dwVolume);
	// ��ʼ������
	int WaveOutInitVolume(DWORD dwVolume);

private:
	// waveOut�ص�����
	static void CALLBACK WaveOutProc(HWAVEOUT hwo, UINT uMsg, DWORD_PTR dwInstance, DWORD_PTR dwParam1, DWORD_PTR dwParam2);

private:
	// ������Ƶ������
	HWAVEOUT m_hWaveOut;
	// ������Ƶ�ĸ�ʽ
	WAVEFORMATEX m_waveformat;

	// ���Ż���
	WAVE_OUT_BUF m_WaveOutBuf[WAVE_RING_SZ];
	unsigned int m_uIdxToWrite;
	unsigned int m_uIdxToRead;

	// ����
	DWORD m_dwVolume;

private:
	// ������
	OpencoreAmrnb m_OpencoreAmrnb;
};

#endif
