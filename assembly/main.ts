
declare function fn(x: f32): f32;

// export function test2(n: i32, s: f32, c: f32): f32 {
//   var t = n & 1 ? fn(c) : fn(s);
//   return n & 2 ? -t : t;
// }

export function test3(n: i32, s: f32, c: f32): f32 {
  var t = n & 1 ? fn(c) : fn(s);
  return select(-t, t, n & 2);
}
