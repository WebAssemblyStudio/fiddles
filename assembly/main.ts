import "allocator/arena";

import { LOAD, STORE } from "internal/arraybuffer";

type Comparator<T> = (a: T, b: T) => i32;

const arr: i32[] = [2, 1];

@inline
function sort1<T>(arrbuf: ArrayBuffer, comparator: Comparator<T>): void {
  let a = LOAD<T>(arrbuf, 0),
      b = LOAD<T>(arrbuf, 1);
  if (comparator(a, b) < 0) {
    STORE<T>(arrbuf, 0, b);
    STORE<T>(arrbuf, 1, a);
  }
}

@inline
function sort2<T>(arrbuf: ArrayBuffer, comparator: Comparator<T>): void {
  let a = LOAD<T>(arrbuf, 0),
      b = LOAD<T>(arrbuf, 1),
      c = comparator(a, b);
    STORE<T>(arrbuf, 0, select(b, a, c) < 0);
    STORE<T>(arrbuf, 1, select(a, b, c) < 0);
}

export function bench1(): void {
  for (let i = 0; i < 1000000; i++) {
    sort1<i32>(<ArrayBuffer>(arr.slice().buffer_), (a, b) => a - b);
  }
}

export function bench2(): void {
  for (let i = 0; i < 1000000; i++) {
    sort2<i32>(<ArrayBuffer>(arr.slice().buffer_), (a, b) => a - b);
  }
}
