class Test {
  x: i32;

  constructor(x: i32) {
    this.x = x;
  }

  incr(): void {
    this.x += 1;
  }
}

export function one(): i32 {
  const test = new Test(0);
  test.incr();
  return test.x;
}
