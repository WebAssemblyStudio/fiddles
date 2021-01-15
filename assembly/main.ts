declare function sayHello(): void;

sayHello();

abstract class Base<T> {
  abstract doSomething(val: T): void;
}

class A extends Base<i32> {
  doSomething(val: i32): void {

  }
}

let refA: Base<i32> | null = null;


export function add(x: i32, y: i32): i32 {
  let localA: Base<i32> = new A();
  // refA = new A();
  // refA.doSomething(23);
  return x + y;
}
