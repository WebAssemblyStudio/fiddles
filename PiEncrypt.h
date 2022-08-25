/*
 * PiEncrypt.h
 *
 *  Created on: 2015年12月23日
 *      Author: kejun
 */

#ifndef SRC_PIENCRYPT_H_
#define SRC_PIENCRYPT_H_
#include"Logger.h"
//#define OUTLOGPATH "../../../Interface/libPiEncrypt/Debug/piencsys.err"
#define OUTLOGPATH "./piencsys.err"
#define LOGE (logger->LOG)
static Logger* logger=Logger::Instance(Logger::file,Logger::debug,OUTLOGPATH);
#define DLL_PUBLIC  __attribute__ ((visibility("default")))
#define EXPORT_FUNC extern "C" DLL_PUBLIC
//获取文件加密状态
//返回值
//0 - 未加密
//1 - 加密
//负数-未知(不知是否加密了)
EXPORT_FUNC long  PiGetFileEncState(const char * pszFullFileName);

//加密文件
//当返回值为FALSE时，nFailCode的值为错误码。
//nFailCode = 1; 取文件属性失败
//nFailCode = 2; 从文件中读取标志信息失败
//nFailCode = 3; 文件只读
//nFailCode = 4; 密钥不正确
//nFailCode = 5; 操作临时或者备份文件失败
//nFailCode = 6; 读狗失败, 请检查狗是否插好，驱动是否安装
//nFailCode = 7; 不是对应的狗，例如加密时插入的解密狗或者安装狗
//nFailCode = 10; 读写文件失败
//新增了是否需要检测狗的参数NeedDog，默认是需要检测狗
EXPORT_FUNC bool  PiEncryptFile(int nKeyId, const char * pszFullFileName, int &nFailCode, bool NeedDog = true);

//解密文件
//当返回值为FALSE时，nFailCode的值为错误码。
//nFailCode = 1; 取文件属性失败
//nFailCode = 2; 从文件中读取标志信息失败
//nFailCode = 3; 文件只读
//nFailCode = 4; 密钥不正确
//nFailCode = 5; 操作临时或者备份文件失败
//nFailCode = 6; 读狗失败, 请检查狗是否插好，驱动是否安装
//nFailCode = 7; 不是对应的狗，例如加密时插入的解密狗或者安装狗
//nFailCode = 9; 不是对应产品序列号，说明该文件可能是由别的厂家加密的
//nFailCode = 10; 读写文件失败
//新增了是否需要检测狗的参数NeedDog，默认是需要检测狗
EXPORT_FUNC bool  PiDecryptFile(const char * pszFullFileName, int &nFailCode, bool NeedDog = true);


//文件以流的方式存在于内存中，此方法解密内存中的文件流
//返回值    0表示失败
//1表示成功
EXPORT_FUNC bool  PiDecFileInMem(unsigned char * pSourceFileMem, int Sourcelen,  unsigned char * pDesFileMem, int DesMemLen, int & failcode);

//文件以流的方式存在内存中，此方法加密内存中的文件流
EXPORT_FUNC bool PiEncFileInMem(int nKeyId,unsigned char * pSourceFileMem, int Sourcelen,  unsigned char * pDesFileMem, int DesMemLen, int & failcode);


//判断内存流是否加密  仅用于文件内存流
//1表示文件内存流加密  0表示文件内存流未加密
EXPORT_FUNC long PiIsMemEnc(unsigned char * pMem, int Memlen);

EXPORT_FUNC int PiGetErrInfo(int nErrorCode, /*out*/char *pszErrInfo);

EXPORT_FUNC bool PiSetConfigPath(const char *pszPath, int &nErrCode);

#endif /* SRC_PIENCRYPT_H_ */
