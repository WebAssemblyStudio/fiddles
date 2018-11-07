import "allocator/arena"

declare function sayHello(): void;

sayHello();

class Foo {
  x: i32

  constructor (x: i32) {
    this.x = x
  }

  add (y: i32): i32 {
    return this.x + y
  }
}

export function add(x: i32, y: i32): i32 {
  const a = new Foo(x)
  const c = new Uint8Array(10)
  const b = new DataView(c.buffer)
  return a.add(y)
}
