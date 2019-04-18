
const AL_BITS: u32 = 4; // 16 bytes to fit up to v128
const AL_SIZE: usize = 1 << <usize>AL_BITS;


export function test1(size: usize): u32 {
  return <u32>(size / AL_SIZE);
}

export function test2(size: usize): u32 {
  return <u32>(size >> AL_BITS);
}
