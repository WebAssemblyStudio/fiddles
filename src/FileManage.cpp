// FileManage.cpp: implementation of the CHookFileManage class.
//
//////////////////////////////////////////////////////////////////////


#include "FileManage.h"
#include "SysIniFile.h"
#include "StringFunc.h"

#include <memory.h>
#include <algorithm>
using namespace std;

//用于输出提示信息的缓存区
extern char g_szHintBuff[1000];



//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////


bool CHookInfo::NeedHook(const char *fileName)
{	
	FileRule * pRule = GetFileRule((char*)fileName);
	if(NULL == pRule)
		return false ;
	else
		return pRule->bDecryptFileOnOpen ;
}

bool CHookInfo::NeedAddFileHeadWhenCreate(const char *fileName)
{	
	FileRule * pRule = GetFileRule((char*)fileName);
	if(NULL == pRule)
		return false ;
	else
		return pRule->bEncryptFileOnNew ;
}

bool CHookInfo::NeedAddFileHeadWhenOpen(const char *fileName)
{	
	FileRule * pRule = GetFileRule((char*)fileName);
	if(NULL == pRule)
		return false ;
	else
		return pRule->bEncryptFileOnExist ;
}

bool CHookInfo::NeedPrintLog(const char *fileName)
{	
	FileRule * pRule = GetFileRule((char*)fileName);
	if(NULL == pRule)
		return false ;
	else
		return pRule->bPrintDebug ;
}

bool CHookInfo::Init(CSysIniFile *pPcl)
{
	//取得模块名
	string strSection = "com.piclesoft.mobile";
    m_pPcl = pPcl;  //设置为局部指针
#ifdef UNICODE
	transform(strSection.begin(),strSection.end(),strSection.begin(),::towlower);
#else
	transform(strSection.begin(),strSection.end(),strSection.begin(),::tolower);
#endif
	GetHookFileInfo(strSection);

	return true ;
}

CHookInfo::CHookInfo()
{
	m_pPcl = NULL;
}

CHookInfo::~CHookInfo()
{
	for(int i = 0 ; i < m_FileTypeRule.size() ; i++ )
	{
		FileRule * pRule = m_FileTypeRule[i].m_pFileRule;
		if(NULL == pRule)
			continue;
		delete pRule ;
	}
}


bool CHookInfo::GetHookFileInfo(string strSection)
{
	//取得文件类型的总个数
	int nCount	= m_pPcl->GetFileTypeCount(strSection);

	//依次读取每个文件类型的信息
	string		strType;
	for(int j = 0 ; j < nCount ; j++)
	{
		CFileRule rule ;
		rule.m_pFileRule = new FileRule ;//在析构函数中释放
		if(NULL == rule.m_pFileRule)
			return false ;
		
		m_pPcl->GetFileType(strSection , j , strType , *rule.m_pFileRule);
		rule.m_strType = strType ;
		m_FileTypeRule.push_back(rule);
	}
	
	return true ;
}

bool CHookInfo::PathFileMatchSpec( char* pszFileParam, char* pszSpec)
{
	bool bMatch = false ;
	if(NULL == pszFileParam || NULL == pszSpec)
		return bMatch ;

	if(0 == strlen(pszFileParam) || 0 == strlen(pszSpec))
		return bMatch ;

	if(WildcardMatch(pszFileParam,pszSpec))
		bMatch = true ;//匹配最后一种类型

	return bMatch ;
}


//Add End

FileRule* CHookInfo::GetFileRule( char* lcpFileName)
{
	
	char fileName[MAXPATH_OF_FILE] = {0};
	strcpy(fileName,lcpFileName);

	if(NULL == fileName || 0 == strlen(fileName))
		return NULL ;

	if(m_FileNameToRule.end() == m_FileNameToRule.find(fileName))
	{
        char pszFileName[MAX_PATH] = {0};
        GetFileNameFromPath(fileName, pszFileName); //先获取文件名
        //以前没有生成类型信息，则生成类型信息
		for(int i = 0 ; i < m_FileTypeRule.size() ; i++ )
		{
			CFileRule rule = m_FileTypeRule[i] ;
			if(PathFileMatchSpec(pszFileName,(char*)rule.m_strType.c_str()))
			{
				m_FileNameToRule[fileName] = rule.m_pFileRule ;
				return rule.m_pFileRule ;
			}
		}

		//没有找到对应的信息，为了避免重复查找，将对应的类型设为空
		m_FileNameToRule[fileName] = NULL ;
		return NULL ;
	}

	return m_FileNameToRule[fileName] ;		
}
