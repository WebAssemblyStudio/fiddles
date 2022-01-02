#define WASM_EXPORT __attribute__((visibility("default")))
#include <math.h>

WASM_EXPORT

double stack[1024];

WASM_EXPORT

int* stkptr() {
  return &stack[0];
}

WASM_EXPORT

int ptr = 0;

WASM_EXPORT

void push(float a) {
  stack[ptr++] = a;
}

WASM_EXPORT

double pop() {
  return stack[--ptr];
}

WASM_EXPORT
double x, y, z, t;

WASM_EXPORT
void add() {
  x = pop();
  y = pop();
  push(y + x);
}

WASM_EXPORT
void sub() {
  x = pop();
  y = pop();
  push(y - x);
}

WASM_EXPORT
void logx() {
  x = pop();
  push(log(x));
}

