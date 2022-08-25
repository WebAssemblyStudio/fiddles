// FileHead.cpp: implementation of the CFileHead class.
//
//////////////////////////////////////////////////////////////////////

#include"../PiEncrypt.h"
#include "FileHead.h"
#include "Rijndael.h"
#include "EncM_SM4.h"
#include "EncM_Rijndael.h"
#include "EncM_Des.h"
#include <string>
#include <assert.h>
#include "TimeFunc.h"
#include "EncryptMgr.h"
#include <string.h>
#include<iostream>
using namespace std;

#define  keyver  88
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CFileHead::CFileHead()
{
	//依次初始化
	memset(m_szSignature , 0 , sizeof(m_szSignature) / sizeof(m_szSignature[0]));
	strcpy(m_szSignature , "PICLESOFT");

//	m_uFileHeadVer = 1 ;	//目前只支持1
//	m_uFileHeadVer = 11; //现在统一把版本号改为11, 以区别没有加序列号的文件头版本。Add By Kejun 2008-05-04
	m_uFileHeadVer = 12;	//使用新的加密方式加密的文件
    m_AlgorithmMode = 0;
	//static CEncAndDecFlow encMeth ;
/*	CNewEncAndDecFLOW encMeth ;
	m_uEncFlowVer = encMeth.m_CurEncFlowVer ; */
	m_uEncFlowVer = 1;
    
//	assert(m_uEncFlowVer == 1);
//	m_uKeyVer =  encMeth.m_CurKeyVer ;
    m_uKeyVer = keyver;

//	m_dTime = GetCurrentDateTime() ;
    
    m_dTime = 0;
        
	m_encfilecount = 0;

    
// 	int nReserveDataSize = sizeof(m_ReserveData) / sizeof(m_ReserveData[0]);
// 	memset(m_ReserveData , 0 , nReserveDataSize);

	int nencfileposinfoSize = sizeof(m_encfileposinfo) / sizeof(m_encfileposinfo[0]);
	memset(m_encfileposinfo , 0 , nencfileposinfoSize);

	int nUserReserveDataSize = sizeof(m_UserReserveData) / sizeof(m_UserReserveData[0]);
	memset(m_UserReserveData , 0 , nUserReserveDataSize);

	int nFileInfoSize = sizeof(m_FileVerInfo) / sizeof(m_FileVerInfo[0]);
	memset(m_FileVerInfo, 0 , nFileInfoSize);

    int nUserInfoSize = sizeof(m_UserInfo) / sizeof(m_UserInfo[0]);
    memset(m_UserInfo, 0 , nUserInfoSize);

//	SetFileVerInfo((BYTE *)("PICLESOFT FILEVERINFO"));

//Delete By Kejun 2006-09-17 下面两句没什么意思，重复了，而且也是为了解决双核问题
// 	BYTE bData[LENG_FILE_HEAD] ; //这下面两句有什么意义？只是为了计算一下校验和？ by kejun 2008-05-04
// 	WriteToMem(bData);	//此函数会自动更新检验和
}


CFileHead::~CFileHead()
{

}

//////////////////////////////////////////////////////////////////////////
//
CFileHead::CFileHead(int nKeyVer)
{
	//依次初始化
	memset(m_szSignature , 0 , sizeof(m_szSignature) / sizeof(m_szSignature[0]));
	strcpy(m_szSignature , "PICLESOFT");

	//#ifndef _VERIFY_SERIALNUM
	//	m_uFileHeadVer = 1 ;	//目前只支持1
	//#else
	//	m_uFileHeadVer = 11; //现在统一把版本号改为11, 以区别没有加序列号的文件头版本。Add By Kejun 2008-05-04
	//m_uFileHeadVer = 12;	//使用新的加密方式加密的文件
	m_uFileHeadVer = 12;
    /// /#endif

	//static CEncAndDecFlow encMeth ;
/*	CNewEncAndDecFLOW encMeth ;
	m_uEncFlowVer = encMeth.m_CurEncFlowVer ; 	
	assert(m_uEncFlowVer == 1);*/
    m_uEncFlowVer = 1;
    m_AlgorithmMode = 0;
	m_uKeyVer =  nKeyVer;
	m_VerifySum = 0;
	// Delete by Kejun 2008-09-17 解决双核下
	// 	//Add BY Kejun 2008-05-04 文件头加序列号
	// #ifdef _VERIFY_SERIALNUM
    memset(m_szEncProductKey, 0x39, sizeof(m_szEncProductKey));
    string strProductKey = g_KeyUtil->GetProductKey();
    memcpy(m_SerialNumber_Clear, strProductKey.c_str(),24);

    BYTE byteKey[128] = {0};
    int  nKeyLen = 0;
//    if(!g_KeyUtil.QueryKey(m_uKeyVer, sizeof(byteKey), byteKey, nKeyLen))
//    {
//        g_objSysErrFile.DoLogMessage("加密文件头序列号时未找到对应的密钥");
//    }
//    else
//    {
//        bool bRet = RijndaelEnc.ChangeToBlackText(byteKey, nKeyLen, (BYTE *)strProductKey.c_str(), sizeof(m_szEncProductKey), (BYTE *)m_szEncProductKey);
//        if(!bRet)
//            g_objSysErrFile.DoLogMessage("加密文件头序列号时出错");
//    }

    if(g_KeyUtil->QueryKey(m_uKeyVer, sizeof(byteKey), byteKey, nKeyLen))
    {
		int nMode = 0;
		g_KeyUtil->m_pclFile.GetAlgorithmMode(nMode);
		if(nMode == 0)
		{
			CRijndaelEnc RijndaelEnc;
			RijndaelEnc.ChangeToBlackText(byteKey, nKeyLen, (BYTE *)strProductKey.c_str(), sizeof(m_szEncProductKey), (BYTE *)m_szEncProductKey);
		}
		else if(nMode == 1)
		{
			CAlgorithmSM4 oSM4;
			oSM4.ChangeToBlackText(byteKey, nKeyLen, (BYTE *)strProductKey.c_str(), sizeof(m_szEncProductKey), (BYTE *)m_szEncProductKey);
		}
    }
    else
    {
    	memset(m_szEncProductKey, 48, sizeof(m_szEncProductKey));
    }

	// #endif
	// 	//Add End

	m_dTime = GetCurrentDateTime() ;
	m_encfilecount = 0;

	// 	int nReserveDataSize = sizeof(m_ReserveData) / sizeof(m_ReserveData[0]);
	// 	memset(m_ReserveData , 0 , nReserveDataSize);

	int nencfileposinfoSize = sizeof(m_encfileposinfo) / sizeof(m_encfileposinfo[0]);
	memset(m_encfileposinfo , 0 , nencfileposinfoSize);

	int nUserReserveDataSize = sizeof(m_UserReserveData) / sizeof(m_UserReserveData[0]);
	memset(m_UserReserveData , 0 , nUserReserveDataSize);

	int nFileInfoSize = sizeof(m_FileVerInfo) / sizeof(m_FileVerInfo[0]);
	memset(m_FileVerInfo, 0 , nFileInfoSize);

    int nUserInfoSize = sizeof(m_UserInfo) / sizeof(m_UserInfo[0]);
    memset(m_UserInfo, 0 , nUserInfoSize);

	//	SetFileVerInfo((BYTE *)("PICLESOFT FILEVERINFO"));

	//Delete By Kejun 2006-09-17 下面两句没什么意思，重复了，而且也是为了解决双核问题
	// 	BYTE bData[LENG_FILE_HEAD] ; //这下面两句有什么意义？只是为了计算一下校验和？ by kejun 2008-05-04
	// 	WriteToMem(bData);	//此函数会自动更新检验和

}

bool CFileHead::WriteToMem(Byte * pSecretKey, int nKeylen, Byte * pData)
{


	if (pSecretKey == NULL || nKeylen > 128 || nKeylen <= 0)
	{
		assert(false);
		return false;
	}
	//#ifndef _VERIFY_SERIALNUM
	//	assert(m_uFileHeadVer == 1 && m_uEncFlowVer == 1);	//目前必须满足的条件
	//
	//#else
	//assert((m_uFileHeadVer == 1 || m_uFileHeadVer == 11) && m_uEncFlowVer == 1);//Modify By Kejun 2008-05-04 目前存在两种格式的文件头
	//assert(m_uFileHeadVer == 0x0c && m_uEncFlowVer == 1);//Modify by kejun 2009-03-17
	if(!AddProductKey(pSecretKey, nKeylen))
	{
		assert(false);
		return false;
	}
	//#endif

	//将内容输出到一个数组BYTE中，以便于保存
	memset(pData , 0 , sizeof(m_szSignature) / sizeof(m_szSignature[0]));
	strcpy((char*)pData , m_szSignature);
	pData += sizeof(m_szSignature) / sizeof(m_szSignature[0]) ;

	*((unsigned short*)pData) = m_uFileHeadVer;
	pData += sizeof(unsigned short) ;

	*((double*)pData) = m_dTime;
	pData += sizeof(double) ;

	//*((unsigned long *)pData) = m_uEncFlowVer;
	//pData += sizeof(unsigned long) ;

	//*((unsigned long *)pData) = m_uKeyVer;
	//pData += sizeof(unsigned long) ;
    
    *((unsigned int *)pData) = m_uEncFlowVer;
    pData += sizeof(unsigned int) ;
    
    *((int *)pData) = m_uKeyVer;
    pData += sizeof(int) ;

	//Add by Kejun 2008-05-04 在文件头增加加密的序列号���
	//#ifdef _VERIFY_SERIALNUM
	memset(pData, 0, sizeof(m_szEncProductKey));
	memcpy(pData, m_szEncProductKey, sizeof(m_szEncProductKey));
	pData += 32;
	//#endif
	//Add End
	//*((unsigned long*)pData) = m_encfilecount;
	//pData += sizeof(unsigned long);
    
    *((unsigned int*)pData) = m_encfilecount;
    pData += sizeof(unsigned int);

	memcpy(pData, m_encfileposinfo, sizeof(m_encfileposinfo) / sizeof(Byte));
	pData += sizeof(m_encfileposinfo)/sizeof(Byte);

	// 	memcpy(pData , m_ReserveData , sizeof(m_ReserveData) / sizeof(BYTE));
	// 	pData += sizeof(m_ReserveData)/sizeof(BYTE) ;

	memcpy(pData , m_UserReserveData , sizeof(m_UserReserveData) / sizeof(Byte));
	pData += sizeof(m_UserReserveData) / sizeof(Byte) ;

	//Add By Kejun 增加文件版本信息(上海的需求) 2008-11-14
	memcpy(pData , m_FileVerInfo, sizeof(m_FileVerInfo) / sizeof(Byte));
	pData += sizeof(m_FileVerInfo) / sizeof(Byte);
	// Add End
	unsigned int  uVerifySum = 0 ;
	Byte * pTmp = pData ;
	for(int iCount = LENG_FILE_HEAD - sizeof(m_VerifySum) ; iCount > 0 ; iCount-- )
		uVerifySum += *(--pTmp) ;
	m_VerifySum = uVerifySum ;
	//*((unsigned long *)pData)  = m_VerifySum;
    *((unsigned int *)pData)  = m_VerifySum;

	return true ;


}

bool CFileHead::IsSameProductKey(Byte * pSecretKey, int nKeylen)
{
	if(m_uFileHeadVer == 1) //老式的文件头，直接返回真 Add BY Kejun 2008-05-04
		return true;

	if (pSecretKey == NULL || nKeylen > 128 || nKeylen <= 0)
	{
		assert(false);
		return false;
	}

	Byte byteKey[128] = {0};
	//CDesEnc DesEnc;
	//CRijndaelEnc RijndaelEnc;//替换加密算法 modify By kejun 2009-03-17
	int nMode = 0;
	g_KeyUtil->m_pclFile.GetAlgorithmMode(nMode);
	if (m_AlgorithmMode != nMode)
	{
		return false;
	}

	if(pSecretKey == NULL || nKeylen <= 0)
	{
		return false;
	}
	memcpy(byteKey, pSecretKey, nKeylen);
	char szProductKey[32] = {0};
	if(nMode == 0)
	{
		CRijndaelEnc RijndaelEnc;
		RijndaelEnc.ChangeToWhiteText(byteKey,
			nKeylen,
			(Byte *)m_szEncProductKey,
			sizeof(m_szEncProductKey),
			(Byte *)szProductKey
			);
	}
	else if(nMode == 1)
	{
		CAlgorithmSM4 oSM4;
		oSM4.ChangeToWhiteText(byteKey,
			nKeylen,
			(Byte *)m_szEncProductKey,
			sizeof(m_szEncProductKey),
			(Byte *)szProductKey
			);
	}
	else
	{
		return false;
	}
	if(0 != strcmp(szProductKey, g_KeyUtil->GetProductKey().c_str()))
//	if(0 != strcmp(szProductKey, g_KeyUtil->GetProductKey().c_str()))
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool CFileHead::AddProductKey(Byte * pSecretKey, int nKeylen)
{
	//Add BY Kejun 2008-05-04 文件头加序列号
	if (pSecretKey == NULL || nKeylen > 128 || nKeylen <= 0)
	{
		assert(false);
		return false;
	}

	//ZeroMemory(m_szEncProductKey, sizeof(m_szEncProductKey));
    memset(m_szEncProductKey, 0,sizeof(m_szEncProductKey));
    std::string strProductKey = g_KeyUtil->GetProductKey();
	Byte byteKey[128] = {0};
	//int  nKeyLen = 0;
	//CDesEnc DesEnc;

    int nMode = 0;
    g_KeyUtil->m_pclFile.GetAlgorithmMode(nMode);
	if (pSecretKey == NULL || nKeylen <= 0)
	{
		return false;
	}
	if(nMode == 0)
	{
		CRijndaelEnc RijndaelEnc;
		//int nBufLen = sizeof(byteKey);
		memcpy(byteKey, pSecretKey, nKeylen);
		bool bRet = RijndaelEnc.ChangeToBlackText(byteKey, nKeylen, (Byte *)strProductKey.c_str(), sizeof(m_szEncProductKey), (Byte *)m_szEncProductKey);
		if(!bRet)
		{
			return false;
		}
	}
	else if(nMode == 1)
	{
		CAlgorithmSM4 oSM4;
		memcpy(byteKey, pSecretKey, nKeylen);
		bool bRet = oSM4.ChangeToBlackText(byteKey, nKeylen, (Byte *)strProductKey.c_str(), sizeof(m_szEncProductKey), (Byte *)m_szEncProductKey);
		if(!bRet)
		{
			return false;
		}
	}
	else
	{
		return false;
	}
	//Add End
	return true;
}

//////////////////////////////////////////////////////////////////////////
bool CFileHead::WriteToMem(Byte *pData)
{
	Byte * p = pData ;
    memcpy(p,m_szSignature,16);
    p += 16;
    *(unsigned short*)p = m_uFileHeadVer;
    p += sizeof(unsigned short);
    *(double*)p = m_dTime ;
    p += sizeof(double);
    *(unsigned int*)p = m_uEncFlowVer ;
    p += sizeof(unsigned int);
    *(int*)p = m_uKeyVer;
    p += sizeof(int);
    memcpy(p,m_szEncProductKey,32);
    p += 32;
    *(unsigned int*)p = m_encfilecount ;
    p += sizeof(unsigned int);
    memcpy(p,m_encfileposinfo,200);
    p += 200;
    memcpy(p,m_SerialNumber_Clear,24);
    p += 24;
    *(unsigned short*)p = m_AlgorithmMode;
    p += sizeof(unsigned short);
    memcpy(p,m_UserInfo,212);
    p += 212;
    p = pData;
    // Add End
    m_VerifySum = 0 ;
    for (int i = 0 ;i < LENG_FILE_HEAD - 4 ; i++)
    {
        m_VerifySum += p[i];
    }

    *(int*)(pData + LENG_FILE_HEAD -4 ) = m_VerifySum;
    return true;
}

//bool CFileHead::WriteToMem(Byte *pData)
//{
//
//	if(!AddProductKey())
//	{
//		assert(false);
//		return false;
//	}
////#endif
//
//	//将内容输出到一个数组BYTE中，以便于保存
//	memset(pData , 0 , sizeof(m_szSignature) / sizeof(m_szSignature[0]));
//	strcpy((char*)pData , m_szSignature);
//	pData += sizeof(m_szSignature) / sizeof(m_szSignature[0]) ;
//
//	*((unsigned short*)pData) = m_uFileHeadVer;
//	pData += sizeof(unsigned short) ;
//
//	*((long long*)pData) = m_dTime;
//	pData += sizeof(long long) ;
//
//	*((unsigned int*)pData) = m_uEncFlowVer;
//	pData += sizeof(unsigned int) ;
//
//	*((unsigned int*)pData) = m_uKeyVer;
//	pData += sizeof(unsigned int) ;
//
//	//Add by Kejun 2008-05-04 在文件头增加加密的序列号项
//	memset(pData, 0, sizeof(m_szEncProductKey));
//	memcpy(pData, m_szEncProductKey, sizeof(m_szEncProductKey));
//	pData += 32;
//	//Add End
//	*((unsigned int*)pData) = m_encfilecount;
//	pData += sizeof(unsigned int);
//
//	memcpy(pData, m_encfileposinfo, sizeof(m_encfileposinfo) / sizeof(Byte));
//	pData += sizeof(m_encfileposinfo)/sizeof(Byte);
//
//// 	memcpy(pData , m_ReserveData , sizeof(m_ReserveData) / sizeof(BYTE));
//// 	pData += sizeof(m_ReserveData)/sizeof(BYTE) ;
//
//	memcpy(pData , m_UserReserveData , sizeof(m_UserReserveData) / sizeof(Byte));
//	pData += sizeof(m_UserReserveData) / sizeof(Byte) ;
//
////Add By Kejun 增加文件版本信息(上海的需求) 2008-11-14
//	memcpy(pData , m_FileVerInfo, sizeof(m_FileVerInfo) / sizeof(Byte));
//	pData += sizeof(m_FileVerInfo) / sizeof(Byte);
//// Add End
//	unsigned int  uVerifySum = 0 ;
//	Byte * pTmp = pData ;
//	for(int iCount = LENG_FILE_HEAD - sizeof(m_VerifySum) ; iCount > 0 ; iCount-- )
//		uVerifySum += *(--pTmp) ;
//	m_VerifySum = uVerifySum ;
//	*((unsigned int *)pData)  = m_VerifySum;
//
//	return true ;
//}
bool CFileHead::ReadFromMem(Byte *pData)
{
	Byte * p = pData;
	memset(m_szSignature , 0 , 16);
	memcpy(m_szSignature, p, 16);
	p += 16;
	m_uFileHeadVer = *(unsigned short*) p;
	p += sizeof(short);
	m_dTime = *(double*)p;
	p += sizeof(double);
	m_uEncFlowVer = *(unsigned int*) p;
	p += sizeof(unsigned int);
	m_uKeyVer = *(int*) p;
	p += sizeof(int);
	memcpy(m_szEncProductKey, pData, 32);
	p += 32;
	m_encfilecount = *(unsigned int *) p;
	p += sizeof(unsigned int);
	memcpy(m_encfileposinfo, p, 200);
	p += 200;
	memcpy(m_SerialNumber_Clear, p, 24);
	p += 24;
	m_AlgorithmMode = *(unsigned short *) p;
	p += sizeof(unsigned short);
	memcpy(m_UserInfo, p, 212);
	p += 212;

	m_VerifySum = *(unsigned int *) p;

	m_listEncUnit.clear();
	if (m_encfilecount <= 20) {
		Byte *pMem = m_encfileposinfo;
		unsigned int nCopyLen = sizeof(FileEncPosInfo);
		for (int i = 0; i < m_encfilecount; i++) {
			FileEncPosInfo tmp;
			memcpy(&tmp, pMem, nCopyLen);
			m_listEncUnit.push_back(tmp);
			pMem += nCopyLen;
		}
	}

	p = pData;
	//校验文件头是否正确
	unsigned int dwCount = 0;
	for (int i = 0; i < LENG_FILE_HEAD - 4; i++)
		dwCount += p[i];
	if (dwCount != m_VerifySum)
		return false;
	return true;
}

//bool CFileHead::ReadFromMem(Byte *pData)
//{
//	//从一个数组中读取内容
//	memset(m_szSignature , 0 , sizeof(m_szSignature) / sizeof(m_szSignature[0]));
//	strcpy(m_szSignature , (char*)pData);
//	pData += sizeof(m_szSignature) / sizeof(m_szSignature[0]) ;
//
//	m_uFileHeadVer = *((unsigned short*)pData);
//	pData += sizeof(unsigned short) ;
//
//	m_dTime = *((long long*)pData);
//	pData += sizeof(long long) ;
//
//	m_uEncFlowVer = *((unsigned int*)pData);
//	pData += sizeof(unsigned int) ;
//
//	m_uKeyVer = *((unsigned int*)pData);
//	pData += sizeof(unsigned int) ;
//
//	//Add BY Kejun 增加文件头中加密序列号 2008-05-04
//    memset(m_szEncProductKey, 0, sizeof(m_szEncProductKey));
//	memcpy(m_szEncProductKey, pData, sizeof(m_szEncProductKey));
//	pData += sizeof(m_szEncProductKey);
//	//Add End
//
//	m_encfilecount = *((unsigned int *)pData);
//	pData += sizeof(unsigned int);
//
//// 	memcpy(m_ReserveData , pData , sizeof(m_ReserveData) / sizeof(BYTE));
//// 	pData += sizeof(m_ReserveData)/sizeof(BYTE) ;
//
//	memcpy(m_encfileposinfo, pData , sizeof(m_encfileposinfo) / sizeof(Byte));
//	pData += sizeof(m_encfileposinfo)/sizeof(Byte);
//
//	char* pMem = (char*)m_encfileposinfo;
//	if (m_encfilecount <= 20)
//	{
//		//初始化加密单元
//		for (int i = 0; i < m_encfilecount; ++i) {
//			FileEncPosInfo fileEncPosInfo = {0};
//			memcpy(&fileEncPosInfo,pMem, sizeof(FileEncPosInfo));
//			pMem += sizeof(FileEncPosInfo);
//			m_listEncUnit.push_back(fileEncPosInfo);
//		}
//	}
//
//
//	memcpy(m_UserReserveData , pData , sizeof(m_UserReserveData) / sizeof(Byte));
//	pData += sizeof(m_UserReserveData) / sizeof(Byte) ;
//
//	//Add By Kejun 增加文件版本信息(上海的需求) 2008-11-14
//	memcpy(m_FileVerInfo, pData, sizeof(m_FileVerInfo) / sizeof(Byte));
//	pData += sizeof(m_FileVerInfo) / sizeof(Byte);
//	//Add End
//	m_VerifySum = *((unsigned int *)pData);
//
//	unsigned int uVerifySum = 0 ;
//	Byte * pTmp = pData ;
//	for(int iCount = LENG_FILE_HEAD - sizeof(m_VerifySum) ; iCount > 0 ; iCount-- )
//		uVerifySum += *(--pTmp) ;
//
//	if(uVerifySum != m_VerifySum)//检验失败
//		return false ;
//
//	//if(m_uFileHeadVer == 21 )
//    //		return false ;
//
//    //assert(m_uFileHeadVer == 0x0c);
//    assert(m_uEncFlowVer == 1);
//    //assert(m_uFileHeadVer == 0x0c && m_uEncFlowVer == 1);
//
//	return true ;
//}

bool CFileHead::IsLegalFileHead(Byte *pData)
{
	//查看是否有本软件增加的文件加密头．有则说明已经加过密．
	for(int i = 0 ; i < sizeof(HEAD_SING) / sizeof(HEAD_SING[0]) ; i++)
	{
		if(pData[i] != HEAD_SING[i])//所有的位必须相同,包括后面的空字符
			return false ;
	}

	return true ;
}

void CFileHead::Empty()
{
	m_uFileHeadVer = - 1 ;//设置为非法
}

bool CFileHead::IsEmpty()
{
	return ((unsigned short)-1 == m_uFileHeadVer ) ;
}

//Add By Kejun 增加文件版本信息(上海的需求) 2008-11-14
void CFileHead::SetFileVerInfo(Byte *szVerInfo)
{
	memcpy(m_FileVerInfo, szVerInfo, sizeof(m_FileVerInfo));
}

void CFileHead::GetFileVerInfo(Byte *szVerInfo)
{
	memcpy(szVerInfo, m_FileVerInfo, sizeof(m_FileVerInfo));
}
//Add End
void CFileHead::SetKeyVer(short uKeyId)
{
    m_uKeyVer = uKeyId;
}
short CFileHead::GetKeyVer()
{
    return m_uKeyVer;
}

bool CFileHead::AddProductKey()
{
	//Add BY Kejun 2008-05-04 文件头加序列号
/*	ZeroMemory(m_szEncProductKey, sizeof(m_szEncProductKey));
	string strProductKey = g_objSysIniFile.GetProductKey();
	Byte byteKey[128] = {0};
	int  nKeyLen = 0;
	//CDesEnc DesEnc;
	CRijndaelEnc RijndaelEnc;
	//int nBufLen = sizeof(byteKey);
	if(!g_objKeyOrigin.QueryKey(m_uKeyVer, sizeof(byteKey), byteKey, nKeyLen))
	{	
		return FALSE;
	}
	else
	{
		BOOL bRet = RijndaelEnc.ChangeToBlackText(byteKey, nKeyLen, (BYTE *)strProductKey.c_str(), sizeof(m_szEncProductKey), (BYTE *)m_szEncProductKey);
		if(!bRet)
		{
			return FALSE;
		}
	}*/
	//Add End
	return true;
}
/*BOOL CFileHead::IsSameProductKeyUseOldM()
{
	//创立工作流
	if(m_uFileHeadVer == 1) //老式的文件头，直接返回真 Add BY Kejun 2008-05-04
		return TRUE;
	int failCode = 0;
	BYTE byteKey[128] = {0};
	int  nKeyLen = 0;
	CDesEnc DesEnc;
	if(!g_objKeyOrigin.QueryKey(m_uKeyVer, sizeof(byteKey), byteKey, nKeyLen))
	{
		return FALSE;
	}
	char szProductKey[32] = {0};
	DesEnc.ChangeToWhiteText(byteKey, 
		nKeyLen, 
		(BYTE *)m_szEncProductKey, 
		sizeof(m_szEncProductKey),
		(BYTE *)szProductKey
		);
	if(!strcmp(szProductKey, g_objSysIniFile.GetProductKey().c_str()))
	{
		return TRUE;
	}
	else
		return FALSE;

}

BOOL CFileHead::IsSameProductKey()//Add By Kejun 2008-05-04
{
	//创立工作流
	if(m_uFileHeadVer == 1) //老式的文件头，直接返回真 Add BY Kejun 2008-05-04
		return TRUE;
	int failCode = 0;
	BYTE byteKey[128] = {0};
	int  nKeyLen = 0;
	//CDesEnc DesEnc;
	CRijndaelEnc RijndaelEnc;//替换加密算法 modify By kejun 2009-03-17
	if(!g_objKeyOrigin.QueryKey(m_uKeyVer, sizeof(byteKey), byteKey, nKeyLen))
	{	
		return FALSE;
	}
	char szProductKey[32] = {0};
	RijndaelEnc.ChangeToWhiteText(byteKey, 
		                     nKeyLen, 
							 (BYTE *)m_szEncProductKey, 
							 sizeof(m_szEncProductKey),
							 (BYTE *)szProductKey
		                     );
	if(!strcmp(szProductKey, g_objSysIniFile.GetProductKey().c_str()))
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}

}*/
//#endif

//////////////////////////////////////////////////////////////////////////
//add by hzg for new encrypt method
void CFileHead::GetFileEncCount(unsigned int & Encount)
{
	Encount = m_encfilecount;
}

void CFileHead::SetFileEncCount(unsigned int & Encount)
{
	m_encfilecount = Encount;
}

bool CFileHead::GetFileEncPosInfo(std::list<FileEncPosInfo> & EncPinfoList)
{
	FileEncPosInfo posinfo;
	Byte * pfileposinfo = m_encfileposinfo;
	for (unsigned long i = 0; i < m_encfilecount; i++)
	{
        /*posinfo.ENCpos = *((unsigned long *)pfileposinfo);
         pfileposinfo += sizeof(unsigned long);
         posinfo.ENClength = *((unsigned long *)pfileposinfo);
         pfileposinfo += sizeof(unsigned long);*/
		posinfo.ENCpos = *((unsigned int *)pfileposinfo);
		pfileposinfo += sizeof(unsigned int);
		posinfo.ENClength = *((unsigned int *)pfileposinfo);
		pfileposinfo += sizeof(unsigned int);

		EncPinfoList.push_back(posinfo);
	}
	return true;
}

bool CFileHead::SetFileEncPosInfo(std::list<FileEncPosInfo> & EncPinfoList)
{
	m_encfilecount = (unsigned int)EncPinfoList.size();
	std::list<FileEncPosInfo>:: iterator pos;
	Byte * pfileposinfo = m_encfileposinfo;
//	int n = sizeof(m_encfileposinfo);
    memset(m_encfileposinfo, 0, sizeof(m_encfileposinfo));
	for (pos = EncPinfoList.begin(); pos != EncPinfoList.end(); pos++)
	{		
		/*memcpy(pfileposinfo, &(pos->ENCpos), sizeof(unsigned long));
		pfileposinfo += sizeof(unsigned long);
		memcpy(pfileposinfo, &(pos->ENClength), sizeof(unsigned long));
		pfileposinfo += sizeof(unsigned long);*/
        memcpy(pfileposinfo, &(pos->ENCpos), sizeof(unsigned int));
        pfileposinfo += sizeof(unsigned int);
        memcpy(pfileposinfo, &(pos->ENClength), sizeof(unsigned int));
        pfileposinfo += sizeof(unsigned int);
        
	}
	return true;
}

std::list<FileEncPosInfo> *CFileHead::GetEncUnitlist() {
	return &m_listEncUnit;
}

bool CFileHead::IsLegalFileHead(Byte *pData, int nLength) {
	if (nLength < sizeof(HEAD_SING))
		return  false;
	return  CFileHead::IsLegalFileHead(pData);
}

unsigned short CFileHead::GetAlgorithmMode()//获取加密算法
{
	return m_AlgorithmMode;
}

