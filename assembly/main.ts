

export function test(fatPtr: f64): f64 {
  let unpackedPtrIn = reinterpret<i64>(fatPtr);
  assert(unpackedPtrIn == 0x80000000_12345678);
  return reinterpret<f64>(unpackedPtrIn);
}
