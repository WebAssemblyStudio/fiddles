#include <string.h>

#define WASM_EXPORT __attribute__((visibility("default")))

extern void pushEvent(char* eventIdPtr,unsigned long eventIdLen, char* eventDataPtr,unsigned long eventDataLen);
extern void clear();
extern char* getChannelConfig(char * keyPtr, unsigned long keyLen);

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
void _pushEvent(char * eventId, char * eventData){
  pushEvent(eventId, strlen(eventId),eventData, strlen(eventData));
}
char* _getChannelConfig(char * keyPtr){
  return getChannelConfig(keyPtr, strlen(keyPtr));
}
int counter = 0;
WASM_EXPORT
void process(void) {  
  char res[20];
  itos1(counter++,res);  
  char * value = _getChannelConfig("eventValues");
  strcat(value, res);
  clear();
  _pushEvent(res, value);
}

WASM_EXPORT
void start(void) {}
