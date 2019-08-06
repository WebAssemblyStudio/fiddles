export function test(arr: Uint8Array): void {
  let sum = unchecked(arr[0]) + unchecked(arr[1]);
  unchecked(arr[3] = sum);
}
