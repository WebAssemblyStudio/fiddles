export function memcmp(vl: usize, vr: usize, n: usize): i32 {
  if (vl == vr) return 0;
  while (n != 0 && load<u8>(vl) == load<u8>(vr)) {
    n--; vl++; vr++;
  }
  return n ? <i32>load<u8>(vl) - <i32>load<u8>(vr) : 0;
}

export function memcmp2(vl: usize, vr: usize, n: usize): i32 {
  if (vl == vr) return 0;
  while (n--) {
    if (<i32>load<u8>(vl) != <i32>load<u8>(vr)) {
	    return <i32>load<u8>(vl) - <i32>load<u8>(vr);
	  }
    vl++; vr++;
  }
  return 0;
}