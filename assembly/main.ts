declare function sayHello(): void;

sayHello();

class Foo {}

function fooOrUint8Aray(foo: Foo | Uint8Array){}

export function add(x: i32, y: i32): i32 {
  fooOrUint8Aray(new Foo())
  return x + y;
}
