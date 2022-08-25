//#include "StdAfx.h"
#include <string.h>
#include "TimeFunc.h"
#include "math.h"
#include "assert.h"
#include "GlobalDefine.h"
#include <stdio.h>

//////////////////////////////////////////////////////////////////////////
//

//获取当前的日期
double GetCurrentDateTime()
{
	time_t	timeSrc;
	timeSrc	= ::time(NULL);

	//把时间变成本地时间
	tm *ptm = localtime(&timeSrc);

	double	dTime = 0;
	
	if (ptm != NULL)
	{
	/*
		_AfxOleDateFromTm((WORD)(ptm->tm_year + 1900),
				(WORD)(ptm->tm_mon + 1), (WORD)ptm->tm_mday,
				(WORD)ptm->tm_hour, (WORD)ptm->tm_min,
				(WORD)ptm->tm_sec, m_dt)*/	

		ptm->tm_year	+= 1900;
		ptm->tm_mon		+= 1;

		//把tm变成double
		if(TimeToDateTime(*ptm , dTime))
			return dTime;
		else
			return 0;
	}
	
	return dTime;
}

//////////////////////////////////////////////////////////////////////////
//时间转换函数
//根据MFC中的COleDateTime改写

// Verifies will fail if the needed buffer size is too large
#define MAX_TIME_BUFFER_SIZE    128         // matches that in timecore.cpp
#define MIN_DATE                (-657434L)  // about year 100
#define MAX_DATE                2958465L    // about year 9999


//根据一个格式，把double转换成一个一个字符串
bool  FormatDateTime(double dDateTime , 
							 const char *pFormat , 
							 string &strResult)
{
	//首先转换成tm
	tm		tmDest;
	bool	bSuccess;

	strResult.erase();

	bSuccess	= DateTimeToTime(dDateTime , tmDest);
	if(!bSuccess)
	{
		assert(false);
		return false;
	}

	// Convert afx internal tm to format expected by runtimes (_tcsftime, etc)
	tmDest.tm_year -= 1900;  // year is based on 1900
	tmDest.tm_mon -= 1;      // month of year is 0-based
	tmDest.tm_wday -= 1;     // day of week is 0-based
	tmDest.tm_yday -= 1;     // day of year is 0-based

	char pszTemp[MAX_TIME_BUFFER_SIZE];
	memset(pszTemp , 0 , MAX_TIME_BUFFER_SIZE);
	strftime(pszTemp , MAX_TIME_BUFFER_SIZE , pFormat , &tmDest);
	strResult	= pszTemp;
	
	return true;
}


// Half a second, expressed in days
#define HALF_SECOND  (1.0/172800.0)

// One-based array of days in year at month start
static int _MonthDays[13] =
{0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365};



//double 与 tm结构之间相互转换
bool  DateTimeToTime(double dDateTime , tm &tmDest)
{
	// The legal range does not actually span year 0 to 9999.
	if (dDateTime > MAX_DATE || dDateTime < MIN_DATE) // about year 100 to about 9999
		return false;

	long nDays;             // Number of days since Dec. 30, 1899
	long nDaysAbsolute;     // Number of days since 1/1/0
	long nSecsInDay;        // Time in seconds since midnight
	long nMinutesInDay;     // Minutes in day

	long n400Years;         // Number of 400 year increments since 1/1/0
	long n400Century;       // Century within 400 year block (0,1,2 or 3)
	long n4Years;           // Number of 4 year increments since 1/1/0
	long n4Day;             // Day within 4 year block
							//  (0 is 1/1/yr1, 1460 is 12/31/yr4)
	long n4Yr;              // Year within 4 year block (0,1,2 or 3)
	bool bLeap4 = true;     // true if 4 year block includes leap year

	double dblDate = dDateTime; // tempory serial date

	// If a valid date, then this conversion should not overflow
	nDays = (long)dblDate;

	// Round to the second
	dblDate += ((dDateTime > 0.0) ? HALF_SECOND : -HALF_SECOND);

	nDaysAbsolute = (long)dblDate + 693959L; // Add days from 1/1/0 to 12/30/1899

	dblDate = fabs(dblDate);
	nSecsInDay = (long)((dblDate - floor(dblDate)) * 86400.);

	// Calculate the day of week (sun=1, mon=2...)
	//   -1 because 1/1/0 is Sat.  +1 because we want 1-based
	tmDest.tm_wday = (int)((nDaysAbsolute - 1) % 7L) + 1;

	// Leap years every 4 yrs except centuries not multiples of 400.
	n400Years = (long)(nDaysAbsolute / 146097L);

	// Set nDaysAbsolute to day within 400-year block
	nDaysAbsolute %= 146097L;

	// -1 because first century has extra day
	n400Century = (long)((nDaysAbsolute - 1) / 36524L);

	// Non-leap century
	if (n400Century != 0)
	{
		// Set nDaysAbsolute to day within century
		nDaysAbsolute = (nDaysAbsolute - 1) % 36524L;

		// +1 because 1st 4 year increment has 1460 days
		n4Years = (long)((nDaysAbsolute + 1) / 1461L);

		if (n4Years != 0)
			n4Day = (long)((nDaysAbsolute + 1) % 1461L);
		else
		{
			bLeap4 = false;
			n4Day = (long)nDaysAbsolute;
		}
	}
	else
	{
		// Leap century - not special case!
		n4Years = (long)(nDaysAbsolute / 1461L);
		n4Day = (long)(nDaysAbsolute % 1461L);
	}

	if (bLeap4)
	{
		// -1 because first year has 366 days
		n4Yr = (n4Day - 1) / 365;

		if (n4Yr != 0)
			n4Day = (n4Day - 1) % 365;
	}
	else
	{
		n4Yr = n4Day / 365;
		n4Day %= 365;
	}

	// n4Day is now 0-based day of year. Save 1-based day of year, year number
	tmDest.tm_yday = (int)n4Day + 1;
	tmDest.tm_year = int(n400Years * 400 + n400Century * 100 + n4Years * 4 + n4Yr);

	// Handle leap year: before, on, and after Feb. 29.
	if (n4Yr == 0 && bLeap4)
	{
		// Leap Year
		if (n4Day == 59)
		{
			/* Feb. 29 */
			tmDest.tm_mon = 2;
			tmDest.tm_mday = 29;
			goto DoTime;
		}

		// Pretend it's not a leap year for month/day comp.
		if (n4Day >= 60)
			--n4Day;
	}

	// Make n4DaY a 1-based day of non-leap year and compute
	//  month/day for everything but Feb. 29.
	++n4Day;

	// Month number always >= n/32, so save some loop time */
	for (tmDest.tm_mon = int((n4Day >> 5) + 1);
		n4Day > _MonthDays[tmDest.tm_mon]; tmDest.tm_mon++);

	tmDest.tm_mday = (int)(n4Day - _MonthDays[tmDest.tm_mon-1]);

DoTime:
	if (nSecsInDay == 0)
		tmDest.tm_hour = tmDest.tm_min = tmDest.tm_sec = 0;
	else
	{
		tmDest.tm_sec = (int)nSecsInDay % 60L;
		nMinutesInDay = nSecsInDay / 60L;
		tmDest.tm_min = (int)nMinutesInDay % 60;
		tmDest.tm_hour = (int)nMinutesInDay / 60;
	}

	return true;
}

bool  TimeToDateTime(const tm &tmSrc , double &dDateTime)
{
	WORD wYear , wMonth , wDay;
	WORD wHour, wMinute , wSecond;

	wYear	= tmSrc.tm_year;
	wMonth	= tmSrc.tm_mon;
	wDay	= tmSrc.tm_mday;
	wHour	= tmSrc.tm_hour;
	wMinute	= tmSrc.tm_min;
	wSecond	= tmSrc.tm_sec;

	// Validate year and month (ignore day of week and milliseconds)
	if (wYear > 9999 || wMonth < 1 || wMonth > 12)
		return false;
	
	//  Check for leap year and set the number of days in the month
	bool bLeapYear = ((wYear & 3) == 0) &&
		((wYear % 100) != 0 || (wYear % 400) == 0);
	
	int nDaysInMonth =
		_MonthDays[wMonth] - _MonthDays[wMonth - 1] +
		((bLeapYear && wDay == 29 && wMonth == 2) ? 1 : 0);
	
	// Finish validating the date
	if (wDay < 1 || wDay > nDaysInMonth ||
		wHour > 23 || wMinute > 59 ||
		wSecond > 59)
	{
		return false;
	}
	
	// Cache the date in days and time in fractional days
	long nDate;
	double dblTime;
	
	//It is a valid date; make Jan 1, 1AD be 1
	nDate = wYear*365L + wYear/4 - wYear/100 + wYear/400 +
		_MonthDays[wMonth-1] + wDay;
	
	//  If leap year and it's before March, subtract 1:
	if (wMonth <= 2 && bLeapYear)
		--nDate;
	
	//  Offset so that 12/30/1899 is 0
	nDate -= 693959L;
	
	dblTime = (((long)wHour * 3600L) +  // hrs in seconds
		((long)wMinute * 60L) +  // mins in seconds
		((long)wSecond)) / 86400.;
	
	dDateTime = (double) nDate + ((nDate >= 0) ? dblTime : -dblTime);
	
	return true;	
}

// double 与 SYSTEMTIME之间的相互转换
// bool  DateTimeToSystemTime(double dDateTime , SYSTEMTIME &systime)
// {
// 	struct tm tmTemp;
// 
// 	//首先把double转换tm
// 	if (DateTimeToTime(dDateTime , tmTemp))
// 	{
// 		//把tm转换成SYSTEMTIME
// 		systime.wYear = (WORD) tmTemp.tm_year;
// 		systime.wMonth = (WORD) tmTemp.tm_mon;
// 		systime.wDayOfWeek = (WORD) (tmTemp.tm_wday - 1);
// 		systime.wDay = (WORD) tmTemp.tm_mday;
// 		systime.wHour = (WORD) tmTemp.tm_hour;
// 		systime.wMinute = (WORD) tmTemp.tm_min;
// 		systime.wSecond = (WORD) tmTemp.tm_sec;
// 		systime.wMilliseconds = 0;
// 		
// 		return true;
// 	}
// 	
// 	return false;
// 
// }
// 
// bool  SystemTimeToDateTime(const SYSTEMTIME &systime , double &dDateTime)
// {
// 	struct tm tmTemp;
// 
// 	//把SYSTEMTIME转换成tm
// 	tmTemp.tm_year	= systime.wYear;
// 	tmTemp.tm_mon	= systime.wMonth;
// 	tmTemp.tm_wday	= systime.wDayOfWeek + 1;
// 	tmTemp.tm_mday	= systime.wDay;
// 	tmTemp.tm_hour	= systime.wHour;
// 	tmTemp.tm_min	= systime.wMinute;
// 	tmTemp.tm_sec	= systime.wSecond;
// 
// 	//把tm转换成double
// 	return TimeToDateTime(tmTemp , dDateTime);	
// }
// 
// double 与 FILETIME之间的相互转换
// bool  DateTimeToFileTime(double dDateTime , FILETIME &filetime)
// { 
// 	SYSTEMTIME systime;
// 
// 	//把double转换成SYSTMETIME
// 	if(!DateTimeToSystemTime(dDateTime , systime))
// 		return false;
// 
// 	//调用Windows API把SYSTEMTIME转换成FILETIME
// 	return SystemTimeToFileTime(&systime , &filetime);
// }
// 
// bool  FileTimeToDateTime(const FILETIME &filetime , double &dDateTime)
// {
// 	SYSTEMTIME systime;
// 
// 	//调用Windows API把FILETIME转换成SYSTEMTIME
// 	if(!FileTimeToSystemTime(&filetime , &systime))
// 		return false;
// 
// 	//再把系统时间转换成double
// 	return SystemTimeToDateTime(systime , dDateTime);
// }
int StringTimeCompare(const char* left , const char* right)
{
		int year1,month1,day1,hour1,min1,sec1;
		int year2,month2,day2,hour2,min2,sec2;
		sscanf(left,"%d-%d-%d %d:%d:%d",&year1,&month1,&day1,&hour1,&min1,&sec1);
		sscanf(right,"%d-%d-%d %d:%d:%d",&year2,&month2,&day2,&hour2,&min2,&sec2);
		int tm1 = year1*10000+month1*100+day1;
		int tm2 = year2*10000+month2*100+day2;
		if(tm1!=tm2) return (tm1>tm2)?1:-1;//如果不相等，大返回1，小返回-1
		tm1 = hour1*3600+min1*60+sec1;
		tm2 = hour2*3600+min2*60+sec2;//将时分秒转换为秒数
		if(tm1!=tm2) return (tm1>tm2)?1:-1;//如果相等，大返回1，小返回-1
		return 0;//到这里必然是相等了
}
bool GetCurrentTimeString(char* timeBuf)
{
	char strNow[32];
	time_t  tmNow = time(NULL);
	strftime(strNow , sizeof(strNow) , "%Y-%m-%d %H:%M:%S" , localtime(&tmNow));
	strcpy(timeBuf , strNow);
	return true;
}
