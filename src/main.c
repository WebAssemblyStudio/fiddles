#define WASM_EXPORT __attribute__((visibility("default")))

const int MAXSIZE = 1024;
unsigned char data[MAXSIZE];

WASM_EXPORT
int sum(int len) {
  int result = 0;
  for(int i=0; i<len; ++i) result += data[i];
  return result;
}

WASM_EXPORT
char* getData(){
  return &data[0];
}