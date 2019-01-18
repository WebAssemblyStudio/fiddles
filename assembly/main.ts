import "allocator/tlsf";
class Vec_3 {
  x: f64 = 0.0;
  y: f64 = 0.0;
  z: f64 = 0.0;

  @operator("*")
  protected deref(value: Vec_3): usize {
    return changetype<usize>(value);
  }
}

export function add(): usize {
  var vec = new Vec_3();
  // @ts-ignore: deref
  return (<Vec_3>null)*vec;
}
