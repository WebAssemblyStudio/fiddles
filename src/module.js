//constants for colors
const BLACK = 0x000000;
const WHITE = 0xFFFFFF;

const IMAGE = [0x000000, 0x151115, 0x151013, 0x141013, 0x161013, 0x151013, 0x000000, 0x151015, 0x160f12, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x150f13, 0x161014, 0x000000, 0x000000, 0x151113, 0x161014, 0x171717, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x140f14, 0x151013, 0x170e13, 0x000000, 0x000000, 0x000000, 0x151015, 0x151013, 0x171115, 0x151113, 0x151013, 0x151013, 0x000000, 0x161013, 0x161114, 0x240000, 0x150e12, 0x161112, 0x1a0d0d, 0x000000, 0x151013, 0x151013, 0x1a1a1a, 0x000000, 0x151013, 0x161114, 0x180c18, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x151013, 0x191317, 0x140f14, 0x000000, 0x000000, 0x000000, 0x151013, 0x171215, 0x140f14, 0x000000, 0x000000, 0x000000, 0x000000, 0x140f14, 0x151113, 0x000000, 0x151013, 0x181316, 0x170e13, 0x000000, 0x161013, 0x161013, 0x000000, 0x000000, 0x150f14, 0x141013, 0x170c17, 0x200020, 0x200020, 0x000000, 0x111111, 0x000000, 0x141114, 0x171215, 0x151012, 0x101010, 0x131313, 0x000000, 0x151014, 0x151013, 0x000000, 0x121212, 0x161010, 0x171111, 0x1c1c1c, 0x141013, 0x151113, 0x160f14, 0x151013, 0x151113, 0x151013, 0x140f14, 0x151013, 0x151013, 0x141012, 0x160f14, 0x151013, 0x151013, 0x141114, 0x151013, 0x141012, 0x000000, 0x151013, 0x141013, 0x161113, 0x161114, 0x151013, 0x151013, 0x150f13, 0x141114, 0x141013, 0x151013, 0x000000, 0x140f13, 0x171215, 0x161114, 0x150f12, 0x151012, 0x141013, 0x141114, 0x141013, 0x151013, 0x151013, 0x130e13, 0x151014, 0x161114, 0x161114, 0x161114, 0x161114, 0x151012, 0x150f12, 0x171215, 0x150f13, 0x000000, 0x151013, 0x151013, 0x141114, 0x171115, 0x160f12, 0x140f14, 0x161114, 0x151013, 0x141013, 0x151013, 0x000000, 0x121212, 0x151013, 0x171215, 0x160f12, 0x150f14, 0x151013, 0x000000, 0x151013, 0x171115, 0x131313, 0x000000, 0x151013, 0x141013, 0x121212, 0x141414, 0x151013, 0x151013, 0x161013, 0x161114, 0x161014, 0x000000, 0x151013, 0x161013, 0x141114, 0x171215, 0x141014, 0x000000, 0x151013, 0x151013, 0x141013, 0x171215, 0x140f14, 0x000000, 0x160f12, 0x171215, 0x161013, 0x151012, 0x151013, 0x000000, 0x161014, 0x171114, 0x170f17, 0x000000, 0x150f13, 0x151013, 0x000000, 0x000000, 0x161013, 0x151013, 0x161013, 0x171114, 0x151113, 0x000000, 0x151013, 0x141113, 0x150f12, 0x171215, 0x161013, 0x000000, 0x151013, 0x151013, 0x161010, 0x151013, 0x171115, 0x151013, 0x151013, 0x181216, 0x141114, 0x151014, 0x161114, 0x000000, 0x160f14, 0x181216, 0x151014, 0x130f13, 0x151013, 0x161013, 0x1c1c1c, 0x000000, 0x151012, 0x151013, 0x170f13, 0x161114, 0x151013, 0x151013, 0x171215, 0x151012, 0x150f12, 0x181216, 0x151013, 0x151013, 0x171215, 0x141013, 0x000000, 0x140f14, 0x151114, 0x151113, 0x151014, 0x150f13, 0x1a0d1a, 0x141012, 0x161013, 0x000000, 0x101010, 0x141013, 0x151013, 0x150f12, 0x161014, 0x151013, 0x000000, 0x000000, 0x161014, 0x151114, 0x1c1c1c, 0x150f13, 0x151014, 0x151013, 0x151013, 0x161014, 0x130f13, 0x141013, 0x140f13, 0x151013, 0x151013, 0x150e15];
const CONT_COLORS = [0xc6e48b, 0x7bc96f, 0x239a3b, 0x196127, 0xfffffff];

const WIDTH = 32;
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
  for (let i = 1; i < max; i++) positions.push(i);
  for (let i = max - 2; i > 0; i--) positions.push(i);

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
