
export function test(outArr: Int32Array, inArr: Int32Array): void {
  unchecked(outArr[0] = unchecked(inArr[0]));
}
