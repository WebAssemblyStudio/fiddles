
function bswap(value: u16): u16 {
  return ((value << 8) | ((value >> 8) & <u16>0x00FF));
}

assert(bswap(<u16>0xFFAA) == 0xAAFF);
