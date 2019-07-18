declare function sayHello(x: i32): void;

sayHello(2);

export function add(x: i32, y: i32): i32 {
  return x + y;
}

class Test {
  constructor(public x: i32, public y: i32){}

  sum(): i32 {
    return this.x + this.y;
  }
}

class State {
  public tests: Test[] =[]
}

const s: State = new State();


export function fill(i: i32):void {
  s.tests.push(new Test(i, i))
}

export function count(): i32 {
  return s.tests.length;
}

export function getSum(n: u8): i32 {
  sayHello(n)
  return s.tests[n].x
}