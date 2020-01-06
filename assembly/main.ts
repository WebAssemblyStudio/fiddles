
class Segment {
  constructor(
    public str: string
  ) {}
}

class Foo {
  constructor(
    public pattern: string = "abc abc abc",
    public segments: Segment[] | null = null
  ) {}

  test(): void {
    var ss = this.pattern.split(" ");
    this.segments = ss.map<Segment>(val => new Segment(val));
  }
}

new Foo().test();