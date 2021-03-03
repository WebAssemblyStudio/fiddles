declare function sayHello(): void;

sayHello();

class Foo {
  constructor(
   public  num: i32
  ) {}
}
export function add(x: i32, y: i32): i32 {
  const s1: Set<Foo> = new Set();
  s1.add(new Foo(1));
  s1.add(new Foo(1));
  s1.add(new Foo(1));
  return s1.values().length;
}
