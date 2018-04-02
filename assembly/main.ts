declare function sayHello(): void;

// This external JavaScript gets called when the module is initialized.
sayHello();

export function readMemory(ptr: i32): u8 {
  return <u8>load<i32>(ptr);
}

// UTF-8 "0000" => [48, 48, 48, 48] => [0x30, 0x30, 0x30, 0x30] => 0x30303030
const FLUSH : u32 = 0x30303030;

export function GitPktLine_flush(ptr: i32): void {
  store<i32>(ptr, FLUSH);
}

export function GitPktLine_hex(ptr: i32, val: i32): void {
  let bottom8 = val & 0x0000000F;
  if (bottom8 < 10) {
    bottom8 += 0x30; // '0'
  } else {
    bottom8 += 0x37; // 0x37; // 'A' - 10
  }
  store<u8>(ptr, bottom8);
}
