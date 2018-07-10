declare namespace console {
  function logi(value: i32): void;
  function logf(value: f64): void;
}

class Foo {}

export function add(x: i32, y: i32): i32 {
  var foo = new Foo;
  return x + y;
}

console.logi(add(1, 2));
