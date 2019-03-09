import "allocator/arena";

var arr = new Uint8Array(32);

export function fill(): void {
  arr.fill(0x66);
}

export function loop(): void {
  for (let i = 0; i < 32; i++) {
    arr[i] = 0x66;
  }
}
