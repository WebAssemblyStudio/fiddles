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

WASM_EXPORT
int sum(){
  int result = 0;
  for(int i=0; i<3; ++i){
    for(int j=0; j<3; ++j){
      result += data[i][j];
    }
  }
  return result;
}
