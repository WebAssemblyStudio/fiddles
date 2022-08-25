/* use dl API include file */
#include <dlfcn.h>
#include <string.h>
#include <stdio.h>
#include <stdint.h>

/* typedef a function pointer to pointer ucnv_convert method */
/*
see the source code define
int32_t ucnv_convert(const char *toConverterName, const char *fromConverterName,
     char *target, int32_t targetSize,
     const char *source, int32_t sourceSize,
     int32_t * err)
*/

typedef int32_t (*TUCNVCONVERT)(
        const char *lpcOutEcd,
        const char *lpcInEcd,
        char* lpOutBuf,
        int32_t nOutBufLen,
        const char* lpcInStr,
        int32_t nInStrLen,
        int32_t *pnErrCode);
/* pointer libicuuc.so dl lib */
static void* g_lpdlIcuuc = 0;

/* ucnv_convert method pointer */
static TUCNVCONVERT g_lpfnUcnvConvert = 0;

//在libicuuc.so中找到函数ucnv_convert
int dl_icuuc_init()
{
    g_lpfnUcnvConvert = 0;
    g_lpdlIcuuc = dlopen("/system/lib/libicuuc.so", RTLD_LAZY);
    if(g_lpdlIcuuc == NULL)
        g_lpdlIcuuc = dlopen("/system/lib64/libicuuc.so",RTLD_LAZY);
    if (g_lpdlIcuuc != 0)
    {
        int i, j;
        char szDLFnName[32] = {0};
        i = 3;
        j = 8;
        //android2.1, ucnv_convert_3_8
        //android2.2, ucnv_convert_4_2
        //android2.3, ucnv_convert_44
        //android4.0, ucnv_convert_46
        //android4.0, ucnv_convert_46
        //android4.1, ucnv_convert_47
        //android4.2, ucnv_convert_48
        //android4.3, ucnv_convert_50
        //android4.4, ucnv_convert_51
        //其尾椎在，在源码的common/unicode/uvernum.h:77:  #define U_ICU_VERSION_SUFFIX _48

        g_lpfnUcnvConvert = (TUCNVCONVERT)dlsym(g_lpdlIcuuc, "ucnv_convert_3_8");
        while (0 == g_lpfnUcnvConvert)
        {
            memset(szDLFnName, 0, 32 * sizeof(char));
            sprintf(szDLFnName, "ucnv_convert_%d%d", i, j);
            g_lpfnUcnvConvert = (TUCNVCONVERT)dlsym(g_lpdlIcuuc, szDLFnName);
            if (g_lpfnUcnvConvert != 0)
            {
                return 1;
            }
            sprintf(szDLFnName, "ucnv_convert_%d_%d", i, j);
            g_lpfnUcnvConvert = (TUCNVCONVERT)dlsym(g_lpdlIcuuc, szDLFnName);
            if (g_lpfnUcnvConvert != 0)
            {
                return 1;
            }
            j++;
            if (j > 9)
            {
                j = 1;
                i++;
                if (i > 5)
                {
                    break;
                }
            }
        }
    }
    return 0;
}

int dl_icuuc_uninit()
{
    if (g_lpdlIcuuc != 0)
    {
        dlclose(g_lpdlIcuuc);
        g_lpdlIcuuc = 0;
    }
    return 1;
}

//utf-8,gb2312,ucs4
//utf-8:  一个英文字母或者是数字占用一个字节，汉字占3个字节
//gb2312: 一个英文字母或者是数字占用一个字节，汉字占2个字节
int32_t dl_icuuc_gbk2utf8(
        char *outbuf, int32_t buflen, const char *instring, int32_t inlen)
{
    int32_t iret;
    iret = 0;
    if (outbuf != 0 && instring != 0)
    {
        if (g_lpfnUcnvConvert != 0)
        {
            int32_t err_code = 0;
            iret = g_lpfnUcnvConvert(
                    "utf-8", "gb2312", outbuf, buflen, instring, inlen, &err_code);
        }
    }

    return iret;
}

int32_t dl_icuuc_utf82gbk(char *outbuf, int32_t buflen, const char *instring, int32_t inlen)
{
    int32_t iret;
    iret = 0;
    if (outbuf != 0 && instring != 0)
    {
        if (g_lpfnUcnvConvert != 0)
        {
            int32_t err_code = 0;
            iret = g_lpfnUcnvConvert(
                    "gb2312", "utf-8", outbuf, buflen, instring, inlen, &err_code);
        }
    }

    return iret;
}

int32_t dl_icuuc_unicode2utf8(char *outbuf, int32_t buflen, const unsigned short *instring, int32_t inlen)
{
    int32_t iret;
    iret = 0;
    if (outbuf != 0 && instring != 0)
    {
        if (g_lpfnUcnvConvert != 0)
        {
            int32_t err_code = 0;
            iret = g_lpfnUcnvConvert(
                    "utf-8", "ucs4", outbuf, buflen, (const char *)instring,
                    inlen*sizeof(unsigned short)/sizeof(char), &err_code);
        }
    }

    return iret;
}

int32_t dl_icuuc_utf82unicode(unsigned short *outbuf, int32_t buflen, const char *instring, int32_t inlen)
{
    int32_t iret;
    iret = 0;
    if (outbuf != 0 && instring != 0)
    {
        if (g_lpfnUcnvConvert != 0)
        {
            int32_t err_code = 0;
            iret = g_lpfnUcnvConvert(
                    "ucs4", "utf-8", (char *)outbuf,
                    buflen*sizeof(unsigned short)/sizeof(char),
                    instring, inlen, &err_code);
        }
    }

    return iret;
}
