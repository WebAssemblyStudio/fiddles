declare function sayHello(i: f32): void;
declare function time(x:i32):void;

import "allocator/tlsf";

class Vec4 extends Float32Array {
  public get x(): f32 {
    return this[0];
  }

  public get y(): f32 {
    return this[1];
  }

  public get z(): f32 {
    return this[2];
  }

  public get w(): f32 {
    return this[3];
  }

  public set x(x: f32) {
    this[0] = x;
  }

  public set y(y: f32) {
    this[1] = y;
  }

  public set z(z: f32) {
    this[2] = z;
  }

  public set w(w: f32) {
    this[3] = w;
  }

  public initialize(x: f32 = 0, y: f32 = 0, z: f32 = 0, w: f32 = 0): void {
    this[0] = x;
    this[1] = y;
    this[2] = z;
    this[3] = w;
  }

  //@ts-ignore
  @inline
  //@ts-ignore
  @operator('+')
   //@ts-ignore
  public add(other: Vec4): Vec4 {
    let out = new Vec4(4);
    out.x = other.x + this.x;
    out.y = other.y + this.y;
    out.w = other.w + this.w;
    out.z = other.z + this.z;
    return out;
  }

  public toNumer(): f32 {
    return this.x + this.y + this.z + this.w;
  }
}

let a = new Vec4(4);
a.initialize(1, 2, 3, 4);
let b = new Vec4(4);
b.initialize(1, 2, 3, 4);

sayHello(2);
time(1);
for (let i: i32 = 0; i<100000; i++) {
  //@ts-ignore
  a+b;  
}
time(2);
// sayHello(3);