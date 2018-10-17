//constants for colors
const BLACK = 0x000000;
const WHITE = 0xFFFFFF;

const IMAGE = [0xffffff, 0xffffff, 0xcdcccd, 0xbab9ba, 0xd0cfd0, 0xf9f8f9, 0xffffff, 0xffffff, 0xffffff, 0xffffff, 0xffffff, 0xffffff, 0xf3f3f3, 0xedecec, 0xffffff, 0xfdfdfd, 0xebeaeb, 0xf6f6f6, 0xffffff, 0xfefefe, 0xffffff, 0xfefefe, 0xffffff, 0xefefef, 0xefefef, 0xffffff, 0xfefefe, 0xffffff, 0xf5f5f5, 0x4f4b4d, 0x171115, 0x161114, 0x171115, 0xd4d3d4, 0x8e8c8d, 0x514d4f, 0xffffff, 0xd9d9d9, 0xdeddde, 0xffffff, 0x726f70, 0x302c2f, 0xffffff, 0xe9e8e9, 0x1c171a, 0x959395, 0xffffff, 0xfafafa, 0xffffff, 0xfcfcfc, 0xffffff, 0x4e4a4c, 0x514d4f, 0xffffff, 0xffffff, 0xfdfdfd, 0x898688, 0x181215, 0x959294, 0xe6e6e6, 0xcccbcb, 0xffffff, 0x8d8b8c, 0x5e5a5c, 0xffffff, 0x332f32, 0x5b5759, 0xffffff, 0x615e60, 0x211c1f, 0xffffff, 0xfaf9f9, 0x161114, 0x8b898a, 0xffffff, 0xfefefe, 0xffffff, 0xffffff, 0xffffff, 0x3c383b, 0x464244, 0xffffff, 0xfcfcfc, 0xffffff, 0x454143, 0x393537, 0xffffff, 0xebeaeb, 0xdfdedf, 0xf9f8f9, 0x8c8a8b, 0x726f71, 0x979596, 0x151013, 0x151013, 0x7f7d7e, 0x747173, 0x161114, 0x9d9b9c, 0x8d8b8c, 0x161114, 0x918f90, 0x696668, 0x817f80, 0xffffff, 0x494548, 0x9f9d9e, 0x5a5658, 0x191417, 0x312d30, 0x2f2a2d, 0xc6c5c6, 0x353133, 0x524e50, 0xffffff, 0x2a2628, 0x181216, 0x848183, 0x625f61, 0x241f22, 0xb5b3b4, 0x1f1a1d, 0x312c2f, 0xbfbdbe, 0x737071, 0x161114, 0x211c1f, 0x1f1a1d, 0x161114, 0x928f91, 0x2e292c, 0x545153, 0xffffff, 0x161114, 0x7b787a, 0x595558,
0x282426, 0xb2b0b1, 0x1a1518, 0x4b474a, 0x494548, 0x302b2e, 0xffffff, 0xe3e2e2, 0x1b1619, 0x7d7a7c, 0x726f70, 0x2c272a, 0xffffff, 0x383436, 0x676365, 0xffffff, 0x656264, 0x252023, 0xffffff, 0xe6e6e6, 0x161013, 0x8f8d8e, 0x3d393c, 0x656263, 0xffffff, 0x1c171a, 0x868385, 0x504c4e, 0x514d4f, 0xffffff, 0x5e5b5d, 0x353133, 0x9c9a9b, 0x181216, 0x726f70, 0xbdbcbc, 0x161013, 0x757274, 0x6a6769, 0x241f22, 0xffffff, 0x312d30, 0x393537, 0xf4f4f4, 0x656264, 0x1e191c, 0xffffff, 0xedeced, 0x161114, 0x8c8a8b, 0x393537, 0x444042, 0xcecdce, 0x161114, 0x828081, 0x514d4f, 0x2a2628, 0xd8d7d7, 0x2a2628, 0x494548, 0xffffff, 0x7d7a7c, 0x171215, 0x161114, 0x1b1719, 0xadacad, 0x7d7a7c, 0x3f3b3e, 0xffffff, 0x949193, 0x161114, 0x686567, 0x838082, 0x3a3538, 0xffffff, 0xecebec, 0x262124, 0xa5a3a4, 0x969495, 0x161114, 0x2a2628, 0x2f2a2d, 0x918f90, 0x716e70, 0x353133, 0x211c1f, 0x191417, 0xb7b6b7, 0xffffff, 0xffffff, 0xf6f6f6, 0xe5e5e5, 0xf5f5f5, 0xffffff, 0xf9f9f9, 0xf9f8f9, 0xffffff, 0xffffff, 0xecebec, 0xf2f2f2, 0xfcfcfc, 0xf8f8f8, 0xffffff, 0xfefefe, 0xf7f7f7, 0xfcfcfc, 0xffffff, 0xe8e8e8, 0xf1f1f1, 0xffffff, 0xf9f9f9, 0xf9f9f9, 0xffffff, 0xedeced, 0xf0f0f0, 0xffffff];

const CONT_COLORS = [0xc6e48b, 0x7bc96f, 0x239a3b, 0x196127, 0xfffffff];

const WIDTH = 28;
const HEIGHT = 9;
let CONTRIBUTIONS = [];

  const num_bars = 7; // TODO determine
  for (let i = 0; i < frame_width; i++) {
    for (let l = 0; l < num_bars; l++) {
      const local = [];
      const rand = Math.floor(Math.random() * CONT_COLORS.length)
      local.push(CONT_COLORS[rand]);
      CONTRIBUTIONS.push(local);
    }
  }

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

/*
  // Conditionally change contributions
  if (frame.frameNumber % 5 === 0) {
    for (let l = 0; l < num_bars; l++) {
      const local = [];
      const rand = Math.floor(Math.random() * CONT_COLORS.length)
      local.push(CONT_COLORS[rand]);
    }
    CONTRIBUTIONS.pop();
    CONTRIBUTIONS.unshift(local);
  }

  // Draw contributions
  offset_y = Math.floor(frame.height / 2 - 7 / 2);
  for (let x = 0; x < frame.width; x++) {
    const local = CONTRIBUTIONS[x];
    for (let y = 0; y < num_bars; y++) {
      frame.color = local[y];
      frame.setPixel(x, offset_y + y);
    }
  }
  /*
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
