declare function sayHello(): void;

declare function log(string: String): void;

sayHello();

log("Log from wasm");

export function add(x: i32, y: i32): i32 {
  return x + y;
}
