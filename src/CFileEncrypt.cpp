/*
 * CFileEncrypt.cpp
 *
 *  Created on: 2015年12月24日
 *      Author: kejun
 */
#include<emscripten.h>
#include "CFileEncrypt.h"
#include <stdio.h>
#include "Rijndael.h"
#include "KeyUtil.h"
#include <iostream>
#include "FileTypeCheck.h"
#include <sys/stat.h>
#include "EncryptMgr.h"
#include"../PiEncrypt.h"
using namespace std;

//#define _TRIVAL 0



CFileEncrypt::CFileEncrypt()
{
    // TODO Auto-generated constructor stub

}

CFileEncrypt::~CFileEncrypt()
{
    // TODO Auto-generated destructor stub
}

bool CFileEncrypt::EncryptFile(int nKeyId, const char *pszFullFileName, int &nFailCode,
                               bool NeedDog)
{
#ifdef _DEBUG
	int nRet = GetFileEncState(pszFullFileName);
	if(nRet == 1)
#else
    if (GetFileEncState(pszFullFileName) == 1)//已经加密的不再加密
#endif
    {
        nFailCode = PI_E_ENC_FILE_ALREADY_ENC;
        return false;
    }

    if (!g_KeyUtil->IsValid())
    {
        nFailCode = g_KeyUtil->GetErrCode();
        return false;
    }

    Byte szkeybuf[1024] = {0};
    int nKeyLen = 0;
    if (false == g_KeyUtil->QueryKey(nKeyId, 1024, szkeybuf, nKeyLen))
    {
    	LOGE(Logger::error,"密钥ID：%d ,密钥不存在！",nKeyId);
        nFailCode = PI_E_PKY_KEY_NOT_EXIST;
        return false;
    }

    char szKey[16] = {0};
//#ifdef _TRIVAL
//	   AppendZeroChar("Welcome to use product of picle Ltd.", 9, szKey);
//#else
    AppendZeroChar((const char *) szkeybuf, nKeyLen, szKey);
//#endif
    std::list<FileEncPosInfo> posinfolist;
    bool Result = GetFilePosInfoFromFile(pszFullFileName, posinfolist);
    if (!Result)
    {
        nFailCode = PI_E_ENC_GET_FILE_POS_ERROR;
        return false;
    }


    FILE *fin = fopen(pszFullFileName, "rb");
    if (fin == NULL)
    {
        nFailCode = PI_E_ENC_OPEN_FILE_ERROR;
        return false;
    }

    //创建一个备份文件，并加入文件头
    char pszNewFileName[1024] = {0};
    sprintf(pszNewFileName, "%s%s", pszFullFileName, "bak");
    FILE *fout = fopen(pszNewFileName, "wb");
    if (fout == NULL)
    {
        fclose(fin);
        nFailCode = PI_E_GEN_FILE_OPER_ERROR;
        return false;
    }
    //const char * pSecretKey = [SecretKey UTF8String];
    CFileHead newfilehead(nKeyId);
    newfilehead.SetFileEncPosInfo(posinfolist);
    int nMode = 0;
    g_KeyUtil->m_pclFile.GetAlgorithmMode(nMode);
    newfilehead.m_AlgorithmMode = nMode;

#ifdef _DEBUG
    cout << "newfilehead.m_encfilecount = " << newfilehead.m_encfilecount << ";" <<endl;
#endif
    Result = AddFileHead(newfilehead, fout);
    if (!Result)
    {
        fclose(fin);
        fclose(fout);
        nFailCode = PI_E_ENC_ADD_FILE_HEAD_ERROR;
        return false;
    }
#ifdef _DEBUG
    cout << "完成AddHead " << endl;
#endif
    if (posinfolist.front().ENClength > 0)
    {
        std::list<FileEncPosInfo>::iterator poss;

//	        fpos_t oldPos;
//	        fgetpos(fin, &oldPos);
        FileEncPosInfo lastEncPos;
        lastEncPos.ENCpos = 0;
        lastEncPos.ENClength = 0;

        fseek(fin, 0, SEEK_SET);
        fseek(fout, LENG_FILE_HEAD, SEEK_SET);
#ifdef _DEBUG
        cout << "开始：输入文件位置, Pos = " << ftell(fin)<< "; 输出文件的位置, Pos = " << ftell(fout) << endl;
#endif
        CEncryptMgr enc;
        enc.SetAlgorithmMode(newfilehead.GetAlgorithmMode());
        for (poss = posinfolist.begin(); poss != posinfolist.end(); poss++)
        {
            //fseek(fin , lastEncPos, SEEK_SET);
            //复制不需要加密的部分
            unsigned long long nNoEncLen = poss->ENCpos - lastEncPos.ENCpos - lastEncPos.ENClength;
            if (nNoEncLen != 0)
            {
                CopyFileToFile(fin, fout, pszFullFileName, nNoEncLen);
                //   Byte *szbuffer = new Byte[nNoEncLen];
                //   fread(szbuffer, sizeof(Byte), nNoEncLen, fin);
                //   fwrite(szbuffer, sizeof(Byte), nNoEncLen, fout);
                ////从源文件读需要加密段，加密后写到目标文件, 目标文件的指针在512个字节之后
                //   delete [] szbuffer;
                //   szbuffer = NULL;
#ifdef _DEBUG
                //cout << "复制不加密后的位置：输入文件的大小"<<GetFileSize(fin)<<"; 输入文件位置, Pos = " << ftell(fin)<< "; 输出文件的位置, Pos = " << ftell(fout) << endl;
#endif
            }
            Byte *buffer = new Byte[poss->ENClength];
            memset(buffer, 0x00, sizeof(Byte) * poss->ENClength);
            int nReadLen = fread(buffer, sizeof(Byte), poss->ENClength, fin);
#ifdef _DEBUG
            cout << "   读加密后的位置：读出字节数" <<nReadLen<< "; sizeof(Byte) = " <<sizeof(Byte)<< "; 输入文件位置, Pos = " << ftell(fin)<< "; 输出文件的位置, Pos = " << ftell(fout) << endl;
#endif
            char *encBuffer = new char[poss->ENClength];
            memset(encBuffer, 0, poss->ENClength);

            //Rijndael_Go(encBuffer, (char *) buffer, poss->ENClength, szKey, 16, false);
            enc.Encrypt((BYTE *)szKey,(BYTE *)buffer,(BYTE *)encBuffer,poss->ENClength);

            //fseek(fin, poss->ENCpos, SEEK_SET);
            int nRet = (int) fwrite(encBuffer, sizeof(char), poss->ENClength, fout);
            if (nRet != (int) poss->ENClength)
            {
                nFailCode = PI_E_ENC_WRITE_FILE_ERROR;
                delete[] buffer;
                delete[] encBuffer;
                fclose(fin);
                fclose(fout);
                return false;
            }
#ifdef _DEBUG
            cout << "   写加密后的位置：写入字节数" <<nRet<< "; 输入文件位置, Pos = " << ftell(fin)<< "; 输出文件的位置, Pos = " << ftell(fout) << endl;
#endif
            delete[] buffer;
            delete[] encBuffer;

            lastEncPos.ENCpos = poss->ENCpos;
            lastEncPos.ENClength = poss->ENClength;
#ifdef _DEBUG
            cout << "复制加密后的位置：输入文件位置, Pos = " << ftell(fin)<< "; 输出文件的位置, Pos = " << ftell(fout) << endl;
#endif
        }
        //复制剩余的部分
        CopyFileToFile(fin, fout,pszFullFileName);
        fseek(fout, 0L, SEEK_SET);
        fseek(fin, 0L, SEEK_SET);                        //将文件指针指向文件头
    }
    else
    {
        fseek(fout, 0L, SEEK_END);
        fseek(fin, 0L, SEEK_SET);
        CopyFileToFile(fin, fout,pszFullFileName);
    }
#ifdef _DEBUG
    //long int filesize = GetFileSize(fin);
    //cout<<"After Encrypt Filesize: "<<filesize<<endl;
#endif
    fflush(fout);
    fflush(fin);
    fclose(fin);
    fclose(fout);
//	    newfilehead.SetFileEncPosInfo(posinfolist);
//	    Result = AddFileHead(newfilehead, pszFullFileName);
//	    if (Result == false)
//	    {
//	        nFailCode = 4;
//	        return false;
//	    }
    if (remove(pszFullFileName) != 0)
    {
#ifdef _DEBUG
        cout<<"AddFileHead: remove失败"<<endl;
#endif
        nFailCode = PI_E_GEN_FILE_OPER_ERROR;
        return false;
    }
    if (rename(pszNewFileName, pszFullFileName) != 0)
    {
#ifdef _DEBUG
        cout<<"AddFileHead: rename失败"<<endl;
#endif
        nFailCode = PI_E_GEN_FILE_OPER_ERROR;
        return false;
    }

    nFailCode = PI_S_SUCCESS;
    return true;
}

long CFileEncrypt::GetFileEncState(const char *pszFullFileName)
{
    FILE *fp = fopen(pszFullFileName, "rb");
    if (fp == NULL)
    {
        return -2;
    }


   // unsigned long long filesize = GetFileSize(fp);
    unsigned long long filesize = GetFileSize(pszFullFileName);
    if (filesize < LENG_FILE_HEAD)
    {
        fclose(fp);
        return 0;
    }

    if (fseek(fp, 0L, SEEK_SET) == -1)
    {
        return -1;
    }

    Byte *buff = new Byte[LENG_FILE_HEAD];
    size_t numread = fread(buff, sizeof(Byte), LENG_FILE_HEAD, fp);
    if (LENG_FILE_HEAD != (unsigned long int) numread)
    {
        fclose(fp);
        delete[] buff;
        return -1;
    }
    fclose(fp);

    CFileHead filehead;

    if (filehead.IsLegalFileHead(buff) == false)
    {
        return 0;
    }

    return 1;
}


bool CFileEncrypt::DecryptFile(const char *pszFullFileName, int &nFailCode, bool NeedDog)
{
    if (GetFileEncState(pszFullFileName) != 1)
    {
        nFailCode = PI_E_DEC_FILE_NOT_ENC;
        return false;
    }

    if (false == g_KeyUtil->IsValid())
    {
        nFailCode = g_KeyUtil->GetErrCode();
        return false;
    }

//#ifdef _TRIVAL
//	   AppendZeroChar("Welcome to use product of picle Ltd.", 9, szKey);
//#else
//	   AppendZeroChar(pszSecretKey, nKeyLen, szKey);
//#endif

    FILE *fin = fopen(pszFullFileName, "rb");
    if (fin == NULL)
    {
        nFailCode = PI_E_GEN_FILE_OPER_ERROR;
        return false;
    }

    //创建一个备份文件，并加入文件头
    char pszNewFileName[1024] = {0};
    sprintf(pszNewFileName, "%s%s", pszFullFileName, "bak");
    FILE *fout = fopen(pszNewFileName, "wb");
    if (fout == NULL)
    {
        fclose(fin);
        nFailCode = PI_E_GEN_FILE_OPER_ERROR;
        return false;
    }
    //读文件头
    Byte *headBuffer = new Byte[LENG_FILE_HEAD];
    int nRet = fread(headBuffer, sizeof(Byte), LENG_FILE_HEAD, fin);
    if (nRet != LENG_FILE_HEAD)
    {
        nFailCode = PI_E_DEC_GET_FILE_HEAD_ERROR;
        fclose(fin);
        fclose(fout);
        delete[] headBuffer;
        return false;
    }

    CFileHead newfilehead;
    std::list<FileEncPosInfo> posinfolist;
    newfilehead.ReadFromMem(headBuffer);

    //获取待解密文件的密钥号，并从PKY中查询对应的密钥
    Byte szKeybuf[1024] = {0};
    int nKeyLen = 0;
    char szKey[16] = {0};
    int nKeyId = newfilehead.GetKeyVer();
    if (!g_KeyUtil->QueryKey(nKeyId, 1024, szKeybuf, nKeyLen))
    {
        nFailCode = PI_E_PKY_KEY_NOT_EXIST;
        return  false;
    }

	//序列号检查先去掉，PCL在华为手机上无法正常解密

    if (!newfilehead.IsSameProductKey(szKeybuf, nKeyLen))
    {
        nFailCode = PI_E_PCL_PRODUCT_KEY_UNMATCH;
        return false;
    }
    AppendZeroChar((const char *)szKeybuf, nKeyLen, szKey);//截断或者补全密钥到16个字节，128位
    newfilehead.GetFileEncPosInfo(posinfolist);

    if (posinfolist.front().ENClength > 0)
    {
        std::list<FileEncPosInfo>::iterator poss;

        FileEncPosInfo lastEncPos;
        lastEncPos.ENCpos = 0;
        lastEncPos.ENClength = 0;

        fseek(fin, LENG_FILE_HEAD, SEEK_SET);
        fseek(fout, 0, SEEK_SET);
#ifdef _DEBUG
        cout << "开始：输入文件位置, Pos = " << ftell(fin)<< "; 输出文件的位置, Pos = " << ftell(fout) << endl;
#endif
        CEncryptMgr enc;
        enc.SetAlgorithmMode(newfilehead.GetAlgorithmMode());
        for (poss = posinfolist.begin(); poss != posinfolist.end(); poss++)
        {
            //fseek(fin , lastEncPos, SEEK_SET);
            //复制不需要加密的部分
            unsigned long long nNoEncLen = poss->ENCpos - lastEncPos.ENCpos - lastEncPos.ENClength;
            
            if (nNoEncLen != 0)
            {
                CopyFileToFile(fin, fout, pszFullFileName,nNoEncLen);

#ifdef _DEBUG
              //  cout << "复制不解密后的位置：输入文件的大小"<<GetFileSize(fin)<<"; 输入文件位置, Pos = " << ftell(fin)<< "; 输出文件的位置, Pos = " << ftell(fout) << endl;
#endif
            }
            Byte *buffer = new Byte[poss->ENClength];
            memset(buffer, 0x00, sizeof(Byte) * poss->ENClength);
            int nReadLen = fread(buffer, sizeof(Byte), poss->ENClength, fin);
#ifdef _DEBUG
            cout << "   读解密后的位置：读出字节数" <<nReadLen<< "; sizeof(Byte) = " <<sizeof(Byte)<< "; 输入文件位置, Pos = " << ftell(fin)<< "; 输出文件的位置, Pos = " << ftell(fout) << endl;
#endif
            char *encBuffer = new char[poss->ENClength];
            memset(encBuffer, 0, poss->ENClength);

            enc.Decrypt((PBYTE)szKey,(PBYTE)buffer,(PBYTE)encBuffer,poss->ENClength);
            //Rijndael_Go(encBuffer, (char *) buffer, poss->ENClength, szKey, 16, true);
            //fseek(fin, poss->ENCpos, SEEK_SET);
            encBuffer[poss->ENClength]='\0';
//            cout<<"写入的解密数据："<<encBuffer<<endl;
            int nRet = (int) fwrite(encBuffer, sizeof(char), poss->ENClength, fout);
            if (nRet != (int) poss->ENClength)
            {
                nFailCode = PI_E_GEN_FILE_OPER_ERROR;
                delete[] buffer;
                delete[] encBuffer;
                fclose(fin);
                fclose(fout);
                return false;
            }
#ifdef _DEBUG
            cout << "   写解密后的位置：写入字节数" <<nRet<< "; 输入文件位置, Pos = " << ftell(fin)<< "; 输出文件的位置, Pos = " << ftell(fout) << endl;
#endif
            delete[] buffer;
            delete[] encBuffer;

            lastEncPos.ENCpos = poss->ENCpos;
            lastEncPos.ENClength = poss->ENClength;
#ifdef _DEBUG
            cout << "复制解密后的位置：输入文件位置, Pos = " << ftell(fin)<< "; 输出文件的位置, Pos = " << ftell(fout) << endl;
#endif
        }
        //复制剩余的部分
        CopyFileToFile(fin, fout,pszFullFileName);
        fseek(fout, 0L, SEEK_SET);
        fseek(fin, 0L, SEEK_SET);                        //将文件指针指向文件头
    }
    else
    {
        fseek(fout, 0L, SEEK_SET);
//        fseek(fin, 0L, SEEK_SET);
        CopyFileToFile(fin, fout,pszFullFileName);
    }
    fclose(fin);
    fclose(fout);

    if (remove(pszFullFileName) != 0)
    {
#ifdef _DEBUG
        cout<<"AddFileHead: remove失败"<<endl;
#endif
        nFailCode = PI_E_GEN_FILE_OPER_ERROR;
        return false;
    }
    if (rename(pszNewFileName, pszFullFileName) != 0)
    {
#ifdef _DEBUG
        cout<<"AddFileHead: rename失败"<<endl;
#endif
        nFailCode = PI_E_GEN_FILE_OPER_ERROR;
        return false;
    }

    nFailCode = PI_S_SUCCESS;
    return true;
}


bool CFileEncrypt::DecFileInMem(Byte *pSourceFileMem,
                                int Sourcelen, Byte *pDesFileMem, int &DecMemLen, int &nFailcode)
{
    if (IsMemEnc(pSourceFileMem, Sourcelen) != 1)
    {
        nFailcode = PI_E_DEC_FILE_NOT_ENC;
        return false;
    }
    if (false == g_KeyUtil->IsValid())
    {
        nFailcode = g_KeyUtil->GetErrCode();
        return false;
    }
//#ifdef _TRIVAL
//    AppendZeroChar("Welcome to use product of picle Ltd.", 9, szKey);
//#else
//    AppendZeroChar(pszSecretKey, nKeyLen, szKey);
//#endif

    memcpy(pDesFileMem, pSourceFileMem + LENG_FILE_HEAD, Sourcelen - LENG_FILE_HEAD);

    CFileHead filehead;
    filehead.ReadFromMem(pSourceFileMem);

    //获取待解密文件的密钥号，并从PKY中查询对应的密钥
    Byte szKeybuf[1024] = {0};
    int nKeyLen = 0;
    char szKey[16] = {0};
    int nKeyId = filehead.GetKeyVer();
    if (!g_KeyUtil->QueryKey(nKeyId, 1024, szKeybuf, nKeyLen))
    {
        nFailcode = PI_E_PKY_KEY_NOT_EXIST;
        return  false;
    }

    if (!filehead.IsSameProductKey(szKeybuf, nKeyLen))
    {
        nFailcode = PI_E_PCL_PRODUCT_KEY_UNMATCH;
        return false;
    }


    AppendZeroChar((const char *)szKeybuf, nKeyLen, szKey);//截断或者补全密钥到16个字节，128位

    std::list<FileEncPosInfo> posinfolist;
    filehead.GetFileEncPosInfo(posinfolist);

    //const char * pSecretKey = [SecretKey UTF8String];

    std::list<FileEncPosInfo>::iterator poss;

    CEncryptMgr enc;
    enc.SetAlgorithmMode(filehead.GetAlgorithmMode());
    for (poss = posinfolist.begin(); poss != posinfolist.end(); poss++)
    {
        unsigned long setpos = poss->ENCpos;

        Byte *pdecfilecon = new Byte[poss->ENClength];
        memset(pdecfilecon, 0, poss->ENClength);

        //Rijndael_Go((char *) pdecfilecon, (char *) pDesFileMem + setpos, poss->ENClength, szKey, 16,
        //            true);

        enc.Decrypt((PBYTE)szKey,(PBYTE)pDesFileMem + setpos,(PBYTE)pdecfilecon,poss->ENClength);

        memcpy(pDesFileMem + setpos, pdecfilecon, poss->ENClength);

        delete[] pdecfilecon;

    }

    DecMemLen = Sourcelen - LENG_FILE_HEAD;
    nFailcode = PI_S_SUCCESS;
    return true;

}

bool CFileEncrypt::EncFileInMem(int nKeyId,Byte * pSourceFileMem, int Sourcelen,  Byte * pDesFileMem, int & EncMemLen, int & nFailcode)
{
    if (IsMemEnc(pSourceFileMem, Sourcelen) == 1)
    {
        nFailcode = PI_E_ENC_FILE_ALREADY_ENC;
        return false;
    }
    if (false == g_KeyUtil->IsValid())
    {
        nFailcode = g_KeyUtil->GetErrCode();
        return false;
    }

    Byte szkeybuf[1024] = {0};
    int nKeyLen = 0;
    if (false == g_KeyUtil->QueryKey(nKeyId, 1024, szkeybuf, nKeyLen))
    {
        nFailcode = PI_E_PKY_KEY_NOT_EXIST;
        return false;
    }

    char szKey[16] = {0};
    AppendZeroChar((const char *) szkeybuf, nKeyLen, szKey);
    std::list<FileEncPosInfo> posinfolist;
    bool Result = GetFilePosInfoFromFile(pSourceFileMem,Sourcelen, posinfolist);
    if (!Result)
    {
        nFailcode = PI_E_ENC_GET_FILE_POS_ERROR;
        return false;
    }

    CFileHead newFileHead(nKeyId);
    newFileHead.SetFileEncPosInfo(posinfolist);
    int nMode;
    g_KeyUtil->m_pclFile.GetAlgorithmMode(nMode);
    newFileHead.m_AlgorithmMode = nMode;
    //newFileHead.AddProductKey();
    newFileHead.WriteToMem(pDesFileMem);

    memcpy(pDesFileMem + LENG_FILE_HEAD, pSourceFileMem , Sourcelen);

    std::list<FileEncPosInfo>::iterator poss;
    CEncryptMgr enc;
    enc.SetAlgorithmMode(newFileHead.GetAlgorithmMode());
    for (poss = posinfolist.begin(); poss != posinfolist.end(); poss++)
    {
        unsigned long setpos = poss->ENCpos;

        Byte *pencfilecon = new Byte[poss->ENClength];
        memset(pencfilecon, 0, poss->ENClength);

//        Rijndael_Go((char *) pencfilecon, (char *) pDesFileMem +LENG_FILE_HEAD + setpos, poss->ENClength, szKey, 16,
//                    false);

        enc.Encrypt((PBYTE)szKey,(PBYTE)pDesFileMem +LENG_FILE_HEAD + setpos,(PBYTE)pencfilecon,poss->ENClength);
        memcpy(pDesFileMem +LENG_FILE_HEAD+ setpos, pencfilecon, poss->ENClength);

        delete[] pencfilecon;

    }

    EncMemLen = Sourcelen + LENG_FILE_HEAD;
    nFailcode = PI_S_SUCCESS;
    return true;

}

long CFileEncrypt::IsMemEnc(Byte *pMem, int Memlen)
{
    if (Memlen < LENG_FILE_HEAD)
        return 0;

    CFileHead filehead;

    if (filehead.IsLegalFileHead(pMem) == false)
    {
        return 0;
    }

    return 1;
}

bool CFileEncrypt::SetConfigPath(const char *pszConfigPath,int &nErrCode)
{
    if(g_KeyUtil == NULL)
    {
        char* cfgPath = new char[1024];
        strcpy(cfgPath,pszConfigPath);
        g_KeyUtil =new CKeyUtil(cfgPath);
    }
    g_KeyUtil->SetPclPath(pszConfigPath);
    g_KeyUtil->SetPkyPath(pszConfigPath);
	bool bRet = g_KeyUtil->Initialize();
	if(!bRet)
	{
		LOGE(Logger::error,"g_KeyUtil初始化失败");
		nErrCode = g_KeyUtil->GetErrCode();
	}
	else
	{
		nErrCode = PI_S_SUCCESS;
	}
	return bRet;
}

bool  CFileEncrypt::ExtractFilePath(const std::string &strFullFileName,    //一个文件的全路径名
                                    std::string &strFilePath)
{
    //针对c:\d\a.txt
    unsigned int nPosBackslashes = strFullFileName.find_last_of('\\');
    //针对c:\d/a.txt
    unsigned int nPosForwardslash = strFullFileName.find_last_of('/');
    //针对c:a.txt c盘的当前目录的a.txt
    unsigned int nPos = strFullFileName.find_last_of(':');

    //取最后一个\/:
    if (nPosBackslashes > nPos)
        nPos = nPosBackslashes;
    if (nPosForwardslash > nPos)
        nPos = nPosForwardslash;

    if (std::string::npos == nPos)
    {
        strFilePath = "";
        return false;
    }
    else
    {
        strFilePath = strFullFileName.substr(0, nPos);
        return true;
    }
}

//提取文件名
bool  CFileEncrypt::ExtractFileName(const std::string &strFullFileName,    //一个文件的全路径名
                                    bool bNeedExt,            //是否输出后缀名
                                    std::string &strFileName)
{
    //针对c:\d\a.txt
    int nPosBackslashes = strFullFileName.find_last_of('\\');
    //针对c:\d/a.txt
    int nPosForwardslash = strFullFileName.find_last_of('/');
    //针对c:a.txt c盘的当前目录的a.txt
    int nPos = strFullFileName.find_last_of(':');

    //取最后一个\/:
    if (nPosBackslashes > nPos)
        nPos = nPosBackslashes;
    if (nPosForwardslash > nPos)
        nPos = nPosForwardslash;

    bool bSuc = (std::string::npos != nPos);
    if (bSuc)
        strFileName = strFullFileName.substr(nPos + 1);
    else
        strFileName = strFullFileName;

    if (!bNeedExt)
    {
        nPos = strFileName.rfind('.');
        if (std::string::npos == nPos)
        {
            //bSuc = false ;
        }
        else
        {
            strFileName = strFileName.substr(0, nPos);
        }
    }

    return bSuc;
}

//组合文件路径
//返回值为strFilePath + strFileName
//在内部算法上只对两者衔接处的斜杠和反斜杠进行处理
std::string  CFileEncrypt::UnionFilePath(const std::string &strFilePath,
                                         const std::string &strFileName)
{
    std::string strFilePathName;

    if (strFilePath.length() == 0)
    {
        return strFileName;
    }
    else
    {
        if (strFileName.length() == 0)
            return strFilePath;

        char chLast, chFirst;

        chLast = strFilePath.at(strFilePath.length() - 1);
        chFirst = strFileName.at(0);

        if (chLast == '\\' || chLast == '/')
        {
            if (chFirst == '\\' || chFirst == '/')
            {
                strFilePathName = strFilePath + strFileName.substr(1, strFileName.length() - 1);
            }
            else
            {
                strFilePathName = strFilePath + strFileName;
            }
        }
        else
        {
            if (chFirst == '\\' || chFirst == '/')
            {
                strFilePathName = strFilePath + strFileName;
            }
            else
            {
                strFilePathName = strFilePath + "\\" + strFileName;
            }
        }
    }

    return strFilePathName;
}

bool CFileEncrypt::GetFilePosInfoFromFile(std::string filename,
                                          std::list<FileEncPosInfo> &PosinfoList)
{
    FILE *fp = fopen(filename.c_str(), "rb");
    if (fp == NULL)
    {
        return false;
    }
    //unsigned long filesize = GetFileSize(fp);
    unsigned long filesize = GetFileSize(filename.c_str());
    fclose(fp);
#ifdef _DEBUG
    cout<<"原始文件长度， filesize="<<filesize<<endl;
#endif
    //区分加密强度
    int iEncMode = g_KeyUtil->GetEncMode();   //加密强度
    CTextFileCheck txtCheck1;
    CRepairFileCheck repair;
    bool bGetUnitSuc = false;
    switch (iEncMode)
    {
        //普通模式
        case ENC_OPDINARY:
            bGetUnitSuc = GetFileModelEncUnit(filesize, PosinfoList);
            break;
            //强
        case ENC_STRONG:
        {
            if(txtCheck1.IsTextFile(filename) || repair.isRepairFile(filename))
                bGetUnitSuc = GetAllEncUnit(filesize,PosinfoList);
            else
                bGetUnitSuc = GetFileStrongEncUnit(filesize,PosinfoList);
        }
            break;
            //中等模式
        case ENC_MEDIUM:
        default://无标志（兼容旧版本）按普通模式
        {
            if(txtCheck1.IsTextFile(filename) || repair.isRepairFile(filename))	//判断文件是否是文本文件  或者 是否是可修复文件
                bGetUnitSuc = GetAllEncUnit(filesize,PosinfoList);
            else
                bGetUnitSuc = GetFileModelEncUnit(filesize, PosinfoList);
        }
            break;
    }


    return true;
}

bool CFileEncrypt::GetFilePosInfoFromFile(Byte *pMem,int length,
                                          std::list<FileEncPosInfo> &PosinfoList)
{
    return GetFileModelEncUnit(length, PosinfoList);
}

bool CFileEncrypt::GetFileModelEncUnit(DWORD nFileLen,list<FileEncPosInfo> &sEncUnit)
{
    unsigned long sectnum, numonesect;
    unsigned long levelegth, dolegth, distance = 0;
    FileEncPosInfo tempposinfo;
    if (nFileLen <= NOSECT_FILESIZE)        //文件大小小于等于3000个字节
    {
        sectnum = 1;
        numonesect = nFileLen - nFileLen % 16;
    }
    else                                        //文件大小大于3000个字节
    {
        sectnum = SECTNUM_OF_ENC;
        numonesect = NUM_OF_ONESECT;
        levelegth = nFileLen % 1000;
        dolegth = nFileLen - levelegth;
        distance = dolegth / sectnum;
    }

    for (unsigned long i = 0; i < sectnum; i++)
    {
        tempposinfo.ENCpos = distance * i;
        tempposinfo.ENClength = numonesect;                   //临���给定长度128
        sEncUnit.push_back(tempposinfo);
#ifdef _DEBUG
        cout<<"文件加密段， ENCpos="<<tempposinfo.ENCpos<<"; ENClength"<<tempposinfo.ENClength<<endl;
#endif
    }
    return true;
}

bool CFileEncrypt::GetAllEncUnit(unsigned long nFileLen,std::list<FileEncPosInfo> &sEncUnit)
{
    if (nFileLen == 0)
    {
        return true;
    }

    //全文加密最大加密长度
    if(nFileLen > LENGTH_OF_MAXENC)
        nFileLen = LENGTH_OF_MAXENC;

    FileEncPosInfo tempEncUnit;
    tempEncUnit.ENCpos = 0;
    tempEncUnit.ENClength = nFileLen - nFileLen%16;
    sEncUnit.push_back(tempEncUnit);
    return true;
}

bool CFileEncrypt::GetFileStrongEncUnit(unsigned long nFileLen,list<FileEncPosInfo> &sEncUnits)
{
    if (nFileLen == 0) {
        return true;
    }
    FileEncPosInfo tempEncUnit;
    unsigned int nEncUnitLen = ENC_UNIT_LEN;
    unsigned long nCount = 0;
    unsigned long nDistance = 0;

    if (nFileLen <= LENGTH_OF_MINFIRSTENC)        //下限3M
    {
        nCount = 1;
        nEncUnitLen = nFileLen - nFileLen % 16;
        tempEncUnit.ENCpos = 0;
        tempEncUnit.ENClength = nEncUnitLen;
        sEncUnits.push_back(tempEncUnit);
    } else {
        DWORD dwFirstEncLen = nFileLen / 100;		//1%的长度
        dwFirstEncLen = dwFirstEncLen - dwFirstEncLen % 16;
        if(dwFirstEncLen < LENGTH_OF_MINFIRSTENC)
            dwFirstEncLen = LENGTH_OF_MINFIRSTENC;
        if(nFileLen - dwFirstEncLen > ENC_UNIT_CONT * ENC_UNIT_LEN)	//首段加密之后，剩余文件长度足够剩下的19段加密
        {
            nCount = ENC_UNIT_CONT;
            int nRestLen = nFileLen - dwFirstEncLen - (ENC_UNIT_CONT - 1) * ENC_UNIT_LEN;
            nDistance = nRestLen / (ENC_UNIT_CONT - 1);
            nDistance = nDistance - nDistance%16;		//间距是16的倍数，加密段的起始位置也总是16的倍数，在内存映射读取文件时，由于偏移是64K的倍数，因此解密内容时不会存在偏移的问题

            for (DWORD i = 0 ; i < nCount ;i++)
            {
                if(i == 0)
                {
                    tempEncUnit.ENCpos = 0;
                    tempEncUnit.ENClength = dwFirstEncLen;
                }
                else
                {
                    tempEncUnit.ENCpos = dwFirstEncLen + i * nDistance + ENC_UNIT_LEN * (i - 1);
                    tempEncUnit.ENClength = ENC_UNIT_LEN;
                }

                sEncUnits.push_back(tempEncUnit);
            }
        }
        else
        {
            //剩余长度不足加密19*128时，忽略剩余内容，不加密
            tempEncUnit.ENCpos = 0;
            tempEncUnit.ENClength = dwFirstEncLen;
            sEncUnits.push_back(tempEncUnit);
        }
    }
    return true;
}

bool CFileEncrypt::GetEncUnit(unsigned long fileLen,std::string filename, std::list<FileEncPosInfo> & PosinfoList)
{
    return true;
}

unsigned long long CFileEncrypt::GetFileSize(const char* filename)
{
//    long long cur_pos = ftell(fp);
//
//    if (cur_pos == -1)
//    {
//        return -1;
//    }
//    if (fseeko(fp, 0L, SEEK_END) == -1)
//    {
//        return -1;
//    }
//    // get file size.
//    unsigned long long filesize = ftell(fp);
//    fseek(fp, cur_pos, SEEK_SET);//还原文件的位置
//    LOGE(Logger::info,"CopyFileToFile filesize %lld",filesize);



//    struct stat64 statbuf;
//    stat64(filename,&statbuf);
//    unsigned long long filesize=statbuf.st_size;

	int filesize=0;
	FILE* fp=fopen(filename,"r");
	if(fp)
	{
		fseek(fp,0,SEEK_END);
		filesize=ftell(fp);
		fclose(fp);
	}
    return filesize;
}

bool CFileEncrypt::AddFileHead(CFileHead filehead, FILE *fp)
{
    if (fp == NULL)
        return false;
    char *pHeadMem = new char[LENG_FILE_HEAD];
    bool bRet = filehead.WriteToMem((Byte *) pHeadMem);
    if (!bRet)
    {
        delete[] pHeadMem;
        fclose(fp);
        //fclose(fin);
#ifdef _DEBUG
        //cout<<"AddFileHead: filehead.WriteToMem失败"<<endl;
#endif
        return false;
    }

    int nRet = (int) fwrite(pHeadMem, sizeof(char), LENG_FILE_HEAD, fp);
    if (nRet != LENG_FILE_HEAD)
    {
#ifdef _DEBUG
        //cout<<"AddFileHead: fwrite失败"<<endl;
#endif
        delete[] pHeadMem;
        //fclose(fp);
        //fclose(fin);
        return false;
    }
    delete[] pHeadMem;
    return true;
}

/*
bool CFileEncrypt::AddFileHead(CFileHead filehead, std::string strFullFileName)
{

//    std::string  strFilePath, strFileName;

//    bool suc = ExtractFilePath(strFullFileName, strFilePath);
//    if (suc != true)
//    {
//#ifdef _DEBUG
//    	cout<<"AddFileHead: ExtractFilePath失败"<<endl;
//#endif
//       return false;
//    }
    //NSString * path = [NSString stringWithUTF8String:strfilepath.c_str()];

//    suc = ExtractFileName(strFullFileName, true, strFileName);
//   if (suc != true)
//    {
//#ifdef _DEBUG
//    	cout<<"AddFileHead: ExtractFileName失败"<<endl;
//#endif
//        return false;
//    }

    //strFileName += "encbak";
    std::string strNewFullName = strFullFileName + "encbak";
    FILE *fout = fopen(strNewFullName.c_str(), "wb");
    if(fout == NULL)
    {
#ifdef _DEBUG
    	cout<<"AddFileHead: fopen(fout)失败, strNewFullName = "<<strNewFullName<<endl;
#endif
    	return false;
    }

    FILE *fin = fopen(strFullFileName.c_str(), "rb");
    if(fin == NULL)
    {
#ifdef _DEBUG
    	cout<<"AddFileHead: fopen(fin)失败"<<endl;
#endif
    	fclose(fout);
    	return false;
    }

    char * pHeadMem = new  char[LENG_FILE_HEAD];
    bool bRet = filehead.WriteToMem((Byte *)pHeadMem);
    if(!bRet)
    {
    	delete [] pHeadMem;
    	fclose(fout);
    	fclose(fin);
#ifdef _DEBUG
    	cout<<"AddFileHead: filehead.WriteToMem失败"<<endl;
#endif
    	return false;
    }

    int nRet = (int)fwrite(pHeadMem, sizeof(char), LENG_FILE_HEAD, fout);
    if(nRet != LENG_FILE_HEAD)
    {
#ifdef _DEBUG
    	cout<<"AddFileHead: fwrite失败"<<endl;
#endif
    	delete [] pHeadMem;
    	fclose(fout);
    	fclose(fin);
    	return false;
    }
    delete [] pHeadMem;

    if(!CopyFileToFile(fin, fout))
    {
#ifdef _DEBUG
    	cout<<"AddFileHead: CopyFileToFile失败"<<endl;
#endif
    	fclose(fin);
    	fclose(fout);
    	return false;
    }
    fclose(fin);
    fclose(fout);

    if(remove(strFullFileName.c_str()) != 0)
    {
#ifdef _DEBUG
    	cout<<"AddFileHead: remove失败"<<endl;
#endif
    	return false;
    }
    if(rename(strNewFullName.c_str(), strFullFileName.c_str()) != 0)
    {
#ifdef _DEBUG
    	cout<<"AddFileHead: rename失败"<<endl;
#endif
    	return false;
    }
    return  true;

}
*/
bool CFileEncrypt::DeleteFileHead(std::string strFullFileName)
{
    /*
    std::string  strFilePath, strFileName;

    bool suc = ExtractFilePath(strFullFileName, strFilePath);
    if (suc != true)
        return false;

    //NSString * path = [NSString stringWithUTF8String:strfilepath.c_str()];

    suc = ExtractFileName(strFullFileName, true, strFileName);
    if (suc != true)
        return false;
*/
    //strFileName += "decbak";
    std::string strNewFullName = strFullFileName + "decbak";
    FILE *fout = fopen(strNewFullName.c_str(), "wb");
    if (fout == NULL)
        return false;

    FILE *fin = fopen(strFullFileName.c_str(), "rb");
    if (fin == NULL)
    {
        fclose(fout);
        return false;
    }

    if (!CopyFileToFile(fin, fout,strFullFileName.c_str()))
    {
        fclose(fin);
        fclose(fout);
        return false;
    }

    fclose(fin);
    fclose(fout);

    if (remove(strFullFileName.c_str()) != 0)
        return false;
    if (rename(strNewFullName.c_str(), strFullFileName.c_str()) != 0)
        return false;

    return true;
}

bool CFileEncrypt::CopyFileToFile(FILE *fin, FILE *fout,const char* pszFullFileName,unsigned long long nCopySize)
{
    if (fin == NULL || fout == NULL)
        return false;
    unsigned long int filesize;
    if (nCopySize == 0)
    {
       // filesize = GetFileSize(fin);
        filesize = GetFileSize(pszFullFileName);
        unsigned long long filepos = ftell(fin);
        filesize -= filepos;

    }
    else
    {
        filesize = nCopySize;
    }

    Byte *buff = new Byte[READLEN];
    memset(buff, 0x00, READLEN * sizeof(Byte));
    unsigned long long readlen = 0;
    unsigned long long sublen;

    while (READLEN < (sublen = filesize - readlen))
    {
        fread(buff, sizeof(Byte), READLEN, fin);
        fwrite(buff, sizeof(Byte), READLEN, fout);
        readlen += READLEN;
    }
    if (sublen > 0)
    {
        fread(buff, sizeof(Byte), sublen, fin);
        fwrite(buff, sizeof(Byte), sublen, fout);
    }
    delete[] buff;
    return true;
}

int CFileEncrypt::AppendZeroChar(const char *inchar, int nCharLen, char *outchar)
{
    int nKeyLen = 16;
    if (nCharLen >= nKeyLen)
    {
        memcpy(outchar, inchar, nKeyLen);
        return nKeyLen;
    }
    memset(outchar, 0, nKeyLen);
    memcpy(outchar, inchar, nCharLen);
    memcpy(outchar,inchar ,nCharLen);
    return nKeyLen;
}

bool CFileEncrypt::ReEncryptFile(const char *pszFullFileName) {

    return false;
}
/*
char *CFileEncrypt::GetSdcardPath()
{
    char caStdOutLine[1024]; // mount 命令的标准输出中的一行信息
    char* pcTmpSDPath = NULL;

// 再用 mount 命令获得的找身份认证锁
    do // 非循环，只是为了方便控制分支层次，便于控制分支流向
    {
        // 通过创建一个管道，调用 fork 产生一个子进程，
        // 执行一个 shell 以运行命令来开启一个进程。
        // 这个进程必须由 pclose() 函数关闭。
        FILE* fp = popen( "mount", // 一个指向以 NULL 结束��� shell 命令字符串的指针，
                // 这行命令将被传到 bin/sh 并使用 -c 标志，
                // 那么 shell 将执行这个命令从这个字符串中读取。
                          "r" );   // 文件指针连接到 shell 命令的标准输出

        if ( NULL == fp )
        {
            break;
        }

        while( NULL != fgets( caStdOutLine,
                              sizeof( caStdOutLine ),
                              fp ) )
        {
            // 如果 找到了你想要的 SD 卡挂载路径 的话，则
//            if ( 判断条件 )
//            {
//                // 注：管道中的数据一定要读完，不然会崩溃掉的
//                continue; // 就不再试下一个挂载地址了
//            }

            // 如果该行内有 /mnt/和 vfat 字符串，说明可能是内/外置 SD 卡的挂载路径
            if ( NULL == strstr( caStdOutLine, " /mnt/" ) &&    // 前面要有空格，以防断章取义
                 NULL == strstr( caStdOutLine, " /storage/" ) ) // 前面要有空格，以防断章取义
            {
                continue; // 不满足条件说明这行不是内/外置 SD 卡的挂载路径
            }

            if ( NULL == strstr( caStdOutLine, " vfat " ) )  // 前后均有空格
            {
                continue; // 不满足条件说明这行不是内/外置 SD 卡的挂载路径
            }

            // 再以空格分隔符拆分字符串
            pcTmpSDPath = strtok( caStdOutLine, " " );

            do // 这里是循环，尝试每一个路径
            {
                if ( ( NULL == pcTmpSDPath ) ||
                     ( '\0' == *pcTmpSDPath ) )
                {
                    continue;
                }

                // 如果字符串中含有/mnt/��符串，说明可能是我们要找的 SD 卡挂载路径
                if ( NULL == strstr( pcTmpSDPath, "/mnt/" ) &&
                     NULL == strstr( pcTmpSDPath, "/storage/" ) )
                {
                    continue;
                }

                //TODO: 在此添加对 SD 卡路径使用的语句，如果只是用其中一个，别忘了设置已找到想要 SD 卡路径的标识

            }while ( pcTmpSDPath == strtok( NULL, " " ) );
        }

        // 关闭标准 I/O 流，等待命令执行结束，然后返回 shell 的终止状态。
        // 如果 shell 不能被执行，
        // 则 pclose() 返回的终止状态与 shell 已执行 exit 一样。
        pclose( fp );

    }while ( 0 );
}
*/
