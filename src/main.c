#define WASM_EXPORT __attribute__((visibility("default")))

typedef struct {
  unsigned char a;
  unsigned short b;
} addition_params;

WASM_EXPORT
unsigned int addStruct(addition_params * params) {
  return (unsigned int)params->a + (unsigned int)params->b;
}
