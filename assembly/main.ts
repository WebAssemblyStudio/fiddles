

export function callIt(f: () => i32): i32 {
	return f();
}

export function test(): f64 {
  return <f64>callIt((): i32 => 10);
}
