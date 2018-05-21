import "allocator/arena";

declare function prints(value: usize): void;

export function apply(reviever: u64, code: u64, action: u64): void {
  prints("Hello world".toUTF8());
}
