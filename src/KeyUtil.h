#pragma once
#include <vector>
#include <string>
#include "KeyFileHelper.h"
#include "PiErrCode.h"
#include "EncIniFile.h"
#include "SysIniFile.h"
#include "FileManage.h"

using namespace std;
#pragma pack(push)
#pragma pack(1)


class CKeyUtil
{
public:
	CKeyUtil(char* cfgPath);
	~CKeyUtil(void);

	//pcl对象需要在文件处理逻辑中查询,因此设置为公有
	CSysIniFile m_pclFile;
	CHookInfo m_hookInfo;

	KEY_FILE	m_keyFile;
private:

	string		m_strEncProductKey; //利用密钥加密后的产品序列号
	string  	m_strCompany;		//单位
	string		m_strPclPath;
	string		m_strPkyPath;
	int 		m_nEncMode;		//加密强度
    int         m_nErrCode;
    
    bool    GetKeyList();
    bool    CheckProductSerialNumber();//检查程序中的序列号 和 pcl中的序列号是否一致
public:
    bool IsValid(){return m_nErrCode == PI_S_SUCCESS;}
    int  GetErrCode(){return m_nErrCode;}
    void SetPclPath(const char*filename = NULL);
    void SetPkyPath(const char*filename = NULL);
    
	bool Initialize();
	//获取密钥数
	int	GetKeyCount();
	
	//查询密钥版本是否存在
	bool IsExistKey(long uKeyVer);

	//查找密钥,返回值为索引
	int	 FindKey(long uKeyVer);

	//根据索引(0 - nCount-1)查找密钥
	bool QueryKeyByIndex(int nIndex ,			//索引
		int nBufLen ,			//缓存大小
		BYTE *pBuffer ,			//缓存区
		int &nKeyLen ,			//返回的密钥长度
		long &uKeyVer			//返回的密钥版本
		);


	//根据密钥版本号查询密钥信息
	//如果分配的缓存区长度小于密钥长度，则返回false
	//如果对应的版本号不存在，也返回false
	bool QueryKey(long uKeyVer ,		//密钥版本
		int nBufLen ,		//缓存区长度
		Byte *pBuffer ,		//在外部分配的缓存区
		int &nKeyLen			//返回的密钥长度
		);	
	string GetProductKey();
	//修改客户端许可的时间期限
	bool ChangeClientStartTimeToFile();
    //判断是否到期,true表示到期
    bool IsTimeDue();

	bool InitConfigPath(char* cfgPath);

	int Readelf();

	int GetEncMode();


};
#pragma pack(pop)
extern CKeyUtil* g_KeyUtil;

inline bool InitKey(char * cfgPath, int &ErrCode)
{
	//更新配置文件的路径
	if(g_KeyUtil == NULL)
	 	g_KeyUtil = new CKeyUtil(cfgPath);
	bool bRet = g_KeyUtil->Initialize();
	if(!bRet)
		ErrCode = g_KeyUtil->GetErrCode();
	else
		ErrCode = PI_S_SUCCESS;
	return bRet;
}
