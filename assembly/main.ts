import "allocator/arena";
import { Action , getMethod, Method, Action1, getMethod1 } from "./name";

declare function sayHello(): void;

sayHello();

export function add(x: i32, y: i32): i32 {
  return x + y;
}


var mth: Method = getMethod("name");
Action.attach(mth, "");


var mth1 = getMethod1("name");
Action1.attachWithoutData(mth1);
Action1.attach(mth1, "");



