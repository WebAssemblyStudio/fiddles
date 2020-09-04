declare function sayHello(): void;

sayHello();

export function add(x: i32, y: i32): i32 {
  return x + y;
}

export function fib(x: i32): i32 {
  if(x <= 1) return 1;
  return fib(x - 1) + fib(x - 2);
}

export function factorial(x: i32): i32 {
  if(x <= 1) return 1;
  if(x == 2) return 2;
  return x * factorial(x - 1);
}