#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#define WASM_EXPORT __attribute__((visibility("default")))

extern void pushEvent(char* eventIdPtr,unsigned long eventIdLen, char* eventDataPtr,unsigned long eventDataLen);
extern void clear();
extern char* getChannelConfig(char * keyPtr, unsigned long keyLen);

char newStr[1024];
WASM_EXPORT
long allocateString (unsigned long length) {  
  return &newStr[0];
}

void _pushEvent(char * eventId, char * eventData){
  pushEvent(eventId, strlen(eventId),eventData, strlen(eventData));
}
char* _getChannelConfig(char * keyPtr){
  getChannelConfig(keyPtr, strlen(keyPtr));
  return newStr;
}


itos1(unsigned int value, char* string)
{
    int string_l = (value == 0) ? 1 : (int)log10(value) + 1;
    int residual = value;
    int it;
    for (it = string_l - 1; it >= 0; it--) {
        int digit;
        digit = residual % 10;
        residual = residual / 10;
        string[it] = '0' + digit;
    }
    string[string_l] = '\0';
    return string;
}
int counter = 0;
WASM_EXPORT
void process(void) {  
  char resNum[20] = "";
  char res[50] = "";
  itos1(counter++,resNum);  
  char * value = _getChannelConfig("eventValues");
  strcat(res, value);
  strcat(res, resNum);
  clear();
  _pushEvent(resNum, res);
}

WASM_EXPORT
void _start(void) {
ssize_t n, m;
    // char buf[BUFSIZ];
    char * testStr = "test123";    
    // int in = open(inFile, O_RDONLY);
    int out = open("/test.txt", O_WRONLY | O_CREAT, 0660);  
    n = strlen(testStr);
    // while ((n = read(in, buf, BUFSIZ)) > 0) {
        char *ptr = testStr;
        while (n > 0) {
            m = write(out, ptr, (size_t)n);
            if (m < 0) {
                fprintf(stderr, "write error: %s\n", strerror(errno));
                return ;
                // exit(1);
            }
            n -= m;
            ptr += m;
        }
    // }

    if (n < 0) {
        fprintf(stderr, "read error: %s\n", strerror(errno));
        return;
    }
}
