import { hash } from './lib';
declare function sayHello(): void;

declare interface Options {
  a: i32;
  b?: i32;
}

class Settings implements Options {
  a = 2;
}

const enum PlacementType {
  'none', 'box', 'spiral'
}

sayHello();

export function add(x: i32, y: i32): i32 {
  return x + y;
}
