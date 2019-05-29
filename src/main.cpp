#define WASM_EXPORT __attribute__((visibility("default")))

#include <cstdint>
#include <string>

using namespace std;

typedef uint8_t byte_t;

extern "C" byte_t* get_storage(const byte_t*);
extern "C" void set_storage(const byte_t*, byte_t*);

//helpers
byte_t* int_to_bytes(int n){
    byte_t* bytes = new byte_t[4];
    memcpy(bytes, (byte_t*)&n, 4);
    return bytes;
}

int int_from_bytes(byte_t* bytes){
  if(bytes==0){
    return 0;
  }
  return *(int *)bytes;
}

WASM_EXPORT
void set(){
    const byte_t* key = reinterpret_cast<const byte_t*>("my_key");
    byte_t* value = int_to_bytes(123);
    set_storage(key, value);
}

WASM_EXPORT
int get(){
    // reinterpret_cast<byte_t*>("Hello, UTF-8");
    const byte_t* key = reinterpret_cast<const byte_t*>("my_key");
    byte_t* value = get_storage(key);
    return int_from_bytes(value);
}