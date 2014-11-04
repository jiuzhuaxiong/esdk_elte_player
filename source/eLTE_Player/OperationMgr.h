/********************************************************************
filename    :    OperationMgr.h
author      :    yubinbin wx200189
created     :    2014/07/01
description :    ����̨���������ࡣ����ע�ᡢע������Ƶ�ش�ҵ���߼�������ӦeLTE SDK�ڵ�OperationManager��
copyright   :    Copyright (c) 2012-2016 Huawei Tech.Co.,Ltd
history     :    2014/07/01 ��ʼ�汾
*********************************************************************/

#ifndef __ELTE_OCX_OPERATION_MGR_H__
#define __ELTE_OCX_OPERATION_MGR_H__

#include "DataType.h"


//////////////////////////////////////////////////////////////////////////
// ��Ƶ�ش�����
struct STVideoParam
{
	std::string strFmtValue;
	std::string strCameraType;
	std::string strUserCfmType;
	std::string strMuteType;

	STVideoParam& operator = (const STVideoParam& v)
	{
		strFmtValue = v.strFmtValue;
		strCameraType = v.strCameraType;
		strUserCfmType = v.strUserCfmType;
		strMuteType = v.strMuteType;
		return *this;
	}
};

//////////////////////////////////////////////////////////////////////////
class OperationMgr
{
public:
	static OperationMgr& Instance();

private:
	OperationMgr(void);
	~OperationMgr(void);

public:
	// ����̨ע��
	int DcLogin(const std::string& userId, const std::string& passwd, 
		const std::string& serverIP, const std::string& localIP, const std::string& sipPort, bool bEnableStatusReport);
	// ����̨ע��
	int DcLogout(const std::string& userId);
	// ����״̬�ϱ�
	int DcTriggerStatusReport(bool bEnableStatusReport) const;
	// ����̨������Ƶ�ش�
	int DcVideoMonitor(int iResId, Video_UL_parameter& param, bool bNeedSave = true);
	// ����̨�Ҷ���Ƶ�ش�
	int DcVideoHangup(int iResId, bool bNeedSave = true);
	// ����Ⱥ��
	int DcSubscribeGroup(const std::string& groupId, unsigned long ulEableSubscribeGroup) const;
	// ���������ļ�����
	void SetParam(const std::string& strFrontFormat, const std::string& strBackFormat);

	// ���ڹ���������
public:
	// �л�����ͷ
	int DcVideoReverse(int iResId, STVideoParam& vParam);
	// ��ȡ�Ƿ�������
	std::string GetMuteType(int iResId);

	// ��½�ǳ�����
private:
	// �û�ID
	std::string m_userId;
	// �û�����
	std::string m_passwd;
	// ����IP
	std::string m_localIP;
	// ������IP
	std::string m_serverIP;
	// SIP�˿�
	std::string m_sipPort;

	// ���ڹ���������
private:
	// Ĭ��ǰ������ͷ��Ƶ��ʽ
	std::string m_strFrontFormat;
	// Ĭ�Ϻ�������ͷ��Ƶ��ʽ
	std::string m_strBackFormat;

	// ��Ƶ�ش���Դ�б�
public:
	std::map<int, STVideoParam> m_mapResource;
};

#endif
