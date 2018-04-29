declare function sayHello(): void;

sayHello();


export function add(): i32 {
  let a : i32 = 0;
  a = (a = a + 1) + (a = a + 1);
  return a;
}
