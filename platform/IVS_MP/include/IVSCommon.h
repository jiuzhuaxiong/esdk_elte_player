/********************************************************************
	filename	: 	IVSCommDef.h
	author		:	z00201790
	created		:	2012/10/23	
	description	:	�ṩIVSͨ�ô������
	copyright	:	Copyright (C) 2011-2015
	history		:	2012/10/23 ��ʼ�汾;
*********************************************************************/
#ifndef IVS_COMM_DEF_H
#define IVS_COMM_DEF_H

#pragma warning(disable : 4786 4503 4996)
#include <stdlib.h>

#define MUILI   1

//////////////////////////////////�����Ǵ��������ٶ���ĺ�////////////////////////////////////////
template<class T>
T* IVS_NEW(T* &m, unsigned long ulMuili = 0)
{
    try
    {
        if (ulMuili == 0)
        {
            m = new(T);
        }
        else
        {
            m = new(T[ulMuili]);
        }
        return m;
    }
    catch(...)
    {
        m = NULL;
        return NULL;
    }
};

template<class T>
void IVS_DELETE(T* &m, unsigned long ulMuili = 0)
{
    if (NULL == m)
    {
        return;
    }

    try
    {
        if (0 == ulMuili)
        {
            delete m;
        }
        else
        {
            delete[] m;
        }
    }
    catch(...)
    {
    }

    m = NULL;
};

//����ָ�밲ȫת��Ϊ��ʵָ��
template<class T>
T* IVS_CAST(T* pVoid)
{
    T* pReal = NULL;

    try
    {
        pReal = dynamic_cast<T*>(pVoid);
    }
    catch(...)
    {
        pReal = NULL;
    }

    return pReal;
};

#endif //IVS_COMM_DEF_H