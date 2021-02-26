abstract class Base<T> {
  abstract doSomething(val: T): void;
}

class A extends Base<i32> {
  doSomething(val: i32): void {

  }
}

class B extends Base<bool> {
  doSomething(val: bool): void {

  }
}

function test<T>(input: Base<T>, val: T): void {
  input.doSomething(val);
}

let refA = new A();
let refB = new B();

test<i32>(refA, 1);
test<bool>(refB, false);
