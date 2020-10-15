export function fib(n: i32): i32 {
  switch (n) {
    case 0:
    case 1: 
    case 2: 
    case 3: 
    case 4: return 1;
  }
  return 0;
}

export function opt(n: i32): i32 {
  return u32(n) <= 4 ? 1 : 0;
}
