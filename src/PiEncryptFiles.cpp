//============================================================================
//// Name        : PiEncryptFiles.cpp
//// Author      : pi
//// Version     :
//// Copyright   : pi
//// Description : Hello World in C++, Ansi-style
////============================================================================
//
//#ifndef _DEBUG
//#define _DEBUG
//#endif
//#include <iostream>
//#include <string.h>
//#include <stdio.h>
//#include "../PiEncrypt.h"
//using namespace std;
//
//void usage();
//unsigned long int GetFileSize(FILE *fp);
//
//int main(int argc, char *argv[])
//{
//#ifdef _DEBUG
//	cout<<"argc="<<argc<<endl;
//	cout<<"argv[0]="<<argv[0]<<endl;
//	cout<<"argv[1]="<<argv[1]<<endl;
//#endif
//	if(argc <= 2)
//	{
//		usage();
//		return -1;
//	}
//	int nFlag = 10;
//	if(strcmp(argv[1], "-e") == 0)
//		nFlag = 0;
//	else if(strcmp(argv[1], "-d") == 0)
//		nFlag = 1;
//	else if(strcmp(argv[1], "-dm") == 0)
//		nFlag = 2;
//	else if(strcmp(argv[1], "-g") == 0)
//		nFlag = 3;
//	else if(strcmp(argv[1], "-i") == 0)
//		nFlag = 4;
//	else
//		nFlag = 10;
//#ifdef _DEBUG
//	cout<<"nFlag="<<nFlag<<endl;
//#endif
//	char pszSercretKey[] = "piclesoft";
//	int nKeyLen = strlen(pszSercretKey);
//	int nFailCode = -1;
//	bool bRet = false;
//	long lRet = 0;
//	switch(nFlag)
//	{
//	case 0:
//#ifdef _DEBUG
//		cout<<"开始加密，文件名："<<argv[2]<<endl;
//#endif
//		//bRet = PiEncryptFile(pszSercretKey, nKeyLen, argv[2], nFailCode, false);
//		if(bRet)
//			cout<<"加密成功！"<<endl;
//		else
//			cout<<"加密失败，失败代码:"<<nFailCode<<endl;
//		break;
//	case 1:
//		//bRet = PiDecryptFile(pszSercretKey, nKeyLen, argv[2], nFailCode, false);
//		if(bRet)
//			cout<<"解密成功！"<<endl;
//		else
//			cout<<"解密失败，失败代码:"<<nFailCode<<endl;
//		break;
//	case 2:
//		break;
//	case 3:
//		lRet = PiGetFileEncState(argv[2]);
//		if(lRet == 0)
//			cout<<"文件未加密"<<endl;
//		else if(lRet == 1)
//			cout<<"文件已加密"<<endl;
//		else
//		{
//			cout<<"未知错误"<<endl;
//		}
//		break;
//	case 4:
//		{
//			FILE *fp = fopen(argv[2], "r");
//			if(fp == NULL)
//				cout<<"打开文件失败";
//			else
//			{
//				long int lFileLen = GetFileSize(fp);
//				if(lFileLen < 512)
//				{
//					cout<<"文件未加密"<<endl;
//					fclose(fp);
//					break;
//				}
//				unsigned char *pszBuffer = new unsigned char[512 + 10];
//				memset(pszBuffer, 0x00, sizeof(unsigned char) * (512 + 10));
//				int bReadLen = fread(pszBuffer, sizeof(unsigned char), 512 + 10, fp);
//				if(bReadLen < 512)
//				{
//					cout<<"文件未加密"<<endl;
//					fclose(fp);
//				}
//				else
//				{
//					lRet = PiIsMemEnc(pszBuffer, 512 + 10);
//					if(lRet == 0)
//								cout<<"文件未加密"<<endl;
//							else if(lRet == 1)
//								cout<<"文件已加密"<<endl;
//							else
//								cout<<"未知错误"<<endl;
//				}
//				fclose(fp);
//				delete [] pszBuffer;
//			}
//		}
//		break;
//	default:
//		usage();
//		break;
//	}
//	return 0;
//}
//
//void usage()
//{
//	cout<<"命令正确使用方法:"<<endl;
//	cout<<"加密文件:PiEncryptFiles -e <filename>"<<endl;
//	cout<<"解密文件:PiEncryptFiles -d <filename>"<<endl;
//	cout<<"解密文件流, 输入文件名，读出内容调不同的接口: PiEncryptFiles -dm <filename>"<<endl;
//	cout<<"检查文件是否加密: PiEncryptFiles -g <filename>"<<endl;
//	cout<<"检查文件流是否加密: PiEncryptFiles -i <filename>"<<endl;
//}
//
//unsigned long int GetFileSize(FILE *fp)
//{
//    long cur_pos = ftell(fp);
//	if(cur_pos == -1)
//	{
//			return -1;
//	}
//
//	if(fseek(fp, 0L, SEEK_END) == -1)
//	{
//			return -1;
//	}
//	// get file size.
//	unsigned long int filesize = ftell(fp);
//	fseek(fp, cur_pos, SEEK_SET);//还原文件的位置
//	return filesize;
//}
