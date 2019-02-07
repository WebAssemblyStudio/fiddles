import "allocator/arena";

declare namespace console {
  function logi(value: i32): void;
  function logf(value: f64): void;
}

class A {
  getAge(): i32 {
    return 1;
  }
}

class B extends A {
   getAge(): i32 {
    return 2;
  }
}

function getObject(a: A): A {
  return a;
}

var a = getObject(new A());
var b = getObject(new B());

console.logi(a.getAge());
console.logi(b.getAge());