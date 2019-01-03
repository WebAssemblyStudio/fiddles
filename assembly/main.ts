import "allocator/arena";

export class Vec_3 {
  public x: f64 = 0.0;
  public y: f64 = 0.0;
  public z: f64 = 0.0;

  constructor(x: f64, y: f64, z: f64) {
    this.x = x;
    this.y = y;
    this.z = z;
  }

  add(vec: Vec_3): Vec_3 {
    return new Vec_3(
      this.x + vec.x,
      this.y + vec.y,
      this.z + vec.z,
    );
  }
}