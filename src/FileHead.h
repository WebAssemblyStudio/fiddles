// FileHead.h: interface for the CFileHead class.
//
//////////////////////////////////////////////////////////////////////
#pragma once

#include <list>
#include "KeyUtil.h"

#define  LENG_FILE_HEAD  512

#define  LENG_FILE_VERINFO 128 //文件版本信息长度
//文件加密单元信息
#pragma pack(push)
#pragma pack(1)
struct  FileEncPosInfo 
{
	//unsigned long ENCpos;	//偏移地址
	//unsigned long ENClength; //加密长度
    unsigned int ENCpos;	//偏移地址
    unsigned int ENClength; //加密长度
    FileEncPosInfo()
	{
    	ENCpos=0;
    	ENClength=0x80;
	}
};

const BYTE HEAD_SING[16] = "PICLESOFT\0\0\0\0\0\0";  //字符串总长度是15个字符+1个\0结尾,一共占用16个字节

class CFileHead  //文件头类
{
public:
	static bool IsLegalFileHead(Byte *pData);//判断pData的内容是否是合法的文件头
	static bool IsLegalFileHead(Byte *pData , int nLength);
	//从字节流中读取
	bool ReadFromMem(Byte *pData);//根据pData的内容，生成对象

	//写入字节流中
	bool WriteToMem(Byte * pData);//将生成的文件头放在pData中
	//////////////////////////////////////////////////////////////////////////
	void GetFileEncCount(unsigned int & Encount);
	void SetFileEncCount(unsigned int & Encount);

	//从文件头信息中读取文件中所有加密单元信息			
	bool GetFileEncPosInfo(std::list<FileEncPosInfo> & EncPinfoList);

	//将文件中所有加密单元信息写入到文件头信息
	bool SetFileEncPosInfo(std::list<FileEncPosInfo> & EncPinfoList);
	//////////////////////////////////////////////////////////////////////////

//	BOOL IsSameProductKey();//Add By Kejun 2008-05-04
//	BOOL IsSameProductKeyUseOldM();	//add by hzg 090325

	unsigned short GetAlgorithmMode();//获取加密算法

	
	CFileHead();
	virtual ~CFileHead();

public:
	//添加一套方法用于直接使用密钥内容加密解密文件  hzg 20121122
	CFileHead(int nKeyVer);

	bool WriteToMem(Byte * pSecretKey, int nKeylen, Byte * pData);

	bool IsSameProductKey(Byte * pSecretKey, int nKeylen);

	bool AddProductKey(Byte * pSecretKey, int nKeylen);
	//add end

	//下面属性的顺序是文件存储顺序，所以不能更改顺序
private:
	char m_szSignature[16] ;//文件头标志   第一个单元 (0-15)

public:
	bool IsEmpty();
	void Empty();

//Add By Kejun 增加文件版本信息(上海的需求) 2008-11-14
	void SetFileVerInfo(Byte *szVerInfo);
	void GetFileVerInfo(Byte *szVerInfo);
//Add End

//... 如果有新内容，在此处增加
	void SetKeyVer(short nKeyId);
	short GetKeyVer();
	std::list<FileEncPosInfo>* GetEncUnitlist();
	bool AddProductKey();
//#endif

	unsigned short  m_uFileHeadVer ;	//此文件头的版本 (16-17)
								//文件头的版本用于确定文件头中的内容
								//目前文件头版本必须为1
	                            //此版本以前为1, 以后必须为11, Add BY Kejun 2008-05-06

	double  m_dTime ;			//加密的时间	(18-25)

	//unsigned short    m_uEncFlowVer ;		//加密流程		(26-29)
	//							//用于表示在具体加密的过程中的整个流程
	unsigned int    m_uEncFlowVer ;		//加密流程		(26-29)
	//用于表示在具体加密的过程中的整个流程

    //short    m_uKeyVer ;			//文件密钥版本  (30-33)
	int m_uKeyVer;					//文件密钥版本  (30-33)
	char    m_szEncProductKey[32]; //利用密钥加密后的产品序列号(34-66) add by kejun 2008-05-04
	unsigned int m_encfilecount;			//记录加密单元数
	Byte m_encfileposinfo[200];		//记录加密单元信息
	Byte m_UserReserveData[110];

	Byte m_SerialNumber_Clear[24]; 	//SN号明文
	unsigned short m_AlgorithmMode;			//加密算法 0=AES ，1=SM4
	Byte m_UserInfo[212];				//用户信息用于扩展

	Byte m_FileVerInfo[LENG_FILE_VERINFO];   //文件版本信息
	unsigned int m_VerifySum ;				//检验和, 一定在文件头的最后单元(508-511)

	std::list<FileEncPosInfo> m_listEncUnit;     //加密单元信息
};
#pragma pack(pop)
