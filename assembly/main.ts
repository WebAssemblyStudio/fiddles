
function bar(): u8 {
  return 255;
}

export function test(): u32 {
  let tmp: u16 = 3127;
  let foo: u16 = (tmp >> 12) + 2;
  if (foo == 2) {
    foo += bar() + 0x10;
    // foo += 255 + 0x10;
  }
  return foo;
}
