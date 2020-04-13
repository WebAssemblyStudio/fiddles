declare function sayHello(): void;
import a from "./exported";

sayHello();

export function add(x: i32, y: i32): i32 {
  return x + y;
}
