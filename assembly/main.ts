
import {
  loadUnsafe,
} from 'internal/arraybuffer';

declare namespace console {
  function logi(value: i32): void;
  function logf(value: f64): void;
}

function createStaticBuffer(offset: usize, byteLength: i32): ArrayBuffer {
  store<i32>(offset, byteLength, offsetof<ArrayBuffer>("byteLength"));
  return changetype<ArrayBuffer>(offset);
}

export function test(size: i32): void {
  var buffer = createStaticBuffer(0, size * 8);

  console.logf(loadUnsafe<f64,f64>(buffer, 0));
  console.logf(loadUnsafe<f64,f64>(buffer, 1));
  console.logf(loadUnsafe<f64,f64>(buffer, 2));
  console.logf(loadUnsafe<f64,f64>(buffer, 3));
}