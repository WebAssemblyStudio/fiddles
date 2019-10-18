#include <stdint.h>
#include <stdlib.h>

typedef uint8_t byte_t;

extern size_t chain_storage_size_get(byte_t*, size_t);
extern byte_t* chain_storage_get(byte_t*, size_t, byte_t*);
extern void chain_storage_set(byte_t*, size_t, byte_t*, size_t);
extern void chain_print_bytes(byte_t*, size_t);
extern void chain_event_emit(byte_t*);

const int ADDR_SIZE=35;

// sdk_storage_set
void sdk_storage_set(byte_t* key, size_t key_size, byte_t* value, size_t value_size) {
    chain_storage_set(key, key_size, value, value_size);
}
// sdk_storage_get
byte_t* sdk_storage_get(byte_t* key, size_t key_size) {
  int size = chain_storage_size_get(key, key_size);
  byte_t* ret = (byte_t*) malloc(size * sizeof(byte_t));
  chain_storage_get(key, key_size, ret);
  return ret;
}

int from_bytes(uint8_t* bytes){
  if(bytes==0){
    return 0;
  }
  return *(uint32_t*)bytes;
}

void change_balance(uint8_t* to, int amount){
  int to_balance = from_bytes(sdk_storage_get(to, ADDR_SIZE));
  to_balance += amount;
  sdk_storage_set(to, ADDR_SIZE, (uint8_t*)&to_balance, 4);
}

void mint(uint8_t* to, int amount){
  change_balance(to, amount);
}

int get_balance(uint8_t* address){
  return from_bytes(sdk_storage_get(address, ADDR_SIZE));
}

void transfer(uint8_t* from, uint8_t* to, int amount){
  change_balance(from, -amount);
  change_balance(to, amount);
}