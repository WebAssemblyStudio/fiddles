//constants for colors
const BLACK = 0x000000;
const WHITE = 0xFFFFFF;

const IMAGE = [0xffffff, 0xffffff, 0xffffff, 0xffffff, 0xffffff, 0xffffff, 0xffffff, 0xffffff, 0xffffff, 0xffffff, 0xffffff, 0xffffff, 0xffffff, 0xffffff, 0xffffff, 0xffffff, 0xffffff, 0xffffff, 0xffffff, 0xffffff, 0xffffff, 0xffffff, 0xffffff, 0xffffff, 0xffffff, 0xffffff, 0xffffff, 0xffffff, 0xffffff, 0x000000, 0x000000, 0x000000, 0x000000, 0xffffff, 0xffffff, 0x000000, 0xffffff, 0xffffff, 0xffffff, 0xffffff, 0xffffff, 0x000000, 0xffffff, 0xffffff, 0x000000, 0xffffff, 0xffffff, 0xffffff, 0xffffff, 0xffffff, 0xffffff, 0x000000, 0x000000, 0xffffff, 0xffffff, 0xffffff, 0xffffff, 0x000000, 0xffffff, 0xffffff, 0xffffff, 0xffffff, 0xffffff, 0x000000, 0xffffff, 0x000000, 0x000000, 0xffffff, 0x000000, 0x000000, 0xffffff, 0xffffff, 0x000000, 0xffffff, 0xffffff, 0xffffff, 0xffffff, 0xffffff, 0xffffff, 0x000000, 0x000000, 0xffffff, 0xffffff, 0xffffff, 0x000000, 0x000000, 0xffffff, 0xffffff, 0xffffff, 0xffffff, 0xffffff, 0xffffff, 0xffffff, 0x000000, 0x000000, 0xffffff, 0xffffff, 0x000000, 0xffffff, 0xffffff, 0x000000, 0xffffff, 0xffffff, 0xffffff, 0xffffff, 0x000000, 0xffffff, 0x000000, 0x000000, 0x000000, 0x000000, 0xffffff, 0x000000, 0x000000, 0xffffff, 0x000000, 0x000000, 0xffffff, 0x000000, 0x000000, 0xffffff, 0x000000, 0x000000, 0xffffff, 0xffffff, 0x000000, 0x000000, 0x000000, 0x000000, 0xffffff, 0x000000, 0x000000, 0xffffff, 0x000000, 0xffffff, 0x000000, 0x000000, 0xffffff, 0x000000, 0x000000, 0x000000, 0x000000, 0xffffff, 0xffffff, 0x000000, 0xffffff, 0xffffff, 0x000000, 0xffffff, 0x000000, 0xffffff, 0xffffff, 0xffffff, 0x000000, 0xffffff, 0xffffff, 0x000000, 0xffffff, 0x000000, 0xffffff, 0xffffff, 0x000000, 0xffffff, 0x000000, 0x000000, 0xffffff, 0x000000, 0x000000, 0xffffff, 0x000000, 0xffffff, 0xffffff, 0x000000, 0xffffff, 0xffffff, 0x000000, 0xffffff, 0x000000, 0x000000, 0xffffff, 0xffffff, 0x000000, 0xffffff, 0xffffff, 0x000000, 0xffffff, 0x000000, 0x000000, 0xffffff, 0x000000, 0xffffff, 0x000000, 0x000000, 0xffffff, 0x000000, 0x000000, 0xffffff, 0xffffff, 0x000000, 0x000000, 0x000000, 0xffffff, 0xffffff, 0x000000, 0xffffff, 0xffffff, 0x000000, 0xffffff, 0xffffff, 0x000000, 0xffffff, 0xffffff, 0x000000, 0xffffff, 0xffffff, 0x000000, 0x000000, 0x000000, 0xffffff, 0xffffff, 0x000000, 0x000000, 0x000000, 0xffffff, 0xffffff, 0xffffff, 0xffffff, 0xffffff, 0xffffff, 0xffffff, 0xffffff, 0xffffff, 0xffffff, 0xffffff, 0xffffff, 0xffffff, 0xffffff, 0xffffff, 0xffffff, 0xffffff, 0xffffff, 0xffffff, 0xffffff, 0xffffff, 0xffffff, 0xffffff, 0xffffff, 0xffffff, 0xffffff, 0xffffff, 0xffffff, 0xffffff];

const CONT_COLORS = [0xc6e48b, 0x7bc96f, 0x239a3b, 0x196127, 0xfffffff];

const WIDTH = 28;
const HEIGHT = 9;
let CONTRIBUTIONS = [];



function drawFrame(frame) {

  const count = Math.floor(frame.frameNumber / 10);

  // clear canvas
  for (let y = 0; y < frame.height; y++) {
    for (let x = 0; x < frame.width; x++) {
      frame.color = WHITE;
      frame.setPixel(x, y);
    }
  }

  // Draw image at offset
  let positions = [];
  let max = frame.width - WIDTH + 1;
  for (let i = 1; i < max - 1; i++) positions.push(i);
  for (let i = max - 3; i > 1; i--) positions.push(i);

  // Draw image at front of tunnel
  let offset_x = positions[count % positions.length];
  let offset_y = 2;
  for (var i = 0; i < IMAGE.length; i++) {
    let y = Math.floor(i / WIDTH);
    let x = i % WIDTH;

     frame.color = IMAGE[i];
     frame.setPixel(x + offset_x, y + offset_y);
  }

  // Draw image at back of tunnel
  offset_x = max - positions[count % positions.length] - 2; // how far to push logo over
  offset_y = frame.height - HEIGHT - 2;
  for (var i = 0; i < IMAGE.length; i++) {
    let y = Math.floor(i / WIDTH);
    let x = i % WIDTH;

     frame.color = IMAGE[i];
     frame.setPixel(WIDTH - x + offset_x, HEIGHT - y + offset_y);
  }

const num_bars = 7;

  // Conditionally change contributions
  if (frame.frameNumber % 10 === 0) {
      const local = [];
    for (let l = 0; l < num_bars; l++) {
      const rand = Math.floor(Math.random() * CONT_COLORS.length)
      local.push(CONT_COLORS[rand]);
    }
    if (CONTRIBUTIONS.length >= frame.width) {
      CONTRIBUTIONS.pop();
    }
    CONTRIBUTIONS.unshift(local);
  }

  // Draw contributions
  offset_y = Math.floor(frame.height / 2 - 7 / 2);
  for (let x = 0; x < frame.width; x++) {
    const local = CONTRIBUTIONS[x];
    if (!local) continue;
    for (let y = 0; y < num_bars; y++) {
      frame.color = local[y];
      frame.setPixel(x, offset_y + y);
    }
  }
  
}

class Frame {
    constructor(buffer, rows, cols, frameNumber) {
        this.width = cols
        this.height = rows
        this.frameNumber = frameNumber
        this.frameSize = 3 * rows * cols
        //data is a ref to just the slice of the buffer for this frame
        this.data = new Uint8Array(buffer, this.frameSize*this.frameNumber, this.frameSize)
    }

    setPixel(x,y) {
        let n = (y*this.width+x)*3
        this.data[n+0] = (this.color & 0xFF0000) >> 16;
        this.data[n+1] = (this.color & 0x00FF00) >> 8;
        this.data[n+2] = (this.color & 0x0000FF) >> 0;
    }

}


export function transform(buffer, rows, cols, frameCount, fps, isFirst) {
    for (let i = 0; i < frameCount; i++) drawFrame(new Frame(buffer, rows, cols, i))
}

export default function () {
    return Promise.resolve({
        transform,
    })
}
