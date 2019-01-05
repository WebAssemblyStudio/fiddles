import "allocator/tlsf";

class vec_3 {
  //public veg: i32[] = new Array<i32>(0);
  public a: i32;
  constructor() {
    this.a = 1;
  }
}

class vec_4 extends vec_3 {
  constructor() {
    super();
  }
}

export function add(x: i32, y: i32): i32 {
  var z = new vec_4();
  return x + y + z.a;
}
