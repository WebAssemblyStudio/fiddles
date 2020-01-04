export function check(): i32 {
  let i: i32 = 0;
  while (i < 32) {
    if (load<i16>(16 + i) == 255) {
      return 0;
    }
    i++;
  }
  return 1;
}