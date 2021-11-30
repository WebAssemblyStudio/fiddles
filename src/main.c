#define WASM_EXPORT __attribute__((visibility("default")))

#include <string.h>

extern void putc_js(char c);

int my_func(char* inBuf, int nBuflen)
{
  char  my_secret[] = "Guvf vf zl fhcre frperg cnffcuenfr";
  
  char* result = strncpy(inBuf, my_secret, nBuflen);
  return strlen(result);
}

char *rot13(char* dst, const char *src, int dstBufLen)
{
    char* result = dst;
    if(src == NULL){
      return NULL;
    }
    if(dst == NULL)
    {
      return NULL;
    }
    
    if(result != NULL){
      strcpy(result, src);
      char* current_char = result;
      
      while(*current_char != '\0'){
        //Only increment alphabet characters
        if((*current_char >= 97 && *current_char <= 122) || (*current_char >= 65 && *current_char <= 90)){
          if(*current_char > 109 || (*current_char > 77 && *current_char < 91)){
            //Characters that wrap around to the start of the alphabet
            *current_char -= 13;
          }else{
            //Characters that can be safely incremented
            *current_char += 13;
          }
        }
        current_char++;
      }
    }
    return result;
}

WASM_EXPORT
int main() {
  char szBuf[40];
  my_func(szBuf, sizeof(szBuf) - 1);
  char* p = rot13(szBuf, szBuf, sizeof(szBuf));
  
  while (*p)
  {
    putc_js(*p);
    p++;
  }
  putc_js('\n');
  return 0;
}
