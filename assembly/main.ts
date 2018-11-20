
declare function log(v: i32): void;

export function test(a: i32, b: i32): i32 {
  switch (true) {
    case a < b:  return -1;
    case a > b:  return +1;
    case a == b: return 0;
  }
  return 0;
}

export function test2(a: i32, b: i32): i32 {
  return a < b ? -1 : a > b ? 1 : 0;
}

export function test3(a: i32, b: i32): i32 {
  return select(-1, select(1, 0, a > b), a < b);
}

