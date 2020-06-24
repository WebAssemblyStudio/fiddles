class MyArray extends Array<u8> {
}

var arr = new MyArray(12);
arr[0] = 1;

export function getFirst(): u8 {
  return arr[0];
}