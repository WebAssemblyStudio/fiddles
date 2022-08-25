//////////////////////////////////
//*
//*SM4�����㷨
//*
//////////////////////////////////


#if !defined(_ENCM_SM4_H_)
#define _ENCM_SM4_H_

#pragma once

//#include "EncM_Core.h"
#include "GlobalDefine.h"

#pragma pack(push)
#pragma pack(1)

class CAlgorithmSM4// : public CEncryptMethod
{
public:
	CAlgorithmSM4(void);
	~CAlgorithmSM4(void);

public:
	bool ChangeToBlackText(BYTE *szSecretKey , 
		int nSecretLeng , 
		BYTE *lpSour , 
		DWORD nNumberOfBytese , 
		BYTE *lpDest)  ;//����(��ɰ���)

	bool ChangeToWhiteText(BYTE *szSecretKey , 
		int nSecretLeng , 
		BYTE *lpSour , 
		DWORD nNumberOfBytese , 
		BYTE *lpDest)  ;//���ܣ�������룩
};
#pragma pack(pop)
#endif //_ENCM_SM4_H_
