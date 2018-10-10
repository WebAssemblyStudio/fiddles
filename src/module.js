const BLACK = 0x000000;
const WHITE = 0xFFFFFF;
const BLUE = 0x0000FF;
const RED = 0xFF0000;

function drawFrame(frame) {
    for(let y = 0; y < frame.height; y++) {
        for(let x=0; x<frame.width; x++) {
            //even or odd
            if(x % 2 === 0) {
                frame.color = BLACK
            } else {
                frame.color = WHITE
            }
            frame.setPixel(x,y)
        }
    }


    // frame.color = BLUE
    // frame.drawLine(0,0,frame.width,frame.height)

    // frame.color = RED
    // frame.fillRect(0,0,frame.width/2, frame.height/2)
}

class Frame {
    constructor(buffer, rows, cols, frameNumber) {
        this.color = BLACK
        this.width = cols
        this.height = rows
        this.frameNumber = frameNumber
        this.frameSize = 3 * rows * cols
        this.data = new Uint8Array(buffer, this.frameSize*frameNumber, this.frameSize)
        for(let i=0; i<rows*cols; i++) {
            const R = (RED & 0xFF0000) >> 16
            this.data[i*3+0] = R;
            this.data[i*3+1] = 0;
            this.data[i*3+2] = R;
        }
    }

    setPixel(x,y) {
        const n = this.frameNumber*this.frameSize + y*this.height*3 + x*3
        this.data[n+0] = (this.color & 0xFF0000) >> 16;
        this.data[n+1] = (this.color & 0x00FF00) >> 8;
        this.data[n+2] = (this.color & 0x0000FF) >> 0;
    }
}


export function transform(buffer, rows, cols, frameCount, fps, isFirst) {
    for (let i = 0; i < frameCount; i++) {
        const frame = new Frame(buffer, rows, cols, i)
        drawFrame(frame)
    }
}

export default function () {
    return Promise.resolve({
        transform,
    })
}