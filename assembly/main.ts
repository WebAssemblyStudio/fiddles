import { NewArray } from "./newarray";

const oldArr = new Array<i32>();
const newArr = new NewArray<i32>();

export function batchPush(n: i32): void {
  for (let i = 0; i < n; i++) {
    oldArr.push(i);
  }
}

export function batchPushNew(n: i32): void {
  for (let i = 0; i < n; i++) {
    newArr.push(i);
  }
}
