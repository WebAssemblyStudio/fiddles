declare function sayHello(): void;

sayHello();

export function add(x: i32, y: i32): i32 {
  return x + y;
}

export function test(s: string): i32 {
  return I32.parseInt(s);
}
