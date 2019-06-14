
declare function logi(value: i32): void;

export function createArray(len: i32): i32 {
  var arr:i32[] = [];
  for (let i = 0; i < len; i ++) {
    arr.push(i);
  }
  return arr.length;
}

logi(createArray(1));
logi(createArray(2));