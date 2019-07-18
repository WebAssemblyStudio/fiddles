declare function sayHello(): void;

sayHello();

export function add(x: i32, y: i32): i32 {
  return x + y;
}

class Test {
  constructor(public x: i32, public y: i32){}
}

const tests: Test[] = new Array<Test>()

export function fill(i: i32):void {
  const t: Test = new Test(i, i*i)
}

export function count(): i32 {
  return tests.length;
}