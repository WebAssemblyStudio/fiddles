export function testShortcutAnd(a: i64, b: i32): bool {
  return (bool(a >> 63) && bool(b));
}

export function testShortcutAnd2(a: i64, b: i32): bool {
  return (bool(i32(a >> 63)) && bool(b));
}

export function testShortcutAnd3(a: i64, b: i32): bool {
  return bool((a >> 63) & b);
}
