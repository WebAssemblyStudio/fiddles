declare function syscall2(n: usize, s: string, len: usize): void;

export function _start(): void {
  println("Hello, world");
  println("Hello, world!");
}

function println(str: string): void {
  syscall2(2, str, str.length);
}
