#define WASM_EXPORT __attribute__((visibility("default")))
#include <stdint.h>
#include <string.h>

extern uint8_t* get_storage(uint8_t*);
extern void set_storage(uint8_t*, uint8_t*);

int from_bytes(uint8_t* bytes){
  if(bytes==0){
    return 0;
  }
  return *(uint32_t*)bytes;
}

void change_balance(uint8_t* to, int amount){
  int to_balance = from_bytes(get_storage(to));
  to_balance += amount;
  set_storage(to, (uint8_t*)&to_balance);
}

WASM_EXPORT
void mint(uint8_t* to, int amount){
  change_balance(to, amount);
}

WASM_EXPORT
int get_balance(uint8_t* address){
  return from_bytes(get_storage(address));
}

WASM_EXPORT
void transfer(uint8_t* from, uint8_t* to, int amount){
  change_balance(from, -amount);
  change_balance(to, amount);
}