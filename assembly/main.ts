
class Vec3 {
  constructor(
    public x: f64 = 0,
    public y: f64 = 0,
    public z: f64 = 0,
  ) {}
}

export function dotNotOptimal(a: Vec3[], b: Vec3): f64 {
  var result = 0.0;
  for (let i = 0; i < a.length; i++) {
    result += a[i].x * b.x + a[i].y * b.y + a[i].z * b.z;
  }
  return result;
}

export function dotOptimal(a: Vec3[], b: Vec3): f64 {
  var result = 0.0;
  var bx = b.x, by = b.y, bz = b.z; // caching
  var len = a.length; // caching
  for (let i = 0; i < len; i++) {
    let v = a[i];
    result += v.x * bx + v.y * by + v.z * bz;
  }
  return result;
}
