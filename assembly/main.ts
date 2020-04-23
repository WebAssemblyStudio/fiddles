class X {
  public normal: i32;
  public viaThis: i32;
  constructor(private x: i32) {
    this.viaThis = this.x;
    this.normal = x;
  }
}

const x = new X(4);
export function normal(): u32 {
  return x.normal;
}
export function viaThis(): u32 {
  return x.viaThis;
}
