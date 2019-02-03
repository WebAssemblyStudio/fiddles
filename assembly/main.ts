declare function sayHello(): void;

sayHello();

export function add(x: i32, y: i32): i32 {
  let r = example();
  return x + y;
}

class Foo{}

function orNull(i: i32): Foo | null {
  if (i%2==0)
  return null;
  return new Foo();
}

function example(): Foo | null {
  let x = orNull(1);
  if (x == null){
    return null;
  }
  return id(x);
}

function id(f: Foo): Foo{
  return f;
}