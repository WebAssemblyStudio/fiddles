#define WASM_EXPORT __attribute__((visibility("default")))

WASM_EXPORT

int main(int argc, char *argv[]) {
  return argc*argc;
}
