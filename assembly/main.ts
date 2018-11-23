declare function sayHello(): void;

sayHello();

export function add(x: i32, y: i32): i32 {
  return x + y;
}

assert(true == changetype<boolean>(1));
assert(false == changetype<boolean>(0));
assert(true == changetype<boolean>(3));
assert(false == changetype<boolean>(2));
