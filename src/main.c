#define WASM_EXPORT __attribute__((visibility("default")))

unsigned char *data[] = {
  {0,0,0},
  {0,0,0},
  {0,0,0}
};

WASM_EXPORT
unsigned char* getData(){
  return &data[0];
}
