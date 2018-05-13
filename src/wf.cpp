#define WASM_EXPORT __attribute__((visibility("default")))

WASM_EXPORT

int check(int input[2]){
  return input[0]*2+input[1]*2;
}

int main() {
  return 42;
}