/*
 * GlobalDefine.h
 *
 *  Created on: 2015年12月24日
 *      Author: kejun
 */
#ifndef SRC_GLOBALDEFINE_H_
#define SRC_GLOBALDEFINE_H_

#define Byte unsigned char
#define BYTE unsigned char
#define UINT unsigned int
#define DWORD unsigned long
#define ULONG unsigned long
#define WORD unsigned short

#define  LENG_FILE_HEAD  512
#define  keyver  88
#define  SECTNUM_OF_ENC	20
#define  NUM_OF_ONESECT	128
#define  NOSECT_FILESIZE     3000
//#define  READLEN       512
#define READLEN     1024
#define LENG_ENC_UNIT  16
#define LENG_ENC_UNIT_8 8

#define LENGTH_OF_MAXENC 100 * 1024 * 1024				//全文加密时最大加密长度，暂定100M。
#define LENGTH_OF_MINFIRSTENC 3 * 1024 * 1024			//普通加密文件第一加密段长度安装文件大小的1%计算（3M~20M）
#define ENC_UNIT_LEN 0X80
#define ENC_UNIT_CONT 20

typedef BYTE *PBYTE;

#define  MYDBUG     //标记一些调试输出
#endif /* SRC_GLOBALDEFINE_H_ */
