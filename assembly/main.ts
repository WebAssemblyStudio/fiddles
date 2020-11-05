class Capsule<T> {
  constructor(
    public value: T = changetype<T>(0)
  ) {

  }
}

export function test(): Capsule<i32> {
  return new Capsule();
}

export function test2(): Capsule<Array<i32> | null> {
  return new Capsule();
}

export function test3(): Capsule<Array<i32> | null> {
  return new Capsule(null);
}

export function test4(): Capsule<Array<i32> | null> {
  return new Capsule([]);
}
