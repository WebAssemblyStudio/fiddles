import "allocator/arena";

declare function sayHello(): void;

class u128 {

  constructor(
    public lo: u64 = 0,
    public hi: u64 = 0,
  ) {}

  @inline @operator('+')
  static add<T>(a: u128, b: T): u128 {
    var bl: u64 = 0;
    var bh: u64 = 0;
  
    /*if (b instanceof u128) {
      bl = (<u128>b).lo;
      bh = (<u128>b).hi;
    } else if (b instanceof u64) {
      bl = <u64>b;
      bh = 0;
    } else if (b instanceof i64) {
      bl = <u64>b;
      bh =-(<i64>((<i64>b) < 0));
    }*/

    var lo = a.lo + bl;
    var hi = a.hi + bh;
        hi += <u64>(lo < bl);
    return new u128(lo, hi);
  }
}

export function main(): u128 {
  var a = new u128(1);
  var b = new u128(2);
  return u128.add(a, b);
}