#include "FileTypeCheck.h"
#include <cstring>
#include <stdio.h>

CFileTypeCheck::CFileTypeCheck(string strFile)
{
	m_dwRelCheckLen = 0;
	m_strFileName = "";
	m_bIsNewFile = false;
	m_bIsThan3000 = false;

	m_strFileName = strFile;
	ReadCheckBuffer();
}

CFileTypeCheck::CFileTypeCheck()
{
	m_dwRelCheckLen = 0;
	m_strFileName = "";
	m_bIsNewFile = false;
	m_bIsThan3000 = false;
}


CFileTypeCheck::~CFileTypeCheck(void)
{
	
}

unsigned long int GetFileSize(FILE *fp)
{
    long cur_pos = ftell(fp);
    if (cur_pos == -1)
    {
        return -1;
    }

    if (fseek(fp, 0L, SEEK_END) == -1)
    {
        return -1;
    }
    // get file size.
    unsigned long int filesize = ftell(fp);
    fseek(fp, cur_pos, SEEK_SET);//还原文件的位置
    return filesize;
}

void CFileTypeCheck::ReadCheckBuffer()
{
    FILE *fp = fopen(m_strFileName.c_str(), "rb");
    if (fp == NULL)
    {
        return ;
    }
	//HANDLE hFile =  CiApi::CreateFileW(m_strFileName.c_str(),GENERIC_READ,FILE_SHARE_DELETE|FILE_SHARE_READ|FILE_SHARE_WRITE,NULL,OPEN_EXISTING,FILE_ATTRIBUTE_NORMAL,NULL);
	//if(nullptr == hFile)
	//{
	//	m_dwRelCheckLen = 0;
	//	return;
	//}
	DWORD dwSize = GetFileSize(fp);
	if(0 == dwSize)
		m_bIsNewFile = true;
	else
		m_bIsNewFile = false;
	if(dwSize <= 3000)
		m_bIsThan3000 = true;
	else
		m_bIsThan3000 = false;
	if(dwSize < FILE_CHECK_LENGTH)
		m_dwRelCheckLen = dwSize;
	else
		m_dwRelCheckLen = FILE_CHECK_LENGTH;
	//DWORD dwRead;
	//ReadFile_API(hFile,m_szBuffer,m_dwRelCheckLen,&dwRead,NULL);
	//CloseHandle(hFile);
    fclose(fp);
    fp = NULL;
}

bool CFileTypeCheck::IsTextAllAsci(char* str,DWORD length)
{
	if(m_bIsNewFile)
		return false;
	int i;
    unsigned char chr;
	for(i = 0 ; i < length ; i++)
	{
		chr= *(str+i);
		if( (chr&0x80) != 0 ) 
			return false;
	}
	return true;
}

bool CFileTypeCheck::IsPdfFile()
{
	string strExt = m_strFileName.substr(m_strFileName.length() - 4,4);

	if("_Tmp" == strExt)
		strExt = m_strFileName.substr(m_strFileName.length() - 8,4);

	if(strcmp(strExt.c_str(),".pdf") == 0)
		return true;
	else
		return true;
}

bool CFileTypeCheck::IsPptxFile()
{
	string strExt = m_strFileName.substr(m_strFileName.length() - 4,4);

	if("_Tmp" == strExt)
		strExt = m_strFileName.substr(m_strFileName.length() - 9,5);
	else
		strExt = m_strFileName.substr(m_strFileName.length() - 5,5);

	if(strcmp(strExt.c_str(),".pptx") == 0)
		return true;
	else
		return false;
}

bool CFileTypeCheck::IsTextUTF8(char* str, unsigned long long length)
{
	int i;
	DWORD nBytes=0;//UFT8����1-6���ֽڱ���,ASCII��һ���ֽ�
    unsigned char chr;
	bool bAllAscii=true; //���ȫ������ASCII, ˵������UTF-8
	for(i = 0 ; i < length ; i++)
	{
		chr= *(str+i);
		if( (chr&0x80) != 0 ) // �ж��Ƿ�ASCII����,�������,˵���п�����UTF-8,ASCII��7λ����,����һ���ֽڴ�,���λ���Ϊ0,o0xxxxxxx
			bAllAscii= false;
		if(nBytes==0) //�������ASCII��,Ӧ���Ƕ��ֽڷ�,�����ֽ���
		{
			if(chr>=0x80)
			{
				if(chr>=0xFC&&chr<=0xFD)
					nBytes=6;
				else if(chr>=0xF8)
					nBytes=5;
				else if(chr>=0xF0)
					nBytes=4;
				else if(chr>=0xE0)
					nBytes=3;
				else if(chr>=0xC0)
					nBytes=2;
				else
				{
					return false;
				}
				nBytes--;
			}
		}
		else //���ֽڷ��ķ����ֽ�,ӦΪ 10xxxxxx
		{
			if( (chr&0xC0) != 0x80 )
			{
				return false;
			}
			nBytes--;
		}
	}
	if( nBytes > 0 ) //Υ������
	{
		return false;
	}
	if( bAllAscii ) //���ȫ������ASCII, ˵������UTF-8
	{
		return false;
	}
	return true;
} 

FILE_TYPE CFileTypeCheck::ChecFileType()
{
	//////////////////////////////////////////////////////////////////////////
	//�ļ�����׺�ж�
	if(IsPdfFile())
		return FILE_CHECK_PDF;
	if (IsPptxFile())
		return FILE_CHECK_PPTX;
	//////////////////////////////////////////////////////////////////////////


	if(m_dwRelCheckLen == 0)
		return FILE_CHECK_UNKNOWN;
	if(IsTextAllAsci(m_szBuffer,m_dwRelCheckLen))
		return FILE_CHECK_TEXT_ASCI;

	return FILE_CHECK_UNKNOWN;
}

FILE_TYPE CFileTypeCheck::ChecFileType(string strFileName)
{
	m_strFileName = strFileName;
	ReadCheckBuffer();
	return ChecFileType();
}

bool CFileTypeCheck::NeedAllEnc()
{
	FILE_TYPE ft = ChecFileType();
	if((ft == FILE_CHECK_PDF || ft == FILE_CHECK_PPTX || ft == FILE_CHECK_TEXT_ASCI) && !m_bIsThan3000)
		return true;
	else
		return false;
}

bool CFileTypeCheck::NeedAllEnc(string strFileName)
{
	FILE_TYPE ft = ChecFileType(strFileName);
	if((ft == FILE_CHECK_PDF || ft == FILE_CHECK_PPTX || ft == FILE_CHECK_TEXT_ASCI) && !m_bIsThan3000)
		return true;
	else
		return false;
}

CTextFileCheck::CTextFileCheck()
{

}
CTextFileCheck::~CTextFileCheck()
{

}

bool CTextFileCheck::IsAnsiChar(unsigned char c)
{
//	if(c & 0x80 == 0 && c & 0x60 != 0)
	if( !(c & 0x80) && (c & 0x60))
	{
		return true;
	}
	else if(c == 0x0D || c == 0x0A || c == 0x09)
		return true;
	else
		return false;
}


int CTextFileCheck::IsUnicodeText(const char* str,DWORD dwLength)
{
	if(dwLength < 3)
		return 0;
    unsigned char c1 = str[0];
    unsigned char c2 = str[1];
    unsigned char c3 = str[2];
	if(c1 == 0xff && c2 == 0xfe)
		return 1;
	if(c1 == 0xfe && c2 == 0xff)
		return 2;
	if(c1 == 0xef && c2 == 0xbb && c3 == 0xbf)
		return 3;

	return 0;
}

bool CTextFileCheck::IsBmpFile(const BYTE* pHeader,DWORD dwLen)
{
	if(dwLen < 2)
		return false;

	if(pHeader[0] == 0x42 && pHeader[1] == 0x4d)
		return true;
	else
		return false;
}

bool CTextFileCheck::IsTifFile(const BYTE* pHeader,DWORD dwLen)
{
	if(dwLen < 4)
		return false;

	if(pHeader[0] == 0x49 && pHeader[1] == 0x49 && pHeader[2] == 0x2a && pHeader[3] == 0x00)
		return true;
	else
		return false;
}

bool CTextFileCheck::IsTextAllAsci(const char* str,DWORD length)
{
	int i;
	char chr;
	for(i = 0 ; i < length ; i++)
	{
		chr= *(str+i);
		if(!IsAnsiChar(chr))
			return false;
	}
	return true;
}

bool CTextFileCheck::IsTextFile(string lpFileName)
{
	//HANDLE hFile = CiApi::CreateFileW(lpFileName,GENERIC_READ,FILE_SHARE_READ|FILE_SHARE_WRITE,NULL,OPEN_EXISTING,FILE_ATTRIBUTE_NORMAL,NULL);
	//if(INVALID_HANDLE_VALUE == hFile)
		//return false;
	//bool bText = IsTextFile(hFile);
	//CiApi::CloseHandle(hFile);

    FILE *fp = fopen(lpFileName.c_str(), "rb");
    if (fp == NULL)
    {
        return false;
    }

    DWORD size = GetFileSize(fp);
    if(size == 0)
        return false;
    //大于3字节，先判断是否为Unicode文本
    if(size < 3) {
        BYTE pHeader[4];
        memset(pHeader, 0, 4 * sizeof(BYTE));
        fread(pHeader, sizeof(BYTE), 4, fp);
        if (IsUnicodeText((const char *) pHeader, 4))            //是否为Unicode文本
        {
            fclose(fp);
            return true;
        }
        if (IsTifFile(pHeader, 4) || IsBmpFile(pHeader, 4))    //是否为tif或者bmp文件
        {
            fclose(fp);
            return false;
        }
    }

        if(size > 2.0 * 1024 * 1024 * 1024)
            size = 2.0 * 1024 * 1024 * 1024;

        if(size > FILE_CHECK_LENGTH * 3) //文件分三段检查，分别为文件开头，中间和结尾
        {
            DWORD dwDistance = (size - FILE_CHECK_LENGTH * 3) / 2;
            DWORD dwOffset1 = 0;
            DWORD dwOffset2 = FILE_CHECK_LENGTH + dwDistance;
            DWORD dwOffset3 = FILE_CHECK_LENGTH * 2 + dwDistance * 2;

            BYTE szBuffer1[FILE_CHECK_LENGTH];
            BYTE szBuffer2[FILE_CHECK_LENGTH];
            BYTE szBuffer3[FILE_CHECK_LENGTH];
            memset(szBuffer1,0,FILE_CHECK_LENGTH* sizeof(BYTE));
            memset(szBuffer2,0,FILE_CHECK_LENGTH* sizeof(BYTE));
            memset(szBuffer3,0,FILE_CHECK_LENGTH* sizeof(BYTE));

            fread(szBuffer1,sizeof(BYTE),FILE_CHECK_LENGTH,fp);
            fseek(fp,dwOffset2,SEEK_CUR);
            fread(szBuffer2,sizeof(BYTE),FILE_CHECK_LENGTH,fp);
            fseek(fp,dwOffset3,SEEK_CUR);
            fread(szBuffer3,sizeof(BYTE),FILE_CHECK_LENGTH,fp);

            DWORD dwTextCnt = 0;
            if(IsTextBuffer(szBuffer1,FILE_CHECK_LENGTH))
                dwTextCnt++;
            if(IsTextBuffer(szBuffer2,FILE_CHECK_LENGTH))
                dwTextCnt++;
            if(IsTextBuffer(szBuffer3,FILE_CHECK_LENGTH))
                dwTextCnt++;

            if(dwTextCnt >= 2)
                return true;
            else
                return false;
        }
        else
        {
            //DWORD dwReadLen = 0;
            BYTE szBuffer[FILE_CHECK_LENGTH];
            memset(szBuffer,0,FILE_CHECK_LENGTH* sizeof(BYTE));
            size_t num = fread(szBuffer,sizeof(BYTE),FILE_CHECK_LENGTH,fp);
            if( num < 0)
            {
                fclose(fp);
                return false;
            } else
            {
                fclose(fp);
                return IsTextBuffer(szBuffer,num);
            }
        }

	return true;
}

/*bool CTextFileCheck::IsTextFile(HANDLE hFile)
{
	LARGE_INTEGER liFileSize;
	CiApi::GetFileSizeEx(hFile,&liFileSize);
	if(0 == liFileSize.QuadPart)
		return false;

	if(3 < liFileSize.QuadPart)		//����3�ֽڣ����ж��Ƿ�ΪUnicode�ı�
	{
		BYTE pHeader[4];
		OVERLAPPED overlapped;
		ZeroMemory(&overlapped,sizeof(OVERLAPPED));
		overlapped.Offset = 0;
		CiApi::ReadFile(hFile,pHeader,4,NULL,&overlapped);
		if(IsUnicodeText((const char*)pHeader,4))			//�Ƿ�ΪUnicode�ı�
			return true;

		if(IsTifFile(pHeader,4) || IsBmpFile(pHeader,4))	//�Ƿ�Ϊtif����bmp�ļ�
			return false;
	}

	if(liFileSize.QuadPart > 2.0 * 1024 * 1024 * 1024)
		liFileSize.QuadPart = 2.0 * 1024 * 1024 * 1024;

	if(liFileSize.QuadPart > FILE_CHECK_LENGTH * 3)			//�ļ������μ�飬�ֱ�Ϊ�ļ���ͷ���м�ͽ�β
	{
		DWORD dwDistance = (liFileSize.QuadPart - FILE_CHECK_LENGTH * 3) / 2;
		DWORD dwOffset1 = 0;
		DWORD dwOffset2 = FILE_CHECK_LENGTH + dwDistance;
		DWORD dwOffset3 = FILE_CHECK_LENGTH * 2 + dwDistance * 2;

		BYTE szBuffer1[FILE_CHECK_LENGTH];
		BYTE szBuffer2[FILE_CHECK_LENGTH];
		BYTE szBuffer3[FILE_CHECK_LENGTH];
        memset(szBuffer1,0,FILE_CHECK_LENGTH* sizeof(BYTE));
        memset(szBuffer2,0,FILE_CHECK_LENGTH* sizeof(BYTE));
        memset(szBuffer3,0,FILE_CHECK_LENGTH* sizeof(BYTE));
		OVERLAPPED overlapped;
		ZeroMemory(&overlapped,sizeof(OVERLAPPED));
		overlapped.Offset = dwOffset1;
		ReadFile(hFile,szBuffer1,FILE_CHECK_LENGTH,NULL,&overlapped);
		overlapped.Offset = dwOffset2;
		ReadFile(hFile,szBuffer2,FILE_CHECK_LENGTH,NULL,&overlapped);
		overlapped.Offset = dwOffset3;
		ReadFile(hFile,szBuffer3,FILE_CHECK_LENGTH,NULL,&overlapped);

		DWORD dwTextCnt = 0;
		if(IsTextBuffer(szBuffer1,FILE_CHECK_LENGTH))
			dwTextCnt++;
		if(IsTextBuffer(szBuffer2,FILE_CHECK_LENGTH))
			dwTextCnt++;
		if(IsTextBuffer(szBuffer3,FILE_CHECK_LENGTH))
			dwTextCnt++;

		if(dwTextCnt >= 2)
			return TRUE;
		else
			return FALSE;
	}
	else
	{
		DWORD dwReadLen = 0;
		BYTE szBuffer[FILE_CHECK_LENGTH];
		ZeroMemory(szBuffer,FILE_CHECK_LENGTH);
		OVERLAPPED overlapped;
		ZeroMemory(&overlapped,sizeof(OVERLAPPED));
		overlapped.Offset = 0;
		overlapped.OffsetHigh = 0;
		BOOL bSuc = CiApi::ReadFile(hFile,szBuffer,FILE_CHECK_LENGTH,NULL,&overlapped);
		int nErr = GetLastError();
		dwReadLen = overlapped.InternalHigh;
		return IsTextBuffer(szBuffer,dwReadLen);
	}
	
}*/

bool CTextFileCheck::IsTextFile(const BYTE* pBuffer,DWORD dwBufferLen)
{
	return IsTextBuffer(pBuffer,dwBufferLen);
}

bool CTextFileCheck::IsTextBuffer(const BYTE* pBuffer,DWORD dwBufferLen)
{

	DWORD dwUnKnownCharCnt = 0;

	if(IsUnicodeText((const char*)pBuffer,dwBufferLen))
		return true;

	for (int i = 0 ; i < dwBufferLen ; i++)
	{
        unsigned char c = pBuffer[i];
		if(!IsAnsiChar(c))
		{
			if((c & 0x80) && c != 0xff)
			{
				if(i != dwBufferLen - 1)
				{
                    unsigned char c1 = pBuffer[i+1];
					if((c1 & 0xC0) && c1 != 0x7f && c1 != 0xff)
					{
						i++;
					}
					else
						dwUnKnownCharCnt ++;
				}
				else
				{
					;
				}
			}
			else
				dwUnKnownCharCnt ++;
		}
	}

	int nPercent = (dwBufferLen - dwUnKnownCharCnt) * 100 / dwBufferLen;
	if(nPercent >= CAMPARE_PERCENT)
		return true;

	return false;
}

CRepairFileCheck::CRepairFileCheck()
{
	
}
CRepairFileCheck::~CRepairFileCheck()
{
	
}

bool CRepairFileCheck::isRepairFile(string lpFileName)
{
	//HANDLE hFile = CiApi::CreateFileW(lpFileName,GENERIC_READ,FILE_SHARE_READ|FILE_SHARE_WRITE,NULL,OPEN_EXISTING,FILE_ATTRIBUTE_NORMAL,NULL);
    FILE *fp = fopen(lpFileName.c_str(), "rb");
    if (fp == NULL)
    {
        return false;
    }

	//if(hFile == INVALID_HANDLE_VALUE)
		//return FALSE;

	BYTE szBuffer[FILE_CHECK_LENGTH];
    memset(szBuffer,0,FILE_CHECK_LENGTH *sizeof(BYTE));
    if(fread(szBuffer,sizeof(BYTE),FILE_CHECK_LENGTH,fp) < 0)
    {
        fclose(fp);
        return false;
    }
    else
    {
        if(isPdfFile(szBuffer))
        {
            fclose(fp);
            return true;
        }

        if(isPptFile(szBuffer))
        {
            fclose(fp);
            return true;
        }

        fclose(fp);
        return false;
    }
	//ZeroMemory(szBuffer,FILE_CHECK_LENGTH);
	//OVERLAPPED overlapped;
	//ZeroMemory(&overlapped,sizeof(OVERLAPPED));
	//overlapped.Offset = 0;
	//overlapped.OffsetHigh = 0;
	//BOOL bSuc = CiApi::ReadFile(hFile,szBuffer,FILE_CHECK_LENGTH,NULL,&overlapped);
	//int nErr = GetLastError();

	//if(!bSuc)
	//{
	//	CiApi::CloseHandle(hFile);
	//	return false;
	//}

	//if(isPdfFile(szBuffer))
	//{
	//	CiApi::CloseHandle(hFile);
	//	return true;
	//}
	//if(isPptFile(szBuffer))
	//{
	//	CiApi::CloseHandle(hFile);
	//	return true;
	//}
	//CiApi::CloseHandle(hFile);
	//return false;
}

bool CRepairFileCheck::isPdfFile(BYTE* buff)
{

	if(buff[0] == 0x25 && buff[1] == 0x50
		&& buff[2] == 0x44 && buff[3] == 0x46)
	{
		return true;
	}
	return false;
}

bool CRepairFileCheck::isPptFile(BYTE* buff)
{

	if(buff[0] == 0x50 && buff[1] == 0x4B)	//0-29  PK    30-48 [Content_Types].xml
	{
		//5B 43 6F 6E 74 65 6E 74 5F 54 79 70 65 73 5D 2E 78 6D 6C
		BYTE xml[19] = {0x5B,0x43,0x6F,0x6E,0x74,0x65,0x6E,0x74,0x5F,0x54,0x79,0x70,0x65,0x73,0x5D,0x2E,0x78,0x6D,0x6C};
		for (int i=0; i<19;i++)
		{
			if(buff[30+i] != xml[i])
				return false;
		}
		return true;
	}
	//ppt xls doc
	if(buff[0] == 0xD0 && buff[1] == 0xCF && buff[2] == 0x11 && buff[3] == 0xE0 && buff[4] == 0xA1 && buff[5] == 0xB1 && buff[6] == 0x1A && buff[7] == 0xE1)
		return true;
	return false;
}
