// #include "malloc.h"

#define WASM_EXPORT __attribute__((visibility("default")))

class Base {
  int _value;
public:
  Base(int value): _value(value) {}
  virtual ~Base() {}

  virtual int get() {
    return _value;
  }
};

class Boo: public Base {
public:
  Boo(int value): Base(value) {}
  virtual ~Boo() {
    // Base::~Base();
  }

  virtual int get() {
    return Base::get() + 1;
  }
};

WASM_EXPORT 
int get(bool boo) {
  Base* foo = boo ? new Boo(1) : new Base(1);
  return foo->get();
}