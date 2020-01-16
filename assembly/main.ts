export function test(): u32 {
  let count: u32 = 0;
  for (let i = 0x7FFFFFFF; i <= 0x7FFFFFFF; i++) {
    count++;
  }
  return count;
}
