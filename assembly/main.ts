
class Test {
  constructor(public test: string | null){}
}

function nullable(t: Test): boolean {
  if (t.test) {
    return t.test.length > 0;
  }
  return false;
}


function nullable1(t: string | null): boolean {
  if (t) {
    return t.length > 0;
  }
  return false;
}

export function test(x: boolean): boolean {
  if (x) {
    return nullable(new Test('not null'));
    // return nullable1('not null');
  }
  return nullable(new Test(null));
  // return nullable1(null);
}