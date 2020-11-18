#define WASM_EXPORT __attribute__((visibility("default")))
 
unsigned char raw[100];
 
WASM_EXPORT
unsigned char* getAddress() {
  return &raw[0];
}
 
WASM_EXPORT
int test() {
 
  raw[0] = 3;
  raw[1] = 4;
  raw[2] = 5;
  
  return raw[7];
}