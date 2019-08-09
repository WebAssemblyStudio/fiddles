
class Boo {
  constructor(public name: string) {}
}

class Foo {
  state: Boo[];
  constructor() {
    let state = new Array<Boo>();
    for (let i = 0; i < 2; i++) {
      state.push(new Boo(String.fromCharCode(i)));
    }
    this.state = state;
  }
}

export function test(): void {
  let foo = new Foo();
}
