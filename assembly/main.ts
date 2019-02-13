export function testLogic(a: i32, b: i32): bool {
  return <bool>(<i32>(a > 0) & <i32>(a < 10) & <i32>(b > 1) & <i32>(b < 20) & <i32>(a != 4) & <i32>(b != 4));
}

export function testLogic2(a: i32, b: i32): bool {
  return <bool>((<i32>(a > 0) & <i32>(a < 10)) && (<i32>(b > 1) & <i32>(b < 20)) && (<i32>(a != 4) & <i32>(b != 4)));
}

export function testLogic3(a: i32, b: i32): bool {
  return a > 0 && a < 10 && b > 1 && b < 20 && a != 4 && b != 4;
}