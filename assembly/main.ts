declare function say(x: string): void;

export function add(x: i32, y: i32): i32 {
  return x + y;
}

class Foo {
  bar() {
    say("What the fuck");
  }
}


class Food {
  bar() {
    say("What the fuck");
  }
}



function xxxxx(a: Foo) {
  a.bar()
}

const x = new Food;

xxxxx(x);