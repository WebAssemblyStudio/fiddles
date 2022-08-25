// EncM_Rijndael.cpp: implementation of the CDesEnc class.
//
//////////////////////////////////////////////////////////////////////
#include "EncM_Rijndael.h"
#include "Rijndael.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CRijndaelEnc::CRijndaelEnc()
{
	
}

CRijndaelEnc::~CRijndaelEnc()
{

}

bool CRijndaelEnc::ChangeToBlackText(BYTE *szSecretKey , 
								int nSecretLeng , 
								BYTE *lpSour , 
								DWORD nNumberOfBytese ,
								BYTE *lpDest)
{
	//加密的字节数与加密单元对齐
	/*nNumberOfBytese = nNumberOfBytese / LENG_ENC_UNIT * LENG_ENC_UNIT;*/
	if(nNumberOfBytese == 0)
		return true;
	return Rijndael_Go((char*)lpDest, (char*)lpSour, nNumberOfBytese, (char*)szSecretKey, nSecretLeng, ENCRYPT);
}

bool CRijndaelEnc::ChangeToWhiteText(BYTE *szSecretKey , 
								int nSecretLeng ,
								BYTE *lpSour ,
								DWORD nNumberOfBytese , 
								BYTE *lpDest)
{
	//解密的字节数与加密单元对齐
	nNumberOfBytese = nNumberOfBytese / LENG_ENC_UNIT * LENG_ENC_UNIT;
	if(nNumberOfBytese == 0)
		return true;

	return Rijndael_Go((char*)lpDest, (char*)lpSour, nNumberOfBytese, (char*)szSecretKey, nSecretLeng, DECRYPT);
}
