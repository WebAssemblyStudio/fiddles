import "allocator/arena"
export { memory }

export function test(): string {
  let byteArray = new Uint8Array(4);
  byteArray[0] = 131;
  byteArray[1] = 100;
  byteArray[2] = 111;
  byteArray[3] = 103;
  let bytes = byteArray.subarray(1);
  return String.fromUTF8(bytes.buffer.data + bytes.byteOffset, byteArray.byteLength);
}
