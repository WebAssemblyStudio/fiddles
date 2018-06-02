// Example of the JavaScript module for the Arc project.

function setFrameBlackAndWhite(frame, rows, cols) {
  for (let i = 0; i < rows; i++) {
    const lineSize = cols * 3;
    const line = frame.subarray(lineSize * i, lineSize * (i + 1));
    if (i & 1) {
      for (let j = 0; j < cols; j++)
        line[j * 3] = line[j * 3 + 1] = line[j * 3 + 2] = 0;
    } else {
      for (let j = 0; j < cols; j++)
        line[j * 3] = line[j * 3 + 1] = line[j * 3 + 2] = 255;
    }
  }
}

function setFramePinkAndGreen(frame, rows, cols) {
  for (let i = 0; i < rows; i++) {
    const lineSize = cols * 3;
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


export function transform(buffer, rows, cols, frameCount, fps, isFirst) {
  /* for (let i = 0; i < frameCount; i++) {
    const second = i / fps;
    if (Math.floor(second) & 1)
      setFrameBlackAndWhite(frame, rows, cols);
    else
      setFramePinkAndGreen(frame, rows, cols);
  }*/
  const frameSize = 3 * rows * cols;
    const frame = new Uint8Array(buffer, frameSize * 3, frameSize);
  const line = frame.subarray(cols * 3 * 3, cols * 3 * (3 + 1));
  line[4] = 255;
}

export default function () {
  return Promise.resolve({
    transform,
  })
}