// Example of the JavaScript module for the Arc project.

function setFrameBlackAndWhite(frame, rows, cols) {
  for (let i = 0; i < rows; i++) {
    const lineSize = cols * 3;
    const line = frame.subarray(lineSize * i, lineSize * (i + 1));
    if (i & 1) {
      for (let j = 0; j < cols; j++) {
        line[j * 3] = 10;
        line[j * 3 + 1] = 90;
        line[j * 3 + 2] = 136;
      }
    } else {
      for (let j = 0; j < cols; j++)
        line[j * 3] = line[j * 3 + 1] = line[j * 3 + 2] = 255;
    }
  }
}

function setFramePinkAndGreen(frame, rows, cols) {
  for (let i = 0; i < rows; i++) {
    const lineSize = cols * 3;
    const line = frame.subarray(lineSize * i, lineSize* (i + 1));
    if (i & 1) {
      for (let j = 0; j < cols; j++) {
        line[j * 3] = line[j * 3 + 2] = 0;
        line[j * 3 + 1] = 255;
      }
    } else {
      for (let j = 0; j < cols; j++) {
        line[j * 3] = line[j * 3 + 2] = 255;
        line[j * 3 + 1] = 0;
      }
    }
  }
}

function writeFiene(frame, rows, cols, startPosition) {
  const fiene = [
    'FFFFFFF  I  EEEEEEE  N        N  EEEEEEE',
    'F        I  E        N N      N  E      ',
    'F        I  E        N  N     N  E      ',
    'FFFFF    I  EEEEEEE  N   N    N  EEEEEEE',
    'F        I  E        N    N   N  E      ',
    'F        I  E        N     N  N  E      ',
    'F        I  E        N      N N  E      ',
    'F        I  EEEEEEE  N        N  EEEEEEE'
  ];

  let rowName = [];

  for (let i = 0; i < fiene.length; i++) {
    for (let j = 0; j < fiene[i].length; j++) {
        rowName[j] = rowName[j] ? fiene[i][j] + rowName[j] : fiene[i][j];
    };
  };

  const lineWidth = 3;
  const grid = frame.subarray(0, (cols * rows) * 3);

  for (let i = 0; i < rowName.length; i++) {
    const nameStart = 36 * i;

    for (let j = 0; j < rowName[i].length; j++) {
      if (rowName[i][j] !== ' ') {
        grid[(nameStart + j) * 3] = 215;
        grid[(nameStart + j) * 3 + 1] = 0;
        grid[(nameStart + j) * 3 + 2] = 121;
      }
    }
  }
}
  
function writeMerel(frame, rows, cols) {
}

export function transform(buffer, rows, cols, frameCount, fps, isFirst) {
  const frameSize = 3 * rows * cols;
  for (let i = 0; i < frameCount; i++) {
    const second = i / fps;
    const frame = new Uint8Array(buffer, frameSize * i, frameSize);
    const  startPosition = 0 * 36;

    //if (i === 0 || (second % Math.floor(second)) === 0 ) {  
      writeFiene(frame, rows, cols, startPosition);
    //}

    
    //if (Math.floor(second) & 1)
    //  setFrameBlackAndWhite(frame, rows, cols);
    //else
    //  setFramePinkAndGreen(frame, rows, cols);
  }
}

export default function () {
  return Promise.resolve({
    transform,
  })
}