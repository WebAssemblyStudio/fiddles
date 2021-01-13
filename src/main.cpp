#include <utility>
#define WASM_EXPORT __attribute__((visibility("default")))

WASM_EXPORT

class Fraction(int numer, int denom) {
public:
  int numer;
  int denom;

  Fraction() {

  }
}

int main() {
  return 43;
}