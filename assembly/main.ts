declare function log(a: i32, b: i32): void;

function floorDivide(n: i32, d: i32): i32 {
  return ((n >= 0) ? (n / d) | 0 : ((((n + 1) / d) | 0) - 1));
}

function mod(x: i32, y: i32): i32 {
  return (x - y * floorDivide(x, y)) | 0;
}

function mod2(x: i32, y: i32): i32 {
  return x % y
}

log(mod(3, 4),  3 % 4);
log(mod(-3, 4), -3 % 4);
log(mod(6, 4), 6 % 4);
log(mod(-6, 4), -6 % 4);
