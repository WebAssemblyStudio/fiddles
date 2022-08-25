#pragma once
#include <stdio.h>
#include <cstdlib>
#pragma pack(push)
#pragma pack(1)
class CFileUtil
{
public:
	CFileUtil(void);
	~CFileUtil(void);
private:
	FILE*	m_file;
	char*	m_filepath;
	bool m_bReaded;//是否读过文件
	bool m_bWritten;//是否写过文件
public:
	bool OpenFile(const char *filename,const char * mode);
	bool CloseFile();
	//获取文件路径
	size_t GetFileFullPathName(char* buffer,unsigned long nMaxLen);//返回读取到字节数

	//lpBuffer					用于保存读入数据的一个缓冲区
	//nNumberOfBytesToRead		要读入的字节数
	//lpNumberOfBytesRead		指向实际读取字节数的指针
	bool ReadFile(void * lpBuffer,unsigned long nNumberOfBytesToRead,unsigned long *lpNumberOfBytesRead);

	//lpBuffer					数据缓存区指针
	//nNumberOfBytesToWrite		你要写的字节数
	//lpNumberOfBytesWritten	用于保存实际写入字节数的存储区域的指针
	bool WriteFile(void * lpBuffer,unsigned long nNumberOfBytesToWrite,unsigned long *lpNumberOfBytesWritten);
	//获取文件大小(文件大小不能超过2G，待测试)
	bool GetFileSize(unsigned long *lpNumberOfBytesFileSize);
    
    //功 能: 清除读写缓冲区，需要立即把输出缓冲区的数据进行物理写入时
    bool Fllush();
    
    //重定位流(数据流/文件)上的文件内部位置指针,等同fseek;origin:SEEK_CUR、 SEEK_END 或 SEEK_SET
    //offset偏移量
    bool Fseek( long offset, int origin);

//	long getCurrentSeek();

};
#pragma pack(pop)
