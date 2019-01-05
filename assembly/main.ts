import "allocator/tlsf";

class vec_3<T> {
  public veg: T[] = new Array<T>(0);

  constructor() {

  }
}

class vec_4 extends vec_3<i32> {
  constructor() {
    super(); 
  }
}

export function add(x: i32, y: i32): i32 {
  var z = new vec_4();
  return x + y;
}
