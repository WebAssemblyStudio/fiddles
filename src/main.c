#define WASM_EXPORT __attribute__((visibility("default")))

int aap(int i){
  return 20 + i;
}

WASM_EXPORT
int main(void) {
  int q = 5,r=20;
  return q+r + aap(1202);
}
