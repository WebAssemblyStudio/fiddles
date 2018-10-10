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
        console.log("making")
        this.color = BLACK
        this.width = rows
        this.height = cols
        this.frameNumber = frameNumber
        this.frameSize = 3 * rows * cols
        this.data = new Uint8Array(buffer, this.frameSize*frameNumber, this.frameSize)
    }

    setPixel(x,y) {
        const n = this.frameNumber*this.frameSize + y*this.height*3 + x*3
        this.data[n+0] = (this.color & 0xFF0000) >> 16;
        this.data[n+1] = (this.color & 0x00FF00) >> 8;
        this.data[n+2] = (this.color & 0x0000FF) >> 0;
    }
}

// Example of the JavaScript module for the Arc project.
// There are 44 rows that each have 36 columns

function fireZebra(frame, rows, cols) {
    // Because the arch uses RGB colors, we need to multiply by 3

    const rgbGradient = [
        [255, 55, 39],
        [255, 73, 31],
        [255, 104, 37],
        [247, 96, 43],
        [245, 125, 15],
        [253, 139, 15],
        [251, 152, 25],
        [255, 156, 1],
        [253, 180, 0],
        [254, 195, 3],
        [253, 207, 0],
        [254, 231, 67]
    ];

    for (let row = 0; row < rows; row++) {
        // In this example we're just selecting a single column every cycle
        // More info: https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/TypedArray/subarray
        const columnLine = frame.subarray(cols * row * 3, cols * (row + 1) * 3);
        // Change colors every cycle
        const colorIndex = Math.floor((row / 2) % rgbGradient.length);
        const rgbColor = rgbGradient[colorIndex];

        // Let's do some zebra coloring using destructuring assignment
        // More info: https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Operators/Destructuring_assignment
        const [R, G, B] = row & 1 ? [0, 0, 0] : rgbColor;

        // Loop over every block that's in the column, bare in mind since we need to set RGB
        // we need to increase the index times try after each cycle
        for (let col = 0; col < cols; col++) {
            const index = col * 3;

            columnLine[index] = R;
            columnLine[index + 1] = G;
            columnLine[index + 2] = B;
        }
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