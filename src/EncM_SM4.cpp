#include "EncM_SM4.h"
#include "sm4.h"
#include <unistd.h>
#include <string.h>

CAlgorithmSM4::CAlgorithmSM4(void)
{
}


CAlgorithmSM4::~CAlgorithmSM4(void)
{
}

bool CAlgorithmSM4::ChangeToBlackText(BYTE *szSecretKey , 
	int nSecretLeng , 
	BYTE *lpSour , 
	DWORD nNumberOfBytese ,
	BYTE *lpDest)
{
	//���ܵ��ֽ�������ܵ��Ԫ����
	nNumberOfBytese = nNumberOfBytese / LENG_ENC_UNIT * LENG_ENC_UNIT;
	if(nNumberOfBytese == 0)
		return true;

	sm4_context ctx;
	unsigned char ucKye[16] = {0};

	if (nSecretLeng > 16)
		memcpy(ucKye,szSecretKey,16);
	else
		memcpy(ucKye,szSecretKey,nSecretLeng);

	sm4_setkey_enc(&ctx,ucKye);
	sm4_crypt_ecb(&ctx,SM4_ENCRYPT,nNumberOfBytese,(unsigned char *)lpSour,(unsigned char *)lpDest);
	return true;
}

bool CAlgorithmSM4::ChangeToWhiteText(BYTE *szSecretKey , 
	int nSecretLeng ,
	BYTE *lpSour ,
	DWORD nNumberOfBytese , 
	BYTE *lpDest)
{
	//���ܵ��ֽ�������ܵ�Ԫ����
	nNumberOfBytese = nNumberOfBytese / LENG_ENC_UNIT * LENG_ENC_UNIT;
	if(nNumberOfBytese == 0)
		return true;
	sm4_context ctx;
	unsigned char ucKye[16] = {0};

	if (nSecretLeng > 16)
		memcpy(ucKye,szSecretKey,16);
	else
		memcpy(ucKye,szSecretKey,nSecretLeng);
	sm4_setkey_dec(&ctx,ucKye);
	sm4_crypt_ecb(&ctx,SM4_DECRYPT,nNumberOfBytese,(unsigned char *)lpSour,(unsigned char *)lpDest);
	return true;
}
