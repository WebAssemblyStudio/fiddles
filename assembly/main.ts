// import "allocator/arena";
// export { allocate_memory, free_memory };

declare function sayHello(): void;

sayHello();

export function add(x: i32, y: i32): i32 {
  const v1 = new Vector3(1, 2, 3);
  const v2 = new Vector3(10, 20, 30);
  v2.add(v1);
  return x + y;
}

export function test1(x: f32, y: f32, z: f32): f32[] {
  const v1 = new Vector3(x, y, z);
  const v2 = new Vector3(1, 2, 3);
  v1.add(v2);
  return [v1.x, v1.y, v1.z];
}

//////////////////////////////////////////////////////////////////////

interface IVector3 {
  x: f32;
  y: f32;
  z: f32;
};

class Vector3 {
  constructor(public x: f32, public y: f32, public z: f32) {
  }

  setScalar(scalar): Vector3 {
    this.x = scalar;
    this.y = scalar;
    this.z = scalar;
    return this;
  }

  setX(x: f32): Vector3 {
    this.x = x;
    return this;
  }

  setY(y: f32): Vector3 {
    this.y = y;
    return this;
  }

  setZ(z: f32): Vector3 {
    this.z = z;
    return this;
  }

  clone(): Vector3 {
    return new Vector3(this.x, this.y, this.z);
  }

  copy(v: Vector3): Vector3 {
    this.x = v.x;
    this.y = v.y;
    this.z = v.z;
    return this;
  }

  add(v: Vector3): Vector3 {
    this.x += v.x;
    this.y += v.y;
    this.z += v.z;
    return this;
  }
}