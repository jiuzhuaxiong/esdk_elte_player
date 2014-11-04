/********************************************************************
Copyright 2012,TD-Tech. Co., Ltd.
Filename:    uioperation.h
Author:      Wu yu wei
Created:     2012/07/26 16:00
Description:
*********************************************************************/

#ifndef UIOPERATION_H
#define UIOPERATION_H

#include "resourceinfo.h"
#include "operationmanager.h"

class UIOperation
{
public:

    virtual ACE_INT32 invoke(ResourceInfo * resInfo);
};

class UIOperationMultiPara
{
public:

    virtual ACE_INT32 invoke(ResourceInfo * resInfo,void * MultiPara);
};

#endif // UIOPERATION_H
