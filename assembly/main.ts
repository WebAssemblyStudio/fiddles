declare function sayHello(): void;

sayHello();

class MyClass {
  val: i32;
  constructor(val: i32){
    this.val = val;
  }
}

let arr = new Array<Point>();

export function add(x: i32, y: i32): i32 {
  some();
  return x + y;
}


let some = (): void => {
  arr.push(Frame({ x: 1, y: 2 }));
}

type Fix<T> = T | undefined;

type A = Fix<i32>;

class Point {
   x: i32
   y: i32
   z: A = 0
}

function Frame(pt: Point): Point {
  return pt;
}