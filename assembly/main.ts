class Base<T> {
  doSomething(val: T): void {

  }
}

class A extends Base<i32> {
  doSomething(val: i32): void {

  }
}

class B extends Base<bool> {
  doSomething(val: bool): void {

  }
}

function test<T>(input: i32, val: T): void {
  const i: Base<T> = changetype<Base<T>>(input);
  i.doSomething(val);
}

let refA = new A();
let refB = new B();

// refA.doSomething(1);
// refB.doSomething(true);

test<i32>(changetype<i32>(refA), 1);
test<bool>(changetype<i32>(refB), false);
