declare function sayHello(): void;

sayHello();
export function createArray(length: i32): Int32Array {
  return new Int32Array(length)
}

export const Int32Array_ID = idof<Int32Array>()