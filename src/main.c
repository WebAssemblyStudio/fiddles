#include <string.h>

#define WASM_EXPORT __attribute__((visibility("default")))

extern void pushEvent(const char *eventIdPtr,unsigned long eventIdLen,const char *eventDataPtr,unsigned long eventDataLen);

void _pushEvent(const char * eventId, const char * eventData){
  pushEvent(eventId, strlen(eventId),eventData, strlen(eventData));
}

WASM_EXPORT
void process(void) {
  const char *d = "123";
  _pushEvent(d,"somedata");
}

WASM_EXPORT
void start(void) {}
