declare function sayHello(): void;

sayHello();

class Variants {
  limit<T>(fn: (context: T | null) => i32, context: T | null = null): void { }
}

export function add(x: i32, y: i32): i32 {
  return x + y;
}
