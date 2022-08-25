#pragma once

#include "GlobalDefine.h"

#define ALGORITHM_AES    0
#define ALGORITHM_SM4    1

class CEncryptMgr
{
public:
	CEncryptMgr(void);
	CEncryptMgr(int nMode);
	~CEncryptMgr(void);

	int m_nAlgorithm_Mode;//�����㷨
	void SetAlgorithmMode(int nMode);//�����㷨
	bool Decrypt(BYTE *lpKey, BYTE *lpSour , BYTE *lpDest , ULONG nLeng);
	bool Encrypt(BYTE*lpKey, BYTE *lpSour , BYTE *lpDest , ULONG nLeng);
};
