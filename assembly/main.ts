import "allocator/arena";


declare function logi(value: i32): void;
declare function logf(value: f64): void;

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

logi(a.getAge());
logi(b.getAge());