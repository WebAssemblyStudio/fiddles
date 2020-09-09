export function crc64_1(crc: u64, seed: u64): u64 {
  let count = 8;

  while (count--) {
    const byte = usize((crc ^ (seed & 0xFF)) & 0xFF);
    crc = load<u64>(byte, crcOffset) ^ (crc >> 8);
    seed >>= 8;
  }
  return crc;
}

export function crc64_2(crc: u64, seed: u64): u64 {
  let byte: usize;
  
  byte = usize((crc ^ (seed & 0xFF)) & 0xFF);
  crc = load<u64>(byte, crcOffset) ^ (crc >> 8);

  byte = usize((crc ^ (seed >> 8 & 0xFF)) & 0xFF);
  crc = load<u64>(byte, crcOffset) ^ (crc >> 8);

  byte = usize((crc ^ (seed >> 16 & 0xFF)) & 0xFF);
  crc = load<u64>(byte, crcOffset) ^ (crc >> 8);

  byte = usize((crc ^ (seed >> 24 & 0xFF)) & 0xFF);
  crc = load<u64>(byte, crcOffset) ^ (crc >> 8);

  byte = usize((crc ^ (seed >> 32 & 0xFF)) & 0xFF);
  crc = load<u64>(byte, crcOffset) ^ (crc >> 8);

  byte = usize((crc ^ (seed >> 40 & 0xFF)) & 0xFF);
  crc = load<u64>(byte, crcOffset) ^ (crc >> 8);

  byte = usize((crc ^ (seed >> 48 & 0xFF)) & 0xFF);
  crc = load<u64>(byte, crcOffset) ^ (crc >> 8);

  byte = usize((crc ^ (seed >> 58)) & 0xFF);
  crc = load<u64>(byte, crcOffset) ^ (crc >> 8);

  return crc;
}

const crcOffset = memory.data<u64>([
  0x0000000000000000, 
  0x7AD870C830358979,
  0xF5B0E190606B12F2
]);