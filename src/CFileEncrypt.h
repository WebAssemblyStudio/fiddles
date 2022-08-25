/*
 * CFileEncrypt.h
 *
 *  Created on: 2015年12月24日
 *      Author: kejun
 */

#ifndef SRC_CFILEENCRYPT_H_
#define SRC_CFILEENCRYPT_H_
#include <string>
#include <list>
#include "GlobalDefine.h"
#include "FileHead.h"
//using namespace std;


class CFileEncrypt {
public:
	CFileEncrypt();
	virtual ~CFileEncrypt();

	static bool EncryptFile(int nKeyId, const char * pszFullFileName, int &nFailCode, bool NeedDog = true);
	static long GetFileEncState(const char * pszFullFileName);
	static bool DecryptFile(const char * pszFullFileName, int &nFailCode, bool NeedDog = true);
	static bool DecFileInMem(Byte * pSourceFileMem, int Sourcelen,  Byte * pDesFileMem, int & DecMemLen, int & nFailcode);
	static bool EncFileInMem(int nKeyId,Byte * pSourceFileMem, int Sourcelen,  Byte * pDesFileMem, int & DecMemLen, int & nFailcode);
	static long IsMemEnc(Byte * pMem, int Memlen);
	static bool SetConfigPath(const char *pszConfigPath,int &nErrCode);
	static bool ReEncryptFile(const char* pszFullFileName); 	//文件重新加密
private:
	static bool  ExtractFilePath(const std::string &strFullFileName , 	//一个文件的全路径名
								  	  	  	  	  	 std::string &strFilePath);
	static bool  ExtractFileName(const std::string &strFullFileName , 	//一个文件的全路径名
								  	  	  	  	  	  bool bNeedExt , 			//是否输出后缀名
													  std::string &strFileName);
	static std::string  UnionFilePath(const std::string &strFilePath ,
								  const std::string &strFileName);
	static bool GetFilePosInfoFromFile(std::string filename, std::list<FileEncPosInfo> & PosinfoList);

	static bool GetFilePosInfoFromFile(Byte *pMem,int length, std::list<FileEncPosInfo> &PosinfoList);
	//全文加密
	static bool GetAllEncUnit(unsigned long nFileLen,std::list<FileEncPosInfo> &sEncUnit);
	static bool GetFileStrongEncUnit(unsigned long nFileLen,list<FileEncPosInfo> &sEncUnits);
    //3k 普通加密
    static bool GetFileModelEncUnit(DWORD nFileLen,list<FileEncPosInfo> &sEncUnit);

	//获取加密分级情况  fileLen 文件大小 filename 文件名称   PosinfoList 加密单元   此函数读取pcl中加密强度设置，对文件采取相应的加密方式
	static bool GetEncUnit(unsigned long fileLen,std::string filename, std::list<FileEncPosInfo> & PosinfoList);

	//static unsigned long long GetFileSize(FILE *fp);
    static unsigned long long GetFileSize(const char* filename);
	//static bool AddFileHead(CFileHead filehead, std::string strFullFileName);
	static bool AddFileHead(CFileHead filehead, FILE *fp);
	static bool DeleteFileHead(std::string strFullFileName);
	static bool CopyFileToFile(FILE * fin, FILE * fout, const char * pszFullFileName,unsigned long long nCopySize = 0);//从两个文件当前指针起复制文件, nCopySize=0时从当前复制到文件尾，否则复制该字节数

	//密钥要求16个字节，对于不满6个字节的按现在的代码，在LInux和Windows系统下都没有问题，但在Android系统下会造成密钥补全不一致
	//所以这里强制给不够长度的密钥以"0"字符(也就是0x30)补全，如果超出16个字节也会强制截断。by kejun 2016-02-17
	static int AppendZeroChar(const char *inchar, int nCharLen, char *outchar);

	bool CheckDisk(std::string &szInFileName,std::string &szOutFileName,bool IsDec );//判断磁盘空间是否足够
    //static char *GetSdcardPath();

};

#endif /* SRC_CFILEENCRYPT_H_ */
