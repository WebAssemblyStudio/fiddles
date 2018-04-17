export function add(x: i32, y: i32): i32 {
  return (new V(x, y)).add();
}

class V {
  public x: i32;
  public y: i32;
  constructor (x: i32, y: i32) {
    this.x = x;
    this.y = y;
  }
  public add (): i32 {
    return this.x + this.y;
  }
}