@unmanaged
class A {
  x: i32;
}

const a: A = {
  x: 1,
};

export function run(): void {
  trace("", 1, a.x);
}
