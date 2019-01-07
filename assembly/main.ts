export const AL_SIZE: u32 = 8;
export const AL_MASK: u32 = AL_SIZE - 1;
export const TEST: u32    = 0xffffffff;

const PAGE_SIZE  = 65536;
const PAGE_MASK  = PAGE_SIZE - 1;
const BLOCK_SIZE = 4096;
const BLOCK_MASK = BLOCK_SIZE - 1;

declare const INIT_64K_PAGECOUNT: u32;
declare const MAX_64K_PAGECOUNT: u32;
declare const X_BUFFER_SIZE: u32; // eXchange Buffer places right after HEAP_BASE, aligned to 8
declare function logger(v: u32): void;

@inline // Shift to next aligned address 
function align(i: u32): u32 {
    return (i + AL_MASK) & ~AL_MASK;
}
@inline // Shift to next aligned address of block
function alignToBlock(i: u32): u32 {
    return (i + BLOCK_MASK) & ~BLOCK_MASK;
}
@inline // Shift to next aligned address of page 
function alignToPage(i: u32): u32 {
    return (i + PAGE_MASK) & ~PAGE_MASK;
}

export function getAligned(offset: u32): void {
    logger(align(offset));
    logger(alignToBlock(offset));
    logger(alignToPage(offset));
}
