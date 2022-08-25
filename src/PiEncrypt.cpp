/*
 * PiEncrypt.cpp
 *
 *  Created on: 2015年12月23日
 *      Author: kejun
 */
#include <string.h>
#include "../PiEncrypt.h"
#include "CFileEncrypt.h"
#include<iostream>

long  PiGetFileEncState(const char * pszFullFileName)
{
	return CFileEncrypt::GetFileEncState(pszFullFileName);
}

bool  PiEncryptFile(int nKeyId, const char * pszFullFileName, int &nFailCode, bool NeedDog)
{
	//strstr(pszFullFileName, "abc");
	return CFileEncrypt::EncryptFile(nKeyId, pszFullFileName, nFailCode, NeedDog);
}

bool  PiDecryptFile(const char * pszFullFileName, int &nFailCode, bool NeedDog)
{
	return CFileEncrypt::DecryptFile(pszFullFileName, nFailCode, NeedDog);
}

bool  PiDecFileInMem(unsigned char * pSourceFileMem, int Sourcelen,  unsigned char * pDesFileMem, int DesMemLen, int & failcode)
{
	return CFileEncrypt::DecFileInMem(pSourceFileMem, Sourcelen, pDesFileMem, DesMemLen, failcode);
}

bool PiEncFileInMem(int nKeyId,unsigned char * pSourceFileMem, int Sourcelen,  unsigned char * pDesFileMem, int DesMemLen, int & failcode)
{
	return CFileEncrypt::EncFileInMem(nKeyId,pSourceFileMem, Sourcelen, pDesFileMem, DesMemLen, failcode);
}

long PiIsMemEnc(unsigned char * pMem, int Memlen)
{
	return CFileEncrypt::IsMemEnc(pMem, Memlen);
}

int PiGetErrInfo(int nErrorCode, /*out*/char *pszErrInfo)
{
	string strErrInfo = GetErrString(nErrorCode);
    strcpy(pszErrInfo, strErrInfo.c_str());
	return 0;
}

bool PiSetConfigPath(const char *pszPath, int &nErrCode)
{
    return CFileEncrypt::SetConfigPath(pszPath,nErrCode);
}

