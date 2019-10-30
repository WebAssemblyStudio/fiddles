
export function test(x: f32, y: f32, z: f32, w: f32): bool {
  return isNaN(x) && isNaN(y) && isNaN(z) && isNaN(w);
}
