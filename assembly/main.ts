export function compared(
  r1:i32,
  g1:i32,
  b1:i32,

  r2:i32,
  g2:i32,
  b2:i32,
):i32{
  let _r = r1-r2;
  let _g = g1-g2;
  let _b = b1-b2;

  if(Math.sqrt(Math.pow(_r,2)+Math.pow(_g,2)+Math.pow(_g,2))<150){
    return 1;
  }
  return 0;
}

export function compared2(
  r1:i32,
  g1:i32,
  b1:i32,

  r2:i32,
  g2:i32,
  b2:i32,
): bool {
  let dr = r1 - r2;
  let dg = g1 - g2;
  let db = b1 - b2;
  return Math.sqrt(dr * dr + dg * dg + db * db) < 150;
}
