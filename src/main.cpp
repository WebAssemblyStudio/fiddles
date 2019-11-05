#define WASM_EXPORT __attribute__((visibility("default")))

class X {
public:
  X() {

  }
};

WASM_EXPORT
int foo() {
  return 10;
}
int main() {
  return 5;
}


