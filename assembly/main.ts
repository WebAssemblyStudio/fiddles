export function memcmp(vl: usize, vr: usize, n: usize): i32 {
  if (vl == vr) return 0;
  while (n != 0 && load<u8>(vl) == load<u8>(vr)) {
    n--; vl++; vr++;
  }
  return n ? <i32>load<u8>(vl) - <i32>load<u8>(vr) : 0;
}

export function memcmp2(vl: usize, vr: usize, n: usize): i32 {
  if (vl == vr) return 0;
  if (n >= 8 && !((vl & 7) | (vr & 7))) {
    while (n >= 8) {
      if (load<u64>(vl) != load<u64>(vr)) break;
      vl += 8;
      vr += 8;
      n  -= 8;
    }
  }
  while (n--) {
    let a = <i32>load<u8>(vl);
    let b = <i32>load<u8>(vr);
    if (a != b) return a - b;
    vl++; vr++;
  }
  return 0;
}