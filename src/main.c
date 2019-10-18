#define WASM_EXPORT __attribute__((visibility("default")))

int SIZE = 0;
int data[];

WASM_EXPORT
int main() {
  return 42;
}

WASM_EXPORT
int* getOffset(){
  return &data[0];
}

WASM_EXPORT
int setSize(int a){
  SIZE = a;
}

WASM_EXPORT
int getSum(){
  int sum = 0;
  for(int i = 0; i <= SIZE;i++){
    sum = sum + data[i];
  }

  return sum;
}
