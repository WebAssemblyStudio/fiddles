//#include "StdAfx.h"
#include <string.h>
#include <unistd.h>
#include "FileUtil.h"
#include "assert.h"
#define MAX_FILE_PATH 128

CFileUtil::CFileUtil(void)
{
	m_file = NULL;
	m_filepath = new char[MAX_FILE_PATH];
	memset(m_filepath, 0, MAX_FILE_PATH);
	m_bReaded = false;
	m_bWritten = false;
}

CFileUtil::~CFileUtil(void)
{
	CloseFile();
	delete[] m_filepath;
}

bool CFileUtil::OpenFile(const char *filename, const char *mode)
{
	memset(m_filepath, 0, MAX_FILE_PATH);
	size_t nSize = strlen(filename);
	if (nSize >= MAX_FILE_PATH)
	{
		nSize = MAX_FILE_PATH - 1;
	}
	memcpy(m_filepath, filename, nSize);
	if (m_file)
	{
		CloseFile();
	}
	m_file = fopen(m_filepath, mode);
	if (m_file == NULL)
	{
		return false;
	}
	return true;
}

bool CFileUtil::CloseFile()
{
	if (NULL == m_file)
	{
		return true;
	}
	int nRetCode = fclose(m_file);
	m_file = NULL;
	if (nRetCode != 0)
	{
		return false;
	}
	return true;
}

size_t CFileUtil::GetFileFullPathName(char *buffer, unsigned long nMaxLen)
{
	if (buffer == NULL)
	{
		return -1;
	}
	size_t nsize = strlen(m_filepath);
	if (0 == nsize)
	{
		return 0;
	}
	if (nMaxLen < nsize)
	{
		memcpy(buffer, m_filepath, nMaxLen);
		return nMaxLen;
	}
	else
	{
		memcpy(buffer, m_filepath, nsize);
		return nsize;
	}
}

bool CFileUtil::ReadFile(void *lpBuffer, unsigned long nNumberOfBytesToRead,
		unsigned long *lpNumberOfBytesRead)
{
	if (m_file == NULL)
	{
		assert(m_file);
		return false;
	}
	if (lpBuffer == NULL)
	{
		assert(lpBuffer);
		return false;
	}
	if (lpNumberOfBytesRead == NULL)
	{
		assert(lpNumberOfBytesRead);
		return false;
	}
	if (m_bWritten)
	{
		fflush(m_file);
		m_bWritten = false;
	}
	m_bReaded = true;
	size_t nRetCode = fread(lpBuffer, 1, nNumberOfBytesToRead, m_file);
	*lpNumberOfBytesRead = nRetCode;
	if (0 != ferror(m_file))
	{
		return false;
	}
	if (nRetCode > nNumberOfBytesToRead)
	{
		return false;
	}
	else
	{
		return true;
	}
}

bool CFileUtil::WriteFile(void *lpBuffer, unsigned long nNumberOfBytesToWrite,
		unsigned long *lpNumberOfBytesWritten)
{
	if (m_file == NULL)
	{
		assert(m_file);
		return false;
	}
	if (lpBuffer == NULL)
	{
		assert(lpBuffer);
		return false;
	}
	if (m_bReaded)
	{
		fflush(m_file);
		m_bReaded = false;
	}
	m_bWritten = true;
	if (lpNumberOfBytesWritten == NULL)
	{
		assert(lpNumberOfBytesWritten);
		return false;
	}
	size_t nRetCode = fwrite(lpBuffer, 1, nNumberOfBytesToWrite, m_file);
	*lpNumberOfBytesWritten = nRetCode;
	if (0 != ferror(m_file))
	{
		return false;
	}
	fflush(m_file);
	return true;
}

bool CFileUtil::GetFileSize(unsigned long *lpNumberOfBytesFileSize)
{
	if (m_filepath == NULL)
	{
		assert(m_filepath);
		return false;
	}
	if (strlen(m_filepath) == 0)
	{
		return false;
	}
	if (lpNumberOfBytesFileSize == NULL)
	{
		assert(lpNumberOfBytesFileSize);
		return false;
	}
	*lpNumberOfBytesFileSize = 0;
// 	struct _stat buf;
// 	int iresult = _stat(m_filepath,&buf);
// 	if(iresult == 0)
// 	{
// 		*lpNumberOfBytesFileSize = buf.st_size;
// 		return true;
// 	}
	if (m_file == NULL)
	{
		assert(m_file);
		return false;
	}
	fseek(m_file, 0L, SEEK_END);
	long size = ftell(m_file);
	fseek(m_file, 0L, SEEK_SET);
	*lpNumberOfBytesFileSize = size;
	return true;

}
bool CFileUtil::Fllush()
{
	if (m_file == NULL)
	{
		return false;
	}
	if (EOF == fflush(m_file))
	{
		return false;
	}
	else
	{
		return true;
	}
}
bool CFileUtil::Fseek(long offset, int origin)
{
	if (m_file == NULL)
	{
		return false;
	}
	if (EOF == fseek(m_file, offset, origin))
	{
		return false;
	}
	else
	{
		return true;
	}

}

//long CFileUtil::getCurrentSeek()
//{
//	fpos_t pos;
//	fgetpos(m_file, &pos);
//	return (long)pos;
//}
