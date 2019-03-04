

export function sin(x: f32): f32 {
  var y: f32, z: f32;
  x *= 1 / Mathf.PI;
  y  = Mathf.floor(x);
  z  = x - y;
  z *= 1.0 - z;
  z *= 3.6 * z + 3.1;
  return select(-z, z, <i32>y & 1);
}

export function cos(x: f32): f32 {
  return sin(x + Mathf.PI * .5);
}
