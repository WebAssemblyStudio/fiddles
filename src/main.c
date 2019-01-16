#define WASM_EXPORT __attribute__((visibility("default")))

WASM_EXPORT unsigned int f64_to_u32(double x) {
  return (unsigned int)x;
}
