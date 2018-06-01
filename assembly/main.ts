import "allocator/arena";
import { u128 } from "./u128";
export { u128 };

declare function log(value: f64): void;

var one = u128.fromI64(-(1 << 63));
log(<f64><i64>(-(1 << 63)));
log(one.toF64());
log(<f64>(<i64>one.hi < 0));

