declare function log(v: i32): void;

let global_id: i32 = 0;

class Base<U> {
  static count: i32 = -1;
  static method() {
    if (this.count < 0) {
      this.count = global_id++;
    }
    return this.count;
  }
}

class Foo extends Base<Foo> {}
class Boo extends Base<Boo> {}

export function test(): void {
  log(Foo.method());
  log(Boo.method());

  log(Foo.method());
  log(Boo.method());
}
