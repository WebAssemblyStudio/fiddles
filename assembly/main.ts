
declare function foo1(): bool;
declare function foo2(): bool;

export function unopt(x: i32, y: i32): bool {
  return x > 0 || foo1() || y == 0 || foo2();
}

export function opt(x: i32, y: i32): bool {
  // @ts-ignore
  return (x > 0) | foo1() | (y == 0) | foo2();
}
