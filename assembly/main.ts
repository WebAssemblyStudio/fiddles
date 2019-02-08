declare function sayHello(): void;
declare function log<T>(i: T): void;
import {itoa} from "internal/number";
import "allocator/arena";
sayHello();

export function add(x: i32, y: i32): i32 {
  return x + y;
}

export function testSplit(): i32 {
  let str = "hell o o o o - - - - - - - -";
  let strs = str.split(" ");
  return strs.length;
}
export function main(): void {

}