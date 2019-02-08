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
// export function main(s: String): void {
//   let argv: String[] = s.split(" ");
//   log(itoa<i32>(argv.length))

//   for (let i = 0; i< argv.length; i++){
//     log(argv[i]);
//   }
//   let str = "hello we have spaces";
//   let args = str.split(" ");
//   log(itoa<i32>(str.length))

//   for (let i = 0; i< args.length; i++){
//     log(args[i]);
//   }
// }