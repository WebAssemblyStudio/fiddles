declare function sayHello(): void;

sayHello();

export function add(fn: (value: i32) => i32, x: i32, y: i32): i32 {
  let z = fn(x);
  return z + y;
}
