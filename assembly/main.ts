declare function log(value: f64): void;

function get_log(d: u32): i32 {
	return <i32>(32 - clz(d));
}

function umulh(a: u32, b: u32): u32 {
  return <u32>((<u64>a * <u64>b) >> 32);
}

function udivmod(n: u32, d: u32): u32 {
  if (d == 1) return n;

  var log = get_log(d);
  // var log = 31 - (<any>Math).clz32(d);
  var align_d: u32 = d << (32 - log);
  var inv: u32 = 1;

  if (align_d) {
    inv = 0x7fffffff - align_d;

    inv = umulh(inv, -umulh(inv, align_d)) << 1; // precision: 6  bits
    inv = umulh(inv, -umulh(inv, align_d)) << 1; // precision: 12 bits
    inv = umulh(inv, -umulh(inv, align_d)) << 1; // precision: 24 bits
    /* on the last iteration we lose some precision because all our ops
       are only 32 bit */
    inv = umulh(inv, -umulh(inv, align_d)) << 1; // 30 bits
    /* The high bit is always one, so shift it off (just like hidden
       bit in floating point) */
    inv = inv << 1;
    /* the last three bits of inv are inaccurate.  The error is in
       the range [3,-4], but we want to bias the error to the low
       side so that it will be in range [0,-7] */
    inv = inv - 3;

    /* inv is 33 bits (with a hidden bit), align_d is 32 bits, but
       note that (1 + frac) * d = d + frac*d. */

    /* we want (mulhu(inv, align_d) + align_d) to be zero.  If it
       comes out less than zero we need to increase inv a little bit */
    inv -= (umulh(inv, align_d) + align_d); // 31 bits
    inv -= (umulh(inv, align_d) + align_d); // 32 bits
    inv -= (umulh(inv, align_d) + align_d); // 33 bits (including hidden bit)
  }

  /* Now we calculate the quotient.  To avoid overflow we don't
    just take (mulhu(inv,n)+n)/2^log, but instead do it in
    pieces: */
  var sh2: i32 = log - 1;
  var t1 = umulh(inv, n);
  /* (t1+(n-t1)/2)/2^(log-1) = ((t1+n)/2)/2^(log-1) =
    (t1+n)/2^log, which is what we wanted, but without any chance
    of overflow into bit 33. */
  return (t1 + ((n - t1) >>> 1)) >>> sh2;
}


function get_log64(d: u64): i32 {
  return <i32>(64 - clz(d));
}

function umulh64(u: u64, v: u64): u64 {
  let u0 = u & 0xFFFFFFFF;
  let v0 = v & 0xFFFFFFFF;

  let u1 = u >> 32;
  let v1 = v >> 32;

  let t = u1 * v0 + (u0 * v0 >> 32);
  let w = u0 * v1 + (t & 0xFFFFFFFF);

  t >>= 32;
  w >>= 32;

  return u1 * v1 + (t + w);
}

function umulh128(u: u128, v: u128): u128 {
  let u0 = u.lo;
  let v0 = v.lo;

  let u1 = u.hi;
  let v1 = v.hi;

  let t = new u128(u1 * v0) + new u128(umulh64(u0, v0));
  let w = new u128(u0 * v1) + t;

  t >>= 64;
  w >>= 64;

  return new u128(u1 * v1) + (t + w);
}

function udivmod64(n: u64, d: u64): u64 {
  if (d == 1) return n;

  var log = get_log64(d);
  var align_d: u64 = d << (64 - log);
  var inv: u64 = 1;

  if (align_d) {
    inv = 0x7fffffffffffffff - align_d;

    inv = umulh64(inv, -umulh64(inv, align_d)) << 1; // precision: 6  bits
    inv = umulh64(inv, -umulh64(inv, align_d)) << 1; // precision: 12 bits
    inv = umulh64(inv, -umulh64(inv, align_d)) << 1; // precision: 24 bits
    inv = umulh64(inv, -umulh64(inv, align_d)) << 1; // precision: 48 bits
    inv = umulh64(inv, -umulh64(inv, align_d)) << 1; // precision: 96 bits
 
    inv <<= 1;
    inv  -= 3;
  }

  var t1 = umulh64(inv, n);
  return (t1 + ((n - t1) >>> 1)) >>> (log - 1);
}

var a: u64 = 10000;
var b: u64 = 24;

log(<f64>(a / b));
log(<f64>udivmod64(a, b));