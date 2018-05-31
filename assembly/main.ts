
export function match(value: i32): i32 {
  switch (value) {
    case 1: return 1;
    case 10: return 2;
    case 100: return 3;
    case 1000: return 4;
  }
  return 0;
}

export function match2(value: i32, value2: i32): i32 {
  switch (value) {
    case 1: {
           if (value2 == 1) return 1;
      else if (value2 == 10) return 2;
      break;
    }
    case 2: {
           if (value2 == 100) return 3;
      else if (value2 == 1000) return 4;
      break;
    }
  }
  return 0;
}
