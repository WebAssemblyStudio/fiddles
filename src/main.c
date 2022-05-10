#define WASM_EXPORT __attribute__((visibility("default")))

// déclaration d'une fonction externe,
// qui sera fournie par le code Javascript
extern void print_int(int i);

WASM_EXPORT
void count(int max) {
  for (int i=1; i<=max; i++) {
    print_int(i);
  }
}
