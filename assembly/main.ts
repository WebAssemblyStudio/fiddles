import "allocator/arena";

declare function log(v: u32): void;

class Base {
  constructor(public id: u32 = 0) {}
}

export class Foo extends Base {
  readonly SOME: u32 = 1;
  // constructor() {
  //  super();
  // }
}

var foo = new Foo();
log(foo.SOME);

