memory.grow(200 * 4 * 4);

function xyToIndex(width: i32, x: i32, y: i32, xOffset: i32, yOffset: i32, colorOffset: i32): i32 {
  let pixelIndex = width * (y + yOffset) + x + xOffset;
  return sizeof<i16>() * (pixelIndex * 4 + colorOffset);
}

export function boxBlur(width: i32, height: i32): void {
    let factor = 9;
    for (let j = 1; j < height - 1; j += 1) {
        for (let i = 1; i < width - 1; i += 1) {
            let r = load<i16>(xyToIndex(width, i, j, -1, -1, 0));
            store<i16>(xyToIndex(width, i, j, 0, 0, 0), r / factor);
        }
    }
}

export function boxBlur_2(width: i32, height: i32): void {
    let factor = 9;
    let h = height - 1;
    let w = width - 1;
    let w8 = 8 * width;
    for (let j = 1; j < h; j++) {
       let w8j = w8 * j;
        for (let i = 1; i < w; i++) {
          let idxStore = w8j + 8 * i;
          let idxLoad  = idxStore - w8 - 8;

          let r = load<i16>(idxLoad);
          store<i16>(idxStore, r / factor);
        }
    }
}