import "allocator/arena";
// import { u128 } from "./u128";
import { safe } from "./safeU128";

declare function log(value: f64): void;

/*
export function foo(x: u128): u128 {
  return u128.shl(x, 1);
}

export function foo2(x: u128): u128 {
  // return new u128(x.lo << 1, (x.hi << 1) | (x.lo >> 63));
  var lo = x.lo;
  return new u128(lo << 1, (x.hi << 1) | (lo >> 63));
}
*/

var a = new safe.u128(1);
var b = new safe.u128(2);
var c = a + b;

log(<f64>c.lo);
