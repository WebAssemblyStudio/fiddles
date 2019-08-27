
declare function f64toI32_js(val: f64): i32;

export function ftoint_js(x: f64): i32 {
  return f64toI32_js(x);
}

export function ftoint_as(x: f64): i32 {
  let result = 0;
  let u = reinterpret<u64>(x);
  let e = (u >> 52) & 0x7ff;
  if (e <= 1023 + 30) {
    result = <i32>x;
  } else if (e <= 1023 + 30 + 53) {
    let v = (u & ((<u64>1 << 52) - 1)) | (<u64>1 << 52);
    v = v << e - 1023 - 52 + 32;
    result = <i32>(v >> 32);
    result = select<i32>(-result, result, u >> 63);
  }
  return result;
}
