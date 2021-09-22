#define WASM_EXPORT __attribute__((visibility("default")))

WASM_EXPORT
int is_valid_selector_char(char c) {
  switch(c) {
    case 'a':
    case 'b':
    case 'c':
    case 'd':
    case 'e':
    case 'f':
    case 'g':
    case 'h':
    case 'i':
    case 'j':
    case 'l':
    case 'm':
    case 'n':
    case 'o':
    case 'p':
    case 'q':
    case 'r':
    case 's':
    case 't':
    case 'u':
    case 'v':
    case 'w':
    case 'x':
    case 'y':
    case 'z':
    case '#':
    case '.': {
      return 1;
    }
    default: {
      return 0;
    }
  }
}

WASM_EXPORT
int main() {
  return is_valid_selector_char('c') +
    is_valid_selector_char('%') +
    is_valid_selector_char('d');
}
