/********************************************************************
filename    :    OpencoreAmrnb.h
author      :    yubinbin wx200189
created     :    2014/07/21
description :    音频转换类。使用opencore-amr开源库，把amr格式转换为wav格式
copyright   :    Copyright (c) 2012-2016 Huawei Tech.Co.,Ltd
history     :    2014/07/21 初始版本
*********************************************************************/

#ifndef __ELTE_OCX_OPENCOREAMRNB_H__
#define __ELTE_OCX_OPENCOREAMRNB_H__


//////////////////////////////////////////////////////////////////////////
// libopencore-amrnb-0.dll接口指针定义
//void* Decoder_Interface_init(void);
typedef void* (*Decoder_Interface_init)(void);
//void Decoder_Interface_exit(void* state);
typedef void (*Decoder_Interface_exit)(void* state);
//void Decoder_Interface_Decode(void* state, const unsigned char* in, short* out, int bfi);
typedef void (*Decoder_Interface_Decode)(void* state, const unsigned char* in, short* out, int bfi);

//////////////////////////////////////////////////////////////////////////

#define OPENCORE_AMR_MODULE_NAME	"libopencore-amrnb-0.dll"	// 开源库DLL名字
#define WAV_BUFFER_SIZE				320							// wav buffer大小
#define OUT_BUFFER_SIZE				160							// 临时buffer大小

typedef unsigned char uint8_t;
typedef short int16_t;

//////////////////////////////////////////////////////////////////////////

class OpencoreAmrnb
{
public:
	OpencoreAmrnb(void);
	~OpencoreAmrnb(void);

public:
	int Init();
	int Exit();
	uint8_t* DecodeAmrToWav(uint8_t* pAmr);

private:
	Decoder_Interface_init m_fpDecoder_Interface_init;
	Decoder_Interface_exit m_fpDecoder_Interface_exit;
	Decoder_Interface_Decode m_fpDecoder_Interface_Decode;

private:
	HMODULE		m_hModule;
	void*		m_pState;
	uint8_t*	m_pWav;
	int16_t*	m_pOutBuf;
};

#endif
