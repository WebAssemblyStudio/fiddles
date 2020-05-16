import { network } from './xnet';

declare function sayHello(): void;

sayHello();

export function add(x: i32, y: i32): i32 {
  const n = new network();
  return x + y + n.get_i();
}
