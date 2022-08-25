// DesEnc.h: interface for the CDesEnc class.
//
//////////////////////////////////////////////////////////////////////
#if !defined(AFX_DESENC_H__20404958_2D40_4711_9837_F8B129DFC574__INCLUDED_)
#define AFX_DESENC_H__20404958_2D40_4711_9837_F8B129DFC574__INCLUDED_

#pragma once

//#include "EncM_Core.h"
#include "GlobalDefine.h"

#pragma pack(push)
#pragma pack(1)
class CDesEnc/* : public CEncryptMethod*/
{
public:
	CDesEnc();
	virtual ~CDesEnc();

public:
		//虚函数
	bool ChangeToBlackText(BYTE *szSecretKey , 
						   int nSecretLeng , 
						   BYTE *lpSour , 
						   DWORD nNumberOfBytese , 
						   BYTE *lpDest)  ;//加密(变成暗码)

	bool ChangeToWhiteText(BYTE *szSecretKey , 
						   int nSecretLeng , 
						   BYTE *lpSour , 
						   DWORD nNumberOfBytese , 
						   BYTE *lpDest)  ;//解密（变成明码）
};
#pragma pack(pop)
#endif // !defined(AFX_DESENC_H__20404958_2D40_4711_9837_F8B129DFC574__INCLUDED_)
