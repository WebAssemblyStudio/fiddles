@sealed @unmanaged
class Foo {
  x: f32;
  y: f32;
  z: f32;
}

export function test(): Foo {
  return new Foo();
}