declare function sayHello(): void;


class Foo {
 num: i32 = 1;
}

class Faa {
  num2: i32 = 2;
}


function fooOrFaa<F = Foo> (input: F): i32 {
  if (input instanceof Foo)
    return input.num
  if (input instanceof Faa)
    return input.num2;
  return 0;
}
export function add(x: i32, y: i32): i32 {
  return fooOrFaa(new Foo());
}
