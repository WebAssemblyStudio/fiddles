#define WASM_EXPORT __attribute__((visibility("default")))

char buffer[64];
// FLAG: flag{w333b_ass3mbly_1s_s0_g0000d}
char FLAG[] = {160, 185, 165, 181, 129, 221, 85, 85, 4, 155, 223, 177, 149, 213, 11, 184, 168, 161, 173, 143, 17, 185, 205, 214, 63, 217, 254, 80, 80, 80, 4, 181, 250};


char q(char a, char b) {
  return (a << 1) ^ b;
}


int p(char *a, char *b) {
  while (*a != 0) {
    if (*a != q(*b, *(b+1))) {
      return 1;
    }
    a++;
    b++;
  }
  return 0;
}


WASM_EXPORT
int check() {
  return p(FLAG, buffer) == 0;
}