#define WASM_EXPORT __attribute__((visibility("default")))

extern void _syscall();

void print_int(int x) {
  _syscall(2, x);
}

int fib(int n) {
  if (n == 1 || n == 2)
    return 1;
  else
    return fib(n-1) + fib(n-2);
}

WASM_EXPORT
int main(void) {
  int x = fib(10);
  print_int(x);
}
