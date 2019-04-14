#define WASM_EXPORT __attribute__((visibility("default")))
#include <std>
#include <time.h>

WASM_EXPORT
int main() {
  int i = 10;

  time_t now = time(0); 

  std::cout << now << std::endl;

  i = i + 100;
  i = i ^ 2;
  i = i / 432;
  i = i - 43;
  i = i * i;
  return i;
}
