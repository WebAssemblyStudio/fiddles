#define WASM_EXPORT __attribute__((visibility("default")))

int SIZE = 256;
char BUFFER[256];

WASM_EXPORT
char* get_offset() {
  return &BUFFER[0];
  // NB: les pointeurs sont vus par Javascript comme des entiers
}

WASM_EXPORT
int get_size() {
  return SIZE;
}

// met le contenu de BUFFER en majuscules
WASM_EXPORT
void upper(int len) {
  for (int i=0; i<len; i++) {
    if ('a' <= BUFFER[i] && BUFFER[i] <= 'z') {
      BUFFER[i] -= 32;
    }
  }
}
