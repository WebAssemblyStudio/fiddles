import "allocator/arena";

class Foo {
  constructor(
    public a: i32 = 0
  ) {}
}

class Boo extends Foo {
  constructor(public b: i32 = 0) {
    super(999999);
  }
}

export function test(): i32 {
  var t = new Boo(2);
  return t.a + t.b;
}

