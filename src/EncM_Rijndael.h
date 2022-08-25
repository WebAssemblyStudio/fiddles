#if !defined(_ENCM_RIJNDAEL_H_)
#define _ENCM_RIJNDAEL_H_

#pragma once


//#include "EncM_Core.h"
#include "GlobalDefine.h"
#pragma pack(push)
#pragma pack(1)
enum {ENCRYPT, DECRYPT};
class CRijndaelEnc/* : public CEncryptMethod*/
{
public:
	CRijndaelEnc();
	virtual ~CRijndaelEnc();

public:
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
#endif // !defined(_ENCM_RIJNDAEL_H_)
