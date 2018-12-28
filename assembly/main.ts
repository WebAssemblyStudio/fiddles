import "allocator/arena";

class Serializer {
  public data: Float64Array = new Float64Array(1000);
  public index: i32 = 0;

  public write_two(inst: f64, a: f64, b: f64): void {
    unchecked(this.data[this.index++] = inst);
    this.data[this.index++] = a;
    this.data[this.index++] = b;
  }
}

export function add(x: i32, y: i32): i32 {
  var s = new Serializer();
  s.write_two(1.0, 2.0, 3.0);
  return x + y;
}
