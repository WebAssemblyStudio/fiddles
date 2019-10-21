
const arr1 = new Array<i32>(10000);
const arr2 = new Array<i32>(10000);

function test(arr: i32[], b: i32): void {
	for (let i = 0; i < arr.length; i++) {
    arr[i] = b + 100;
  }
}

function test2(arr: i32[], b: i32): void {
  let val = b + 100;
  let len = arr.length;
  let buf = arr.dataStart;
	for (let i = 0; i < len; i++) {
    store<i32>(buf + (i << 2), val);
  }
}

export function bench1(n: i32): void {
  test(arr1, n);
}

export function bench2(n: i32): void {
  test2(arr2, n);
}