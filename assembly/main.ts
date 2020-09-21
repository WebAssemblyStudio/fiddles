declare function sayHello(): void;

sayHello();

export function add(x: i32, y: i32): i32 {
  return x + y;
}

export function fib(n: i32): i32 {
  var a = 0, b = 1
  if (n > 0) {
    while (--n) {
      let t = a + b
      a = b
      b = t
    }
    return b
  }
  return a
}