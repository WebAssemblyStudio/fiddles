
var _U64hi: u32;

export function getHiPart(): u32 {
  return _U64hi;
}

export function getU64(): u32 {
  var val = <u64>(-1) >> 2;
  _U64hi = <u32>(val >> 32);
  return <u32>val;
}

export function getU64_v2(): f64 {
  var val = <u64>(-1) >> 2;
  return reinterpret<f64>(val);
}
