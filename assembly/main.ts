export function test1(x: i32): i32 {
  return x < -0x40000000 ? -0x40000000 : (x > 0x3FFFFFFF ? 0x3FFFFFFF : x);
}

export function test2(x: i32): i32 {
  return max<i32>(-0x40000000, min<i32>(0x3FFFFFFF, x));
}

@inline
function _min(a: i32, b: i32): i32 {
  var d = a - b;
  return b + (d & d >> 31);
}

@inline
function _max(a: i32, b: i32): i32 {
  var d = a - b;
  return a - (d & d >> 31);
}

export function test3(x: i32): i32 {
  return _max(-0x40000000, _min(0x3FFFFFFF, x));
}
