
const arr: i32[] = [1, 2, 3, 4, 5, 6];

export function reduce1(): i32 {
  return arr.reduce<i32>((a, b) => a + b, 0);
}

export function reduce2(): i32 {
  return arr.reduce((a, b) => a + b, 0);
}
