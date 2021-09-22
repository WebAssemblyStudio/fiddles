function freeFunction<T>(value: T): T {
  return value;
}

function bad<T>(value: T, func: (value: T) => T): T {
  return func(value);
}

export function test(): i64 {
  return bad<i64>(123, freeFunction);
}