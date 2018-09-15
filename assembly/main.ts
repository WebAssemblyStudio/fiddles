export function licmTest(size: i32): i32 {
  var acc = 0;
  for (let i = 0; i < size; i++) {
    var t = <i32>Math.asin(Math.LOG10E);
    acc += t;
  }
  return acc;
}
