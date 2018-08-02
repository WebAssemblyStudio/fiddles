import "allocator/arena";

declare namespace console {
  function logi(value: i32): void;
  function logf(value: f64): void;
}

class A {
  age: u64;
  setAge(age:u64):void{
    this.age = age;
  }
}

class B extends A{
  year:u64;
}

function assemblyArr<T extends A>(len:i32): T[] {
  let aArr = new Array<T>(len);
  for (let index = 0; index < len; ++index) {
    aArr[index] = {};
    aArr[index].setAge(index);
  }
  return aArr;
}

let arr = assemblyArr<B>(3);
for (let index=0; index < arr.length; index++) {
  console.logf(<f64>arr[index].age);
}
