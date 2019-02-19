declare function sayHello(): void;

sayHello();
/** Number of alignment bits. */
export const AL_BITS: u32 = 3;
/** Number of possible alignment values. */
export const AL_SIZE: usize = 1 << <usize>AL_BITS;
/** Mask to obtain just the alignment bits. */
export const AL_MASK: usize = AL_SIZE - 1;
/** Maximum 32-bit allocation size. */
export const MAX_SIZE_32: usize = 1 << 30; // 1GB

export function add(x: i32, y: i32): i32 {
  return x + y;
}

var startOffset: usize = (HEAP_BASE + AL_MASK) & ~AL_MASK;
var offset: usize = startOffset;

// Memory allocator interface

