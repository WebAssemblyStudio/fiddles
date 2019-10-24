#include <stdint.h>
#include <stdlib.h>
#include <string.h>

typedef uint8_t byte_t;

extern size_t chain_storage_size_get(byte_t*, size_t);
extern byte_t* chain_storage_get(byte_t*, size_t, byte_t*);
extern void chain_storage_set(byte_t*, size_t, byte_t*, size_t);
extern void chain_print_bytes(byte_t*, size_t);
extern void chain_event_emit(byte_t*);
extern void chain_get_caller(byte_t*);
extern void chain_get_creator(byte_t*);
extern byte_t* chain_invoke(byte_t*, byte_t* params);

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

int sdk_is_caller(byte_t* address) {
  byte_t* caller = (byte_t*) malloc(ADDR_SIZE * sizeof(byte_t));
  chain_get_caller(caller);
  int n = memcmp(caller, address, ADDR_SIZE);
  free(caller);
  if (n == 0) {
    return 1;
  }
  return 0;
}

int sdk_caller_is_creator() {
  byte_t* caller = (byte_t*) malloc(ADDR_SIZE * sizeof(byte_t));
  byte_t* creator = (byte_t*) malloc(ADDR_SIZE * sizeof(byte_t));
  chain_get_caller(caller);
  chain_get_caller(creator);
  int n = memcmp(creator, caller, ADDR_SIZE);
  free(caller);
  free(creator);
  if (n == 0) {
    return 1;
  }
  return 0;
}

int from_bytes(uint8_t* bytes){
  if(bytes==0){
    return 0;
  }
  return *(uint32_t*)bytes;
}

int change_balance(uint8_t* to, uint64_t amount, int sign){
  uint64_t to_balance = from_bytes(sdk_storage_get(to, ADDR_SIZE));
  if(sign < 0){
    if(to_balance < amount){
      return -1;
    }
    to_balance -= amount;
  } else{
    to_balance += amount;
  }
  sdk_storage_set(to, ADDR_SIZE, (uint8_t*)&to_balance, 4);
  return 0;
}

int mint(uint8_t* to, uint64_t amount){
  if(!sdk_caller_is_creator()){
    return -1;
  }
  return change_balance(to, amount, 1);
}

int get_balance(uint8_t* address){
  return from_bytes(sdk_storage_get(address, ADDR_SIZE));
}

int transfer(uint8_t* to, uint64_t amount){
  byte_t from[ADDR_SIZE];
  chain_get_caller(from);
  int success = change_balance(from, amount, -1);
  if(success != -1){
    return change_balance(to, amount, 1);
  }
  return -1;
}