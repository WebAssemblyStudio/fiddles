class Foo {}

export function add(x: i32, y: i32): i32 {
  var foo = new Foo;
  return x + y;
}

add(1, 2);
