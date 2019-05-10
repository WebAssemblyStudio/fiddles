declare function sayHello(str:string): void;

sayHello("haha");

import {sub}  from "./lib";

export function add(x: i32, y: i32): i32 {
  return sub(x , -y);
}
