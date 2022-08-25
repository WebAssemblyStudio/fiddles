#include <cctype>
#include <cstdlib>
#include <stdio.h>

#include "SeriesNum.h"
//////////////////////////////////////////////////////////////////////////
//生成序列号函数
template< class A >
void SwapObj( A &x, A &y )
{
	A temp;
	temp = x; 
	x = y; 
	y = temp; 
}

//生成序列号
void CreateSeriesNum( const char *strRandNum, const char *strProduct, SERIES_NUMBER &seriesNum )
{
	//初始化序列号4个部分
	//strProduct产品编号
	//strRandNum检查值
	char strGenerateChar[6];//检查值生成的6位字符
	Generate( strRandNum, strGenerateChar );
	char corporation[] = "PICLE";//公司名
	//seriesNum初始化为0
	strcpy( seriesNum.section1, "****" );
	strcpy( seriesNum.section2, "****" );
	strcpy( seriesNum.section3, "****" );
	strcpy( seriesNum.section4, "****" );
	strcpy( seriesNum.section5, "****" );
	
	char *section[5];
	section[0] = seriesNum.section1;
	section[1] = seriesNum.section2;
	section[2] = seriesNum.section3;
	section[3] = seriesNum.section4;
	section[4] = seriesNum.section5;
	
	//////////////////////////////////////////////////////////////////////////	
	//第一步
	//将公司名反转后分别插入到5段中，位置从4开始到0得到
	//Section1-Section2-Section3-Section4-Section5;
	//***E-**L*-*C**-I***-P***
	int sectionIndex;
	for ( sectionIndex = 0; sectionIndex < 5; sectionIndex++ )
	{
		int pos = 3 - sectionIndex;
		pos = pos >= 0? pos:3; 
		section[sectionIndex][pos] = corporation[4 - sectionIndex];
	}

	//////////////////////////////////////////////////////////////////////////	
	//第二步
	//把3位随机值（907）循序插入放在第907%5 = 2段，位置被占用则断成2断
	//Section1-Section2-Section3-Section4-Section5;
	//***E-90L7-*C**-I***-P***
	int nRand = atoi(strRandNum);
	int pos = nRand % 5;
	pos = pos == 0?5:pos;
	int i = 0, j = 0;
	for ( i = 0, j = 0; i < 4; i++ )
	{
		if ( '*' != section[pos-1][i] ) continue;
		section[pos-1][i] = strRandNum[j++];
	}
	
	//////////////////////////////////////////////////////////////////////////	
	//第三步
	// 产品编号（123456）逐个字符123456插入到其余4段中，不插在段首，从随机值插入段之后
	//的段开始轮流插，这样保证了出了随机值所在段意外任何段都不会包含超过3个数字，并且
	//任何段都有至少一个数字，检查时候容易定位随机值所在段，得到
	// 	Section1-Section2-Section3-Section4-Section5;
	//    *4*E-90L7-*C15-I26*-P3**
	for ( i = 0 ; i < 6; pos++ )
	{
		pos = pos < 5?pos:0;//段下标转回
		for ( j = 1; j < 5; j++ )
		{
			if ( '*' != section[pos][j] )continue;
			section[pos][j] = strProduct[i++];
			break;
		}
	}

	//////////////////////////////////////////////////////////////////////////	
	//第四步
	//6位字符（ABCDEF）逆序（FEDCBA）填充各段空缺
	//	Section1-Section2-Section3-Section4-Section5;
	//     F4EE-90L7-DC15-I26C-P3BA
	for ( pos = 0, i = 5 ; i > -1; pos++ )
	{
		pos = pos < 5?pos:0;//段下标转回
		for ( j = 0; j < 5; j++ )
		{
			if ( '*' != section[pos][j] )continue;
			section[pos][j] = strGenerateChar[i--];
			break;
		}
	}
}

//由随机数排列组合生成6位字符
void Generate( const char *rand, char *strGenerateChar )
{
	char randNum[4];//随机数排列组合数组
	strcpy( randNum, rand );
	strcpy( randNum, "015" );
	int nRand;//随机数的排列组合数
	int i = 0, j = 0;
	for ( i = 0; i < 3; i++ )
	{
		nRand = atoi( randNum );
		strGenerateChar[j++] = nRand % 26 + 'A'; 

		SwapObj( randNum[1], randNum[2] );
		nRand = atoi( randNum );
		strGenerateChar[j++] = nRand % 26 + 'A'; 

		SwapObj( randNum[0], randNum[1] );
	}
	strGenerateChar[j] = 0;
}

//////////////////////////////////////////////////////////////////////////
//检查序列号函数

//检查序列号，老版本，未使用
bool CheckSeriesNum(
					 char *strProduct, 
					 SERIES_NUMBER &seriesNum,
					 int nCheckNum
					 )
{
	int nRand;
	char productNo[21],corporation[21];
	GetSeriesCom( seriesNum, nRand, productNo, corporation );
	if ( strcmp( "PICLE", corporation ) != 0 ) return false;
	if ( -1 != nCheckNum && nCheckNum != nRand ) return false;

	return true;
}

//提取验证值
bool GetRandNum( char *str, int &nRand )
{
	int i = 0;
	int count = 0;
	nRand = 0;
	for ( i = count = 0; i < 5; i++ )
	{
		if ( isdigit(str[i]) )
		{
			nRand = nRand * 10 + str[i] - 48;
			count++;
		}
	}
	if ( count == 3 )
		return true;
	else 
		return false;
}

//从序列号中提取验证值、产品编号、公司名
bool GetSeriesCom( SERIES_NUMBER &seriesNum, int &nRand, char *strProduct, char *strCorporation )
{
	//////////////////////////////////////////////////////////////////////////
	//第一步
	//提取随机验证值
	int seriesIndex = 0;
	nRand = 0;
	char *section[6];
	section[0] = NULL;
	section[1] = seriesNum.section1;
	section[2] = seriesNum.section2;
	section[3] = seriesNum.section3;
	section[4] = seriesNum.section4;
	section[5] = seriesNum.section5;
	for ( seriesIndex = 1; seriesIndex < 6; seriesIndex++ )
	{
		if ( GetRandNum( section[seriesIndex], nRand ) )
		{
			break;
		}
	}
	if ( 6 == seriesIndex )
	{
		return false;//未找到随机验证值
	}

	//////////////////////////////////////////////////////////////////////////
	//第二步
	//提取产品编号
	int pos = 0;
	pos = (nRand % 5)?(nRand % 5):5;//计算随机值所在段编号
	//产生6位验证字符
	seriesIndex = pos +1 ;//定位到产品编号开始段编号 
	//char product[6];
	int i = 0;
	//从5段中提取产品编号,一共要提取6个字符
	int section_pos[6] = {1,1,1,1,1,1};//section要提取字符的记数
	for ( i = 0; i < 6; seriesIndex++ )
	{
		seriesIndex = seriesIndex < 6?seriesIndex:1;//编号轮转修正
		if ( pos == seriesIndex ) continue;//随机值所在段直接跳过
		int j = 0;
		int count = 0;//出现数字记数
		for ( j = 1, count = 0; j < 4; j++ )//编号从个段1位置开始
		{
			if ( isdigit(section[seriesIndex][j]) ) 
			{
				count++;
				if ( count == section_pos[seriesIndex] )
				{
					strProduct[i++] = section[seriesIndex][j];
					section_pos[seriesIndex]++;
					break;
				}
			}
		}
		if ( j == 4 ) return false;//产品编号错误
		
	}
	strProduct[i] = 0;

	//////////////////////////////////////////////////////////////////////////
	//第三步
	//提取检验字符串
	char checkStr[7] = {0};
	section_pos[0] = section_pos[1] = section_pos[2] 
		= section_pos[3] = section_pos[4] = section_pos[5] = 1;//初始化section要提取字符的记数
	int reFor = 0;
	for ( seriesIndex = 1, i = 0; i < 6; seriesIndex++ )
	{
		if ( seriesIndex > 5 )
		{
			if ( 1 == reFor ) return false;//提取检验字符串错误
			reFor = 1;
			seriesIndex = 1;//编号轮转修正
		}
		if ( pos == seriesIndex ) continue;//随机值所在段直接跳过
		int j = 0;
		int count = 0;//出现大写字母记数记数
		for ( j = 0, count = 0; j < 4; j++ )//编号从个段0位置开始
		{
			if ( isupper(section[seriesIndex][j]) ) 
			{
				if (  j == 4 - seriesIndex || (j == 3 && seriesIndex == 5) ) continue;//公司名字字符串
				count++;
				if ( count == section_pos[seriesIndex] )
				{
					checkStr[i++] = section[seriesIndex][j];
					section_pos[seriesIndex]++;
					break;
				}
			}
		}
	}
	checkStr[i] = 0;
	//检查检验字符串和检验值是否匹配
	char strRand[4];
	//itoa( nRand, strRand, 10 );
    sprintf(strRand, "%d" , nRand);
	char calCheckStr[7] = {0};
	Generate( strRand, calCheckStr );
	int j = 0;
	for ( i = 0, j = 5; i < 6; i++, j-- )
	{
		if ( calCheckStr[i] != checkStr[j] )
			return false;//检验字符串和检验值不匹配
	}

	//////////////////////////////////////////////////////////////////////////
	//第三步
	//提取公司名
	strCorporation[0] = section[5][3];
	strCorporation[1] = section[4][0];
	strCorporation[2] = section[3][1];
	strCorporation[3] = section[2][2];
	strCorporation[4] = section[1][3];
	strCorporation[5] = 0;
	return true;
}

