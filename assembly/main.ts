
// declare function log(v: i32): void;

export function toInt32_1(x: f64): i32 {
  const inv32 = 1.0 / 4294967296;
  return <i32><i64>(x - 4294967296 * floor(x * inv32));
}

export function toInt32_2(d: f64): i32 {
  var ret = 0;
  var u = reinterpret<u64>(d);
  var e = (u >> 52) & 0x7ff;
  if (e <= (1023 + 30)) {
    ret = <i32>d;
  } else if (e <= (1023 + 30 + 53)) {
    let v = (u & ((<u64>1 << 52) - 1)) | (<u64>1 << 52);
    v = v << ((e - 1023) - 52 + 32);
    ret = <i32>(v >> 32);
    ret = select<i32>(-ret, ret, u >> 63);
  }
  return ret;
}
