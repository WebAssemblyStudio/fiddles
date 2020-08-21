declare function sayHello(): void;

sayHello();

export function add(x: i32, y: i32): i32 {
  const arr = new Array<i32>(10); // 使用基本类型 u64 创建数组
  const zero = arr[0]; // zero 的值是 0
  return x + y + zero;
}
