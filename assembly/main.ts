@external("env", "sayHello")
declare function sayHello(): void;

declare namespace console {
  function logi(value: int): void;
  function logf(value: double): void;
}

sayHello();

export function add(x: i32, y: i32): i32 {
  return x + y;
}

console.logi(add(1, 2));
