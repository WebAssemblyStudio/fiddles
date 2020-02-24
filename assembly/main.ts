export function test1(len: i32): i32 {
  let arr = new Array<i32>(len);
  for (let i = 0; i < len; i++) {
    arr[i] = 0;
  }
  return arr.length;
}

export function test2(len: i32): i32 {
  let arr: i32[] = [];
  for (let i = 0; i < len; i++) {
    arr.push(0);
  }
  return arr.length;
}

export function test3(len: i32): i32 {
  let arr = new Array<i32>(len);
  arr.fill(0);
  return arr.length;
}

