
declare function _print(ptr: usize, len: i32): void;

function print(str: string): void {
    const buffer = String.UTF8.encode(str);
    _print(changetype<usize>(buffer), buffer.byteLength);
}

export function main(): void {
  print("setup");
}
