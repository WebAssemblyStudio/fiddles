import "allocator/arena";


declare function log(v: i32): void;

/*
// u8 =>  8  bits
// u16 => 16 bits
// u32 => 32 bits
// u64 => 64 bits
export class fp128<Q> {
  constructor(public lo: i64 = 0, public hi: i64 = 0) {}

  @inline
  get fractBits(): i32 {
    return 8 * sizeof<Q>();
  }
}

const a = new fp128<u8>(1);

log(a.fractBits);
*/

class Foo<Q> {
  @inline
  get fractBits(): i32 {
    return 8 * sizeof<Q>();
  }
}

const a = new Foo();
log(a.fractBits);