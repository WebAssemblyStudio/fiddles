export function sum(limit: u32): u32 {
  let sum: u32 = 0;
  for (let i: u32 = 0; i < limit; i++) {
    sum += i;
  }
  return sum;
}