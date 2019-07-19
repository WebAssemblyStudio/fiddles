#define WASM_EXPORT __attribute__((visibility("default")))
#include <stdint.h>
#include <string.h>

typedef uint8_t byte_t;
extern byte_t* hmalloc(int);
extern byte_t* get_storage(byte_t*);
extern void set_storage(byte_t*, byte_t*);

byte_t* strbytes(const char *s){
  byte_t* ret = hmalloc(32);
  memcpy(ret, s, 3);
  return ret;
}

WASM_EXPORT
int calc() {
  set_storage("order_book_book", strbytes("456"));
  byte_t* value = get_storage("order_book_book");
  int a = 9;
  int b = 2;
  return a-b+value[0];
}
