

export function copy(src: usize, dst: usize, len: usize): void {
  memory.copy(src, dst, len);
}
