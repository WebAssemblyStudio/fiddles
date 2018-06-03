import "allocator/arena";
import { u128 } from "./u128";

declare function log(value: f64): void;

/*
var one = u128.fromI64(-(1 << 63));
log(<f64><i64>(-(1 << 63)));
log(one.toF64());
log(<f64>(<i64>one.hi < 0));
*/

function __floatuntidf(a: usize): f64 {
  var t = changetype<u128>(a);

  if (t == 0) return 0.0;

  var v  = t.clone();
  var sd = 128 - u128.clz(v);
  var e  = sd - 1;

  if (sd > 53) {
    if (sd != 55) {
      if (sd == 54) v <<= 1;
      else {
        v = (
          u128.shr(v, sd - 55) |
          u128.fromU32(<u32>(v & (u128.shr(u128.Max, 128 + 55 - sd))) != 0)
        );
      }
    }

    v.lo |= (v.lo & 4) != 0;
    v.inc();
    v >>= 2;

    if (v & u128.shl(u128.One, 53)) {
      v >>= 1;
      ++e;
    }
  } else {
    v = u128.shl(v, 53 - sd);
  }

  var u: u64 = (<u64>((e + 1023) << 20) | ((v >> 32).toU32() & 0x000FFFFF)) << 32; // high part
  return reinterpret<f64>(u | <u64>v.toU32());
}

var a = u128.Max - u128.One;
var c = a.safeAdd(u128.One).safeAdd(u128.Max);

log(c.toF64());
log(__floatuntidf(changetype<usize>(c)));

