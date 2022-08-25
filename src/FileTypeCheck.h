#pragma once
#include <string>
#include "GlobalDefine.h"

using namespace std;

#define FILE_CHECK_LENGTH 512
#define CAMPARE_PERCENT	90
enum FILE_TYPE{FILE_CHECK_UNKNOWN = 0,FILE_CHECK_TEXT_ASCI,FILE_CHECK_TEXT_UTF8,FILE_CHECK_PDF,FILE_CHECK_PPTX};

class CFileTypeCheck
{
private:
	char m_szBuffer[FILE_CHECK_LENGTH];
	DWORD m_dwRelCheckLen;
	string m_strFileName;
	bool m_bIsNewFile;
	bool m_bIsThan3000;
public:
	CFileTypeCheck(string strFile);
	CFileTypeCheck();
	~CFileTypeCheck(void);

private:
	void ReadCheckBuffer();
	bool IsTextUTF8(char* str, unsigned long long length);
	bool IsPdfFile();
	bool IsPptxFile();

public:
	bool IsTextAllAsci(char* str,DWORD length);
	bool IsLessThan3000Byte() {return m_bIsThan3000;}
	FILE_TYPE ChecFileType();
	FILE_TYPE ChecFileType(string strFileName);

	bool NeedAllEnc();
	bool NeedAllEnc(string strFileName);
};

class CImageFileCheck
{
public:
	static bool IsImageFile(string lpFileName);
	static bool IsImageFile();
	
};

class CTextFileCheck
{
public:
	CTextFileCheck();
	~CTextFileCheck();
private:
	bool IsBmpFile(const BYTE* pHeader,DWORD dwLen);
	bool IsTifFile(const BYTE* pHeader,DWORD dwLen);
public:
	bool IsAnsiChar(unsigned char c);
	int IsUnicodeText(const char* str,DWORD dwLength);
	bool IsTextAllAsci(const char* str,DWORD length);
	bool IsTextBuffer(const BYTE* pBuffer,DWORD dwBufferLen);
public:

	bool IsTextFile(string lpFileName);
	//bool IsTextFile(HANDLE hFile);
	bool IsTextFile(const BYTE* pBuffer,DWORD dwBufferLen);
};

class CRepairFileCheck
{
public:
	CRepairFileCheck();
	~CRepairFileCheck();
public:
	bool isRepairFile(string lpFileName);
private:
	bool isPdfFile(BYTE* buff);
	bool isPptFile(BYTE* buff);
};

