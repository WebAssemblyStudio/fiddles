export function f1(x: number): number {
  if (x === 1 || x === 2) {
    return 1;
  }
  return f1(x - 1) + f1(x - 2);
}

export function f2(x: number): number {
  if (i32(x === 1) | i32(x === 2)) {
    return 1;
  }
  return f2(x - 1) + f2(x - 2);
}

export function f3(x: number): number {
  do {
    if (x === 1) {
      break;
    }
    if (x === 2) {
      break;
    }
    return f3(x - 1) + f3(x - 2);
  } while (false);
  return 1;
}

export function f4(x: number): number {
  if (x === 1) {
    return 1;
  }
  if (x === 2) {
    return 1;
  }
  return f4(x - 1) + f4(x - 2);
}

export function f5(x: i32): i32 {
  do {
    if (x === 1) {
      break;
    }
    if (x === 2) {
      break;
    }
    return f5(x - 1) + f5(x - 2);
  } while (false);
  return 1;
}