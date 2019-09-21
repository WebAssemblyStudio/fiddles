#define WASM_EXPORT __attribute__((visibility("default")))

WASM_EXPORT
int main() {
  char cmpsts[16384];
  for (int x = 0; x < 1000; ++x)
    for (int i = 0; i <= 254; ++i)
      if ((cmpsts[i >> 3] & (1 << (i & 7))) == 0) {
        int bp = i + i + 3;
        int s = (bp * bp - 3) >> 1;
//        for (; s < 131072; s += bp) cmpsts[s >> 3] |= 1 << (s & 7);
        int slmt = s + (bp << 3);
        if (slmt > 131072) slmt = 131072;
        for (; s < slmt; s += bp) {
          char msk = 1 << (s & 7);
          for (int c = s >> 3; c < 16384; c += bp) cmpsts[c] |= msk;
        }
      }
  int count = 1;
  for (int i = 0; i < 131072; ++i)
    if ((cmpsts[i >> 3] & (1 << (i & 7))) == 0) ++count;
  return count;
}
