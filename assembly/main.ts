import 'allocator/arena';

class a {
  constructor(
    public func: (ptr: usize, signal: i32) => i32
  ) {}
}

class test1 extends a {
  x: i32 = 22;

  constructor() {
    super((inst: usize, signal: i32): i32 => {
      return changetype<test1>(inst).x + signal;
    })
  }
}

class test2 extends a {
  y: i32 = 22;

  constructor() {
    super((inst: usize, signal: i32): i32 => {
      return changetype<test2>(inst).y + 322 + signal;
    })
  }
}

const commands: a[] = [new test1(), new test2()];

export function callfunc(ndx: u32, signal: i32): i32 {
  return commands[ndx].func(changetype<usize>(commands[ndx]), signal);
}