declare function sayHello(): void;

sayHello();

export function add(x: i32, y: i32): i32 {
  return x + y;
}


export class Test {

  getType<T>(ele: T): i32 {
    if (isString<T>(ele)) {
      return 1;
    }
    return 0;
  }

  test(): void {
    this.getType(12)
  }
}