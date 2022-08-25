/*
 * com_pi_pilocker_piencryptfiles_libPiEncrypt_jni.cpp
 *
 *  Created on: 2016年1月21日
 *      Author: kejun
 */
#include <string.h>
#include "../com_pi_pilocker_piencryptfiles_libPiEncrypt_jni.h"
#include "../PiEncrypt.h"
#include "GlobalDefine.h"
//#define Byte unsigned char

/*
 * Class:     com_pi_pilocker_piencryptfiles_libPiEncrypt_jni
 * Method:    native_init
 * Signature: ()V
 */
JNIEXPORT jint JNICALL Java_com_pi_pilocker_piencryptfiles_libPiEncrypt_1jni_SetConfigPath
		(JNIEnv *env, jclass obj, jstring jPath)
{
    const char *strPath = env->GetStringUTFChars(jPath, 0);
    int failcode = -1;
    bool bRet = PiSetConfigPath(strPath, failcode);
    if(bRet)
    	return 0;
    else
    	return failcode;
    //PiSetConfigPath()
}

/*
 * Class:     com_pi_pilocker_piencryptfiles_libPiEncrypt_jni
 * Method:    PiGetFileEncState
 * Signature: (Ljava/lang/String;)J
 */
JNIEXPORT jlong JNICALL Java_com_pi_pilocker_piencryptfiles_libPiEncrypt_1jni_PiGetFileEncState
  (JNIEnv * env, jclass obj, jstring jMsg)
{
    const char *strMsgPtr = env->GetStringUTFChars( jMsg , 0);
    long lRet = PiGetFileEncState(strMsgPtr);
    return lRet;
}

/*
 * Class:     com_pi_pilocker_piencryptfiles_libPiEncrypt_jni
 * Method:    PiIsMemEnc
 * Signature: ([BI)J
 */
JNIEXPORT jlong JNICALL Java_com_pi_pilocker_piencryptfiles_libPiEncrypt_1jni_PiIsMemEnc
  (JNIEnv *env , jclass obj, jbyteArray memBuffer, jint bufferLen)
{
    jbyte * arrayBody = env->GetByteArrayElements(memBuffer, 0);
    //jsize theArrayLengthJ = env->GetArrayLength(memBuffer);
    Byte * Buffer = (Byte *)arrayBody;

    long lRet = PiIsMemEnc(Buffer, (int)bufferLen);
    return lRet;
}

/*
 * Class:     com_pi_pilocker_piencryptfiles_libPiEncrypt_jni
 * Method:    PiEncryptFile
 * Signature: ([BILjava/lang/String;I)Z
 */
JNIEXPORT jint  JNICALL Java_com_pi_pilocker_piencryptfiles_libPiEncrypt_1jni_PiEncryptFile
  (JNIEnv * env, jclass obj, jint keyId, jstring filename)
{
//	jbyte * arrayBody = env->GetByteArrayElements(key,0);
//	// jsize theArrayLengthJ = env->GetArrayLength(key);
//	 Byte * Buffer = (Byte *)arrayBody;

	 const char *szFilename = env->GetStringUTFChars(filename, 0);
	 int failcode = -1;
	 /*bool bRet = */PiEncryptFile((int)keyId, szFilename, failcode, false);
	 return failcode;
}

/*
 * Class:     com_pi_pilocker_piencryptfiles_libPiEncrypt_jni
 * Method:    PiDecryptFile
 * Signature: ([BILjava/lang/String;I)Z
 */
JNIEXPORT jint  JNICALL Java_com_pi_pilocker_piencryptfiles_libPiEncrypt_1jni_PiDecryptFile
  (JNIEnv * env, jclass obj, jstring filename)
{
//    jbyte * arrayBody = env->GetByteArrayElements((jbyteArray)key, 0);
//    //jsize theArrayLengthJ = env->GetArrayLength(key);
//    Byte * Buffer = (Byte *)arrayBody;

    const char *szFilename = env->GetStringUTFChars(filename, 0);
    int failcode = -1;
    /*bool bRet = */PiDecryptFile(szFilename, failcode, false);
    return failcode;
}

/*
 * Class:     com_pi_pilocker_piencryptfiles_libPiEncrypt_jni
 * Method:    PiDecFileInMem
 * Signature: ([BI[BI[BII)Z
 */
JNIEXPORT jint JNICALL Java_com_pi_pilocker_piencryptfiles_libPiEncrypt_1jni_PiDecFileInMem
  (JNIEnv * env, jclass obj, /*jbyteArray key, jint keyLen, */jbyteArray srcBuf, jint srcLen, jbyteArray dstBuf, jint dstLen)
{
//	jbyte * arrayBody = env->GetByteArrayElements(key,0);
//	Byte * keyBuffer = (Byte *)arrayBody;

	Byte * srcBuffer = new Byte[srcLen];
	env->GetByteArrayRegion(srcBuf, 0, srcLen, (jbyte *)srcBuffer);
	//arrayBody = env->GetByteArrayElements(srcBuf,0);
	//Byte * srcBuffer = (Byte *)arrayBody;

	//arrayBody = env->GetByteArrayElements(dstBuf,0);
	Byte * dstBuffer = new Byte[dstLen];
	int failcode = -1;
	bool bRet = PiDecFileInMem(srcBuffer, srcLen, dstBuffer, dstLen, failcode);
	if(bRet)
		env->SetByteArrayRegion(dstBuf, 0, dstLen, (jbyte *)dstBuffer);
	delete [] srcBuffer;
	delete [] dstBuffer;
	return failcode;
}

/*
 * Class:     com_pi_pilocker_piencryptfiles_libPiEncrypt_jni
 * Method:    PiEncFileInMem
 * Signature: ([BI[BI)I
 */
JNIEXPORT jint JNICALL Java_com_pi_pilocker_piencryptfiles_libPiEncrypt_1jni_PiEncFileInMem
        (JNIEnv *env, jclass, jint keyid, jbyteArray srcBuf, jint srcLen, jbyteArray dstBuf, jint dstLen)
{
    Byte * srcBuffer = new Byte[srcLen];
    env->GetByteArrayRegion(srcBuf, 0, srcLen, (jbyte *)srcBuffer);

    Byte * dstBuffer = new Byte[dstLen];
    int failcode = -1;
    bool bRet = PiEncFileInMem(keyid,srcBuffer, srcLen, dstBuffer, dstLen, failcode);
    if(bRet)
        env->SetByteArrayRegion(dstBuf, 0, dstLen, (jbyte *)dstBuffer);
    delete [] srcBuffer;
    delete [] dstBuffer;
    return failcode;
}


JNIEXPORT jstring JNICALL Java_com_pi_pilocker_piencryptfiles_libPiEncrypt_1jni_PiGetErrInfo
		(JNIEnv * env, jclass obj, jint errCode/*, jcharArray errInfo*/)
{
	char *pszErrInfo = new char[1024];
    //env->GetCharArrayRegion(errInfo, 0, 1024, (jchar *)pszErrInfo);
	memset(pszErrInfo, 0x00, sizeof(char) * 1024);
	int nRet = PiGetErrInfo(errCode, pszErrInfo);
    //以下为由char *字符串转为jni的jstring，必须有这样的过程才能正常把C++的char *转为java可用的String
    int strLen = strlen(pszErrInfo);
    jclass jstrObj   = env->FindClass("java/lang/String");
    jmethodID  methodId  = env->GetMethodID( jstrObj, "<init>", "([BLjava/lang/String;)V");
    jbyteArray byteArray = env->NewByteArray(strLen);
    jstring    encode    = env->NewStringUTF("utf-8");

    env->SetByteArrayRegion(byteArray, 0, strLen, (jbyte*)pszErrInfo);
    delete [] pszErrInfo;
    return (jstring)env->NewObject(jstrObj, methodId, byteArray, encode);
	//return (jstring)pszErrInfo;
}



