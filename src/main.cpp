#include <string.h>

#define WASM_EXPORT __attribute__((visibility("default")))

extern void pushEvent(char* eventIdPtr,unsigned long eventIdLen, char* eventDataPtr,unsigned long eventDataLen);

void _pushEvent(char * eventId, char * eventData){
  pushEvent(eventId, strlen(eventId),eventData, strlen(eventData));
}

WASM_EXPORT
void process(void) {
  char *d = "123";
  char *d2 = "somedata";
  _pushEvent(d,d2);
}

WASM_EXPORT
void start(void) {}
