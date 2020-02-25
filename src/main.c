#define WASM_EXPORT __attribute__((visibility("default")))

typedef struct {
  char a;
  short b;
} addition_params;

WASM_EXPORT
int addStruct(addition_params * params) {
  return (int)params->a + (int)params->b;
}
