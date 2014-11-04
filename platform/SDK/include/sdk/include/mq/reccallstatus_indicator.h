﻿#ifndef RECCALL_STATUSINDICATOR_H
#define RECCALL_STATUSINDICATOR_H

#include "mq/p2pvideocallstatus_indicator.h"
#include "mq/p2pcallstatus_indicator.h"
#include "mq/grpcallstatus_indicator.h"



class SDK_IMPORT_EXPORT RECGroupStatusIndicator: public GrpDspInfo
{
public:
	RECGroupStatusIndicator(MSISDN grpId);
        RECGroupStatusIndicator(RECGroupStatusIndicator& copy);
	void setVpnid(int callervpnid, int calleevpnid);
	void setRecUser(MSISDN reccaller, MSISDN reccallee);
	void setCallId(MSISDN callid);
	MSISDN getRECCaller();
	MSISDN getRECCallee();
	MSISDN getCallerVpnId();
	MSISDN getCalleeVpnId();
	MSISDN getCallId();

private:
    MSISDN theRECCaller;
    MSISDN theRECCallee;
    int theCallerVpnId;
    int theCalleeVpnId;
    MSISDN theCallId;
};

class SDK_IMPORT_EXPORT RECP2pcallStatusIndicator: public P2pcallStatusIndicator
{
public:
	RECP2pcallStatusIndicator(MSISDN caller, MSISDN callee);
        RECP2pcallStatusIndicator(RECP2pcallStatusIndicator& copy);
	void setVpnid(int callervpnid, int calleevpnid);
	void setRecUser(MSISDN reccaller, MSISDN reccallee);
	void setCallId(MSISDN callid);
	MSISDN getRECCaller();
	MSISDN getRECCallee();
	MSISDN getCallerVpnId();
	MSISDN getCalleeVpnId();
	MSISDN getCallId();
private:
    MSISDN theRECCaller;
    MSISDN theRECCallee;
    int theCallerVpnId;
    int theCalleeVpnId;
    MSISDN theCallId;
};

class SDK_IMPORT_EXPORT RECP2pvideocallStatusIndicator: public P2pvideocallStatusIndicator
{
public:
	RECP2pvideocallStatusIndicator(MSISDN caller, MSISDN callee);
        RECP2pvideocallStatusIndicator(RECP2pvideocallStatusIndicator& copy);
        void setVpnid(int callervpnid, int calleevpnid);
	void setRecUser(MSISDN reccaller, MSISDN reccallee);
	void setCallId(MSISDN callid);
    MSISDN getRECCaller();
    MSISDN getRECCallee();
    MSISDN getCallerVpnId();
    MSISDN getCalleeVpnId();
    MSISDN getCallId();

private:
    MSISDN theRECCaller;
    MSISDN theRECCallee;
    int theCallerVpnId;
    int theCalleeVpnId;
    MSISDN theCallId;
};


#endif // RECCALLSTATUS_INDICATOR_H
