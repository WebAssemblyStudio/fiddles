function closure(): () => i32 {
  return function(): i32 {
    return 100
  }
}

export function test(): i32 {
  return closure()();
}
