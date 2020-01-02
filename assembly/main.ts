@inline function M6502_SHIFT_PIN<T>(m: T, p0: T,p1: T): T {
  return (m & p0) / p0 * p1;
}

const M6502_A4  = <u64>1 << 4;
const M6522_CS1 = <u64>1 << 40;

export function test(): u64 {
    let m0 = <u64>0x123456789ABCDEF0 | M6502_A4;
    let m1 = <u64>0xFEDCBA9876543210 & ~M6522_CS1;
    m1 |= M6502_SHIFT_PIN(m0, M6502_A4, M6522_CS1);
    return m1;
}
