//constants for colors
const BLACK = 0x000000;
const WHITE = 0xFFFFFF;
const BLUE = 0x0000FF;
const RED = 0xFF0000;


const randomNumber = (min, max) => Math.random() * (max - min) + min;

let lines = []
function drawFrame(frame, i) {
  if (i % 10 === 0) {
    lines.push([randomNumber(0, frame.width), randomNumber(0, frame.height)])
  }

  if (i % 2 === 0) {
    for (let index of lines) {
      lines[index] = [lines[index][0] - 1, lines[index][1]]
    }
  }

  for (let [index, value] of lines.entries()) {
    frame.drawLine(0, value[1], value[0], value[1])
  }
}

class Frame {
    constructor(buffer, rows, cols, frameNumber) {
        this.color = BLUE
        this.width = cols
        this.height = rows
        this.frameNumber = frameNumber
        this.frameSize = 3 * rows * cols
        //data is a ref to just the slice of the buffer for this frame
        this.data = new Uint8Array(buffer, this.frameSize*this.frameNumber, this.frameSize)
        for(let i=0; i<rows*cols; i++) {
            const R = (this.color & 0xFF0000) >> 16
            const G = (this.color & 0x00FF00) >> 8
            const B = (this.color & 0x0000FF) >> 0
            this.data[i*3+0] = R;
            this.data[i*3+1] = G;
            this.data[i*3+2] = B;
        }

        this.color = RED
        this.setPixel(0,0)
    }

    setPixel(x,y) {
        let n = (y*this.width+x)*3
        this.data[n+0] = (this.color & 0xFF0000) >> 16;
        this.data[n+1] = (this.color & 0x00FF00) >> 8;
        this.data[n+2] = (this.color & 0x0000FF) >> 0;
    }
    fillRect(x,y,w,h) {
        x = Math.floor(x)
        y = Math.floor(y)
        w = Math.floor(w)
        h = Math.floor(h)
        for(let j=y; j<y+h; j++) {
            for(let i=x; i<x+w; i++) {
                this.setPixel(i,j)
            }
        }
    }
    drawLine(x0,y0, x1,y1) {
        //Bresenham's from Rosetta Code
        // http://rosettacode.org/wiki/Bitmap/Bresenham's_line_algorithm#JavaScript
        x0 = Math.floor(x0);
        y0 = Math.floor(y0);
        x1 = Math.floor(x1);
        y1 = Math.floor(y1);
        const dx = Math.abs(x1 - x0), sx = x0 < x1 ? 1 : -1;
        const dy = Math.abs(y1 - y0), sy = y0 < y1 ? 1 : -1
        let err = (dx>dy ? dx : -dy)/2;

        while (true) {
            this.setPixel(x0,y0);
            if (x0 === x1 && y0 === y1) break;
            const e2 = err
            if (e2 > -dx) { err -= dy; x0 += sx; }
            if (e2 < dy) { err += dx; y0 += sy; }
        }
    }

}


export function transform(buffer, rows, cols, frameCount, fps, isFirst) {
    for (let i = 0; i < frameCount; i++) drawFrame(new Frame(buffer, rows, cols, i), i)
}

export default function () {
    return Promise.resolve({
        transform,
    })
}
