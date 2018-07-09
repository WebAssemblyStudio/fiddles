#define WASM_EXPORT __attribute__((visibility("default")))



int init_global(int v){
  return v * 2;
}
static int ovm = init_global(32); 
WASM_EXPORT
int main() {
  return ovm;
}
