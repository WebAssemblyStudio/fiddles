#include <stdint.h>
#include <stdlib.h>

typedef uint8_t byte_t;

extern size_t chain_storage_size_get(byte_t*, size_t);
extern byte_t* chain_storage_get(byte_t*, size_t, byte_t*);
extern void chain_storage_set(byte_t*, size_t, byte_t*, size_t);
extern void chain_print_bytes(byte_t*, size_t);
extern void chain_event_emit(byte_t*);
extern uint64_t chain_invoke(byte_t*, byte_t*, size_t, byte_t*, size_t);

const char method[] = "transfer";
const byte_t method_args[] = {88, 118, 68, 9, 20, 83, 169, 129, 99, 131, 252, 244, 239, 69, 75, 250, 36, 71, 162, 77, 85, 46, 212, 44, 115, 79, 253, 93, 60, 121, 172, 251, 145, 191, 116, 30, 0, 0, 0, 0, 0, 0, 0};
const char contract[] = "LADSUJQLIKT4WBBLGLJ6Q36DEBJ6KFBQIIABD6B3ZWF7NIE4RIZURI53";
const char self_contract[] = "";
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

void transfer_if_thirty(int amount){
  if (amount == 30) {
    chain_invoke(contract, method, sizeof(method), method_args, sizeof(method_args));
  }
}

int transfer(uint8_t* to, uint64_t amount){
  return chain_invoke(self_contract, method, sizeof(method), method_args, sizeof(method_args));
}