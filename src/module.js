//constants for colors
const BLACK = 0x000000;
const WHITE = 0xFFFFFF;
const BLUE = 0x0000FF;
const RED = 0xFF0001;

const IMAGE = ["rgb(0,0,0)", "rgb(0,0,0)", "rgb(19,14,19)", "rgb(20,17,20)", "rgb(20,15,20)", "rgb(36,0,36)", "rgb(0,0,0)", "rgb(0,0,0)", "rgb(0,0,0)", "rgb(0,0,0)", "rgb(0,0,0)", "rgb(0,0,0)", "rgb(20,20,20)", "rgb(26,13,13)", "rgb(0,0,0)", "rgb(0,0,0)", "rgb(23,12,23)", "rgb(26,26,26)", "rgb(0,0,0)", "rgb(0,0,0)", "rgb(0,0,0)", "rgb(0,0,0)", "rgb(0,0,0)", "rgb(15,15,15)", "rgb(15,15,15)", "rgb(0,0,0)", "rgb(0,0,0)", "rgb(0,0,0)", "rgb(23,23,23)", "rgb(21,16,19)", "rgb(23,17,21)", "rgb(22,17,20)", "rgb(23,17,21)", "rgb(22,16,22)", "rgb(21,17,19)", "rgb(21,16,19)", "rgb(0,0,0)", "rgb(19,19,19)", "rgb(21,14,21)", "rgb(0,0,0)", "rgb(22,17,18)", "rgb(20,16,19)", "rgb(0,0,0)", "rgb(21,11,21)", "rgb(21,15,19)", "rgb(20,16,20)", "rgb(0,0,0)", "rgb(0,0,0)", "rgb(0,0,0)", "rgb(0,0,0)", "rgb(0,0,0)", "rgb(21,16,18)", "rgb(21,16,19)", "rgb(0,0,0)", "rgb(0,0,0)", "rgb(0,0,0)", "rgb(22,16,20)", "rgb(24,18,21)", "rgb(22,15,20)", "rgb(19,19,19)", "rgb(23,18,18)", "rgb(0,0,0)", "rgb(21,16,19)", "rgb(22,16,19)", "rgb(0,0,0)", "rgb(21,16,20)", "rgb(21,16,19)", "rgb(0,0,0)", "rgb(21,16,19)", "rgb(21,16,19)", "rgb(0,0,0)", "rgb(43,0,0)", "rgb(22,17,20)", "rgb(20,16,18)", "rgb(0,0,0)", "rgb(0,0,0)", "rgb(0,0,0)", "rgb(0,0,0)", "rgb(0,0,0)", "rgb(20,16,19)", "rgb(21,16,19)", "rgb(0,0,0)", "rgb(0,0,0)", "rgb(0,0,0)", "rgb(21,16,19)", "rgb(21,17,19)", "rgb(0,0,0)", "rgb(23,12,23)", "rgb(22,15,22)", "rgb(36,0,36)", "rgb(20,16,18)", "rgb(22,17,20)", "rgb(20,16,18)", "rgb(21,16,19)", "rgb(21,16,19)", "rgb(20,17,18)", "rgb(20,15,19)", "rgb(21,16,19)", "rgb(21,17,19)", "rgb(21,16,19)", "rgb(22,17,20)", "rgb(21,17,19)", "rgb(20,16,19)", "rgb(20,17,19)", "rgb(0,0,0)", "rgb(21,15,19)", "rgb(22,17,19)", "rgb(21,16,18)", "rgb(21,16,19)", "rgb(20,16,19)", "rgb(21,16,19)", "rgb(21,16,21)", "rgb(21,16,19)", "rgb(22,16,19)", "rgb(0,0,0)", "rgb(21,16,19)", "rgb(24,18,22)", "rgb(21,15,19)", "rgb(21,16,19)", "rgb(21,16,19)", "rgb(22,16,19)", "rgb(21,16,19)", "rgb(22,16,19)", "rgb(22,15,18)", "rgb(22,17,18)", "rgb(22,17,20)", "rgb(21,16,19)", "rgb(21,16,19)", "rgb(22,17,20)", "rgb(21,15,19)", "rgb(21,16,19)", "rgb(21,16,19)", "rgb(0,0,0)", "rgb(22,17,20)", "rgb(21,16,19)", "rgb(21,15,20)", "rgb(21,16,19)", "rgb(21,15,18)", "rgb(21,16,19)", "rgb(21,16,20)", "rgb(21,15,19)", "rgb(21,16,19)", "rgb(0,0,0)", "rgb(25,16,16)", "rgb(22,16,19)", "rgb(22,16,20)", "rgb(22,17,18)", "rgb(21,16,19)", "rgb(0,0,0)", "rgb(21,16,19)", "rgb(22,15,18)", "rgb(0,0,0)", "rgb(21,17,20)", "rgb(21,16,19)", "rgb(0,0,0)", "rgb(19,19,19)", "rgb(22,16,19)", "rgb(21,17,19)", "rgb(21,16,19)", "rgb(21,17,18)", "rgb(0,0,0)", "rgb(21,15,19)", "rgb(21,15,19)", "rgb(21,16,19)", "rgb(21,16,19)", "rgb(0,0,0)", "rgb(20,16,19)", "rgb(21,16,19)", "rgb(21,17,19)", "rgb(24,18,22)", "rgb(22,17,18)", "rgb(21,18,18)", "rgb(22,16,19)", "rgb(20,15,19)", "rgb(20,16,19)", "rgb(21,16,19)", "rgb(0,0,0)", "rgb(20,16,19)", "rgb(21,17,19)", "rgb(21,21,21)", "rgb(21,17,20)", "rgb(21,16,19)", "rgb(0,0,0)", "rgb(26,13,26)", "rgb(22,17,20)", "rgb(20,16,18)", "rgb(21,17,19)", "rgb(21,16,19)", "rgb(19,14,19)", "rgb(22,17,20)", "rgb(21,17,19)", "rgb(21,16,19)", "rgb(21,16,19)", "rgb(24,18,18)", "rgb(21,16,19)", "rgb(21,15,19)", "rgb(0,0,0)", "rgb(22,16,20)", "rgb(21,16,19)", "rgb(22,17,20)", "rgb(21,16,19)", "rgb(20,17,20)", "rgb(22,16,20)", "rgb(21,16,20)", "rgb(0,0,0)", "rgb(22,15,20)", "rgb(22,17,20)", "rgb(20,16,19)", "rgb(21,15,19)", "rgb(21,15,19)", "rgb(0,0,0)", "rgb(24,12,24)", "rgb(22,16,19)", "rgb(21,16,18)", "rgb(20,16,18)", "rgb(22,17,20)", "rgb(21,16,19)", "rgb(21,16,19)", "rgb(21,17,19)", "rgb(21,16,20)", "rgb(21,16,19)", "rgb(21,16,19)", "rgb(21,16,19)", "rgb(20,16,20)", "rgb(0,0,0)", "rgb(0,0,0)", "rgb(26,26,26)", "rgb(18,18,18)", "rgb(23,23,23)", "rgb(0,0,0)", "rgb(0,0,0)", "rgb(36,0,36)", "rgb(0,0,0)", "rgb(0,0,0)", "rgb(24,12,24)", "rgb(18,18,18)", "rgb(0,0,0)", "rgb(32,32,32)", "rgb(0,0,0)", "rgb(0,0,0)", "rgb(28,28,28)", "rgb(0,0,0)", "rgb(0,0,0)", "rgb(20,20,20)", "rgb(17,17,17)", "rgb(0,0,0)", "rgb(0,0,0)", "rgb(0,0,0)", "rgb(0,0,0)", "rgb(26,13,26)", "rgb(16,16,16)", "rgb(0,0,0)"];
const WIDTH = 28;
const HEIGHT = 9;

function drawFrame(frame) {

  for (let i = 0; i < IMAGE.length; i++) {

    frame.color = IMAGE[i];

    let x = i % HEIGHT;
    let y = Math.floor(i % HEIGHT);
    frame.setPixel(x, y);

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

}


export function transform(buffer, rows, cols, frameCount, fps, isFirst) {
    for (let i = 0; i < frameCount; i++) drawFrame(new Frame(buffer, rows, cols, i))
}

export default function () {
    return Promise.resolve({
        transform,
    })
}
