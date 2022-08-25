// EncIniFile.cpp: implementation of the CEncIniFile class.
//
//////////////////////////////////////////////////////////////////////

#include <assert.h>
#include <string.h>
#include "EncIniFile.h"
#include "TimeFunc.h"
#include<iostream>
//使用DES加密方法
#include "FileUtil.h"
#include "PiErrCode.h"
#include "EncM_Des.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CEncIniFile::CEncIniFile()
{
    m_nErrCode = 0;
}

CEncIniFile::~CEncIniFile()
{

}

CEncIniFile &CEncIniFile::operator=(const CEncIniFile &src)
{
	m_arrIniInfo		= src.m_arrIniInfo;
	m_strFileName		= src.m_strFileName;
	m_strFilePathName	= src.m_strFilePathName;
	
	return *this;
}

CEncIniFile::_Entry::_Entry()
{

}

CEncIniFile::_Entry::~_Entry()
{

}

int	CEncIniFile::_Entry::GetBufferLength()
{
	if(strEntry.length() == 0)
		return 0;
	
	return int(strEntry.length() + strValue.length()) + 5;	//5为等于(3)和回车换行(2)
}

bool CEncIniFile::_Entry::WriteBuffer(Byte *pBuffer)
{
	int		nBufLen ;	//需要缓存区的长度
	string	strTemp;

	nBufLen	= GetBufferLength();
	if(nBufLen == 0)
		return false;

	strTemp		= strEntry + " = " + strValue + "\r\n";
	assert(nBufLen == (int)strTemp.length());
	memcpy(pBuffer , strTemp.c_str() , nBufLen);	//写入

	return true;
}

CEncIniFile::_Section::_Section()
{

}

CEncIniFile::_Section::~_Section()
{

}

int CEncIniFile::_Section::GetBufferLength()
{
	if(strSectionName.length() == 0)
		return 0;

	int nBufTotalLen	= 0;

	nBufTotalLen	= int(strSectionName.length()) + 4;

	//遍历入口名
	_Entry  entry;
	
	//for(int i = 0 ; i < arrEntries.size() ; i++)
	for(UINT i = 0 ; i < arrEntries.size() ; i++)
	{
		entry	= arrEntries.at(i);
		
		nBufTotalLen	+= entry.GetBufferLength();
	}


	return nBufTotalLen;
}

bool CEncIniFile::_Section::WriteBuffer(Byte *pBuffer)
{
	int		nBufLen ;				//需要缓存区的长度
	int		nBufTotalLen;
	int		nWriteLen;				//实际写入的长度
	int		nWriteTotalLen = 0;		//写入的总长度
	string  strTemp;
	
	nBufTotalLen	= GetBufferLength();
	if(nBufTotalLen == 0)
		return false;

	//写入节名
	nBufLen		= int(strSectionName.length()) + 4;
	strTemp		= '[' + strSectionName + "]\r\n";
	assert(nBufLen == (int)strTemp.length());
	memcpy(pBuffer , strTemp.c_str() , nBufLen);	//写入	

	nWriteTotalLen	+= nBufLen;
	pBuffer			+= nBufLen;		//移动指针

	//遍历入口名
	_Entry  entry;

	//for(int i = 0 ; i < arrEntries.size() ; i++)
	for(UINT i = 0 ; i < arrEntries.size() ; i++)
	{
		entry	= arrEntries.at(i);

		nBufLen		= entry.GetBufferLength();
		if(nBufLen == 0)
			continue;

		nWriteLen	= entry.GetBufferLength();
		entry.WriteBuffer(pBuffer);
		assert(nBufLen == nWriteLen);
		if(nBufLen != nWriteLen)
			return false;

		nWriteTotalLen	+= nWriteLen;
		pBuffer			+= nBufLen;		//移动指针
	}

	assert(nBufTotalLen == nWriteTotalLen);
	if(nBufTotalLen != nWriteTotalLen)
		return false;	
	
	return true;
}

CEncIniFile::_Total::_Total()
{

}

CEncIniFile::_Total::~_Total()
{

}

int CEncIniFile::_Total::GetBufferLength()
{
	int		nBufTotalLen = 0;
	
	//遍历节名
	_Section   section;
	//for(int i = 0 ; i < arrSections.size() ; i++)
	for(UINT i = 0 ; i < arrSections.size() ; i++)
	{
		section	= arrSections.at(i);

		nBufTotalLen	+= section.GetBufferLength();
	}

	return nBufTotalLen;
}

bool CEncIniFile::_Total::WriteBuffer(Byte *pBuffer)
{
	int		nWriteLen;
	int		nBufTotalLen;
	int		nWriteTotalLen = 0;

	nBufTotalLen	= this->GetBufferLength();

	//遍历节名
	_Section   section;
	//for(int i = 0 ; i < arrSections.size() ; i++)
	for(UINT i = 0 ; i < arrSections.size() ; i++)
	{
		section	= arrSections.at(i);

		nWriteLen		= section.GetBufferLength();		
		section.WriteBuffer(pBuffer);

		nWriteTotalLen	+= nWriteLen;
		pBuffer			+= nWriteLen;
	}

	assert(nBufTotalLen == nWriteTotalLen);
	if(nBufTotalLen != nWriteTotalLen)
		return false;

	return true;	
}

void CEncIniFile::_Total::Reset()
{
	arrSections.clear();	
}

int CEncIniFile::_Total::FindSection(const string &strSectionName)
{
	//遍历节名
	_Section   section;
	//for(int i = 0 ; i < arrSections.size() ; i++)
	for(UINT i = 0 ; i < arrSections.size() ; i++)
	{
		section	= arrSections.at(i);
		
		//if(stricmp(strSectionName.c_str() , section.strSectionName.c_str()) == 0)
		if(strcasecmp(strSectionName.c_str() , section.strSectionName.c_str()) == 0)
			return i;
	}

	return -1;	
}

void CEncIniFile::TrimSpace(string &strText ,
							bool  bTrimLeft ,
							bool  bTrimRight)
{
	if(strText.length() == 0)
		return;

	if(!bTrimLeft && !bTrimRight)
		return;

	char ch;
	int	 nStartPos	= -1;	//合法字符的起始位置
	int	 nEndPos	= -1;	//合法字符的终止位置
	//int	 nTotalLen;			//字符串总长
	UINT	 nTotalLen;			//字符串总长
	int  nCopyLen;			//字符串复制长度


	nTotalLen	= int(strText.length());
	//for(int i = 0 ; i < nTotalLen ; i++)
	for(UINT i = 0 ; i < nTotalLen ; i++)
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

void CEncIniFile::TrimSpaceAndTab(string &strText ,
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
	//int	 nTotalLen;			//字符串总长
	UINT	 nTotalLen;			//字符串总长
	int  nCopyLen;			//字符串复制长度
	
	
	nTotalLen	= int(strText.length());
	//for(int i = 0 ; i < nTotalLen ; i++)
	for(UINT i = 0 ; i < nTotalLen ; i++)
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

void CEncIniFile::QuerySections(vector<string> &arrSections)
{
	arrSections.clear();

	//遍历节名
	_Section   section;
	//for(int i = 0 ; i < m_arrIniInfo.arrSections.size() ; i++)
	for(UINT i = 0 ; i < m_arrIniInfo.arrSections.size() ; i++)
	{
		section	= m_arrIniInfo.arrSections.at(i);
		
		arrSections.push_back(section.strSectionName);
	}	
}

void CEncIniFile::QueryEntries(const string &strSectionName , 
							   vector<string> &arrEntries)
{
	arrEntries.clear();

	int	nSectionIndex;

	nSectionIndex	= m_arrIniInfo.FindSection(strSectionName);
	if(nSectionIndex < 0)
		return;

	_Section  section;
	section	= m_arrIniInfo.arrSections.at(nSectionIndex);

	_Entry		entry;
	//for(int i = 0 ; i < section.arrEntries.size() ; i++)
	for(UINT i = 0 ; i < section.arrEntries.size() ; i++)
	{
		entry	= section.arrEntries.at(i);

		arrEntries.push_back(entry.strEntry);
	}
}

bool CEncIniFile::HasSection(const string &strSectionName)
{
	return (m_arrIniInfo.FindSection(strSectionName) >= 0);
}

bool CEncIniFile::HasEntry(const string &strSectionName , 
						   const string &strEntry)
{
	int	nSectionIndex;
	
	nSectionIndex	= m_arrIniInfo.FindSection(strSectionName);
	if(nSectionIndex < 0)
		return false;
	
	_Section  section;
	section	= m_arrIniInfo.arrSections.at(nSectionIndex);
	
	_Entry		entry;
	//for(int i = 0 ; i < section.arrEntries.size() ; i++)
	for(UINT i = 0 ; i < section.arrEntries.size() ; i++)
	{
		entry	= section.arrEntries.at(i);

		//if(stricmp(strEntry.c_str() , entry.strEntry.c_str()) == 0)
		if(strcasecmp(strEntry.c_str() , entry.strEntry.c_str()) == 0)
			return true;
	}

	return false;
}

bool CEncIniFile::GetEntryValue(const string &strSectionName ,
								const string &strEntry ,
								string &strValue)
{
	strValue.erase();

	int	nSectionIndex;
	
	nSectionIndex	= m_arrIniInfo.FindSection(strSectionName);
	if(nSectionIndex < 0)
		return false;
	
	_Section  section;
	section	= m_arrIniInfo.arrSections.at(nSectionIndex);
	
	_Entry		entry;
	for(int i = 0 ; i < (int)section.arrEntries.size() ; i++)
	{
		entry	= section.arrEntries.at(i);

		//if(stricmp(strEntry.c_str() , entry.strEntry.c_str()) == 0)
		if(strcasecmp(strEntry.c_str() , entry.strEntry.c_str()) == 0)
		{
			strValue	= entry.strValue;
			return true;
		}
	}
	
	return false;
}

bool CEncIniFile::SetEntryValue(const string &strSectionName , 
								const string &strEntry , 
								const string &strValue)
{
	string	strSecName;
	string  strEntryName;

	strSecName		= strSectionName;
	//TrimSpaceAndTab(strSecName);
	if(strSecName.length() == 0)
		return false;

	strEntryName	= strEntry;
	TrimSpaceAndTab(strEntryName);
	if(strEntryName.length() == 0)
		return false;

	int			nIndex;
		
	nIndex	= m_arrIniInfo.FindSection(strSecName);
	if(nIndex < 0)	//没有找到节名
	{
		_Section	section;
		_Entry		entry;

		section.strSectionName	= strSecName;

		entry.strEntry	= strEntryName;
		entry.strValue	= strValue;
		section.arrEntries.push_back(entry);

		m_arrIniInfo.arrSections.push_back(section);	//加入一个节信息
	}
	else	//找到节名
	{
		_Section	&section		= m_arrIniInfo.arrSections.at(nIndex);

		//遍历入口项	
		//for(int i = 0 ; i < section.arrEntries.size() ; i++)
		for(UINT i = 0 ; i < section.arrEntries.size() ; i++)
		{
			_Entry &entry	= section.arrEntries.at(i);
			
			//if(stricmp(strEntryName.c_str() , entry.strEntry.c_str()) == 0)	//找到对应的入口项
			if(strcasecmp(strEntryName.c_str() , entry.strEntry.c_str()) == 0)	//找到对应的入口项
			{
				entry.strValue	= strValue;
				return true;
			}
		}

		//没有找到对应的入口项
		_Entry		entry;
		
		entry.strEntry	= strEntryName;
		entry.strValue	= strValue;
		section.arrEntries.push_back(entry);
	}
	
	return true;
}

bool CEncIniFile::DeleteSection(const string &strSectionName)
{
	int		nIndex;
	nIndex	= m_arrIniInfo.FindSection(strSectionName);
	if(nIndex < 0)
		return false;

	vector<_Section>::iterator	iter = m_arrIniInfo.arrSections.begin();

	//for(int i = 0 ; i < m_arrIniInfo.arrSections.size() ; i++ , iter++)
	for(UINT i = 0 ; i < (UINT)m_arrIniInfo.arrSections.size() ; i++ , iter++)
	{
		if(i == nIndex)
		{
			m_arrIniInfo.arrSections.erase(iter);
			return true;
		}
	}	

	return false;
}

bool CEncIniFile::DeleteEntry(const string &strSectionName , 
							  const string &strEntry)
{
	int		nIndex;
	//UINT		nIndex;
	nIndex	= m_arrIniInfo.FindSection(strSectionName);
	if(nIndex < 0)
		return false;

	_Section	&section	= m_arrIniInfo.arrSections.at(nIndex);
	vector<_Entry>::iterator	iter = section.arrEntries.begin();

	//for(int i = 0 ; i < section.arrEntries.size() ; i++ , iter++)
	for(UINT i = 0 ; i < section.arrEntries.size() ; i++ , iter++)
	{
		_Entry	&entry = section.arrEntries.at(i);

		//if(stricmp(strEntry.c_str() , entry.strEntry.c_str()) == 0)
		if(strcasecmp(strEntry.c_str() , entry.strEntry.c_str()) == 0)
		{
			section.arrEntries.erase(iter);
			return true;
		}
	}	

	return false;
}

bool CEncIniFile::IsSectionLine(Byte *pLine , int nBufLen)
{
	if(nBufLen == 0)
		return false;

	int		nLeftBracket	= -1;	//左中括号位置
	int		nRightBracket	= -1;	//右中括号位置

	char	ch;
	for(int i = 0 ; i < nBufLen ; i++)
	{
		ch  = (char)*(pLine + i);

		switch(ch)
		{
		case '[':
			{
				if(nLeftBracket >= 0)
					return false;
				else
					nLeftBracket	= i;
			}
			break;
		case ']':
			{
				if(nLeftBracket < 0 || nRightBracket >= 0)
					return false;

				nRightBracket = i;
			}
			break;
		case ' ':
		case '\t':
			break;
		default:
			{
				if(nLeftBracket < 0 || nRightBracket >= 0)
					return false;
			}
		}
	}

	if(nLeftBracket < 0 || nRightBracket <= nLeftBracket)
		return false;

	return true;
}

bool CEncIniFile::IsEntryLine(Byte *pLine ,
							  int nBufLen)
{
	if(nBufLen == 0)
		return false;

	char	ch;
	for(int i = 0 ; i < nBufLen ; i++)
	{
		ch  = (char)*(pLine + i);

		if(ch == '=')
		{
			if( nBufLen == 1 || i == 0 || i == nBufLen - 1)
				return false;
			else
				return true;
		}
	}

	return true;
}

bool CEncIniFile::ExtractSection(Byte *pLine ,
								 int nBufLen , 
								 string &strSectionName)
{
	strSectionName.erase();

	if(nBufLen == 0)
		return false;
	
	int		nLeftBracket	= -1;	//左中括号位置
	int		nRightBracket	= -1;	//右中括号位置
	
	char	ch;
	for(int i = 0 ; i < nBufLen ; i++)
	{
		ch  = (char)*(pLine + i);
		
		switch(ch)
		{
		case '[':
			{
				if(nLeftBracket >= 0)
					return false;
				else
					nLeftBracket	= i;
			}
			break;
		case ']':
			{
				if(nLeftBracket < 0 || nRightBracket >= 0)
					return false;
				
				nRightBracket = i;
			}
			break;
		case ' ':		//忽略空格和制表符
		case '\t':
			break;
		default:
			{
				if(nLeftBracket < 0 || nRightBracket >= 0)
					return false;
			}
		}
	}
	
	if(nLeftBracket < 0 || nRightBracket <= nLeftBracket)
		return false;

	if(nRightBracket - nLeftBracket > 1)
	{
		char *pText;

		pText	= new char[nRightBracket - nLeftBracket];
		memset(pText , 0 , nRightBracket - nLeftBracket);
		memcpy(pText , pLine + nLeftBracket + 1 , nRightBracket - nLeftBracket - 1);

		strSectionName	= pText;
		delete []pText;
	}	
	
	return true;
}

bool CEncIniFile::ExtractEntry(Byte *pLine ,
							   int nBufLen , 
							   string &strEntry , 
							   string &strValue)
{
	if(nBufLen == 0)
		return false;

	char	ch;
	int i;
	for(i = 0 ; i < nBufLen ; i++)
	{
		ch  = (char)*(pLine + i);
		
		if(ch == '=')
		{
			if( nBufLen == 1 || i == 0)
				return false;
			else
				break;
		}
	}

	if(i >= nBufLen)
		return false;

	//提取入口项
	char	*pText;
	pText		= new char[i + 1];
	pText[i]	= '\0';
	memcpy(pText , pLine , i);
	strEntry	= pText;
	delete []pText;
	TrimSpaceAndTab(strEntry);
	if(strEntry.length() == 0)
		return false;

	//提取值
	if(i == (nBufLen - 1))	//说明等于号后没有文本
	{
		strValue.erase();
	}
	else
	{
		pText	= new char[nBufLen - i];
		pText[nBufLen - i - 1] = '\0';
		memcpy(pText , pLine + i + 1 , nBufLen - i - 1);
		strValue	= pText;
		delete []pText;
		TrimSpaceAndTab(strValue);		
	}

	return true;
}

bool CEncIniFile::ProcessBuffer(Byte *pBuffer , int nBufLen)
{
	assert(nBufLen > 0);

	//if(::IsBadReadPtr(pBuffer , nBufLen))
		//return false;

	string		strCurSecName;	//当前所在的节名
	string		strSecName ;
	string		strEntry;
	string      strValue;
	int			nStartPos = 0;	//一行的起始位置
	int			nRowLen;
	char        chCur , chNext;
	
	for(int i = 0 ; i < nBufLen ; i++)
	{
		chCur	= (char)*(pBuffer + i);
		if(chCur != '\r')
			continue;

		if(i == (nBufLen - 1))	//最后一个字母
			continue;

		chNext	= (char)*(pBuffer + i + 1);
		if(chNext != '\n')
			continue;

		//////////////////////////////////////////////////////////////////////////
		//说明找到了一个"回车换行符"

		//提取当前行的信息
		if(i - nStartPos > 1)
		{
			nRowLen	= i - nStartPos;

			//检查该行的信息
			if(IsSectionLine(pBuffer + nStartPos , nRowLen))	//说明该行为节名
			{
				strCurSecName.erase();

				//提取节名
				ExtractSection(pBuffer + nStartPos , nRowLen , strCurSecName);
			}
			else
			{
				if(IsEntryLine(pBuffer + nStartPos , nRowLen))	//说明为一个入口项
				{
					if(strCurSecName.length() > 0 &&
						ExtractEntry(pBuffer + nStartPos , nRowLen , strEntry , strValue))
					{
						this->SetEntryValue(strCurSecName , strEntry , strValue);
					}
				}
			}
		}

		//获取下一行的起始位置
		nStartPos = i + 2;

		i++;	//跳过一个字符		
	}

	//获取最后一行
	if(nStartPos < (nBufLen - 1))
	{
		nRowLen	= nBufLen - 1 - nStartPos ;
		
		//检查该行的信息
		if(IsSectionLine(pBuffer + nStartPos , nRowLen))	//说明该行为节名
		{
			strCurSecName.erase();
			
			//提取节名
			ExtractSection(pBuffer + nStartPos , nRowLen , strCurSecName);
		}
		else
		{
			if(IsEntryLine(pBuffer + nStartPos , nRowLen))	//说明为一个入口项
			{
				if(strCurSecName.length() > 0 &&
					ExtractEntry(pBuffer + nStartPos , nRowLen , strEntry , strValue))
				{
					this->SetEntryValue(strCurSecName , strEntry , strValue);
				}
			}
		}
	}

	return true;	
}

void CEncIniFile::KeepFileName(const string &strFilePathName)
{
	//记录文件名信息
	m_strFilePathName	= strFilePathName;
	
	char	ch1	= '\\';
	char	ch2	= '/';
	long	nPos1 , nPos2;
	nPos1	= strFilePathName.rfind(ch1 , strFilePathName.length());
	if(nPos1 > 0)
	{
		nPos2	= strFilePathName.rfind(ch2 , strFilePathName.length());
		if(nPos2 > nPos1)
		{
			m_strFileName	= strFilePathName.substr(nPos2 + 1 , strFilePathName.length());
		}
		else
		{
			m_strFileName	= strFilePathName.substr(nPos1 + 1 , strFilePathName.length());
		}
	}	
	else
	{
		nPos2	= strFilePathName.rfind(ch2 , strFilePathName.length());
		if(nPos2 > 0)
		{
			m_strFileName	= strFilePathName.substr(nPos2 + 1 , strFilePathName.length());
		}
	}
}

//获取布尔值
bool  CEncIniFile::GetBooleanValue(const string &strSectionName , 
								   const string &strEntry , 
								   bool  bDefaultValue)
{
	string	strText;

	GetEntryValue(strSectionName , strEntry , strText);
	
	//删除字符串中的空格和制表字符
	TrimSpaceAndTab(strText , true , true);
	if(strText.length() == 0)
		return bDefaultValue;

	//if(stricmp(strText.c_str() , "T") == 0 ||
	//	stricmp(strText.c_str() , "TRUE") == 0 ||
	//	stricmp(strText.c_str() , "Y") == 0 ||
	//	stricmp(strText.c_str() , "YES") == 0)
	if(strcasecmp(strText.c_str() , "T") == 0 ||
		strcasecmp(strText.c_str() , "TRUE") == 0 ||
		strcasecmp(strText.c_str() , "Y") == 0 ||
		strcasecmp(strText.c_str() , "YES") == 0)
		return true;
	
	return false;
}

//设置布尔值
void  CEncIniFile::SetBooleanValue(const string &strSectionName ,
								   const string &strEntry , 
								   bool  bValue)
{
	if(bValue)
		SetEntryValue(strSectionName , strEntry , "Yes");
	else
		SetEntryValue(strSectionName , strEntry , "No");
}

//获取整形值
int  CEncIniFile::GetIntValue(const string &strSectionName , 
							  const string &strEntry , 
							  int nDefaultValue)
{
	string	strText;
	
	GetEntryValue(strSectionName , strEntry , strText);
	
	//删除字符串中的空格和制表字符
	TrimSpaceAndTab(strText , true , true);
	if(strText.length() == 0)
		return nDefaultValue;

	int	nRet;
	sscanf(strText.c_str() , "%d" , &nRet);
	//sscanf_s(strText.c_str() , "%d" , &nRet);

	return nRet;
}

//和设置整形值
void CEncIniFile::SetIntValue(const string &strSectionName , 
							  const string &strEntry ,
							  int nValue)
{
	char buffer[20];
	sprintf(buffer , "%d" , nValue);
	//sprintf_s(buffer , _countof(buffer), "%d" , nValue);

	SetEntryValue(strSectionName , strEntry , buffer);
}

bool CEncIniFile::ReadFromTextFile(const string &strFilePath)
{
	//注：对文件进行读写操作时，需调用Windows的API，不要调用C++运行期库函数
	//这样会减小风险，避免对文件进行累计加密

	Byte	*pBuffer	= NULL;
	DWORD	dwFileLen	= 0;
	//HANDLE	hFile		= INVALID_HANDLE_VALUE;
	CFileUtil file;

	m_arrIniInfo.Reset();
	m_strFilePathName.erase();
	m_strFileName.erase();
	
//	try
//	{
		//���ļ�
// 		hFile	= ::CreateFile(strFilePath.c_str() , GENERIC_READ , 
// 								FILE_SHARE_READ | FILE_SHARE_WRITE, NULL ,
// 								OPEN_EXISTING , FILE_ATTRIBUTE_NORMAL , NULL);
// 
// 		if(hFile == INVALID_HANDLE_VALUE)
// 			return false;
		if (!file.OpenFile(strFilePath.c_str(),"rb"))
		{
			return false;
		}

		//获取文件的大小
		//dwFileLen	= ::SetFilePointer(hFile , 0 , NULL , FILE_END);
		if(!file.GetFileSize(&dwFileLen) && (long)dwFileLen < 0)
		{
			//::CloseHandle(hFile);
			file.CloseFile();
			return false;
		}		

		if(dwFileLen > 0)
		{
			//把文件移至文件首部
			//::SetFilePointer(hFile , 0 , NULL , FILE_BEGIN);
			
			//从文件中读取数据
			DWORD	dwReadLen = 0;
			
			pBuffer		= new Byte[dwFileLen];
// 			if(!::ReadFile(hFile , pBuffer , dwFileLen ,&dwReadLen , NULL) ||
// 				dwFileLen != dwReadLen)
// 			{
// 				assert(false);
// 
// 				delete []pBuffer;
// 				::CloseHandle(hFile);
// 				return false;			
// 			}
			if (!file.ReadFile(pBuffer , dwFileLen ,&dwReadLen) || dwFileLen != dwReadLen)
			{
				assert(false);

				delete []pBuffer;
				file.CloseFile();
				return false;
			}
			
			//处理数据
			this->ProcessBuffer(pBuffer , int(dwReadLen));
			delete []pBuffer;
			pBuffer	= NULL;
		}
		
		//关闭文件
		//::CloseHandle(hFile);
//	}
//	catch (...)
//	{
//		assert(false);
//
//		if(pBuffer != NULL)
//			delete []pBuffer;
//
//// 		if(hFile != INVALID_HANDLE_VALUE)
//// 			::CloseHandle(hFile);
//		file.CloseFile();
//
//		return false;
//	}
	//�ر��ļ����
// 	if(hFile != INVALID_HANDLE_VALUE)
// 		::CloseHandle(hFile);
	file.CloseFile();


	KeepFileName(strFilePath);

	return true;
}

bool CEncIniFile::WriteIntoTextFile(const string &strFilePath)
{

	Byte	*pBuffer	= NULL;
	long	nFileLen	= 0;
	//HANDLE	hFile		= INVALID_HANDLE_VALUE;
	CFileUtil file;

//	try
//	{
		//获取缓存区大小
		nFileLen	= m_arrIniInfo.GetBufferLength();
		if(nFileLen > 0)
		{
			pBuffer	= new Byte[nFileLen];
			m_arrIniInfo.WriteBuffer(pBuffer);
		}

		//打开文件
// 		hFile	= ::CreateFile(strFilePath.c_str() , GENERIC_WRITE , 
// 								FILE_SHARE_READ | FILE_SHARE_WRITE , NULL ,
// 								CREATE_ALWAYS , 
// 								FILE_ATTRIBUTE_NORMAL , NULL);
// 		if(hFile == INVALID_HANDLE_VALUE)
// 		{
// 			if(pBuffer)
// 				delete []pBuffer;
// 
// 			return false;
// 		}
		if (!file.OpenFile(strFilePath.c_str(),"rb"))
		{
			return false;
		}
		if(nFileLen > 0)
		{
			//把数据写入文件
			long	nWriteLen = 0;

// 			if(!::WriteFile(hFile , pBuffer , nFileLen , (DWORD*)&nWriteLen , NULL) ||
// 				nFileLen != nWriteLen)
// 			{
// 				::CloseHandle(hFile);
// 				delete []pBuffer;
// 				return false;
// 			}
			if (!file.ReadFile(pBuffer , nFileLen ,(unsigned long*)&nWriteLen) || nFileLen != nWriteLen)
			{
				assert(false);

				delete []pBuffer;
				file.CloseFile();
				return false;
			}
			
			delete []pBuffer;
		}		
		
		//关闭文件
		//::CloseHandle(hFile);
		file.CloseFile();
//	}
//	catch (...)
//	{
//		if(pBuffer != NULL)
//			delete []pBuffer;
//
//// 		if(hFile != INVALID_HANDLE_VALUE)
//// 			::CloseHandle(hFile);
//		file.CloseFile();
//
//		return false;
//	}

	KeepFileName(strFilePath);
	
	return true;
}

bool CEncIniFile::WriteIntoTextBinary(char *szTextBinary)
{
	Byte	*pBuffer	= NULL;
	long	nFileLen	= 0;
	//HANDLE	hFile		= INVALID_HANDLE_VALUE;

	//获取缓存区大小
	nFileLen	= m_arrIniInfo.GetBufferLength();
	if(nFileLen > 0)
	{
		pBuffer	= new Byte[nFileLen];
		m_arrIniInfo.WriteBuffer(pBuffer);
	}
	return true;
}

bool CEncIniFile::ReadFromEncFile(const string &strFilePath)
{
	//加密文件的格式
	//签名(4B) + 时间(8B) + 密钥长度(2B) + 密钥 + 加密版本(4) + 数据长度(4B) + 数据

	Byte	signature[4];
	double	dTime;
	short	sKeyLen;
	Byte	*pKey  = NULL;
	//long	nVer;
	//long	nDataLen;
    int     nVer;
    int     nDataLen;
	Byte	*pData = NULL;
	int		nFileLen ;
	DWORD	dwReadLen;
	//HANDLE	hFile = INVALID_HANDLE_VALUE;
	CFileUtil file;
    m_nErrCode = PI_E_UNKONWN;

	//初始化
	m_arrIniInfo.Reset();
	m_strFilePathName.erase();
	m_strFileName.erase();

//	try
//	{
		//���ļ�
// 		hFile	= ::CreateFile(strFilePath.c_str() , GENERIC_READ , 
// 								FILE_SHARE_READ | FILE_SHARE_WRITE, NULL ,
// 								OPEN_EXISTING, 
// 								FILE_ATTRIBUTE_NORMAL , NULL);
// 		if(hFile == INVALID_HANDLE_VALUE)
// 			return false;
		if (!file.OpenFile(strFilePath.c_str(),"rb"))
		{
            m_nErrCode = PI_E_PCL_OPEN_FILE_ERROR;
			return false;
		}

		//获取文件大小
		//nFileLen	= ::SetFilePointer(hFile , 0 , NULL , FILE_END);
		//if(nFileLen < 0)
		if(!file.GetFileSize((unsigned long*)&nFileLen) && (long)nFileLen < 0)
		{
			//::CloseHandle(hFile);
			file.CloseFile();
            m_nErrCode = PI_E_PCL_GET_FILESZIE_ERROR;
			return false;
		}

		if(nFileLen == 0)	//如果为空，则直接返回true
		{
			KeepFileName(strFilePath);
			//::CloseHandle(hFile);
			file.CloseFile();
            m_nErrCode = PI_E_PCL_GET_FILESZIE_ERROR;
			return true;
		}

		//::SetFilePointer(hFile , 0 , NULL , FILE_BEGIN);

		//////////////////////////////////////////////////////////////////////////
		//从文件中读取数据

		//读取签名
// 		if(!::ReadFile(hFile , signature , 4 , &dwReadLen , NULL) ||
// 			dwReadLen != 4)
// 		{
// 			::CloseHandle(hFile);
// 			return false;
// 		}
		if (!file.ReadFile(signature , 4 , &dwReadLen) && dwReadLen != 4)
		{
			file.CloseFile();
            m_nErrCode = PI_E_PCL_SIGNATURE_ERROR;
			return false;
		}

		//比较签名
		if(memcmp(signature , "#PS#" , 4) != 0)	//签名不对
		{
			file.CloseFile();//::CloseHandle(hFile);
            m_nErrCode = PI_E_PCL_SIGNATURE_ERROR;
			return false;
		}

		//读取时间
// 		if(!::ReadFile(hFile , &dTime , 8 , &dwReadLen , NULL) ||
// 			dwReadLen != 8)
// 		{
// 			::CloseHandle(hFile);
// 			return false;
// 		}
		if (!file.ReadFile(&dTime , 8 , &dwReadLen) || dwReadLen != 8)
		{
			file.CloseFile();
            m_nErrCode = PI_E_PCL_READ_TIME_ERROR;
			return false;
		}

		//获取密钥长度
// 		if(!::ReadFile(hFile , &sKeyLen , 2 , &dwReadLen , NULL) ||
// 			dwReadLen != 2 || sKeyLen <= 0)
// 		{
// 			::CloseHandle(hFile);
// 			return false;
// 		}
		if (!file.ReadFile(&sKeyLen , 2 , &dwReadLen ) ||
			dwReadLen != 2 || sKeyLen <= 0)
		{
			file.CloseFile();
            m_nErrCode = PI_E_PCL_READ_KEY_LEN_ERROR;
			return false;
		}

		pKey	= new Byte[sKeyLen + 1];
        memset(pKey, 0x00, sKeyLen + 1);
		//读取密钥
// 		if(!::ReadFile(hFile , pKey , sKeyLen , &dwReadLen , NULL) ||
// 			(DWORD)sKeyLen != dwReadLen)
// 		{
// 			::CloseHandle(hFile);
// 			delete []pKey;
// 			return false;
// 		}
		if(!file.ReadFile(pKey , sKeyLen , &dwReadLen ) ||
			(DWORD)sKeyLen != dwReadLen)
		{
			//::CloseHandle(hFile);
             m_nErrCode = PI_E_PCL_READ_KEY_ERROR;
			file.CloseFile();
			delete []pKey;
			return false;
		}

		//读取加密版本
// 		if(!::ReadFile(hFile , &nVer , 4 , &dwReadLen , NULL) ||
// 			dwReadLen != 4 || nVer != 1)	//版本目前只支持1
// 		{
// 			::CloseHandle(hFile);
// 			delete []pKey;
// 			return false;
// 		}
		if(!file.ReadFile(&nVer , 4 , &dwReadLen ) ||
			dwReadLen != 4 || nVer != 1)	//版本目前只支持1
		{
            m_nErrCode = PI_E_PCL_READ_ENC_VER_ERROR;
			file.CloseFile();
			delete []pKey;
			return false;
		}

		//读取数据长度
// 		if(!::ReadFile(hFile , &nDataLen , 4 , &dwReadLen , NULL) ||
// 			dwReadLen != 4 || nDataLen < 0)
// 		{
// 			::CloseHandle(hFile);
// 			delete []pKey;
// 			return false;
// 		}
		if(!file.ReadFile(&nDataLen , 4 , &dwReadLen) ||
			dwReadLen != 4 || nDataLen < 0)
		{
            m_nErrCode = PI_E_PCL_READ_DATA_LEN_ERROR;
			file.CloseFile();
			delete []pKey;
			return false;
		}

		//读取数据
		if(nDataLen > 0)
		{
			pData = new Byte[nDataLen];

// 			if(!::ReadFile(hFile , pData , nDataLen , &dwReadLen , NULL) || 
// 				dwReadLen != nDataLen)
// 			{
// 				::CloseHandle(hFile);
// 				delete []pKey;
// 				delete []pData;
// 				return false;
// 			}
			if(!file.ReadFile(pData , nDataLen , &dwReadLen) || 
				dwReadLen != nDataLen)
			{
                m_nErrCode = PI_E_PCL_READ_DATA_ERROR;
				file.CloseFile();
				delete []pKey;
				delete []pData;
				return false;
			}

			CDesEnc	enc;
			//解密数据
			if(!enc.ChangeToWhiteText(pKey , sKeyLen , pData , nDataLen ,  pData))
			{
                m_nErrCode = PI_E_PCL_DEC_DATA_ERROR;
				assert(false);
				file.CloseFile();//::CloseHandle(hFile);

				delete []pKey;
				delete []pData;
				return false;
			}

			//分析
			if(!this->ProcessBuffer(pData , nDataLen))
			{
				assert(false);
                m_nErrCode = PI_E_PCL_ANALYSIS_DATA_ERROR;
				delete []pData;
				delete []pKey;
				return false;
			}

			delete []pData;
			pData = NULL;
		}

		delete []pKey;		
//	}
//	catch (...)
//	{
//// 		if(hFile != INVALID_HANDLE_VALUE)
//// 			::CloseHandle(hFile);
//        m_nErrCode = PI_E_PCL_READ_FILE_EXCPTION;
//		file.CloseFile();
//
//		if(pKey != NULL)
//			delete []pKey;
//
//		if(pData != NULL)
//			delete []pData;
//
//		return false;
//	}

	//关闭文件句柄
// 	if(hFile != INVALID_HANDLE_VALUE)
// 		::CloseHandle(hFile);
	file.CloseFile();
	//记录文件名
	KeepFileName(strFilePath);
    m_nErrCode = PI_S_SUCCESS;

	return true;
}

bool CEncIniFile::WriteIntoEncFile(const string &strFilePath)
{
	//加密文件的格式
	//签名(4B) + 时间(8B) + 密钥长度(2B) + 密钥 + 加密版本(4) + 数据长度(4B) + 数据

	//BYTE	signature[4];	
	short	sKeyLen ;
	double	dTime;
	Byte	*pHead  = NULL;
	long	nVer;
	long	nDataLen;
	Byte	*pData = NULL;
	//int		nFileLen ;
	DWORD	dwWriteLen;
	//HANDLE	hFile = INVALID_HANDLE_VALUE;
	CFileUtil file;

//	try
//	{
		//获取当前时间
		dTime	= GetCurrentDateTime();

		//填充数据缓存区，需对数据进行对齐
		nDataLen	= m_arrIniInfo.GetBufferLength();
		if(nDataLen > 0)
		{
			long	nAdd = 0;	//把数据长度变成8的倍数，不足则补' '

			nAdd		= 8 - (nDataLen % 8);
			if(nAdd == 8)
				nAdd	= 0;
			nDataLen	+= nAdd;			
			pData	= new Byte[nDataLen];
			m_arrIniInfo.WriteBuffer(pData);
			if(nAdd > 0)
			{
				memset(pData + nDataLen - nAdd , ' ' , nAdd);
			}

			//对数据进行加密，以时间作为密钥
            CDesEnc	enc;
			if(!enc.ChangeToBlackText((Byte*)&dTime , sizeof(double) , pData , nDataLen , pData))
			{
				assert(false);
				delete []pData;
				return false;				
			}
		}

		//创立文件头
		long	nHeadLen	= 4 + 8 + 2 + 8 + 4 + 4;
		pHead	= new Byte[nHeadLen];

		memcpy(pHead , "#PS#" , 4);
		memcpy(pHead + 4 , &dTime , 8);
		sKeyLen	= 8;
		memcpy(pHead + 4 + 8 , &sKeyLen , 2);
		memcpy(pHead + 4 + 8 + 2 , &dTime , 8);
		nVer	= 1;
		memcpy(pHead + 4 + 8 + 2 + 8 , &nVer , 4);
		memcpy(pHead + 4 + 8 + 2 + 8 + 4 , &nDataLen , 4);
		
		//打开文件
// 		hFile	= ::CreateFile(strFilePath.c_str() , GENERIC_WRITE , 
// 									FILE_SHARE_READ | FILE_SHARE_WRITE, NULL ,
// 									CREATE_ALWAYS , 
// 									FILE_ATTRIBUTE_NORMAL , NULL);
// 		if(hFile == INVALID_HANDLE_VALUE)
// 		{
// 			if(pData != NULL)
// 				delete []pData;
// 
// 			if(pHead != NULL)
// 				delete []pHead;
// 			
// 			return false;
// 		}
		if (!file.OpenFile(strFilePath.c_str(),"wb+"))
		{
			if(pData != NULL)
				delete []pData;
			if(pHead != NULL)
				delete []pHead;
			return false;
		}

		//////////////////////////////////////////////////////////////////////////
		//把数据写入文件中

		//写入头
// 		if(!::WriteFile(hFile , pHead , nHeadLen , &dwWriteLen , NULL) ||
// 			nHeadLen != dwWriteLen)
// 		{
// 			assert(false);
// 			::CloseHandle(hFile);
// 
// 			delete []pHead;
// 
// 			if(pData != NULL)
// 				delete []pData;
// 
// 			return false;
// 		}
		if(!file.WriteFile(pHead , nHeadLen , &dwWriteLen ) ||
			nHeadLen != dwWriteLen)
		{
			assert(false);
			file.CloseFile();

			delete []pHead;

			if(pData != NULL)
				delete []pData;

			return false;
		}

		//写入数据
// 		if(!::WriteFile(hFile , pData , nDataLen , &dwWriteLen , NULL) ||
// 			nDataLen != dwWriteLen)
// 		{
// 			assert(false);
// 			::CloseHandle(hFile);
// 			
// 			delete []pHead;
// 			
// 			if(pData != NULL)
// 				delete []pData;
// 			
// 			return false;
// 		}
		if(!file.WriteFile(pData , nDataLen , &dwWriteLen) ||
			nDataLen != dwWriteLen)
		{
			assert(false);
			//::CloseHandle(hFile);
			file.CloseFile();

			delete []pHead;

			if(pData != NULL)
				delete []pData;

			return false;
		}

		//关闭文件
		file.CloseFile();//::CloseHandle(hFile);

		//释放缓存
		delete []pHead;
		if(pData != NULL)
			delete []pData;
		
//	}
//	catch (...)
//	{
//// 		if(hFile != INVALID_HANDLE_VALUE)
//// 			::CloseHandle(hFile);
//		file.CloseFile();
//
//		if(pHead != NULL)
//			delete []pHead;
//
//		if(pData != NULL)
//			delete []pData;
//
//		return false;
//	}

	KeepFileName(strFilePath);

	return true;
}

bool CEncIniFile::WriteIntoEncBinary(char *szEncBinary)
{
	//加密文件的格式
	//签名(4B) + 时间(8B) + 密钥长度(2B) + 密钥 + 加密版本(4) + 数据长度(4B) + 数据

	//BYTE	signature[4];	
	short	sKeyLen ;
	double	dTime;
	Byte	*pHead  = NULL;
	long	nVer;
	long	nDataLen;
	Byte	*pData = NULL;
	//int		nFileLen ;
	//DWORD	dwWriteLen;
	//HANDLE	hFile = INVALID_HANDLE_VALUE;

	
		//获取当前时间
		dTime	= GetCurrentDateTime();

		//填充数据缓存区，需对数据进行对齐
		nDataLen	= m_arrIniInfo.GetBufferLength();
		if(nDataLen > 0)
		{
			long	nAdd = 0;	//把数据长度变成8的倍数，不足则补' '

			nAdd		= 8 - (nDataLen % 8);
			if(nAdd == 8)
				nAdd	= 0;
			nDataLen	+= nAdd;			
			pData	= new Byte[nDataLen];
			m_arrIniInfo.WriteBuffer(pData);
			if(nAdd > 0)
			{
				memset(pData + nDataLen - nAdd , ' ' , nAdd);
			}

			//对数据进行加密，以时间作为密钥
            CDesEnc	enc;
			if(!enc.ChangeToBlackText((Byte*)&dTime , sizeof(double) , pData , nDataLen , pData))
			{
				assert(false);
				delete []pData;
				return false;				
			}
		}

		//创立文件头
		long	nHeadLen	= 4 + 8 + 2 + 8 + 4 + 4;
		pHead	= new Byte[nHeadLen];

		memcpy(pHead , "#PS#" , 4);
		memcpy(pHead + 4 , &dTime , 8);
		sKeyLen	= 8;
		memcpy(pHead + 4 + 8 , &sKeyLen , 2);
		memcpy(pHead + 4 + 8 + 2 , &dTime , 8);
		nVer	= 1;
		memcpy(pHead + 4 + 8 + 2 + 8 , &nVer , 4);
		memcpy(pHead + 4 + 8 + 2 + 8 + 4 , &nDataLen , 4);

		memcpy(szEncBinary, pHead, nHeadLen);
		memcpy(szEncBinary + nHeadLen, pData, nDataLen);
		
		delete pData;
		delete pHead;
	return true;
}

