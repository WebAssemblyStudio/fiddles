#ifndef SERIESNUM_H
#define	SERIESNUM_H 1

#include <string.h>

#pragma pack(push)
#pragma pack(1)

struct SERIES_NUMBER//序列号结构
{
	char section1[5];
	char section2[5];
	char section3[5];
	char section4[5];
	char section5[5];
    SERIES_NUMBER()
    {
        memset(section1, 0, 5);
        memset(section2, 0, 5);
        memset(section3, 0, 5);
        memset(section4, 0, 5);
        memset(section5, 0, 5);
    }
};
#pragma pack(pop)
//交换变量值
template< class A >
void swap( A &x, A &y );

//////////////////////////////////////////////////////////////////////////
//生成序列号函数

//生成序列号
void CreateSeriesNum( const char *strRandNum, 
					 const char *strProduct, 
					 SERIES_NUMBER &seriesNum );
//由随机数排列组合生成6位字符
void Generate( const char *rand, char *strGenerateChar );

//////////////////////////////////////////////////////////////////////////
//检查序列号函数

//检查序列号，并得到序列号中的产品编号
bool CheckSeriesNum( char *strProduct, SERIES_NUMBER &seriesNum, int nCheckNum = -1 );
//提取验证值，成功返回真，失败返回假
bool GetRandNum( char *str, int &nRand );
//从序列号中提取验证值、产品编号、公司名
bool GetSeriesCom( SERIES_NUMBER &seriesNum, int &nRand, char *strProduct, char *strCorporation );

#endif
