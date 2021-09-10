


// 413 bytes
export function saw(x: f32, amp: f32, freq: f32): f32 {
  const hpi: f32 = Mathf.PI / 2.0;
  const norm: f32 = 2.0 / Mathf.PI;
  return amp * (norm * abs(Mathf.PI - abs(freq * x - hpi) % (2.0 * Mathf.PI)) - 1.0);
}

// 1.2 kb
// export function sin(x: f32, amp: f32, freq: f32): f32 {
//   return amp * Mathf.sin(x * freq);
// }
