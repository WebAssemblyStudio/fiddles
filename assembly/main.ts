@external("env", "sayHello")
declare function sayHello(): void;

declare namespace console {
  function logi(value: i32): void;
  function logf(value: f64): void;
}

sayHello();

export function add(x: i32, y: i32): i32 {
  var foo:i32[] = [1, 2, 3, 4];
  for (var i:i32 in foo)
    console.logi(i);
  return x + y;
}

console.logi(add(1, 2));
