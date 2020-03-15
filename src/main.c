#define WASM_EXPORT __attribute__((visibility("default")))

WASM_EXPORT
int main() {
  return testsss(42);
}
WASM_EXPORT
int testsss(int testParameter){
  int testResult=testParameter*2;
  return testResult;
}
