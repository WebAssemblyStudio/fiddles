declare function sayHello(): void;

export function loop1(x: i32, y: i32, n: i32): i32 {
  var r: i32 = 0;
  for (let i = -n; i < 0; i += 8) {
    r += x * y;
  }
  return r;
}

export function loop2(x: i32, y: i32, n: i32): i32 {
  var r: i32 = 0;
  for (let i = 0; i < n; i += 8) {
    r += x * y;
  }
  return r;
}
