
import {
  loadUnsafe,
} from 'internal/arraybuffer';

declare namespace console {
  function logi(value: i32): void;
  function logf(value: f64): void;
}

var array: Array<f64> = null;

export function test(size: i32): void {
  console.logf(unchecked(array[0]));
  console.logf(unchecked(array[1]));
  console.logf(unchecked(array[2]));
  console.logf(unchecked(array[3]));
}