import init from './init.js';

declare function sayHello(): void;

sayHello();
init()

export function add(x: i32, y: i32): i32 {
  return x + y;
}
