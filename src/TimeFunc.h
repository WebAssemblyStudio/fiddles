/*------------------------------------------------------------------
 *与时间相关的函数
 *时间函数都是根据COleDateTime类变化而来，与它完全一致
 *
 *
 *
 *
 *----------------------------------------------------------------*/
#ifndef _TIMEFUNC_H__
#define _TIMEFUNC_H__
#include <time.h>
#include <string>
using namespace std;
#pragma pack(1)
//#include "windows.h"

/////////////////////////////////////////////////////////////////////////////
//获取时间的函数
//注：在double类型中只有确定到秒，没有毫秒信息
//年份从100-9999

//获取当前的日期
double  GetCurrentDateTime();

//////////////////////////////////////////////////////////////////////////
//时间转换函数
//根据MFC中的COleDateTime改写
//COleDateTime中数据类型DATE与double一致

//根据一个格式，把double转换成一个一个字符串
bool  FormatDateTime(double dDateTime , 
							 const char *pFormat , 
							 string &strResult);

//double 与 tm结构之间相互转换
bool  DateTimeToTime(double dDateTime , tm &tmDest);
bool  TimeToDateTime(const tm &tmSrc , double &dDateTime);

//大于1，等于0，小于-1
int StringTimeCompare(const char* left , const char* right);

bool GetCurrentTimeString(char* timeBuf);

//double 与 SYSTEMTIME之间的相互转换
//bool  DateTimeToSystemTime(double dDateTime , SYSTEMTIME &systime);
//bool  SystemTimeToDateTime(const SYSTEMTIME &systime , double &dDateTime);

//double 与 FILETIME之间的相互转换
// bool  DateTimeToFileTime(double dDateTime , FILETIME &filetime);
// bool  FileTimeToDateTime(const FILETIME &filetime , double &dDateTime);

#endif
