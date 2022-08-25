/*------------------------------------------------------------------
*与字符串相关的函数
*
*
*
*
*----------------------------------------------------------------*/
#ifndef __STRINGFUNC_H__
#define __STRINGFUNC_H__

#include <string>
#include <vector>
#include <bits/stdint-uintn.h>
#define MAX_PATH 256


//////////////////////////////////////////////////////////////////////////
//与字符串裁剪相关的函数

//裁剪一个字符串两端的空格字符
void TrimSpace(std::string &strText ,	//输入的字符串文本
						bool  bTrimLeft ,	//是否裁剪左边的空格字符
						bool  bTrimRight);	//是否裁剪右边的空格字符

//裁剪一个字符串两端的空格和制表字符
void TrimSpaceAndTab(std::string &strText ,
							  bool bTrimLeft ,
							  bool bTrimRight);

//////////////////////////////////////////////////////////////////////////
//

//根据分隔符把字符串分成不同的子串
//分隔字符可以为分隔字符串中任意一个字符
void ExtractComponentFromString(const std::string &strText ,		//需要提取的原始字符串
										 const std::string &strDelimit ,	//分隔字符串
										 std::vector<std::string> &arrParts	//返回的结果
										 );



//////////////////////////////////////////////////////////////////////////
//!!!
//注：以下函数不要使用，需要修改

// 从一个文件路径名中提取模块名
bool ExtractModuleFileName(char* pszFullFileName);


//
bool ReplaceFileName(
							  char* pszOldFileName,
							  char* pszBaseNewFileName,
							  char* pszNewFileName
							  );


// Converts a string to a boolean value
bool StrToBool(const char* pszValue);

// Converts a boolean value to a string
//
void BoolToStr(bool bValue, char* pszResult);

// Trims leading spaces and control characters from a string
//
void TrimLeft(
					   const char*  pszParam,
					   char*        pszResult
					   );

// Trims trailing spaces and control characters from a string
//
void TrimRight(
						const char*  pszParam,
						char*        pszResult
						);

// Trims leading and trailing spaces and control characters from a string
//
void Trim(
				   const char*  pszParam,
				   char*        pszResult
				   );

// Return next entry of an comma separated string
//
bool GetNextCommaSeparatedString(
	const char*  pszParam,
	char*        pszResult,
	uint32_t       dwLength,
	long*        pnCommaPos
	);

// 
// Tranlsates Unicode to Ansi strings
//---------------------------------------------------------------------------

typedef unsigned char byte;


byte asctob(byte b);

byte  btoasc(byte b);
std::string strToLower(const std::string &str);
bool compareNoCase(const std::string &strA,const std::string &strB);


int bytesToString(byte* bInput, int iInputLen, byte* bOutput);


int StringTobytes(byte* bInput, int iLen, byte* bOutput);

bool GetPathNameAndExt(const char* path , char* fileName , char* ext);

bool GetFileNameFromPath(const char* path , char* fileName);
//支持通配符比较字条串
bool WildcardMatch(const char *pszString, const char *pszMatch);
#endif
