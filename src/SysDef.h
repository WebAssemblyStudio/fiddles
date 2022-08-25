/*------------------------------------------------------------------
*定义系统级使用的类型和常量
*
*
*
*
*----------------------------------------------------------------*/


#ifndef _SYSDEF_H__
#define _SYSDEF_H__

//错误类型
enum EnumErrorStatus 
{
	esOK			= 0x0000 ,		//成攻
	esUnExpected	= 0x0001 ,		//未知错误
	esNotSupported	= 0x0002 ,		//不支持 
	esInvalidPara	= 0x0003,		//非法参数
	esUnSupportVer	= 0x0004,		//不支持的版本
	esInvalidRight	= 0x0005,		//没有操作权限
	esNotFound		= 0x0006,		//未找到
	esHasExist		= 0x0007 ,		//已经存在

	//////////////////////////////////////////////////////////////////////////
	//与加密狗有关的错误码
	esDogErr		= 0x4000,			//未知的加密码狗错误
	esDogNotExist	= 0x4001,			//加密狗不存在
	esDogIsOpen		= 0x4002,			//狗是打开的，用于打开狗时使用
	esDogTypeErr	= 0x4003,			//加密狗类型错误
	esOpenDogErr	= 0x4004,			//打开加密狗失败
	esVerifyDogPassWordErr	= 0x4005,	//校验密码失败
	esCloseDogErr	= 0x4006,			//关闭加密狗失败
	esReadDogErr	= 0x4007,			//读加密狗失败
	esWriteDogErr	= 0x4008,			//写加密狗失败
	esCreateDogFileErr	= 0x4009 ,		//创建加密狗文件失败


};

//授权时的绑定硬件类型
enum EnumHardwareType
{
	htHardDisk	= 1 ,	//硬盘ID
	htNetCard	= 2 ,	//网卡MAC
	htUSB		= 3 
};

//////////////////////////////////////////////////////////////////////////
//客户端版本
enum EnumClientVersion
{
	FORINNER = 0,		//自用
	FOROUTER = 1,		//外协
	FOROUTERGOING = 2   //外发

};
//加密强度
enum EnumEncMode
{
	ENC_OPDINARY = 0,	//普通
	ENC_MEDIUM = 1, //中等
	ENC_STRONG = 2,	//强

	ENC_NOSET = 3	//未设置
};
const char SECNAME_RUNVERSION[] = "runversion";
const char ENTRYNAME_RUNVERSION_VERTYPE[] = "versiontype";
//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////
//试用版的单位密钥信息
const char	TRYKEY_NAME[]	= "Welcome to use product of picle Ltd.";
const unsigned long	TRYKEY_ID		= (unsigned long)-1;
const char	TRYKEY_DESC[]	= "圆周率试用版密钥";

//////////////////////////////////////////////////////////////////////////
//在加密系统中使用的几个文件名
const char	FILENAME_SYS_INI[]		= "Piencsys.ini";		//系统配置文件
const char	FILENAME_SYS_ENCINI[]	= "Piencsys.pcl";		//加密形式的系统配置文件
const char  FILENAME_SYS_KEY[]		= "Piencsys.pky";		//客户机密钥文件名
const char  FILENAME_SYS_TIME[]     = "Piencsys.ptm";		//客户机时间文件
const char  FILENAME_SYS_BASECFG[]  ="Piencsys.pbc";		//基础配置文件,浏览窗口配置文件和模板

const char	FILENAME_SYS_ERROR[]	= "Piencsys.err";		//系统全局的错误输出文件，
//它放在操作系统的系统目录下
const char FILENAME_SYS_MODULE_FILE[] = "Piencsys.pmc";		//进程模块配置文件

const char	FILENAME_SYS_APPFEAT[]	= "Piappfeat.mdl";		//每种应用程序的特征信息文件
const char	FILENAME_SYS_KEYDESC[]	= "KeyDesc.txt";		//系统的密钥版本与密钥描述之间的映射文件

const char  SUFFIXOFBKFILE[]		= ".$pbk";				//中间备份文件的后缀
const char	PREFIXOFTEMPFILE[]		= "Pienc";				//中间临时文件的前缀

const char  STR_SYS_TEMPROOTDIRNAME[]		= "Intranet";	//系统的临时目录名

//////////////////////////////////////////////////////////////////////////
//在注册表中定义的键和键值名
const char	KEY_CLIENT_PRODUCT[]	= "Software\\Piclesoft\\Pilock\\客户端";		//加密产品客户端对应的键
const char	KEY_MANAGER_PRODUCT[]	= "Software\\Piclesoft\\Pilock\\管理控制台";	//加密产品管理控制台对应的键

const char KEY_SYSTEM_AUTORUN[]		= "SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run";
//系统自动运行注册表键值

const	char KEYVALUENAME_SWITCHSTATE[]	= "圆周率客户机状态管理器";

const	char KEYVALUENAME_CLIENTSHORTCUT[]	= "圆周率软件\\文件智能锁";

const	char KEYVALUENAME_ROOTSHORTCUT[]	= "圆周率软件";

const char KEY_CLEANFILE_NAME[]		= "Clean Piclesoft";
//卸载智能锁客户端时所使用自动启动键值名

const char	KEYVALUE_DEFAULTKEYVER[]= "DefaultKeyVersion";				//键值说明缺省的密钥版本，类型REG_DWORD
//在KEY_PRODUCT下

//////////////////////////////////////////////////////////////////////////
//与管理控制台相关的

const char	KEYVALUE_LASTLOGINNAME[]	= "LastLoginName";				//在管理控制台中，最近登录的用户名

//加解密时是否遍历目录
const char	KEYVALUE_RECURSIVEDIR[]		= "RecursiveDir";

//////////////////////////////////////////////////////////////////////////
//与客户端更新的相关的

//////////////////////////////////////////////////////////////////////////
//键值名

const char	KEYVALUE_TITLEHINT[]		= "TitleHint";					//在客户端中使用，定义标题的格式字符串

//客户端的更新程序所在的目录
const char  KEYVALUE_CLIENTUPDATEDIR[]			= "Updatedir";

//客户端的钩子模块的总开关
//added 2007-1-15
const char	KEYVALUE_STOPWORKING[]				= "StopWorking";

//用于确定客户端处于加密模式时，弹出确定对话框
//added 2007-1-17
const char	KEYVALUE_CONFIRMENCRYPTE[]			= "ConfirmEncrypt";

//时间标志
const char KEYVALUE_CURRENTSTATE[]				="CurrentState";
//默认状态标志
const char KEYVALUE_DEFAULT[]					="Default";
//MD5校验值
const char KEYCALUE_CURRENTFLAG[]				="CurrentFlag";

//模块验证文件名，目录在system32下
const char TMPLEFILENAME_SYSTEM32[]			="PiDecTmpl.tmple";

const char TMPLEFILEINFONAME_SYSTEM32[]		="PiDecTmpl.TempleInfo";

const char DISKLOWERFILTERS[] =				"SYSTEM\\CurrentControlSet\\Control\\Class\\{4D36E967-E325-11CE-BFC1-08002BE10318}";			//此处写有USB过滤驱动所使用到的注册表路径

const char DISKDRIVESERVER[]					="SYSTEM\\CurrentControlSet\\services\\usbstormon";

//此处是添加驱动服务所在的注册表键值

const char FILEENCFOLD[]							="{042A179F-B838-47AC-A4B6-31F32A6999FE}_enc";
//const char FILEDECFOLD							="{C0F3DB9A-D137-423E-B219-9BA97EA6ED8A}_dec";
//const char	ENCFILETEMPFOLD						="{819ECE22-6FED-4337-9C03-D1F294DC1426}_tmp";
const char ENCFILEEXT	[]						="_$sys";

const char WORKTEMPFOLD[]						="yah_enc";

#define  MAXPATH_OF_FILE 2048						//扩容，避免文件读写时越界 modify by pengcong 2017-07-06

#endif
