#include <cassert>
#include <memory.h>
#include "StringFunc.h"
#include <algorithm>
//////////////////////////////////////////////////////////////////////////
//与字符串裁剪相关的函数
char *strlwr(char *s)
{
	char *str;
	str = s;
	while(*str != '\0')
	{
		if(*str >= 'A' && *str <= 'Z') {
			*str += 'a'-'A';
		}
		str++;
	}
	return s;
}

//裁剪一个字符串两端的空格字符
void TrimSpace(std::string &strText ,	//输入的字符串文本
						bool  bTrimLeft ,	//是否裁剪左边的空格字符
						bool  bTrimRight)	//是否裁剪右边的空格字符
{
	if(strText.length() == 0)
		return;

	if(!bTrimLeft && !bTrimRight)
		return;

	char ch;
	int	 nStartPos	= -1;	//合法字符的起始位置
	int	 nEndPos	= -1;	//合法字符的终止位置
	int	 nTotalLen;			//字符串总长
	int  nCopyLen;			//字符串复制长度


	nTotalLen	= strText.length();
	for(int i = 0 ; i < nTotalLen ; i++)
	{
		ch	= strText.at(i);

		switch(ch)
		{
		case ' ':	//空格忽略	
			break;
		default:	//非空格字符
			{
				if(nStartPos < 0)
				{
					nStartPos	= nEndPos	= i;
					break;

					if(bTrimLeft && !bTrimRight)	//只剪切左边字符串
					{
						if(nStartPos == 0)
						{
							return;
						}
						else
						{
							nCopyLen		= nTotalLen - nStartPos;
							strText		= strText.substr(nStartPos , nCopyLen);

							return;
						}
					}
				}
				else
				{
					assert(bTrimRight);
					nEndPos	= i;
				}
			}
		}	//end switch		
	}	//end for

	assert(nEndPos >= nStartPos);
	if(nStartPos < 0)	//说明全部是空格字符
	{
		strText.erase();
		return;
	}

	nCopyLen	= nEndPos - nStartPos + 1;
	strText		= strText.substr(nStartPos , nCopyLen);
}

//裁剪一个字符串两端的空格和制表字符
void TrimSpaceAndTab(std::string &strText ,
							  bool bTrimLeft ,
							  bool bTrimRight)
{
	if(strText.length() == 0)
		return;

	if(!bTrimLeft && !bTrimRight)
		return;

	char ch;
	int	 nStartPos	= -1;	//合法字符的起始位置
	int	 nEndPos	= -1;	//合法字符的终止位置
	int	 nTotalLen;			//字符串总长
	int  nCopyLen;			//字符串复制长度


	nTotalLen	= strText.length();
	for(int i = 0 ; i < nTotalLen ; i++)
	{
		ch	= strText.at(i);

		switch(ch)
		{
		case ' ':	//空格字符忽略	
		case '\t':	//制表字符忽略
			break;
		default:	//非空格、制表字符
			{
				if(nStartPos < 0)
				{
					nStartPos	= nEndPos	= i;
					break;

					if(bTrimLeft && !bTrimRight)	//只剪切左边字符串
					{
						if(nStartPos == 0)
						{
							return;
						}
						else
						{
							nCopyLen		= nTotalLen - nStartPos;
							strText		= strText.substr(nStartPos , nCopyLen);

							return;
						}
					}
				}
				else
				{
					assert(bTrimRight);
					nEndPos	= i;
				}
			}
		}	//end switch		
	}	//end for

	assert(nEndPos >= nStartPos);
	if(nStartPos < 0)	//说明全部是空格字符或制表字符
	{
		strText.erase();
		return;
	}
	nCopyLen	= nEndPos - nStartPos + 1;
	strText		= strText.substr(nStartPos , nCopyLen);
}

//根据分隔符把字符串分成不同的子串
//分隔字符可以为分隔字符串中任意一个字符
void ExtractComponentFromString(const std::string &strText ,		//需要提取的原始字符串
										 const std::string &strDelimit ,	//分隔字符串
										 std::vector<std::string> &arrParts	//返回的结果
										 )
{
	arrParts.clear();
	if(strText.length() == 0)
		return;

	char	*pBuffer	= new char[strText.length() + 1];
	strcpy(pBuffer , strText.c_str());

	strlwr(pBuffer);
	char *token;	

	token = strtok( pBuffer , strDelimit.c_str() );
	while( token != NULL )
	{
		arrParts.push_back(token);		
		token = strtok( NULL , strDelimit.c_str());
	}

	delete []pBuffer;
}

//---------------------------------------------------------------------------
// 从一个文件路径名中提取模块名
//
//---------------------------------------------------------------------------

bool ExtractModuleFileName(char* pszFullFileName)
{
	bool  bResult = false;

	if (pszFullFileName)
	{
		char  *pdest;
		char   ch = '\\';

		// Search backward 
		pdest = strchr(pszFullFileName, ch);
		if( pdest != NULL )
			strcpy(pszFullFileName, &pdest[1]);

		bResult = true;
	} // if
	else
	{
		assert(false);
	}

	return bResult;
}

//---------------------------------------------------------------------------
// ReplaceFileName
//
//---------------------------------------------------------------------------
bool ReplaceFileName(
							  char* pszOldFileName,
							  char* pszBaseNewFileName,
							  char* pszNewFileName
							  )
{
	bool  bResult = false;
	char *pdest;
	char   ch = '\\';

	if (pszOldFileName  && pszBaseNewFileName)
	{
		if (pszNewFileName)
		{
			memset(pszNewFileName,0, sizeof(char) * MAX_PATH);
			strcpy(pszNewFileName, pszOldFileName);
			// Search backward and replaces the dll name with the hook one
			pdest = strchr(pszNewFileName, ch);
			if( pdest != NULL )
				strcpy(&pdest[1], pszBaseNewFileName);
			else
				strcpy(pszNewFileName, pszBaseNewFileName);

			bResult = true;
		} // if
		else
		{
			assert(false);
		}
	} // if
	else
	{
		assert(false);
	}

	return bResult;
}

//
// Converts a string to a boolean value
//
bool StrToBool(const char* pszValue)
{
	return ( (0 == strcasecmp("YES", pszValue)) ||
		(0 == strcasecmp("Y", pszValue)) ||
		(0 == strcasecmp("TRUE", pszValue)) );
}

//
// Converts a boolean value to a string
//
void BoolToStr(bool bValue, char* pszResult)
{
	bValue ? strcpy(pszResult, "Yes") :
		strcpy(pszResult, "No");
}

//
// Trims leading spaces and control characters from a string
//
void TrimLeft(
					   const char*  pszParam,
					   char*        pszResult
					   )
{
	char szBuffer[MAX_PATH];
	strcpy(szBuffer, "\0");
	if ( pszParam && (strlen(pszParam) > 0) )
	{
		uint32_t dwIndex = 0;
		while ( (dwIndex < strlen(pszParam)) && (pszParam[dwIndex] ==' '))
			dwIndex++;
		if (dwIndex < strlen(pszParam))
			strcpy(szBuffer, &pszParam[dwIndex]);
	} // if
	strcpy(pszResult, szBuffer);
}

//
// Trims trailing spaces and control characters from a string
//
void TrimRight(
						const char*  pszParam,
						char*        pszResult
						)
{ 
	char szBuffer[MAX_PATH];
	strcpy(szBuffer, "\0");
	if ( pszParam &&(strlen(pszParam) > 0) )
	{
		int nIndex = strlen(pszParam) - 1;
		while ( (nIndex >= 0) && (pszParam[nIndex] == ' ' ))
			nIndex--;
		if (nIndex >= 0)
		{
			memcpy(
				szBuffer,
				pszParam,
				(nIndex + 1)
				); 
			szBuffer[nIndex+1] = 0;
		} // if
	} // if
	strcpy(pszResult, szBuffer);
}

//
// Trims leading and trailing spaces and control characters from a string
//
void Trim(
				   const char*  pszParam,
				   char*        pszResult
				   )
{
	TrimLeft(pszParam, pszResult);
	TrimRight(pszParam, pszResult);
}



//
// Return next entry of an comma separated string
//
bool GetNextCommaSeparatedString(
	const char*  pszParam,
	char*        pszResult,
	uint32_t        dwLength,
	long*        pnCommaPos
	)
{
	*pnCommaPos = -1;
	bool   bResult = false;
	char*  pdest;
	strcpy(pszResult, "\0");

	if (strlen(pszParam) > 0)
	{
		memset(pszResult, 0,dwLength);

		char* pszCompare = const_cast<char*>(pszParam);
		pdest = strstr(pszCompare, ",");
		if (pdest)
			*pnCommaPos = pdest - pszParam - 1;
		else
			*pnCommaPos = strlen(pszParam);
		memcpy(
			pszResult,
			pszParam,
			((*pnCommaPos) + 1)
			); 
		(*pnCommaPos)++;

		Trim(pszResult, pszResult);

		bResult = true;
	} // if

	return bResult;
}

// string转小写
std::string strToLower(const std::string &str)
{
	std::string strTmp = str;
	transform(strTmp.begin(),strTmp.end(),strTmp.begin(),tolower);
	return strTmp;
}
// string.compareNoCase
bool compareNoCase(const std::string &strA,const std::string &strB)
{
	std::string str1 = strToLower(strA);
	std::string str2 = strToLower(strB);
	return (str1 == str2);
}
//---------------------------------------------------------------------------
// 
// Tranlsates Unicode to Ansi strings
//---------------------------------------------------------------------------


byte asctob(byte b)
{

	byte btemp = 0;
	if(b >= '0' && b <= '9')
	{
		btemp = b - 0x30;
	}
	else if(b >= 'A' && b <= 'F')
	{
		btemp = b + 0x0a - 0x41;
	}
	return btemp;
}

//二进制转为ASCII码
byte btoasc(byte b)
{
	byte btmp = 0;
	if(b <= 0x09)
	{
		btmp = 0x30 + b;
	}
	else if((b >= 0xa) && (b <= 0xf))
	{
		btmp = 0x41 + b - 0xa;
	}
	return btmp;
}
//---------------------------------------------------------------------------

int bytesToString(byte* bInput, int iInputLen, byte* bOutput)
{
	for (int i = 0; i < iInputLen; i++)
	{
		byte bTemp = 0;
		bTemp = bInput[i] >> 4;
		bTemp = bTemp & 0x0f;
		bOutput[2 * i] = btoasc(bTemp);
		bTemp = bInput[i] & 0x0f;
		bOutput[2 * i + 1] = btoasc(bTemp);
	}
	return iInputLen * 2;
}
//---------------------------------------------------------------------------

int StringTobytes(byte* bInput, int iLen, byte* bOutput)
{

	for (int i = 0; i < iLen / 2; i++)
	{
		byte bTemp = 0;
		bTemp = asctob(bInput[2 * i]);
		bTemp = bTemp << 4;
		bTemp += asctob(bInput[2 * i + 1]);
		bOutput[i] = bTemp;
	}
	return iLen / 2;
}


bool GetPathNameAndExt(const char* path , char* fileName , char* ext)
{
	//路径不能以/结尾
	int nLen  = strlen(path);
	char last = path[nLen-1];
	if(last == '/')
		return false;
	const char* pStart = strrchr(path,'/');
	char file_buf[MAX_PATH]= {0};
	if(!pStart)
	{
		strcpy(file_buf, path);	//没有找到,可以判断为,是相对路径,只传递了文件名称
	} else	//可能是相对路径或绝对路径,使用斜杠后的文件名即可
	{
		strcpy(file_buf , pStart+1);
	}
	//查找.的指针,只取最后一个点
	char* pFileStart = strrchr(file_buf,'.');
	if(!pFileStart)
	{	//没有扩展名
		strcpy(fileName,file_buf);
	} else
	{
		strcpy(ext,pFileStart+1);
		*pFileStart = '\0';
		strcpy(fileName , file_buf);
	}
	return true;
}
bool GetFileNameFromPath(const char* path , char* fileName)
{
	//路径不能以/结尾
	int nLen  = strlen(path);
	char last = path[nLen-1];
	if(last == '/')
		return false;
	const char* pStart = strrchr(path,'/');
	if(!pStart)
	{
		strcpy(fileName, path);	//没有找到,可以判断为,是相对路径,只传递了文件名称
	} else	//可能是相对路径或绝对路径,使用斜杠后的文件名即可
	{
		strcpy(fileName , pStart+1);
	}
	return true;
}
//////////////////////////////////////////////////////////////////////////
//    WildcardMatch
//        pszString    - Input string to match
//        pszMatch    - Match mask that may contain wildcards like ? and *
//
//        A ? sign matches any character, except an empty string.
//        A * sign matches any string inclusive an empty string.
//        Characters are compared caseless.

bool WildcardMatch(const char *pszString, const char *pszMatch)
{
    // We have a special case where string is empty ("") and the mask is "*".
    // We need to handle this too. So we can't test on !*pszString here.
    // The loop breaks when the match string is exhausted.
    while (*pszMatch)
    {
        // Single wildcard character
        if (*pszMatch=='?')
        {
            // Matches any character except empty string
            if (!*pszString)
                return false;

            // OK next
            ++pszString;
            ++pszMatch;
        }
        else if (*pszMatch=='*')
        {
            // Need to do some tricks.

            // 1. The wildcard * is ignored.
            //    So just an empty string matches. This is done by recursion.
            //      Because we eat one character from the match string, the
            //      recursion will stop.
            if (WildcardMatch(pszString,pszMatch+1))
                // we have a match and the * replaces no other character
                return true;

            // 2. Chance we eat the next character and try it again, with a
            //    wildcard * match. This is done by recursion. Because we eat
            //      one character from the string, the recursion will stop.
            if (*pszString && WildcardMatch(pszString+1,pszMatch))
                return true;

            // Nothing worked with this wildcard.
            return false;
        }
        else
        {
            // Standard compare of 2 chars. Note that *pszSring might be 0
            // here, but then we never get a match on *pszMask that has always
            // a value while inside this loop.
            if ( *pszString++ != *pszMatch++ )
                return false;
        }
    }

    // Have a match? Only if both are at the end...
    return !*pszString && !*pszMatch;
}
