#include <unistd.h>
#include <cassert>
#include <string>
#include <algorithm>
//#include <strcasecmp.h>
#include "EncIniFile.h"
#include "SysIniFile.h"
#include "IniFileConst.h"
#include "StringFunc.h"
#include <stdio.h>
#include"../PiEncrypt.h"

using namespace std;
//////////////////////////////////////////////////////////////////////////
//class CSysIniFile
int strcasecmp(string str1, string str2)
{
	string strA = str1;
	transform(strA.begin(), strA.end(), strA.begin(), ::tolower);
	string strB = str2;
	transform(strB.begin(), strB.end(), strB.begin(), ::tolower);
	return strA.compare(strB);//返回值：0表示字符串相同;
}

CSysIniFile::CSysIniFile()
{
}

CSysIniFile::~CSysIniFile()
{
}

CSysIniFile &CSysIniFile::operator=(const CSysIniFile &src)
{
	return *this;
}

void CSysIniFile::InitializeFileRule(FileRule &rule)
{
	rule.bDecryptFileOnOpen		= false;
	rule.bEncryptFileOnExist	= false;
	rule.bEncryptFileOnNew		= false;
	rule.bPrintDebug			= false;
}

//从一个字符串中提取文件类型字符子串和文件属性子串
	//*.dwg<D|EE|NE>
	//子串为*.dwg和D|EE|NE
void CSysIniFile::ExtractFileTypeAndRule(const string &strText , 
										 string &strFileType , 
										 string &strFileRule)
{
	//初始化
	strFileType.erase();
	strFileRule.erase();

	int	nPos;
	nPos = strText.find_first_of('<' , 0);
	
	if(nPos >= 0)
	{
		assert(nPos > 0);
		
		strFileType	= strText.substr(0 , nPos);
		
		int	nPos2;
		nPos2	= strText.find_first_of('>' , nPos + 1);
		if(nPos2 <= nPos)
		{
			assert(false);
			return ;
		}
		
		strFileRule	= strText.substr(nPos + 1 , nPos2 - nPos - 1);		
	}
	else
	{
		strFileType	= strText;
	}	
}

void CSysIniFile::ExtractFileTypeAndRule(const string &strText , 
										 string &strFileType , 
										 FileRule &rule)
{
	string strRule;

	ExtractFileTypeAndRule(strText , strFileType , strRule);

	StringToFileRule(strRule , rule);
}

void CSysIniFile::UnionFileTypeAndRule(const string &strFileType ,
									   const string &strFileRule , 
									   string &strText)
{
	strText = strFileType + "<" + strFileRule + ">";
}

void CSysIniFile::UnionFileTypeAndRule(const string &strFileType , 
									   const FileRule &rule , 
									   string &strText)
{
	string	strFileRule;

	FileRuleToString(rule , strFileRule);

	UnionFileTypeAndRule(strFileType , strFileRule , strText);
}

void CSysIniFile::FileRuleToString(const FileRule &rule , string &strRule)
{
	strRule.erase();

	if(rule.bDecryptFileOnOpen)
		strRule	= "D";
	
	if(rule.bEncryptFileOnExist)
	{
		if(strRule.length() > 0)
			strRule += "|EE";
		else
			strRule	+= "EE";
	}

	if(rule.bEncryptFileOnNew)
	{
		if(strRule.length() > 0)
			strRule	+= "|NE";
		else
			strRule	+= "NE";
	}

	if(rule.bPrintDebug)
	{
		if(strRule.length() > 0)
			strRule	+= "|P";
		else
			strRule	+= "P";
	}
}

void CSysIniFile::StringToFileRule(const string &strRule , FileRule &rule)
{
	//进行初始化
	InitializeFileRule(rule);

	vector<string>	arrRules;
	string			strSeps	= "|";	//定义分隔符
	string			strPart;

	ExtractComponentFromString(strRule , strSeps , arrRules);

	for(int i = 0 ; i < (int)arrRules.size() ; i++)
	{
		strPart		= arrRules.at(i);

		//裁剪空格字符
		TrimSpace(strPart , true , true);
		if(strPart.length() == 0)
			continue;

		//if(stricmp(strPart.c_str() , "D") == 0)
		if(strcasecmp(strPart/*.c_str()*/ , "D") == 0)
		{
			rule.bDecryptFileOnOpen	= true;
			continue;
		}

		//if(stricmp(strPart.c_str() , "EE") == 0)
		if(strcasecmp(strPart/*.c_str()*/ , "EE") == 0)
		{
			rule.bEncryptFileOnExist	= true;
			continue;
		}

		//if(stricmp(strPart.c_str() , "NE") == 0)
		if(strcasecmp(strPart/*.c_str()*/ , "NE") == 0)
		{
			rule.bEncryptFileOnNew		= true;
			continue;
		}

		//if(stricmp(strPart.c_str() , "P") == 0)
		if(strcasecmp(strPart/*.c_str()*/ , "P") == 0)
		{
			rule.bPrintDebug	= true;
			continue;
		}
	}	

	//修改规则
	if(rule.bEncryptFileOnExist || rule.bEncryptFileOnNew)
		rule.bDecryptFileOnOpen	= true;
}

string CSysIniFile::GetProductKey()
{
	string	strText;
	
	GetEntryValue(SECNAME_SUMMARY , ENTRYNAME_SUMMARY_PRODUCTKEY , strText);

	return strText;
}

void CSysIniFile::SetProductKey(const string &strProductKey)
{
	SetEntryValue(SECNAME_SUMMARY , ENTRYNAME_SUMMARY_PRODUCTKEY , strProductKey);
}

void CSysIniFile::SetEncMode(int iEncMdoe)
{
	SetIntValue(SECNAME_SUMMARY , ENTRYNAME_HOOKSCOPE_ENCMODE , iEncMdoe);
}

int CSysIniFile::GetEncMode()
{
	int temp = -1;	//-1为未找到
	return GetIntValue(SECNAME_SUMMARY, ENTRYNAME_HOOKSCOPE_ENCMODE, temp);
}

string CSysIniFile::GetUnitName()
{
	string	strText;
	
	GetEntryValue(SECNAME_SUMMARY , ENTRYNAME_SUMMARY_UNITNAME , strText);
	
	return strText;
}

void CSysIniFile::SetUnitName(const string &strUnitName)
{
	SetEntryValue(SECNAME_SUMMARY , ENTRYNAME_SUMMARY_UNITNAME , strUnitName);
}

string CSysIniFile::GetGrantDogCnnString()
{
	string	strText;
	
	GetEntryValue(SECNAME_SUMMARY , ENTRYNAME_SUMMARY_GRANTDOGCNNSTRING , strText);
	
	return strText;
}

void CSysIniFile::SetGrantDogCnnString(const string &strCnn)
{
	SetEntryValue(SECNAME_SUMMARY , ENTRYNAME_SUMMARY_GRANTDOGCNNSTRING , strCnn);
}

bool CSysIniFile::IsUseWindowsHook()
{
	return GetBooleanValue(SECNAME_HOOKSCOPE , ENTRYNAME_HOOKSCOPE_USEWINDOWSHOOK , false);
}

void CSysIniFile::SetUseWindowsHook(bool bUse)
{
	SetBooleanValue(SECNAME_HOOKSCOPE , ENTRYNAME_HOOKSCOPE_USEWINDOWSHOOK , bUse);
}

bool CSysIniFile::IsUseUsbDevice()
{
	return GetBooleanValue(SECNAME_HOOKSCOPE , ENTRYNAME_HOOKSCOPE_USEUSBDEVICE , true);
}

void CSysIniFile::SetUseUsbDevice(bool bUse)
{
	SetBooleanValue(SECNAME_HOOKSCOPE , ENTRYNAME_HOOKSCOPE_USEUSBDEVICE , bUse);
}

bool CSysIniFile::IsUseClipboard()
{
	return GetBooleanValue(SECNAME_HOOKSCOPE , ENTRYNAME_HOOKSCOPE_USECLIPBOARD , true);
}

void CSysIniFile::SetUseClipboard(bool bUse)
{
	SetBooleanValue(SECNAME_HOOKSCOPE , ENTRYNAME_HOOKSCOPE_USECLIPBOARD , bUse);
}

bool CSysIniFile::IsUsePrinter()
{
	return GetBooleanValue(SECNAME_HOOKSCOPE , ENTRYNAME_HOOKSCOPE_USEPRINTER , true);
}

void CSysIniFile::SetUsePrinter(bool bUse)
{
	SetBooleanValue(SECNAME_HOOKSCOPE , ENTRYNAME_HOOKSCOPE_USEPRINTER , bUse);
}

bool CSysIniFile::IsPrintScreen()
{
	return GetBooleanValue(SECNAME_HOOKSCOPE , ENTRYNAME_HOOKSCOPE_USEPRINTSCREEN , true);
}
void CSysIniFile::SetPrintScreen(bool bUse)
{
	SetBooleanValue(SECNAME_HOOKSCOPE , ENTRYNAME_HOOKSCOPE_USEPRINTSCREEN , bUse);
}
bool CSysIniFile::IsUseOnlyRead()
{
	return GetBooleanValue(SECNAME_HOOKSCOPE, ENTRYNAME_HOOKSCOPE_USERREADONLY , false);
}
void CSysIniFile::SetOnlyRead(bool bUse)
{
	SetBooleanValue(SECNAME_HOOKSCOPE , ENTRYNAME_HOOKSCOPE_USERREADONLY , bUse);
}
//////////////////////////////////////////////////////////////////////////
//add by lyj 2015-7-31 初始化标志函数
bool CSysIniFile::InitCheckSign()		//返回TRUE代表原配置文件中有检查标志，返回FALSE代表原配置文件中没有检查标志，同时新添加检查标志
{
	if(HasSection(SECNAME_CHECKSIGN))
		return true;
	AddCheckSign(true,true);
	WriteIntoEncFile(GetFilePath());
	return false;
}
bool CSysIniFile::IsHaveCheckSign()
{
	return HasSection(SECNAME_CHECKSIGN);
}
void CSysIniFile::AddCheckSign(bool bCheckHard,bool bCheckTime)
{
	SetBooleanValue(SECNAME_CHECKSIGN,ENTRYNAME_CHECKSIGN_CHECKBINDHARD,bCheckHard);
	SetBooleanValue(SECNAME_CHECKSIGN,ENTRYNAME_CHECKSIGN_CHECKLIMITTIME,bCheckTime);
}

bool CSysIniFile::IsCheckBindHard()
{
	return GetBooleanValue(SECNAME_CHECKSIGN,ENTRYNAME_CHECKSIGN_CHECKBINDHARD,true);
}
void CSysIniFile::SetCheckBindHard(bool bCheck)
{
	SetBooleanValue(SECNAME_CHECKSIGN,ENTRYNAME_CHECKSIGN_CHECKBINDHARD,bCheck);
}
bool CSysIniFile::IsCheckLimitTime()
{
	return GetBooleanValue(SECNAME_CHECKSIGN,ENTRYNAME_CHECKSIGN_CHECKLIMITTIME,true);
}
void CSysIniFile::SetCheckLimitTime(bool bCheck)
{
	SetBooleanValue(SECNAME_CHECKSIGN,ENTRYNAME_CHECKSIGN_CHECKLIMITTIME,bCheck);
}
void CSysIniFile::SetCheckInlineClipbord(bool bCheck)
{
	SetBooleanValue(SECNAME_HOOKSCOPE,ENTRYNAME_HOOKSCOPE_INLINECLIPBOARD,bCheck);
}
bool CSysIniFile::IsCheckInlineClipboard()
{
	return GetBooleanValue(SECNAME_HOOKSCOPE,ENTRYNAME_HOOKSCOPE_INLINECLIPBOARD,false);
}
void CSysIniFile::SetCheckDataControl(bool bCheck)
{
	SetBooleanValue(SECNAME_HOOKSCOPE,ENTRYNAME_HOOKSCOPE_DATABASECONTROL,bCheck);
}
bool CSysIniFile::IsCheckDataControl()
{
	return GetBooleanValue(SECNAME_HOOKSCOPE,ENTRYNAME_HOOKSCOPE_DATABASECONTROL,false);
}
void CSysIniFile::SetCheckInlineCoverApi(bool bCheck)
{
	SetBooleanValue(SECNAME_HOOKSCOPE,ENTRYNAME_HOOKSCOPE_INLINECOVERAPI,bCheck);
}
void	CSysIniFile::SetQQPrntScr(bool bCheck)
{
	SetBooleanValue(SECNAME_HOOKSCOPE,ENTRYNAME_HOOKSCOPE_QQPRNTSCR,bCheck);
}
bool	CSysIniFile::IsCheckQQPrntScr()
{
	return GetBooleanValue(SECNAME_HOOKSCOPE,ENTRYNAME_HOOKSCOPE_QQPRNTSCR,false);
}
void	CSysIniFile::SetUSBBind(bool bCheck)
{
	SetBooleanValue(SECNAME_HOOKSCOPE,ENTRYNAME_HOOKSCOPE_USBBind,bCheck);
}
bool	CSysIniFile::IsUseUSBBind()
{
	return GetBooleanValue(SECNAME_HOOKSCOPE,ENTRYNAME_HOOKSCOPE_USBBind,false);
}
bool CSysIniFile::IsCheckInlineCoverApi()
{
	return GetBooleanValue(SECNAME_HOOKSCOPE,ENTRYNAME_HOOKSCOPE_INLINECOVERAPI,false);
}
void	CSysIniFile::SetCheckTextCopy(bool bCheck)
{
	SetBooleanValue(SECNAME_HOOKSCOPE,ENTRYNAME_HOOKSCOPE_TEXTCOPY,bCheck);
}
bool	CSysIniFile::IsCheckTextCopy()
{
	return GetBooleanValue(SECNAME_HOOKSCOPE,ENTRYNAME_HOOKSCOPE_TEXTCOPY,false);
}
void	CSysIniFile::SetCheckImageCopy(bool bCheck)
{
	SetBooleanValue(SECNAME_HOOKSCOPE,ENTRYNAME_HOOKSCOPE_IMAGECOPY,bCheck);
}
bool	CSysIniFile::IsCheckImageCopy()
{
	return GetBooleanValue(SECNAME_HOOKSCOPE,ENTRYNAME_HOOKSCOPE_IMAGECOPY,false);
}

//加密算法
bool CSysIniFile::SetAlgorithmMode(int nMode)
{
	SetIntValue(SECNAME_HOOKSCOPE , ENTRYNAME_HOOKSCOPE_ALGORITHMMODE , nMode);
	return true;
}
bool CSysIniFile::GetAlgorithmMode(int &nMode)
{
	//获取失败时值为0，默认AES算法
	nMode = GetIntValue(SECNAME_HOOKSCOPE , ENTRYNAME_HOOKSCOPE_ALGORITHMMODE);
	return true;
}

EnumClientVersion CSysIniFile::GetClientVersion()
{
	return (EnumClientVersion)GetIntValue(SECNAME_RUNVERSION,ENTRYNAME_RUNVERSION_VERTYPE,FORINNER);
}

void CSysIniFile::SetClinetVersion(EnumClientVersion ver)
{
	SetIntValue(SECNAME_RUNVERSION,ENTRYNAME_RUNVERSION_VERTYPE,ver);
}

//////////////////////////////////////////////////////////////////////////

bool CSysIniFile::IsTryVersion()
{
	return HasSection(SECNAME_TRYVERSION);
}

bool CSysIniFile::GetBindingHardware(EnumHardwareType &hardtype , 
									 string &strHardID)
{
	hardtype	= htHardDisk;
	strHardID.erase();

	if(!HasSection(SECNAME_TRYVERSION))
		return false;

	int  nHardType;

	nHardType	= GetIntValue(SECNAME_TRYVERSION , 
							  ENTRYNAME_TRYVERSION_BINDHARDTYPE , 
							  (int)htHardDisk);

	hardtype	= (EnumHardwareType)nHardType;

	GetEntryValue(SECNAME_TRYVERSION , 
				  ENTRYNAME_TRYVERSION_BINDHARDID , 
				  strHardID);

	return true;	
}

void CSysIniFile::SetBindingHardware(EnumHardwareType hardtype , const string &strHardID)
{
	if(strHardID.length() == 0)		//如果字符串为空，则删除试用版标志
	{
		DeleteSection(SECNAME_TRYVERSION);
	}
	else
	{
		char   type[10];
		sprintf(type , "%d" , (int)hardtype);
		//sprintf_s(type , _countof(type), "%d" , (int)hardtype);
		
		SetEntryValue(SECNAME_TRYVERSION , 
			ENTRYNAME_TRYVERSION_BINDHARDTYPE ,
			type);
		
		SetEntryValue(SECNAME_TRYVERSION , 
			ENTRYNAME_TRYVERSION_BINDHARDID ,
			strHardID);
	}	
}

bool CSysIniFile::HasHookAppTypeNoCheckEffect(const string &strAppName)
{
	if(strAppName.length() == 0)
		return false;
	
	string	strText;
	GetEntryValue(SECNAME_HOOKSCOPE , ENTRYNAME_HOOKSCOPE_HOOKAPPTYPE , strText);
	
	string	strSeps	= ",;|";	//分隔符可以是任意的一种
	vector<string>	arrApps;
	string	strApp;
	
	ExtractComponentFromString(strText , strSeps , arrApps);
	//for(int i = 0 ; i < arrApps.size() ; i++)
	for(UINT i = 0 ; i < arrApps.size() ; i++)
	{
		strApp	= arrApps.at(i);
		
		TrimSpaceAndTab(strApp , true , true);
		
		//if(stricmp(strAppName.c_str() , strApp.c_str()) == 0)	//检查到匹配的应用程序类型
		if(strcasecmp(strAppName.c_str() , strApp.c_str()) == 0)	//检查到匹配的应用程序类型
		{

			return true;	
		}
	}
	
	return false;
}

bool CSysIniFile::IsHookAppType(const string &strAppName)
{
	if(strAppName.length() == 0)
		return false;

	string	strText;
	GetEntryValue(SECNAME_HOOKSCOPE , ENTRYNAME_HOOKSCOPE_HOOKAPPTYPE , strText);

	string	strSeps	= ",;|";	//分隔符可以是任意的一种
	vector<string>	arrApps;
	string	strApp;

	ExtractComponentFromString(strText , strSeps , arrApps);
	//for(int i = 0 ; i < arrApps.size() ; i++)
	for(UINT i = 0 ; i < arrApps.size() ; i++)
	{
		strApp	= arrApps.at(i);

		TrimSpaceAndTab(strApp , true , true);

		//if(stricmp(strAppName.c_str() , strApp.c_str()) == 0)	//检查到匹配的应用程序类型
		if(strcasecmp(strAppName.c_str() , strApp.c_str()) == 0)	//检查到匹配的应用程序类型
		{
			return IsTakeEffect(strAppName);	//返回是否生效
		}
	}

	return false;
}

void CSysIniFile::QueryHookedAppType(vector<string> &arrApps)
{
	arrApps.clear();
	
	string	strText;
	GetEntryValue(SECNAME_HOOKSCOPE , ENTRYNAME_HOOKSCOPE_HOOKAPPTYPE , strText);
	
	string	strSeps	= ",;|";	//分隔符可以是任意的一种
		
	ExtractComponentFromString(strText , strSeps , arrApps);
	
	//进行裁剪
	//for(int i = 0 ; i < arrApps.size() ; i++)
	for(UINT i = 0 ; i < arrApps.size() ; i++)
	{
		string &strAppName	= arrApps.at(i);

		TrimSpaceAndTab(strAppName , true , true);
	}
}

int	 CSysIniFile::GetFileTypeCount(const string &strAppName)
{
	string	strSectionName;
	strSectionName	= "*" + strAppName + "*";

	//没有与应用程序对应的节名
	if(!HasSection(strSectionName))
		return 0;

	string	strFileTypes;
	string  strFileType;
	vector<string>	arrFileTypes;

	GetEntryValue(strSectionName , ENTRYNAME_APPTYPE_HOOKFILETYPE , strFileTypes);

	ExtractComponentFromString(strFileTypes , ":" , arrFileTypes);

	return arrFileTypes.size();	
}

bool CSysIniFile::GetFileType(const string &strAppName , 
							  int nIndex ,  
							  string &strFileType ,  
							  FileRule &rule)
{
	//初始化
	strFileType.erase();
	InitializeFileRule(rule);

	string	strSectionName;
	strSectionName	= "*" + strAppName + "*";
	
	//没有与应用程序对应的节名
	if(!HasSection(strSectionName))
		return false;
	
	string	strText;
	vector<string>	arrFileTypes;
	
	GetEntryValue(strSectionName , ENTRYNAME_APPTYPE_HOOKFILETYPE , strText);
	
	ExtractComponentFromString(strText , ":" , arrFileTypes);
	if(nIndex < 0 || nIndex >= arrFileTypes.size())
	{
		assert(false);
		return false;
	}

	strText	= arrFileTypes.at(nIndex);
	TrimSpace(strText , true , true);
	if(strText.length() == 0)	//直接返回
		return true;

	//从字符串中提取文件类型和规则
	string strFileRule;
	ExtractFileTypeAndRule(strText , strFileType , strFileRule);
	StringToFileRule(strFileRule , rule);

	return true;
}

bool CSysIniFile::GetFileRule(const string &strAppName , 
							  const string &strFileType , 
							  FileRule &rule)
{
	int nIndex;

	nIndex	= FindFileTypeIndex(strAppName , strFileType);
	if(nIndex < 0)
		return false;

	string	strType;

	return GetFileType(strAppName , nIndex , strType , rule);
}

bool CSysIniFile::SetFileRule(const string &strAppName , 
							  const string &strFileType , 
							  const FileRule &rule)
{
	string	strText , strFileRule;
	vector<string>	arrFileTypes;

	string	strSectionName;
	strSectionName	= "*" + strAppName + "*";
	
	//没有与应用程序对应的节名
	if(!HasSection(strSectionName))
		return false;
	
	GetEntryValue(strSectionName , ENTRYNAME_APPTYPE_HOOKFILETYPE , strText);
	
	ExtractComponentFromString(strText , ":" , arrFileTypes);
	
	bool bFind = false;
	//遍历数组
	//for(int i = 0 ; i < arrFileTypes.size() ; i++)
	for(UINT i = 0 ; i < arrFileTypes.size() ; i++)
	{
		string &strFileTypeAndRule = arrFileTypes.at(i);

		//分离文件类型和规则
		ExtractFileTypeAndRule(strFileTypeAndRule , strText , strFileRule);

		//if(stricmp(strText.c_str() , strFileType.c_str()) == 0)
		if(strcasecmp(strText.c_str() , strFileType.c_str()) == 0)
		{
			bFind	= true;

			UnionFileTypeAndRule(strFileType , rule , strFileTypeAndRule);
			break;
		}
	}

	if(!bFind)
		return false;

	//重新组合
	//for(int i = 0 ; i < arrFileTypes.size() ; i++)
	for(UINT i = 0 ; i < arrFileTypes.size() ; i++)
	{
		if(i == 0)
			strText	= arrFileTypes.at(i);
		else
		{
			strText += ":" + arrFileTypes.at(i);
		}
	}

	SetEntryValue(strSectionName , ENTRYNAME_APPTYPE_HOOKFILETYPE , strText);

	return true;	
}

int	CSysIniFile::FindFileTypeIndex(const string &strAppName , 
								   const string &strFileType)
{
	string	strSectionName;
	strSectionName	= "*" + strAppName + "*";
	
	//没有与应用程序对应的节名
	if(!HasSection(strSectionName))
		return false;
	
	string	strText;
	vector<string>	arrFileTypes;
	
	GetEntryValue(strSectionName , ENTRYNAME_APPTYPE_HOOKFILETYPE , strText);
	
	ExtractComponentFromString(strText , ":" , arrFileTypes);

	string strType , strRule;

	//遍历数组，找到对应的文件类型
	//for(int i = 0 ; i < arrFileTypes.size() ; i++)
	for(UINT i = 0 ; i < arrFileTypes.size() ; i++)
	{
		strText	= arrFileTypes.at(i);

		//提取文件类型和规则
		ExtractFileTypeAndRule(strText , strType , strRule);

		//if(stricmp(strType.c_str() , strFileType.c_str()) == 0)
		if(strcasecmp(strType.c_str() , strFileType.c_str()) == 0)
			return i;
	}
	
	return -1;
}

bool CSysIniFile::AddAppType(const string &strAppName)
{
	if(strAppName.length() == 0)
	{
		assert(false);
		return false;
	}

	//检查程序名字是否存在
	if(!HasHookAppTypeNoCheckEffect(strAppName))
	{
		string	strText;
		
		//在字符串中获取应用程序类型
		GetEntryValue(SECNAME_HOOKSCOPE , ENTRYNAME_HOOKSCOPE_HOOKAPPTYPE , strText);

		strText += "," + strAppName;

		SetEntryValue(SECNAME_HOOKSCOPE , ENTRYNAME_HOOKSCOPE_HOOKAPPTYPE , strText);	
	}

	return true;	
}

bool CSysIniFile::RemoveAppType(const string &strAppName)
{
	string	strText;

	//在字符串中获取应用程序类型
	GetEntryValue(SECNAME_HOOKSCOPE , ENTRYNAME_HOOKSCOPE_HOOKAPPTYPE , strText);
	
	string	strSeps	= ",;|";	//分隔符可以是任意的一种
	vector<string>	arrApps;
	string	strApp;
		
	ExtractComponentFromString(strText , strSeps , arrApps);

	vector<string>::iterator		iter = arrApps.begin();
	
	for(; iter != arrApps.end() ; iter++)
	{
		strApp	= *iter;
		
		TrimSpaceAndTab(strApp , true , true);
		
		//if(stricmp(strAppName.c_str() , strApp.c_str()) == 0)	//应用程序存在
		if(strcasecmp(strAppName.c_str() , strApp.c_str()) == 0)	//应用程序存在
		{
			arrApps.erase(iter);	//进行删除
			break;
		}		
	}
	
	//重新组合
	strText.erase();
	//for(int i = 0 ; i < arrApps.size() ; i++)
	for(UINT i = 0 ; i < arrApps.size() ; i++)
	{
		if(i == 0)
		{
			strText	= arrApps.at(i);
			continue;
		}

		strText	+= "," + arrApps.at(i);
	}

	//重新设置
	SetEntryValue(SECNAME_HOOKSCOPE , ENTRYNAME_HOOKSCOPE_HOOKAPPTYPE , strText);

	//删除钩取的文件类型
	string	strSectionName;
	strSectionName	= "*" + strAppName + "*";

	DeleteSection(strSectionName);

	return true;
}

bool CSysIniFile::InsertFileType(const string &strAppName , 
								 int nPos ,  
								 const string &strFileType , 
								 const FileRule &rule)
{
	if(nPos < 0 || strAppName.length() == 0 || strFileType.length() == 0)
		return false;

	string		strSectionName;
	strSectionName	= string("*") + strAppName + "*";

	//首先在[HookScope]节的HookAppType入口中，查找是否支持应用程序
	if(!HasHookAppTypeNoCheckEffect(strAppName))
	{
		if(HasSection(strSectionName))
		{
			assert(false);
			RemoveAppType(strAppName);
		}

		string		strAppType;

		GetEntryValue(SECNAME_HOOKSCOPE , ENTRYNAME_HOOKSCOPE_HOOKAPPTYPE , strAppType);
		if(strAppType.length() == 0)
			strAppType	= strAppName;
		else
			strAppType	+= "," + strAppName;
		SetEntryValue(SECNAME_HOOKSCOPE , ENTRYNAME_HOOKSCOPE_HOOKAPPTYPE , strAppType);
	}

	//然后在[*AppName*]中查找入口项HookFileType
	string   strValue;
	GetEntryValue(strSectionName , ENTRYNAME_APPTYPE_HOOKFILETYPE , strValue);

	//提取组成部分
	string	strSeps	= ":";
	vector<string>	arrParts;
	string	strFileTypeAndRule , strRule;

	FileRuleToString(rule ,strRule);
	strFileTypeAndRule	= strFileType + "<" + strRule + ">";
	ExtractComponentFromString(strValue , strSeps , arrParts);

	//把strFileTypeAndRule插入arrParts中的nPos处
	bool bInsert	= false;
	vector<string>::iterator	iter = arrParts.begin();
	//for(int i = 0 ; i < arrParts.size() ; i++ , iter++)
	for(UINT i = 0 ; i < arrParts.size() ; i++ , iter++)
	{
		if(i == nPos)
		{
			bInsert	= true;
			arrParts.insert(iter , strFileTypeAndRule);
			break;
		}
	}
	if(!bInsert)
		arrParts.push_back(strFileTypeAndRule);

	//把arrParts变成一个字符串
	//for(int i = 0 ; i < arrParts.size() ; i++)
	for(UINT i = 0 ; i < arrParts.size() ; i++)
	{
		if(i == 0)
			strValue	= arrParts.at(i);
		else
		{
			strValue	+= ":" + arrParts.at(i);
		}
	}

	//重写入口项
	SetEntryValue(strSectionName , ENTRYNAME_APPTYPE_HOOKFILETYPE , strValue);

	return true;
}

string CSysIniFile::GetAppLogicModuleName(const string &strAppName)
{
	assert(strAppName.length() > 0);

	string strModuleName;
	string strSectionName;

	strSectionName = "*" + strAppName + "*";

	this->GetEntryValue(strSectionName , ENTRYNAME_APPTYPE_LOGICMODULENAME , strModuleName);

	if(strModuleName.length() == 0)
		strModuleName = "PFileLogic.dll";

	return strModuleName;	
}

void CSysIniFile::SetAppLogicModuleName(const string &strAppName , 
										const string &strLogicModuleName)
{
	assert(strAppName.length() > 0);

	string strSectionName;
	
	strSectionName = "*" + strAppName + "*";
	SetEntryValue(strSectionName , ENTRYNAME_APPTYPE_LOGICMODULENAME , strLogicModuleName);
}

bool CSysIniFile::IsTakeEffect(const string &strAppName)
{
	bool	bCheck = false;
	string  strSectionName;
	
	strSectionName = "*" + strAppName + "*";
	bCheck = this->GetBooleanValue(strSectionName , ENTRYNAME_APPTYPE_TAKEEFFECT , true);	//为了兼容，缺省值为TRUE
	
	return bCheck;
}

void CSysIniFile::SetTakeEffectFlag(const string &strAppName , bool bEffect)
{
	string  strSectionName;
	
	strSectionName = "*" + strAppName + "*";
	this->SetBooleanValue(strSectionName , ENTRYNAME_APPTYPE_TAKEEFFECT , bEffect);
}

bool CSysIniFile::RemoveFileType(const string &strAppName , 
								 const string &strFileType)
{
	string	strSectionName;
	strSectionName	= "*" + strAppName + "*";
	
	//没有与应用程序对应的节名
	if(!HasSection(strSectionName))
		return false;
	
	string	strText;
	vector<string>	arrFileTypes;
	
	GetEntryValue(strSectionName , ENTRYNAME_APPTYPE_HOOKFILETYPE , strText);
	
	ExtractComponentFromString(strText , ":" , arrFileTypes);

	vector<string>::iterator iter = arrFileTypes.begin();
	
	//遍历数组，找到对应的文件类型
	string  strType , strFileRule;
	bool	bFind = false;
	for(; iter != arrFileTypes.end() ; iter++)
	{
		strText	= *iter;

		ExtractFileTypeAndRule(strText , strType , strFileRule);
		
		//if(stricmp(strType.c_str() , strFileType.c_str()) == 0)
		if(strcasecmp(strType.c_str() , strFileType.c_str()) == 0)
		{
			arrFileTypes.erase(iter);
			bFind	= true;
			break;
		}
	}

	if(!bFind)
		return false;

	//重新进行组合
	strText.erase();
	//for(int i = 0 ; i < arrFileTypes.size() ; i++)
	for(UINT i = 0 ; i < arrFileTypes.size() ; i++)
	{
		if(i == 0)
		{
			strText	= arrFileTypes.at(i);
			continue;
		}

		strText	+= ":" + arrFileTypes.at(i);
	}

	SetEntryValue(strSectionName , ENTRYNAME_APPTYPE_HOOKFILETYPE , strText);

	return true;
}

bool CSysIniFile::RemoveFileType(const string &strAppName , 
								 int nIndex)
{
	string		strFileType;
	FileRule	rule;

	if(!GetFileType(strAppName , nIndex , strFileType , rule))
		return false;

	return RemoveFileType(strAppName , strFileType);	
}

//////////////////////////////////////////////////////////////////////////
//以下的读写操作需要保持同步

bool   CSysIniFile::ReadFromEncFile(const string &strFilePath)
{
	bool bSuccess = false;

	try
	{
		bSuccess	= CEncIniFile::ReadFromEncFile(strFilePath);
	}
	catch (...)
	{
	}
	return bSuccess;
}

bool   CSysIniFile::ReadFromTextFile(const string &strFilePath)
{
	bool bSuccess = false;
	
	try
	{
		bSuccess	= CEncIniFile::ReadFromTextFile(strFilePath);
	}
	catch (...)
	{
	}
	return bSuccess;
}
bool copyFile(const char* src, const char* des)
{
    bool bRet = false;
    FILE* pSrc = NULL, *pDes = NULL;
    pSrc = fopen(src, "r");
    pDes = fopen(des, "w+");


    if (pSrc && pDes)
    {
        int nLen = 0;
        char szBuf[1024] = {0};
        while((nLen = fread(szBuf, 1, sizeof szBuf, pSrc)) > 0)
        {
            fwrite(szBuf, 1, nLen, pDes);
        }
        bRet = true;
    }
    else
        bRet = false;


    if (pSrc)
        fclose(pSrc), pSrc = NULL;


    if (pDes)
        fclose(pDes), pDes = NULL;


    return bRet;
}

bool   CSysIniFile::WriteIntoEncFile(const std::string &strFilePath)
{
	bool bSuccess = false;
	
	try
	{
		string strTempFilePath;
		
		//检查文件是否存在
		if(access(strFilePath.c_str(),F_OK) == 0)	//文件存在
		{
			strTempFilePath	= strFilePath + ".$bak";
			
			bSuccess	= copyFile(strFilePath.c_str() , strTempFilePath.c_str() );
			
			if(bSuccess)
			{
				bSuccess	= CEncIniFile::WriteIntoEncFile(strFilePath);
				
				if(bSuccess)	
					remove(strTempFilePath.c_str());	//删除临时备份文件
			}
		}
		else
		{
			bSuccess	= CEncIniFile::WriteIntoEncFile(strFilePath);
		}		
	}
	catch (...)
	{
	}
	return bSuccess;
}

bool   CSysIniFile::WriteIntoTextFile(const string &strFilePath)
{
	bool bSuccess = false;
	
	try
	{
		string strTempFilePath;

		//检查文件是否存在
		if(access(strFilePath.c_str(),F_OK) == 0)	//文件存在
		{
			strTempFilePath	= strFilePath + ".$bak";
			
			bSuccess	= copyFile(strFilePath.c_str() , strTempFilePath.c_str());

			if(bSuccess)
			{
				bSuccess	= CEncIniFile::WriteIntoTextFile(strFilePath);

				if(bSuccess)	
					remove(strTempFilePath.c_str());	//删除临时备份文件
			}
		}
		else
		{
			bSuccess	= CEncIniFile::WriteIntoTextFile(strFilePath);
		}		
	}
	catch (...)
	{
	}
	return bSuccess;	
}

bool CSysIniFile::IsHookAppType(const string &strAppName, bool &bUseIat)
{
	if(strAppName.length() == 0)
		return false;

	string	strText;
	GetEntryValue(SECNAME_HOOKSCOPE , ENTRYNAME_HOOKSCOPE_HOOKAPPTYPE , strText);

	string	strSeps	= ",;|";	//分隔符可以是任意的一种
	vector<string>	arrApps;
	string	strApp;

	bool bNeedHook = false;
	bUseIat = false;
	ExtractComponentFromString(strText , strSeps , arrApps);
	//for(int i = 0 ; i < arrApps.size() ; i++)
	for(UINT i = 0 ; i < arrApps.size() ; i++)
	{
		strApp	= arrApps.at(i);

		TrimSpaceAndTab(strApp , true , true);

		//if(stricmp(strAppName.c_str() , strApp.c_str()) == 0)	//检查到匹配的应用程序类型
		if(strcasecmp(strAppName.c_str() , strApp.c_str()) == 0)	//检查到匹配的应用程序类型
		{
			bNeedHook = true;
//			return IsTakeEffect(strAppName);	//返回是否生效
			bUseIat = IsTakeEffect(strAppName);
			break;
		}
	}

	return bNeedHook;
}
