#include <stdint.h>
#include <stdlib.h>
#include <string.h>

typedef uint8_t byte_t;
typedef uint8_t* address;

extern size_t chain_storage_size_get(byte_t*, size_t);
extern byte_t* chain_storage_get(byte_t*, size_t, byte_t*);
extern void chain_storage_set(byte_t*, size_t, byte_t*, size_t);
extern void chain_print_bytes(byte_t*, size_t);
extern void chain_event_emit(byte_t*);
extern void chain_get_caller(byte_t*);
extern void chain_get_creator(byte_t*);
extern byte_t* chain_invoke(byte_t*, byte_t* params);

const int ADDR_SIZE=35;
const int OWNER_KEY_SIZE=5;
const char *OWNER = "OWNER";
const int IS_PAUSE_KEY_SIZE=8;
const char *IS_PAUSE = "IS_PAUSE";

// sdk_storage_set
void sdk_storage_set(byte_t* key, size_t key_size, byte_t* value, size_t value_size) {
    chain_storage_set(key, key_size, value, value_size);
}

// sdk_storage_get
byte_t* sdk_storage_get(byte_t* key, size_t key_size) {
  int size = chain_storage_size_get(key, key_size);
  if (size == 0) {
      return 0;
  }
  byte_t* ret = (byte_t*) malloc(size * sizeof(byte_t));
  chain_storage_get(key, key_size, ret);
  return ret;
}

int from_bytes(uint8_t* bytes){
  if (bytes==0) {
    return 0;
  }
  return *(uint32_t*)bytes;
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

int caller_is_owner() {
  byte_t* caller = (byte_t*) malloc(ADDR_SIZE * sizeof(byte_t));
  chain_get_caller(caller);
  byte_t* owner = (byte_t*) malloc(ADDR_SIZE * sizeof(byte_t));
  owner = sdk_storage_get((uint8_t *)OWNER, OWNER_KEY_SIZE);
  int n = memcmp(owner, caller, ADDR_SIZE);
  free(caller);
  free(owner);
  if (n == 0) {
    return 1;
  }
  return 0;
}

int set_owner(address add) {
  if (!caller_is_owner()) {
    return -1;
  }
  sdk_storage_set((uint8_t *)OWNER, OWNER_KEY_SIZE, add, ADDR_SIZE);
  return 0;
}

int pause() {
  if (!caller_is_owner()) {
    return -1;
  }
  uint8_t pause = 1;
  sdk_storage_set((uint8_t *)IS_PAUSE, IS_PAUSE_KEY_SIZE, &pause, 1);
  return 0;
}

int unpause() {
  if (!caller_is_owner()) {
    return -1;
  }
  uint8_t unpause = 0;
  sdk_storage_set((uint8_t *)IS_PAUSE, IS_PAUSE_KEY_SIZE, &unpause, 1);
  return 0;
}

int is_pausing() {
  return from_bytes(sdk_storage_get((uint8_t *)IS_PAUSE, IS_PAUSE_KEY_SIZE));
}

int sdk_caller_is_creator() {
  byte_t* caller = (byte_t*) malloc(ADDR_SIZE * sizeof(byte_t));
  byte_t* creator = (byte_t*) malloc(ADDR_SIZE * sizeof(byte_t));
  chain_get_caller(caller);
  chain_get_creator(creator);
  int n = memcmp(creator, caller, ADDR_SIZE);
  free(caller);
  free(creator);
  if (n == 0) {
    return 1;
  }
  return 0;
}


int change_balance(address to, uint64_t amount, int sign){
  uint64_t to_balance = from_bytes(sdk_storage_get(to, ADDR_SIZE));
  if (sign < 0) {
    if (to_balance < amount) {
      return -1;
    }
    to_balance -= amount;
  } else {
    to_balance += amount;
  }
  sdk_storage_set(to, ADDR_SIZE, (uint8_t*)&to_balance, 8);
  return 0;
}

int set_owner_to_creator() {
  byte_t* creator = (byte_t*) malloc(ADDR_SIZE * sizeof(byte_t));
  chain_get_creator(creator);
  sdk_storage_set((uint8_t *)OWNER, OWNER_KEY_SIZE, creator, ADDR_SIZE);
  return 0;
}

int mint(uint64_t amount) {
  // set up genesis owner
  if (!caller_is_owner()) {
    byte_t* owner = (byte_t*) malloc(ADDR_SIZE * sizeof(byte_t));
    owner = sdk_storage_get((uint8_t *)OWNER, OWNER_KEY_SIZE);
    if (owner == 0) {
      set_owner_to_creator();
    } else {
      return -1;
    }
  }

  // minting
  byte_t* caller = (byte_t*) malloc(ADDR_SIZE * sizeof(byte_t));
  chain_get_caller(caller);
  return change_balance(caller, amount, 1);
}

int get_balance(address address){
  return from_bytes(sdk_storage_get(address, ADDR_SIZE));
}

int transfer(address to, uint64_t amount){
  if (is_pausing()) {
    return -1;
  }
  byte_t from[ADDR_SIZE];
  chain_get_caller(from);
  int success = change_balance(from, amount, -1);
  if (success != -1) {
    return change_balance(to, amount, 1);
  }
  return -1;
}
