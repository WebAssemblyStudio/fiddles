declare function sayHello(): void;

sayHello();

class Base<T> {
  doSomething(val: T): void {}
}

class A<T> extends Base<i32> {
  doSomething(val: i32): void {

  }
}

class B<T> extends Base<bool> {
  doSomething(val: bool): void {

  }
}

let refA: Base<i32> | null = new A();
let refB: Base<bool> | null = new B();

refA.doSomething(1);
refB.doSomething(false);


export function add(x: i32, y: i32): i32 {
  return x + y;
}
