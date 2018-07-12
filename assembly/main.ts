import 'allocator/arena'

@external("env", "sayHello")
declare function sayHello(): void;

declare namespace console {
  function logi(value: i32): void;
  function logf(value: f64): void;
}

sayHello();

export function add(x: i32, y: i32): i32 {
  return x + y;
}

export function fewThings(): void {
  for (let a: u32 = 0; a < 255; a++) {
    let thing = new Something(a)
    console.logi(thing.value)
  }
}

console.logi(add(1, 2));
fewThings()


class Something {
  value: u32

  constructor(initialValue: u32) {
    this.value = initialValue
  }
}