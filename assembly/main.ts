let d = 1

export function testLet2(): i32 {
  let d = (d = 2, 3);
  return d;
}
