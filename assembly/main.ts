declare function sayHello(): void;

sayHello();

export function add(x: i32, y: i32): i32 {
  let x_u64: u64 = 4294967297; 2^32 + 1
  let str_u64 = x_u64.toString();
  assert(str_u64 === "4294967297", str_u64 + " is not 4294967297");
  return x + y;
}
