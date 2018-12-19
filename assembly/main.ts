
import "allocator/arena";

let arr:  Array<i32>;
let arr2: Array<i32>;
let arr3: Array<i32>;
let arr4: Array<i32>;

let area: i32 = 0;

export function init(width: i32, height: i32): void {
  area = width * height;
  arr  = new Array<i32>(area);
  arr2 = new Array<i32>(area);
  arr3 = new Array<i32>(area);
  arr4 = new Array<i32>(area);

  for (let i = 0; i < area; ++i) {
    arr[i]  = 0;
    arr2[i] = i;
    arr3[i] = area - 1 - i;
    arr4[i] = i * 2 + 1;
  }
}

export function test_slow(): void {
  for (let i = 0; i < area; ++i) {
    arr[i] += arr2[i] * arr3[i] / arr4[i];
  }
}

export function test_fast(): void {
  let _area = area, _arr = arr, _arr2 = arr2, _arr3 = arr3, _arr4 = arr4;
  for (let i = 0; i < _area; ++i) {
    _arr[i] += _arr2[i] * _arr3[i] / _arr4[i];
  }
}
