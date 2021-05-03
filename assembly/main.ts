import { NewArray } from "./new-array";

const arr = new NewArray<i32>();

export function test(n: i32): void {
  for (let i = 0; i < n; i++) {
    arr.push(i);
  } 
}
