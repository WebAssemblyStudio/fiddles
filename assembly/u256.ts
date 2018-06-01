import { u128 } from "./u128";

export class u256 {
  static zero: u256 = new u256()
  static one:  u256 = new u256(1)
  static min:  u256 = u256.zero
  static max:  u256 = new u256(<u64>-1, <u64>-1, <u64>-1, <u64>-1)

  @inline
  static fromU128(value: u128): u256 {
    return new u256(value.lo, value.hi);
  }

  @inline
  static fromU64(value: u64): u256 {
    return new u256(value);
  }

  @inline
  static fromI64(value: i64): u256 {
    return new u256(value, 0, 0, -(<u64>(value < 0)));
  }

  @inline
  static fromU128Values(lo: u128, hi: u128): u256 {
    return new u256(lo.lo, lo.hi, hi.lo, hi.hi);
  }

  @inline
  static fromU64Values(lo1: u64, lo2: u64, hi1: u64, hi2: u64): u256 {
    return new u256(lo1, lo2, hi1, hi2);
  }

  @inline
  static fromU32Values(
    l0: u32, l1: u32, l2: u32, l3: u32,
    h0: u32, h1: u32, h2: u32, h3: u32,
  ): u256 {
    return new u256(
      (<u64>l0) | ((<u64>l1) << 32),
      (<u64>l2) | ((<u64>l3) << 32),
      (<u64>h0) | ((<u64>h1) << 32),
      (<u64>h2) | ((<u64>h3) << 32),
    );
  }

  // TODO need improvement
  // max safe int for f64 actually 52-bits
  @inline
  static fromF32(value: f32): u256 {
    return new u256(<u64>value);
  }

  // TODO need improvement
  // max safe uint for f64 actually 52-bits
  @inline
  static fromF64(value: f64): u256 {
    return new u256(<u64>value);
  }

  constructor(
    public lo1: u64 = 0,
    public lo2: u64 = 0,
    public hi1: u64 = 0,
    public hi2: u64 = 0,
  ) {}

  @inline
  copyFrom(other: u256): this {
    this.lo1 = other.lo1;
    this.lo2 = other.lo2;
    this.hi1 = other.hi1;
    this.hi2 = other.hi2;
    return this;
  }

  @inline
  copyFromU128(value: u128): this {
    this.lo1 = value.lo;
    this.lo2 = value.hi;
    this.hi1 = 0;
    this.hi2 = 0;
    return this;
  }

  @inline
  copyFromI64(value: i64): this {
    this.lo1 = value;
    this.lo2 = 0;
    this.hi1 = 0;
    this.hi2 = -(<u64>(value < 0));
    return this;
  }

  @inline
  copyFromU64(value: u64): this {
    this.lo1 = value;
    this.lo2 = 0;
    this.hi1 = 0;
    this.hi2 = 0;
    return this;
  }

  @inline
  copyFromI32(value: i32): this {
    this.lo1 = value;
    this.lo2 = 0;
    this.hi1 = 0;
    this.hi2 = -(<u64>(value < 0));
    return this;
  }

  @inline
  copyFromU32(value: u32): this {
    this.lo1 = value;
    this.lo2 = 0;
    this.hi1 = 0;
    this.hi2 = 0;
    return this;
  }

  // TODO
  // toString(): string
}
