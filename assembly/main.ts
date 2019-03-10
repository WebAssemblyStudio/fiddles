

export function sign1(x: i32): i32 {
  return <i32>(x > 0) - <i32>(x < 0);
}

export function  sign2(x: i32): i32 {
  var y = x >> 31;
  var z = 0 - <u32>x;
  var w = z >> 31;
  return w | y;
}
