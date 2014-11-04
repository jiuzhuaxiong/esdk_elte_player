/********************************************************************
Copyright 2012,TD-Tech. Co., Ltd.
Filename:    reportmanager.h
Author:      Wang Kai
Created:     2013/01/23 10:00
Description: ReportManager接口，子类继承实现

*********************************************************************/

#ifndef REPORTMANAGER_H
#define REPORTMANAGER_H

#include "sdk_export.h"

class GISReportIndicator;

class SDK_IMPORT_EXPORT GISReportManager
{
public:

    //GIS上报数据
    virtual void notifyGISReport(GISReportIndicator *) = 0;
    //GIS订阅通知
    virtual void notifyGISSubRsp(GISReportIndicator * ) = 0;

private:

};


#endif // REPORTMANAGER_H
