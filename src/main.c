#define WASM_EXPORT __attribute__((visibility("default"))) 
#define DONT_EXPORT __attribute__((visibility("hidden"))) static 

WASM_EXPORT int regress(int pointCount) {
  return 0;
}

extern void expandMemory(void);
