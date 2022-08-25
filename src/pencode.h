//
// Created by Administrator on 2018/3/9.
//

#ifndef PIENCRYPTFILES_DEBUG_PSTRING_H
#define PIENCRYPTFILES_DEBUG_PSTRING_H


#include <stdint.h>

int dl_icuuc_init();
int32_t dl_icuuc_gbk2utf8(char *outbuf, int32_t buflen, const char *instring, int32_t inlen);

#endif //PIENCRYPTFILES_DEBUG_PSTRING_H
