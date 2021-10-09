#define WASM_EXPORT __attribute__((visibility("default")))
typedef struct
{
  int e,f;
} Test;
WASM_EXPORT
int main() {
  Test c;
  c.e = 23;
  return c.e;
}
