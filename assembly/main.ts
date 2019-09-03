export function charsFromByte(byte: u32): u32 {
  let hi = byte >>> 4;
  let lo = byte & 0xF;
  hi += select(0x57, 0x30, hi > 9);
  lo += select(0x57, 0x30, lo > 9);
  return ((lo << 16) | hi);
}

export function charsFromByte2(byte: u32): u32 {
  let hi = byte >>> 4;
  let lo = byte & 0xF;
  return ((87 + hi + (((hi - 10) >> 8) & ~38)) & 0xFFFF) | ((87 + lo + (((lo - 10) >> 8) & ~38)) << 16);
}
