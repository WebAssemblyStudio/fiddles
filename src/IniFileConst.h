/*------------------------------------------------------------------
*定义在配置文件中使用的常量
*
*
*
*
*----------------------------------------------------------------*/

#ifndef _INIFILECONST_H__
#define _INIFILECONST_H__

//////////////////////////////////////////////////////////////////////////
//命名规则
//节名规则
//SECNAME_*
//入口规则
//ENTRYNAME_节名_*

//定义节名
const char SECNAME_SUMMARY[]	= "Summary";
const char SECNAME_HOOKSCOPE[]	= "HookScope";
const char SECNAME_TRYVERSION[]	= "TryVersion";		//用于试用版
const char SECNAME_TRACE[]		= "Trace";
const char SECNAME_CHECKSIGN[]	= "CheckSign";		//检查标志

//定义入口项
const char ENTRYNAME_SUMMARY_PRODUCTKEY[]			= "ProductKey";			//用于描述产品序列号
const char ENTRYNAME_SUMMARY_UNITNAME[]				= "UnitName";			//使用单位名
const char ENTRYNAME_SUMMARY_GRANTDOGCNNSTRING[]	= "GrantDogConnectString";	//加密狗连接字符串

const char ENTRYNAME_HOOKSCOPE_USEWINDOWSHOOK[]	= "UseWindowsHook";			//是否使用Windows钩子
const char ENTRYNAME_HOOKSCOPE_USEUSBDEVICE[]	= "UseUsbDevice";			//是否使用usb设备
const char ENTRYNAME_HOOKSCOPE_USECLIPBOARD[]	= "UseClipboard";			//是否使用剪贴板
const char ENTRYNAME_HOOKSCOPE_USEPRINTER[]		= "UsePrinter";				//是否使用打印机
const char ENTRYNAME_HOOKSCOPE_INLINECLIPBOARD[]		= "UseInlineClipboard";		//使用内联方式的剪贴板控制
const char ENTRYNAME_HOOKSCOPE_DATABASECONTROL[]	= "DataBaseControl";	//数据库控制
const char ENTRYNAME_HOOKSCOPE_INLINECOVERAPI[]	= "UserInlineCoverApi";		//使用内联的ReplaceFile CopyFile MoveFile
const char ENTRYNAME_HOOKSCOPE_QQPRNTSCR[]	= "QQPrntscr";					//使用内联的拷屏功能
const char ENTRYNAME_HOOKSCOPE_USBBind[]	= "USBBind";					//使用USB绑定功能
const char ENTRYNAME_HOOKSCOPE_TEXTCOPY[]			= "TextCopy";			//文本拷贝
const char ENTRYNAME_HOOKSCOPE_IMAGECOPY[]			= "ImageCopy";			//图像拷贝
const char ENTRYNAME_HOOKSCOPE_HOOKAPPTYPE[]	= "HookApplicationType";	//需要钩取的应用程序类型
const char ENTRYNAME_HOOKSCOPE_USERREADONLY[]  = "OnlyReadOpen";			//过滤只读打开文件
const char ENTRYNAME_HOOKSCOPE_USEPRINTSCREEN[] = "UsePrintScreen";         //是否允许屏幕拷贝//Add BY Kejun 2007-07-19 以前加过可能由于版本被覆盖重新加上

const char ENTRYNAME_TRYVERSION_BINDHARDTYPE[]	= "BindingHardType";	//绑定的硬件类型
const char ENTRYNAME_TRYVERSION_BINDHARDID[]	= "BindingHardID";		//绑定的硬件ID

const char ENTRYNAME_HOOKSCOPE_ENCMODE[] = "EncMode";	//加密模式，用于标识加密强度	add by lk 20190429

const char ENTRYNAME_HOOKSCOPE_ALGORITHMMODE[] = "AlgorithmMode";				//加密算法

//它对于的节名为[*AppName*]
const char ENTRYNAME_APPTYPE_LOGICMODULENAME[]	= "LogicModuleName";		//与应用程序对应的逻辑处理模块名
//const char ENTRYNAME_APPTYPE_CHECKAPPMODULE	= "CheckAppModuleFeature";	//通过检查应用程序的模块来对应用程序进行真实性确定
const char ENTRYNAME_APPTYPE_HOOKFILETYPE[]		= "HookFileType";			//针对具体一种应用程序需要处理的文件类型

const char ENTRYNAME_APPTYPE_TAKEEFFECT[]		= "TakeEffect";				//是否生效，如果为��，则对该类型不进行钩取
//2006-08-30增加
const char ENTRYNAME_CHECKSIGN_CHECKBINDHARD[]	= "CheckBindHard";		//是否检查硬件类型
const char ENTRYNAME_CHECKSIGN_CHECKLIMITTIME[]	= "CheckLimitTime";		//是否检查许可时间

const char SECNAME_IDENTIFYFILE[] = {"PICLESOFT"};
const char ENTRYNAME_IDENTIFYFILE_ID[] = {"DISKID"};
const char ENTRYNAME_IDENTIFYFILE_UDISKSIZE[] = {"UDISKSIZE"};
const char ENTRYNAME_IDENTIFYFILE_PRODUCTID[] = {"DISKPRODUCTID"};
#endif
