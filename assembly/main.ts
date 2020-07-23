export const Uint32Array_ID = idof<Uint32Array>();

const stack = new StaticArray<u32>(100);

export function floodFill(x: u32, y: u32, color: u32, width: u32, height: u32, data: Uint32Array): u32 {
  const index: u32 = (x + y * width);
  const oldc32 = data[index];

  let stackIndex: u32 = 0;
  let count: u32 = 0;

  unchecked(stack[stackIndex ++] = x);
  unchecked(stack[stackIndex ++] = y);

  while (stackIndex > 0) {
    const cy = unchecked(stack[--stackIndex]);
    const cx = unchecked(stack[--stackIndex]);

    if (stackIndex < 0) {
      break;
    }

    const i:u32 = (cx + cy * width);

    unchecked(data[i] = color);
    count++;

    // unroll
    // for (let j = 0; j < 4; j ++) {

    // j = 0;
    let nx: u32 = cx + 0;
    let ny: u32 = cy - 1;

    if (nx >= 0 && ny >= 0 && nx < width && ny < height) {
      const ni = (nx + ny * width);
      
      if (unchecked(data[ni]) === oldc32) {
        unchecked(stack[stackIndex++] = nx);
        unchecked(stack[stackIndex++] = ny);
      }
    }

    // j = 1
    nx = cx + 1;
    ny = cy + 0;

    if (nx >= 0 && ny >= 0 && nx < width && ny < height) {
      const ni = (nx + ny * width);
      
      if (unchecked(data[ni]) === oldc32) {
        unchecked(stack[stackIndex++] = nx);
        stack[stackIndex++] = ny;
      }
    }

    // j = 2
    nx = cx + 0;
    ny = cy + 1;

    if (nx >= 0 && ny >= 0 && nx < width && ny < height) {
      const ni = (nx + ny * width);
      
      if (unchecked(data[ni]) === oldc32) {
        unchecked(stack[stackIndex++] = nx);
        unchecked(stack[stackIndex++] = ny);
      }
    }

    // j = 3
    nx = cx - 1;
    ny = cy + 0;

    if (nx >= 0 && ny >= 0 && nx < width && ny < height) {
      const ni = (nx + ny * width);
      
      if (unchecked(data[ni]) === oldc32) {
        unchecked(stack[stackIndex++] = nx);
        unchecked(stack[stackIndex++] = ny);
      }
    }
  }
  return count;
}
