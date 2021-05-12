#define WASM_EXPORT __attribute__((visibility("default")))
int VAL=0;
WASM_EXPORT
int main() {
  return 42;
}
WASM_EXPORT
void setValue(int val){
  printf("%s","Added value");
VAL=val;
}
WASM_EXPORT
int getValue(){
  int m = VAL + 10;
return m;
}