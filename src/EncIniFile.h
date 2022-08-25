//*********************************************************************************
// EncIniFile.h: interface for the CEncIniFile class.
//用于访问加密后的配置文本文件
//
//
//由于把文件一次行读入内存中，因此适用于文件不是很大的配置文件
//*********************************************************************************

#ifndef _ENCINIFILE_H__
#define _ENCINIFILE_H__

#include <vector>
#include <string>
#include "GlobalDefine.h"


using namespace std;

class CEncIniFile  
{
private:
    int m_nErrCode;
public:
	CEncIniFile();
	~CEncIniFile();

	CEncIniFile &operator=(const CEncIniFile &src);
    
    int GetErrCode(){return m_nErrCode;}

	//裁剪字符串两端的空格字符
	static void TrimSpace(string &strText ,
						  bool bTrimLeft = true, 
						  bool bTrimRight = true);

	//裁剪字符串两端的空格字符和制表符(Tab)字符
	static void TrimSpaceAndTab(string &strText , 
							    bool	bTrimLeft = true , 
								bool    bTrimRight = true);

	//////////////////////////////////////////////////////////////////////////
	//定义由外部访问的接口

	//查询和查找

	//是否有节名
	bool	HasSection(const string &strSectionName);

	//是否有入口项
	bool	HasEntry(const string &strSectionName , 
					 const string &strEntry);
	
	//获取文件中的所有节名
	void    QuerySections(vector<string> &arrSections);

	//获取给定节名下的所有入口项
	void    QueryEntries(const string &strSectionName , 
						 vector<string> &arrEntries);

	bool    GetEntryValue(const string &strSectionName , 
						  const string &strEntry ,
						  string &strValue);

	//增加或修改
	bool	SetEntryValue(const string &strSectionName , 
						  const string &strEntry ,
						  const string &strValue);

	//删除
	bool   DeleteSection(const string &strSectionName);
	bool   DeleteEntry(const string &strSectionName ,
					   const string &strEntry);

	//获取完整的绝对文件路径名
	string  GetFilePath()	{return m_strFilePathName;}

	//只获取文件名，里面没有路径信息
	string  GetFileName()	{return m_strFileName;}

	//文件读写
	bool   ReadFromEncFile(const string &strFilePath);		//从加密文件中读取
	bool   ReadFromTextFile(const string &strFilePath);		//从文本文件中读取

	bool   WriteIntoEncFile(const string &strFilePath);		//写入加密文件中
	bool   WriteIntoTextFile(const string &strFilePath);	//写入文本文件中

	//把配置写到二进制流 add by kejun 2010-03-19
	bool WriteIntoEncBinary(char *szEncBinary);
	bool WriteIntoTextBinary(char *szTextBinary);
	//add end
	//////////////////////////////////////////////////////////////////////////
	//由外部访问的较高级接口
	//“缺省值”主要用在没有找到对应的入口项时使用

	//获取和设置布尔值
	bool  GetBooleanValue(const string &strSectionName , 
						  const string &strEntry , 
						  bool  bDefaultValue = false);

	void  SetBooleanValue(const string &strSectionName ,
						  const string &strEntry , 
						  bool  bValue);

	//获取和设置整形值
	int  GetIntValue(const string &strSectionName , 
					 const string &strEntry , 
					 int nDefaultValue = 0);

	void SetIntValue(const string &strSectionName , 
		             const string &strEntry ,
					 int nValue);
private:
	//数据
	string		m_strFilePathName;		//文件路径名
	string		m_strFileName;

	//保存文件名到内部变量
	void KeepFileName(const string &strFilePathName);

	//一个入口项
	class _Entry
	{
	public:
		_Entry();
		~_Entry();
		
		string	strEntry;		//入口名字
		string	strValue;		//值

		int		GetBufferLength();			//需要缓存的大小
		bool	WriteBuffer(Byte *pBuffer);	//写入缓存
	};

	//一个节名
	class _Section
	{
	public:
		_Section();
		~_Section();
		
		string	strSectionName;
		vector<_Entry>	arrEntries;

		int		GetBufferLength();
		bool	WriteBuffer(Byte *pBuffer);
	};

	//整个文件中的信息
	class _Total
	{
	public:
		_Total();
		~_Total();
	
		vector<_Section> arrSections;

		int		GetBufferLength();
		bool	WriteBuffer(Byte *pBuffer);

		int		FindSection(const string &strSectionName);

		void    Reset();		//清空
	};

	_Total		m_arrIniInfo;

	//从缓存中处理信息
	bool ProcessBuffer(Byte *pBuffer , int nBufLen);

	//判断一行是否是节名
	bool IsSectionLine(Byte *pLine , int nBufLen);	//判断一行是否是节名

	//判断一行是否是入口项
	bool IsEntryLine(Byte *pLine , int nBufLen);	//判断一行是否是入口

	//从一行中提取节名
	bool ExtractSection(Byte *pLine ,
						int nBufLen , 
						string &strSectionName);

	//从一行中提取入口项名和值
	bool ExtractEntry(Byte *pLine ,
					  int nBufLen , 
					  string &strEntry , 
					  string &strValue);

	
};

#endif // 
