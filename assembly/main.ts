import "allocator/arena";
@external("env", "sayHello")
declare function sayHello(): void;

declare namespace console {
  function logi(value: i32): void;
  function logf(value: f64): void;
}

sayHello();

export function add(x: i32, y: i32): i32 {
  const foo:u8[] = [123, 100, 22, 0, 50, 111, 94, 24];
  const size:i32 = 8;
  var ptrData = memory.allocate(size);
  for (let i = 0; i < size; i++) {
    store<u8>(ptrData, foo[i], i);
  }
  return foo[0];
}

console.logi(add(1, 2));
