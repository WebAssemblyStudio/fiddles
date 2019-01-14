import "allocator/tlsf";

declare function sayHello(ptr: i32): void;
declare function log(value: i32): void;
export function hello(ptr: i32): void {
   store<i32>(ptr, 2);
}

export function add(x: i32, y: i32): void {
  let p: i32 = 1;
  sayHello(changetype<usize>(p));
  let value = load<i32>(changetype<usize>(p));
  log(value);
}
