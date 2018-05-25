#define WASM_EXPORT __attribute__((visibility("default")))

WASM_EXPORT
int i32_extend8_s(int x) {
  return (x & 0x00000080) ? (x | 0xffffff80) : (x & 0x0000007f);
}

WASM_EXPORT
int i32_extend16_s(int x) {
  return (x & 0x00008000) ? (x | 0xffff8000) : (x & 0x00007fff);
}

WASM_EXPORT
long long int i64_extend8_s(long long int x) {
  return (x & 0x0000000000000080) ? (x | 0xffffffffffffff80) : (x & 0x000000000000007f);
}

WASM_EXPORT
long long int i64_extend16_s(long long int x) {
  return (x & 0x0000000000008000) ? (x | 0xffffffffffff8000) : (x & 0x0000000000007fff);
}

WASM_EXPORT
long long int i64_extend32_s(long long int x) {
  return (x & 0x0000000080000000) ? (x | 0xffffffff80000000) : (x & 0x000000007fffffff);
}
