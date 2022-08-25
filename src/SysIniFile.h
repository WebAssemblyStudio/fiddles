//*********************************************************************************
// SysIniFile.h: interface for the CSysIniFile class.
//用于访问加密后的系统配置文件
//
//
//*********************************************************************************
#ifndef _SYSINIFILE_H__
#define _SYSINIFILE_H__

#include "EncIniFile.h"
#include "SysDef.h"

enum EnumHardwareType;		//defined in SysDef.h
enum EnumClientVersion;

class CEncIniFile;		//defined in EncIniFile.h

//定义文件处理的规则
struct FileRule 
{
	bool  bDecryptFileOnOpen;		//当文件打开一个文件时，需要判断文件是否需要解密
									//true，则需要解密
									//false，则不需要解密

	bool  bEncryptFileOnExist;		//打开一个已经存在的文件时，如果文件没有加密时，
									//是否需要加密

	bool  bEncryptFileOnNew;		//新建一个文件时，是否需要加密

	bool  bPrintDebug;				//是否需要输出调试信息

	FileRule()
	{
		bDecryptFileOnOpen	= false;
		bEncryptFileOnExist	= false;
		bEncryptFileOnNew	= false;
		bPrintDebug			= false;
	}

	FileRule &operator=(const FileRule &rule)
	{
		bDecryptFileOnOpen		= rule.bDecryptFileOnOpen;
		bEncryptFileOnExist		= rule.bEncryptFileOnExist;
		bEncryptFileOnNew		= rule.bEncryptFileOnNew;
		bPrintDebug				= rule.bPrintDebug;
        return *this;
	}
};

class CSysIniFile : public CEncIniFile
{
public:
	CSysIniFile();
	~CSysIniFile();

	CSysIniFile &operator=(const CSysIniFile &src);
//////////////////////////////////////////////////////////////////////////
//定义与文件相关的高级逻辑接口

	//获取和设置产品序列号
	string	GetProductKey();
	void	SetProductKey(const string &strProductKey);

	//获取和设置使用单位名
	string	GetUnitName();
	void	SetUnitName(const string &strUnitName);

	//获取和设置加密狗的连接字符串
	string	GetGrantDogCnnString();
	void	SetGrantDogCnnString(const string &strCnn);

	//判断是否使用Windows钩子
	bool	IsUseWindowsHook();
	void	SetUseWindowsHook(bool bUse);
	
	//判断是否使用Usb设备
	bool	IsUseUsbDevice();
	void	SetUseUsbDevice(bool bUse);

	//判断是否使用剪贴板
	bool	IsUseClipboard();
	void	SetUseClipboard(bool bUse);

	//判断是否使用打印机
	bool	IsUsePrinter();
	void	SetUsePrinter(bool bUse);

	//判断是否允许拷贝屏幕
	bool    IsPrintScreen();
	void    SetPrintScreen(bool bUse);

	//设置,获取加密模式	add by lk 20190429
	void SetEncMode(int iEncMdoe);
	int GetEncMode();

	//add by lyj 2015-7-31 添加检查标志，设置标志信息
	//////////////////////////////////////////////////////////////////////////
	bool	InitCheckSign();
	bool	IsHaveCheckSign();
	void	AddCheckSign(bool bCheckHard,bool bCheckTime);
	bool	IsCheckBindHard();
	void	SetCheckBindHard(bool bCheck);
	bool	IsCheckLimitTime();
	void	SetCheckLimitTime(bool bCheck);
	void	SetCheckInlineClipbord(bool bCheck);
	bool	IsCheckInlineClipboard();
	void	SetCheckDataControl(bool bCheck);
	bool	IsCheckDataControl();
	void	SetCheckTextCopy(bool bCheck);
	bool	IsCheckTextCopy();
	void	SetCheckImageCopy(bool bCheck);
	bool	IsCheckImageCopy();
	void	SetCheckInlineCoverApi(bool bCheck);
	bool	IsCheckInlineCoverApi();
	void	SetQQPrntScr(bool bCheck);	//设置是否启用QQ,rtx,飞秋拷屏
	bool	IsCheckQQPrntScr();			//判断是否启用QQ拷屏
	void	SetUSBBind(bool bCheck);	//设置Usb绑定方式
	bool	IsUseUSBBind();				//是否使用Usb绑定方式
		bool    IsUseOnlyRead();
	void    SetOnlyRead(bool bUse);
	//////////////////////////////////////////////////////////////////////////
	
	//加密算法
	bool SetAlgorithmMode(int nMode); //设置 0=AES , 1=SM4
	bool GetAlgorithmMode(int &nMode);//获取

	
	//客户端版本控制
	//设置客户端版本类型
	EnumClientVersion GetClientVersion();
	//获得客户端版本类型
	void SetClinetVersion(EnumClientVersion ver);


	//////////////////////////////////////////////////////////////////////////
	//与试用版相关的信息

	//检查是否是试用版
	bool	IsTryVersion();

	//获取和设置绑定硬件信息
	void  SetBindingHardware(EnumHardwareType hardtype , 
							 const string &strHardID);	//如果硬件ID字符串为空，则不是试用版
	bool  GetBindingHardware(EnumHardwareType &hardtype , string &strHardID);
	//////////////////////////////////////////////////////////////////////////
	//与应用程序类型和文件类型相关的函数
	//注：在应用程序名中不能加后缀
	//文件类型的格式为： *.dwg<D|EE|NE|P>:*.dxf<D|P>
	//在应用程序类型和文件类型比较时对大小写不敏感

	//查询系统钩取的应用程序名
	void     QueryHookedAppType(vector<string> &arrApps);

	//判断是否钩子给定的程序类型
	//还需要检查钩取的类型是否已经生效
	//是配置的应用程序与生效状态的综合结果
	bool	IsHookAppType(const string &strAppName);

	bool	IsHookAppType(const string &strAppName, bool &bUseIat);

	//获取给定应用程序类型的文件类型数
	int		GetFileTypeCount(const string &strAppName);

	//根据索引获取文件类型的信息
	bool	GetFileType(const string &strAppName ,
						int			 nIndex ,			//索引
						string		 &strFileType ,		//输出
						FileRule	 &rule				//输出
						);
	//查询文件类型索引
	//如果没有找到，则返回－1
	int		FindFileTypeIndex(const string &strAppName , 
							  const string &strFileType);

	//获取文件处理规则
	bool	GetFileRule(const string &strAppName , 
						const string &strFileType , 
						FileRule	 &rule);
//获取文件处理规则
	FileRule GetFileRuleMobile(const string &strFileType)
	{
		FileRule rule;
		GetFileRule("com.piclesoft.mobile",strFileType , rule);
		return rule;
	}
	//设置文件处理规则
	//如果文件类型不存在，则返回false
	bool	SetFileRule(const string &strAppName , 
						const string &strFileType ,
						const FileRule	&rule);
	
	//增加程序类型
	bool	AddAppType(const string &strAppName);

	//删除程序类型
	bool	RemoveAppType(const string &strAppName);

	//删除文件类型
	bool	RemoveFileType(const string &strAppName ,
						   int	 nIndex);
	bool	RemoveFileType(const string &strAppName ,
						   const string &strFileType);

	//插入文件类型
	//如果应用程序类型或者文件类型不存在，都会动态创立
	bool	InsertFileType(const string &strAppName ,
						   int			nPos ,		//插入的位置
						   const string &strFileType ,
						   const FileRule	&rule);
	
	//与应用程序对应的逻辑模块相关的接口
	string GetAppLogicModuleName(const string &strAppName);	//获取逻辑模块名，例如：PFileLogic.dll、PWordProcess.dll等
	void   SetAppLogicModuleName(const string &strAppName , const string &strLogicModuleName);
	
	//是否检查应用程序模块的真实性
//	bool IsNeedCheckAppModule(const string &strAppName);				//是否需要检查程序的真实性
//	void SetAppModuleCheckFlag(const string &strAppName , bool bCheck);
	
	//获取和设置钩取的应用程序类型是否生效
	bool IsTakeEffect(const string &strAppName);
	void SetTakeEffectFlag(const string &strAppName , bool bEffect);

//////////////////////////////////////////////////////////////////////////
//在读写操作时保持同步

	//文件读写
	bool   ReadFromEncFile(const string &strFilePath);		//从加密文件中读取
	bool   ReadFromTextFile(const string &strFilePath);		//从文本文件中读取
	
	bool   WriteIntoEncFile(const string &strFilePath);		//写入加密文件中
	bool   WriteIntoTextFile(const string &strFilePath);	//写入文本文件中

private:
	//是否钩取了应用程序类型，此时不管生效状态
	bool	HasHookAppTypeNoCheckEffect(const string &strAppName);

	//文件规则与字符串的相互转换
	void FileRuleToString(const FileRule &rule , string &strRule);
	void StringToFileRule(const string &strRule , FileRule &rule);

	//初始化文件规则
	void InitializeFileRule(FileRule &rule);

	//从一个字符串中提取文件类型字符子串和文件属性子串
	//*.dwg<D|EE|NE>
	//子串为*.dwg和D|EE|NE
	void ExtractFileTypeAndRule(const string &strText , 
								string &strFileType , 
								string &strFileRule);

	void ExtractFileTypeAndRule(const string &strText ,
								string &strFileType ,
								FileRule &rule);

	void UnionFileTypeAndRule(const string &strFileType ,
							  const string &strFileRule , 
							  string &strText);
	void UnionFileTypeAndRule(const string &strFileType ,
							  const FileRule &rule ,
							  string &strText);

	
};
#endif
