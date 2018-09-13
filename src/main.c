#define WASM_EXPORT __attribute__((visibility("default")))

WASM_EXPORT
void reverse(char *str, int length) {
  int actualLength = 0;
  for(int i = 0; str[i] != '\0', i < length; i++ ) { }
  for (int begin = 0, int end = length - 1, begin < end, begin < length, end >= 0; begin++, end--) {
    char inter = str[begin];
    str[begin] = str[end];
    str[end] = inter;
  }
}

WASM_EXPORT
int main() {
  return 42;
}
