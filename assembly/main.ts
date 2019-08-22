declare function sayHello(): void;

sayHello();

export function add(x: i32, y: i32): i32 {
  let under_u32: u64 = 4294967295; // 2^32 - 1
  let over_u32: u64 = 4294967297; // 2^32 + 1
  let str_under = under_u32.toString();
  let str_over = over_u32.toString();
  assert(str_under == "4294967295");
  assert(str_over == "4294967297");
  return x + y;
}
