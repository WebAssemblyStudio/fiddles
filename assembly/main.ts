declare function sayHello(): void;

sayHello();

export function add(x: i32, y: i32): i32 {
  return x + y;
}

export class Bruh {
  private val: i16 = 0

  public setV(v: i16): void {
    this.val = v
  }

  public getV(): i16 {
    return this.val
  }
}