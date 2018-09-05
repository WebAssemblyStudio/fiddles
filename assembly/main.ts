import "allocator/arena";

declare namespace console {
  function logi(value: i32): void;
  function logf(value: f64): void;
}

export function createArray( len: i32): i32 {
  var arr:i32[] = [];
  for (let i =0 ; i < len; i ++) {
    arr.push(i);
  }
  return arr.length;
}

console.logi(createArray(1));
console.logi(createArray(2));
