import {
  loadUnsafe,
  storeUnsafe,
  allocateUnsafe,
} from "internal/arraybuffer";

import "allocator/arena";

const len = 8000000;
var array = new Array<i32>(len);

for (let i = 0; i < len; ++i) {
  array[i] = i;
}

export function filterTest1(): i32 {
  var res = array.filter(function (value: i32, index: i32, arr: i32[]): bool {
    return (index & 15) == 0;
  });
  return res.length;
}

export function filterTest2(): i32 {
  var res = newfilter<i32>(array, function (value: i32, index: i32, arr: i32[]): bool {
    return (index & 15) == 0;
  });
  return res.length;
}


function newfilter<T>(array: T[], callbackfn: (value: T, index: i32, array: Array<T>) => bool): Array<T> {
    var buffer = array.buffer_;
    var length = array.length;
    var result = new Array<T>(length);
    var outBuffer = result.buffer_;
    var count = 0;
    for (let index = 0, toIndex = length; index < min(toIndex, array.length); ++index) {
      let value = loadUnsafe<T,T>(buffer, index);
      if (callbackfn(value, index, array)) {
        storeUnsafe<T,T>(outBuffer, count, value);
        ++count;
      }
    }
    result.length = count;
    return result;
  }