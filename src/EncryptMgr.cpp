#include <string.h>
#include "EncryptMgr.h"
#include "EncM_Rijndael.h"
#include "EncM_SM4.h"
#include"../PiEncrypt.h"

CEncryptMgr::CEncryptMgr(void)
{
	m_nAlgorithm_Mode = ALGORITHM_AES;
}

CEncryptMgr::~CEncryptMgr(void)
{
}

CEncryptMgr::CEncryptMgr(int nMode)
{
	m_nAlgorithm_Mode = nMode;
}

bool CEncryptMgr::Decrypt(BYTE *lpKey, BYTE *lpSour , BYTE *lpDest , ULONG nLeng)
{
	if (m_nAlgorithm_Mode == ALGORITHM_AES)
	{
		CRijndaelEnc oRijndeal;
		return oRijndeal.ChangeToWhiteText(lpKey,strlen((const char*)lpKey),lpSour,nLeng,lpDest);
	}
	else if (m_nAlgorithm_Mode == ALGORITHM_SM4)
	{
		CAlgorithmSM4 oSM4;
		return oSM4.ChangeToWhiteText(lpKey,strlen((const char*)lpKey),lpSour,nLeng,lpDest);
	}
}

bool CEncryptMgr::Encrypt(BYTE *lpKey, BYTE *lpSour , BYTE *lpDest , ULONG nLeng)
{
	if (m_nAlgorithm_Mode == ALGORITHM_AES)
	{
		CRijndaelEnc oRijndeal;
		return oRijndeal.ChangeToBlackText(lpKey,strlen((const char*)lpKey),lpSour,nLeng,lpDest);
	}
	else if (m_nAlgorithm_Mode == ALGORITHM_SM4)
	{
		CAlgorithmSM4 oSM4;
		return oSM4.ChangeToBlackText(lpKey,strlen((const char*)lpKey),lpSour,nLeng,lpDest);
	}
}

void CEncryptMgr::SetAlgorithmMode(int nMode)
{
	m_nAlgorithm_Mode = nMode;
}
