/*
  在 Wasm 中执行如下 JS:

  for (var i = 0; i < 10; i++) {
    console.log('hello wasm: ' + i);
  }
 */
#include <stdio.h>
#include <string.h>

#define WASM_EXPORT __attribute__((visibility("default")))

extern void prop_get(int dst, int obj, int key);
extern void prop_call_1_void(int obj, int key, int arg1);
extern void add_to(int dst, int src1, int src2);
extern void put_i(int dst, int val);
extern void put_s(int dst, const char* ptr, const size_t len);



const char* STRING_POOL[] = {
  "console",
  "log",
  "hello wasm: "
};


WASM_EXPORT
void init() {
  for (int i = 0; i < sizeof(STRING_POOL); i++) {
    put_s(i + 1, STRING_POOL[i], strlen(STRING_POOL[i]));
  }
}


WASM_EXPORT
void logic() {
  prop_get(4, 0, 1);            // r4 = window['console']

  for (int i = 0; i < 10; i++) {
    put_i(5, i);                // r5 = i
    add_to(5, 3, 5);            // r5 = r3 + r5
    prop_call_1_void(4, 2, 5);  // r4['log'](r5)
  }
}
