// FileManage.h: interface for the CHookFileManage class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_FILEMANAGE_H__E974D98C_9C0E_4A58_9516_63BE6B1784F3__INCLUDED_)
#define AFX_FILEMANAGE_H__E974D98C_9C0E_4A58_9516_63BE6B1784F3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#pragma warning( disable : 4786)  // Disable warning messages
#include <map>

#include <string>
#include "SysIniFile.h"
using namespace std ;

//#define FILEVERINFOLENGTH  128


class CHookInfo		//记录钩取的文件类型
{
public:
	bool NeedHook(const char* fileName);		//根据文件名判断是否需要钩取
	bool NeedPrintLog(const char *fileName);	//根据文件名判断是否需要打印
	bool NeedAddFileHeadWhenCreate(const char *fileName);	//根据文件名判断新建文件时是否需要加文件头
	bool NeedAddFileHeadWhenOpen(const char *fileName);		//根据文件名判断打开文件时是否需要加文件头

	CHookInfo();
	~CHookInfo();
	bool Init(CSysIniFile *pPcl);		//通过接口从配置文件中读取信息

private:
	CSysIniFile* m_pPcl;
	struct CFileRule	//文件类型对应的钩取规则
	{
		string m_strType ;			//文件类型
		FileRule * m_pFileRule ;	//规则信息
	};


	FileRule* GetFileRule( char* fileName);	//通过文件名取得规则
	bool PathFileMatchSpec( char* pszFileParam, char* pszSpec);

	//通过文件名判断一个文件是否属于某些类型,第一个参数是路径＋文件名，兼容不带路径的文件名
	bool GetHookFileInfo(string strSection);	//取得strSection节的相关信息
	vector<CFileRule>      m_FileTypeRule ;		//文件类型及钩取信息的集合
	map<string,FileRule*>  m_FileNameToRule ;	//记录已知的文件名和对应的规则
};


#endif // !defined(AFX_FILEMANAGE_H__E974D98C_9C0E_4A58_9516_63BE6B1784F3__INCLUDED_)
