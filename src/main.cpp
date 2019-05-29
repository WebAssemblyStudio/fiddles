#define WASM_EXPORT __attribute__((visibility("default")))

#include <cstdint>
#include <string>

using namespace std;

typedef uint8_t byte_t;

extern "C" byte_t* alloc_mem(int);
extern "C" byte_t* get_storage(byte_t*);
extern "C" void set_storage(byte_t*, byte_t*);
extern "C" void print_bytes(int, byte_t*);

//helpers
byte_t* int_to_bytes(int n){
    byte_t* bytes = alloc_mem(4);
    memcpy(bytes, (byte_t*)&n, 4);
    return bytes;
}

int int_from_bytes(byte_t* bytes){
  if(bytes==0){
    return 0;
  }
  return *(int *)bytes;
}

inline byte_t* strbytes(const char *s){
  byte_t* ret = alloc_mem(32);
  memcpy(ret, s, 32);
  return ret;
}

WASM_EXPORT
void set(){
    byte_t* key = strbytes("abcdef");
    byte_t* value = int_to_bytes(123);
    set_storage(key, value);
}


WASM_EXPORT
int get(){
    // reinterpret_cast<byte_t*>("Hello, UTF-8");
    byte_t* key = strbytes("abcdef");
    byte_t* value = get_storage(key);
    print_bytes(6, key);
    return int_from_bytes(value);
}