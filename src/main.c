

#define WASM_EXPORT __attribute__((visibility("default")))


long add() {
  return 0xFFFFFFFFFF;
}

WASM_EXPORT
int main(){
  return add();
}
