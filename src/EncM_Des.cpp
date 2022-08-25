// DesEnc.cpp: implementation of the CDesEnc class.
//
//////////////////////////////////////////////////////////////////////

#include "EncM_Des.h"
#include"../PiEncrypt.h"
#include "WjcDes.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CDesEnc::CDesEnc()
{

}

CDesEnc::~CDesEnc()
{

}

bool CDesEnc::ChangeToBlackText(BYTE *szSecretKey , 
								int nSecretLeng , 
								BYTE *lpSour , 
								DWORD nNumberOfBytese ,
								BYTE *lpDest)
{
	//加密的字节数与加密单元对齐
	nNumberOfBytese = nNumberOfBytese / LENG_ENC_UNIT * LENG_ENC_UNIT;
	if(nNumberOfBytese == 0)
		return true;

	return Des_Go((char*)lpDest, (char*)lpSour, nNumberOfBytese, (char*)szSecretKey, nSecretLeng, ENCRYPT);
}

bool CDesEnc::ChangeToWhiteText(BYTE *szSecretKey ,
								int nSecretLeng ,
								BYTE *lpSour ,
								DWORD nNumberOfBytese , 
								BYTE *lpDest)
{
	//解密的字节数与加密单元对齐,字节对齐在程序中有两套，DES对应8，AES对应16
	nNumberOfBytese = nNumberOfBytese / LENG_ENC_UNIT_8 * LENG_ENC_UNIT_8;
	if(nNumberOfBytese == 0)
		return true;

	return Des_Go((char*)lpDest, (char*)lpSour, nNumberOfBytese, (char*)szSecretKey, nSecretLeng, DECRYPT);
}

