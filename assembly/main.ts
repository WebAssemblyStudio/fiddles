import "allocator/arena";

import { LOAD } from "internal/arraybuffer";

function forEach<T>(arr: Array<T>, callbackfn: (value: T, index: i32, array: Array<T>) => void): void {
  for (let index = 0, length = arr.length_; index < min(length, arr.length_); ++index) {
    callbackfn(LOAD<T>(arr.buffer_, index), index, arr);
  }
}

var acc: i32 = 0;
var arr = new Array<i32>(1000000);

export function init(): void {
  for (let i = 0; i < arr.length; ++i) {
    arr[i] = i;
  }
}

export function test1(): i32 {
  acc = 0;
  arr.forEach((val: i32, i: i32, array: i32[]): void => {
    acc += val;
  });
  return acc;
}

export function test2(): i32 {
  acc = 0;
  forEach<i32>(arr, (val: i32, i: i32, array: i32[]): void => {
    acc += val;
  });
  return acc;
}