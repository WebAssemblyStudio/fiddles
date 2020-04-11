declare function sayHello(): void;

sayHello();

export function add(x: i32, y: i32): i32 {
  return x + y;
}

export function sum(limit: u32): u32 {
  let sum: u32 = 0;
  for (let i: u32 = 0; i < limit; i++) {
    sum += i;
  }
  return sum;
}
