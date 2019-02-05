import "allocator/arena";

export class U128 {
  constructor(public lo: u64 = 0, public hi: u64 = 0) {}
}

export class u128 extends U128 {
  @inline static get Zero(): u128 { return new u128(); }
  @inline static get One():  u128 { return new u128(1); }
  @inline static get Min():  u128 { return new u128(); }
  @inline static get Max():  u128 { return new u128(-1, -1); }
}

export function test(): u128 {
  var a = u128.Max;
  return a;
}


