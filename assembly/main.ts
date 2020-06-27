declare function log(v: i32): void;

let global_id: i32 = 0;

class Base {
  static count: i32 = -1;
  static method(): i32 {
    if (this.count < 0) {
      this.count = global_id++;
    }
    return this.count;
  }
}

class Foo extends Base {}
class Boo extends Base {}

export function test(): void {
  log(Foo.method());
  log(Boo.method());

  log(Foo.method());
  log(Boo.method());
}
