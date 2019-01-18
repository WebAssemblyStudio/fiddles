import "allocator/tlsf";
class Vec_3 {
  x: f64 = 0.0;
  y: f64 = 0.0;
  z: f64 = 0.0;

  @operator.prefix("!")
  protected deref(): usize {
    return changetype<usize>(this);
  }
}

export function add(): usize {
  var vec = new Vec_3();
  // @ts-ignore: deref
  return <usize>!vec;
}
