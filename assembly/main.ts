@unmanaged
class A {
  x: i32;
}

const a: A = {
  x: 1,
};

export function run(): i32 {
  return a.x;
}
