#define WASM_EXPORT __attribute__((visibility("default")))

extern void* memory;

WASM_EXPORT
void best(int p0, int p1, int p2) {
  int* mem32 = memory;

  int l0 = 0, l1 = 0, l2 = 0;
  if (p1 < 1) return;
  l0 = p1 << 2;
  do {
    l1 = p0 + l0;
    l2 = mem32[l1];
    mem32[l1] = mem32[p0];
    mem32[p0] = l2;
    p0 += 4;
    p1 -= 1;
  } while(p1 != 0);

}
