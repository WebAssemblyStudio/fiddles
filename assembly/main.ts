export function test(): bool {
  var val: i32 = -1;
  var res: u64 = val as u64;
  return res == 0xffffffffffffffff; // true
}
