#define WASM_EXPORT __attribute__((visibility("default")))

WASM_EXPORT
typedef struct leon_s {
  int a;
  int b;
  char *str1;
  char *str2;
} leon_t;

WASM_EXPORT
char *test() {
  leon_t leon;

  leon.a = 1337;
  leon.b = 123;
  leon.str1 = "hiya";
  leon.str2 = "wagwan";

  return leon.str1;
}
