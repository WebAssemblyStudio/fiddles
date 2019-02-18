
declare function fn(x: f32): f32;

export function test(n: i32, s: f32, c: f32): f32 {
    switch (n & 3) {
    case 0: {
      return fn(s);
    }
    case 1: {
      return -fn(s)
    }
    case 2: {
      return fn(c);
    }
    case 3:
    default: {
      return -fn(c);
      break;
    }
  }
}

export function test2(n: i32, s: f32, c: f32): f32 {
  var t = n & 1 ? fn(c) : fn(s);
  return n & 2 ? -t : t;
}

export function test3(n: i32, s: f32, c: f32): f32 {
  var t = n & 1 ? fn(c) : fn(s);
  return select(-t, t, n & 2);
}
