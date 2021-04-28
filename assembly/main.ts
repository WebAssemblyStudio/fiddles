// The entry file of your WebAssembly module.

export function add(a: i32, b: i32): i32 {
  return a + b;
}

export function hello(): string {
  return 'hello, world!';
}

import * as console from "./myConsole";

export function sayHello(): void {
  console.log('hello, world!');
}
