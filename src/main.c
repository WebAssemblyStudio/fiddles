#define WASM_EXPORT __attribute__((visibility("default")))
#include <math.h>

WASM_EXPORT
void (*func[1024])( );

WASM_EXPORT
int funcptr() {
  return func;
}

WASM_EXPORT
double stack[1024];

WASM_EXPORT
int stackptr() {
  return stack;
}

WASM_EXPORT
double reg[1024];

WASM_EXPORT
int regptr() {
  return reg;
}

WASM_EXPORT
int prog[1024];

WASM_EXPORT
int progptr() {
  return prog;
}

WASM_EXPORT
int stkindex = 0;

WASM_EXPORT
void push(double a) {
  stack[stkindex++]  = a;
}

WASM_EXPORT
double pop() {
  return stack[--stkindex];
}

double x, y, z, t;

WASM_EXPORT
void swap() {
  x = pop();
  y = pop();
  push(x);
  push(y);
}

WASM_EXPORT
double getx() {
  return stack[stkindex - 1];
}

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
void powyx() {
  x = pop();
  y = pop();
  push(pow(y, x));
}

WASM_EXPORT
void ln() {
  x = pop();
  push(log(x));
}

WASM_EXPORT
void lastx() {
  push(x);
}

WASM_EXPORT
void lasty() {
  push(y);
}

WASM_EXPORT
void init() {
  func[0] = &div;
  func[1] = &mul;
  func[2] = &sub;
  func[3] = &add;
  func[4] = &powyx;
  func[5] = &ln;  
  func[6] = &swap;
  func[7] = &getx;  
}

WASM_EXPORT
void ex(int steps) {
  for (int i=0; i <=steps; i++) {
    func[prog[i]]();
  }
}

