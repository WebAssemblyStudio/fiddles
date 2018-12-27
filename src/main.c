#define WASM_EXPORT __attribute__((visibility("default")))

WASM_EXPORT
int main() {
  return 42;
}

int add(int x, int y)
{
  return x + y;
}

WASM_EXPORT
int performTest(int n){
  auto value = 0;
  for(auto i = 0; i < n; i++){
    value = add(i,1);
  }
  return value;
}