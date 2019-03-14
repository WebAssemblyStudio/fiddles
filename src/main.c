#define WASM_EXPORT __attribute__((visibility("default")))

int a() {
  return 123;
}

int b() {
  return 42;
}

WASM_EXPORT
int main(int i) {
  int (*fun_ptr)() = &a;
  if(i == 0){
    fun_ptr = &b;
  }
  return (*fun_ptr)();
}
