import "allocator/arena";

declare namespace console {
  function logi(v: i32): void;
}

var cache = new Map<i32,i32>();

export function fib(num: i32): i32 {
  if (!cache.has(num)) {
    let a: i32 = 0,
        b: i32 = 1,
        tmp: i32;
    for (let i = 0; i < num; i++) {
      tmp = a;
      a = b;
      b = tmp + b;
    }
    cache.set(num, a);
  }
  return cache.get(num);
}

console.logi(fib(2));
console.logi(fib(3));
console.logi(fib(2));
