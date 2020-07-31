


export function test1(x: u8): i32 {
  return popcnt(x);
}


export function test2(x: u8): i32 {
  let v = x as u32;
  const tbl: u8[] = [
    0, 1, 1, 2, 1, 2, 2, 3, 1, 2, 2,
    3, 2, 3, 3, 4, 1, 2, 2, 3, 2, 3,
    3, 4, 2, 3, 3, 4, 3, 4, 4, 5
  ];
  return tbl[v & 0xf] + tbl[v >> 4];
}
