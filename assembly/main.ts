declare function sayHello(): void;

sayHello();

export function add(x: i32, y: i32): i32 {
  return x + y;
}

export function fibonachi(x: i32) : i32 {
  if (x <= 0) {
    return 0;
  } else if (x === 1) {
    return 1;
  } else {
    return fibonachi(x - 1) + fibonachi(x - 2);
  }
}