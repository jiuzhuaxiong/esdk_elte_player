#ifndef QUERYMANAGER_H
#define QUERYMANAGER_H


#include<stdint.h>

#include "sdk_export.h"
#include <list>
#include <string>

typedef int MSISDN;

class SDK_IMPORT_EXPORT GisQuerySub
{
public:
    std::string UserId;     //UserID
    std::string UserName;     //UserName
    GisQuerySub(){;}
    GisQuerySub(const GisQuerySub& gis);
    void operator =(const GisQuerySub& gis);
};
typedef std::list<GisQuerySub*> GisQuerySubList;
typedef std::list<GisQuerySub*>::iterator GisQuerySubListIter;

class SDK_IMPORT_EXPORT GISTrackPoint
{
public:    
    std::string Latitude;     //fix camera Latitude
    std::string Longitude;     //fix camera Longitude
    std::string Altitude;     //fix camera Altitude
    std::string Direction;   //Direction
    std::string ReportTime;    //report time
    std::string GPSStatus;     //GPS  search status
    std::string Reasoncode;     //GPS  search status
    GISTrackPoint(){;}
    GISTrackPoint(const GISTrackPoint& gispoint);
};
typedef std::list<GISTrackPoint*> TracePointList;
typedef std::list<GISTrackPoint*>::iterator GISTrackPointListIter;

class SDK_IMPORT_EXPORT  QueryManager
{    

public:
    GisQuerySubList  * query_gis_sub(MSISDN dcid);
    TracePointList * query_gis_track(MSISDN resid,std::string BeginTime,std::string EndTime);
    void init(std::string serverIP);

public:
    QueryManager();

};

class SDK_IMPORT_EXPORT QueryManager_T
{
public:
  /// Global access point to the Singleton.
  static QueryManager *instance (void);
};

#endif // QUERYMANAGER_H
