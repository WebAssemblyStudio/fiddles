#define WASM_EXPORT __attribute__((visibility("default")))
#include <math.h>

WASM_EXPORT

const int SIZE = 1024;

int (*func[SIZE])( int );

WASM_EXPORT

int funcptr() {
  return &func;
}

double stack[SIZE];

WASM_EXPORT

int stackptr() {
  return &stack;
}

WASM_EXPORT

int stkptr = 0;

WASM_EXPORT

void push(double a) {
  stack[stkptr++] = a;
}

WASM_EXPORT

double pop() {
  return stack[--stkptr];
}

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

void mul() {
  x = pop();
  y = pop();
  push(y * x);
}

WASM_EXPORT

void div() {
  x = pop();
  y = pop();
  push(y / x);
}

WASM_EXPORT

void swap() {
  x = pop();
  y = pop();
  push(x);
  push(y);
}

WASM_EXPORT

void lnx() {
  x = pop();
  push(log(x));
}

WASM_EXPORT

int main() {
  func[0]=&add;
  func[1]=sub;
  func[2]=mul;
  func[3]=div; 
  func[4]=swap; 
  func[5]=lnx; 
  return 0;
}

WASM_EXPORT

void ex() {
  func[0](0);
}
