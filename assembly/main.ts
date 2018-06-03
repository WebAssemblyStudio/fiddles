import "allocator/arena";
import { u128 } from "./u128";

declare function log(value: f64): void;

/*
var one = u128.fromI64(-(1 << 63));
log(<f64><i64>(-(1 << 63)));
log(one.toF64());
log(<f64>(<i64>one.hi < 0));
*/

// var a = u128.Max - u128.One;
// var c = a.safeAdd(u128.One);//.safeAdd(u128.Max);
// var c = u128.fromI32(-100);

// log(c.toF64());

export function foo(x: u128): u128 {
  return u128.shl(x, 1);
}

export function foo2(x: u128): u128 {
  // return new u128(x.lo << 1, (x.hi << 1) | (x.lo >> 63));
  var lo = x.lo;
  return new u128(lo << 1, (x.hi << 1) | (lo >> 63));
}
