import "allocator/arena";
import { HEADER_SIZE } from "internal/arraybuffer";

declare function prints(value: usize): void;

function UTF16LEtoLatin1Ptr(str: string): usize {
  var output = new Array<u8>(str.length + 1);
  for (let i = 0, len: i32 = str.length; i < len; i++) {
    let code = str.codePointAt(i);
    output[i] = code >= 0xFF ? 0 : <u8>code;
  }
  output[str.length] = 0;
  return changetype<usize>(output.buffer_) + HEADER_SIZE;
}

export function apply(reviever: u64, code: u64, action: u64): void {
  prints(UTF16LEtoLatin1Ptr("Hello world"));
}
