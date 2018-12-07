//constants for colors
const BLACK = 0x000000;
const WHITE = 0xFFFFFF;
const BLUE = 0x0000FF;
const RED = 0xFF0000;
const GREEN = 0x00FF00;

const colorRotation = [
  WHITE //, RED, GREEN, BLUE, RED, GREEN, BLUE, RED, GREEN, BLUE, RED, GREEN, BLUE,
]

let r = 255, g = 0, b = 0;
for (let i = 0; i < 255; i+= 30) {
  g = i;
  b = i;
  let c = (r << 16) | (g << 8) | (b);
  colorRotation.push(c);
}
/*
let r = 0, g = 255, b = 0;
for (let i = 0; i < 255; i+= 30) {
  r = i;
  b = i;
  let c = (r << 16) | (g << 8) | (b);
  colorRotation.push(c);
}
let r = 0, g = 0, b = 255;
for (let i = 0; i < 255; i+= 30) {
  g = i;
  r = i;
  let c = (r << 16) | (g << 8) | (b);
  colorRotation.push(c);
}
*/
let fnforcolor = 0;
let colorindex = 0;
let color, prevcolor;

function drawFrame(frame) {
    let framenumber = frame.frameNumber;
    if (framenumber == 0) {
      frame.color = WHITE;
      frame.fillRect(0,0,frame.width,frame.height);
      return;
    }
    
    if (fnforcolor > (frame.width / 2) + 1) {
      color = colorRotation[++colorindex];
      prevcolor = colorRotation[colorindex - 1];
      fnforcolor = 0;
    }
    //let framenumber = 2;
    //black and white columns
    for(let y = 0; y < frame.height; y++) {
        for(let x=0; x<frame.width; x++) {
            //even or odd
            if((x > (frame.width / 2 - fnforcolor)) && (x < frame.width / 2 + fnforcolor)) {
                frame.color = color;
                frame.setPixel(x,y);
            } else {
                frame.color = prevcolor;
                frame.setPixel(x,y);
            }
            //frame.setPixel(x,y)
        }
    }

  fnforcolor++;

    //calculate the smaller of width or height
    // const size = Math.min(frame.width,frame.height)

    //fill the corner with a red square
    // frame.color = RED
    //frame.fillRect(0,0,size/2, size/2)

    //diagonal blue lines for an X
   // frame.color = 0x0000FF;
   // frame.drawLine(0,0,size,size)
   // frame.drawLine(size-1,0,0,size)
}

class Frame {
    constructor(buffer, rows, cols, frameNumber) {
        this.color = WHITE;
        this.width = cols
        this.height = rows
        this.frameNumber = frameNumber
        this.frameSize = 3 * rows * cols
        //data is a ref to just the slice of the buffer for this frame
        this.data = new Uint8Array(buffer, this.frameSize*this.frameNumber, this.frameSize)
        // for(let i=0; i<rows*cols; i++) {
        //     const R = (this.color & 0xFF0000) >> 16
        //     const G = (this.color & 0x00FF00) >> 8
        //     const B = (this.color & 0x0000FF) >> 0
        //     this.data[i*3+0] = R;
        //     this.data[i*3+1] = G;
        //     this.data[i*3+2] = B;
        // }
        //this.color = WHITE;
        //this.fillRect(0, 0, cols, rows);

        //this.color = RED
        //this.setPixel(0,0)
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


export function transform(buffer, rows, cols, frameCount, fps) {
    for (let i = 0; i < frameCount; i++) drawFrame(new Frame(buffer, rows, cols, i))
}

export default function () {
    return Promise.resolve({
        transform,
    })
}
