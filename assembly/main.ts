

export function test1(x: i32): i32 {
  switch (x) {
    case 2: return 1;
    case 3: return 5;
  }
  return 0;
}

export function test2(x: i32): i32 {
  if (x == 2) return 1;
  else if (x == 3) return 5;
  else return 0;
}
