declare function sayHello(): void;

sayHello();

export function add(x: i32, y: i32): i32 {
  let b: bool = true;
  return isBool<boolean>() ? 1 : 0;
}

function isBool<T>(): boolean {
  if (isInteger<T>()){
    return false;
  }
  return isBoolean<T>();
}
