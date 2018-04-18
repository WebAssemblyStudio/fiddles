#include <cstdlib>
#include <cstddef>
#include <cstdint>

#define WASM_EXPORT __attribute__((visibility("default")))

using CodeFn = uint32_t (*)();

extern "C" {
void hello(CodeFn f);
}

template <typename T> void generic() { hello(T::code); }

struct Zero {
  uint32_t code() { return 0; }
};

struct One {
  uint32_t code() { return 1; }
};

struct Two {
  uint32_t code() { return 2; }
};

WASM_EXPORT void trigger_generic_monos() {
  generic<Zero>();
  generic<One>();
  generic<Two>();
}

WASM_EXPORT
int main() { return 42; }
