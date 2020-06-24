

function isType<T, U>(): bool {
  let x: T;
  return x instanceof U;
}

export function shouldBeTrue(): bool {
  return isType<Array<i32>, Array<i32>>();
}

export function shouldBeFalse(): bool {
  return isType<usize, u32>();
}
