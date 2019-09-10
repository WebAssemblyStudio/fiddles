declare function sayHello(): void;


class Foo {
 num: i32 = 1;
}


function fooOrFaa(input: Foo | null): i32 {
  return input.num;
}
export function add(x: i32, y: i32): i32 {
  return fooOrFaa(new Foo());
}
