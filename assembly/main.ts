
function bswap(value: u16): u16 {
  return <u16>((value << 8) | ((value >> 8) & <u16>0x00FF)) & 0xFFFF;
}

assert(bswap(<u16>0xFFAA) == 0xAAFF);
