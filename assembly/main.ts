import "allocator/arena";

declare namespace console {
  function logi(value: i32): void;
  function logf(value: f64): void;
}

class A {
  age: u64;
}

function assemblyArr(len:i32): A[] {
  let aArr = new Array<A>(len);
  for (let index = 0; index < len; ++index) {
    aArr[index] = { age: index }; 
  }
  return aArr;
}

let arr = assemblyArr(3);
for (let index=0; index < arr.length; index++) {
  console.logf(<f64>arr[index].age);
}
