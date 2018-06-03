// Example of the JavaScript module for the Arc project.

const timeline = [
  { x: 1, color: [ 8, 0, 0 ] },
  {},
  {},
  {},
  { x: 1, color: [ 8, 0, 0 ] },
  {},
  {},
  {},
  { x: 1, color: [ 8, 0, 0 ] },
  {},
  {},
  {},
  { x: 1, color: [ 8, 0, 0 ] },
  {},
  {},
  {},
  { x: 1, color: [ 8, 0, 0 ] },
  {},
  {},
  {},
  { x: 1, color: [ 8, 0, 0 ] },
  {},
  {},
  {},
  { x: 1, color: [ 8, 0, 0 ] },
  {},
  {},
  {},
  { x: 1, color: [ 8, 0, 0 ] },
  {},
  {},
  {},
  { x: 1, color: [ 0, 8, 0 ] },
  {},
  {},
  {},
  { x: 1, color: [ 0, 8, 0 ] },
  {},
  {},
  {},
  { x: 1, color: [ 0, 8, 0 ] },
  {},
  {},
  {},
  { x: 1, color: [ 0, 8, 0 ] },
  {},
  {},
  {},
  { x: 1, color: [ 0, 8, 0 ] },
  {},
  {},
  {},
  { x: 1, color: [ 0, 8, 0 ] },
  {},
  {},
  {},
  { x: 1, color: [ 0, 0, 8 ] },
  {},
  {},
  {},
  { x: 1, color: [ 0, 0, 8 ] },
  {},
  {},
  {},
  { x: 1, color: [ 0, 0, 8 ] },
  {},
  {},
  {},
  { x: 1, color: [ 0, 0, 8 ] },
  {},
  {},
  {},
  { x: 1, color: [ 0, 0, 8 ] },
  {},
  {},
  {},
  { x: 1, color: [ 0, 0, 8 ] },
  {},
  {},
  {},
  { x: 1, color: [ 0, 8, 0 ] },
  {},
  {},
  {},
  { x: -1, color: [ 0, 8, 0 ] },
  {},
  {},
  {},
  { x: -1, color: [ 0, 8, 0 ] },
  {},
  {},
  {},
  { x: -1, color: [ 0, 8, 0 ] },
  {},
  {},
  {},
  { x: -1, color: [ 0, 0, 8 ] },
  {},
  {},
  {},
  {},
  { x: -1, color: [ 0, 0, 8 ] },
  {},
  {},
  {},
  {},
  { x: -1, color: [ 0, 0, 8 ] },
  {},
  {},
  {},
  {},
  { x: -1, color: [ 0, 0, 8 ] },
  {},
  {},
  {},
  {},
  { x: -1, color: [ 0, 0, 8 ] },
  {},
  {},
  {},
  {},
  { x: -1, color: [ 0, 0, 8 ] },
  {},
  {},
  {},
  {},
  { x: -1, color: [ 0, 8, 0 ] },
  {},
  {},
  {},
  { x: -1, color: [ 0, 8, 0 ] },
  {},
  {},
  {},
  { x: -1, color: [ 0, 8, 0 ] },
  {},
  {},
  {},
  { x: -1, color: [ 0, 8, 0 ] },
  {},
  {},
  {},
  { x: -1, color: [ 0, 0, 8 ] },
  {},
  {},
  {},
  {},
  { x: -1, color: [ 0, 0, 8 ] },
  {},
  {},
  {},
  {},
  { x: -1, color: [ 0, 0, 8 ] },
  {},
  {},
  {},
  {},
  { x: -1, color: [ 0, 0, 8 ] },
  {},
  {},
  {},
  {},
];

let tick = 0;

let current = {
  position: 0,
  colors: [ 64, 64, 64 ]
};

let colorDirection = [
  1,
  1,
  1,
];

let history = [];
const historyLength = 100;

function darken( colors, step = 1 ) {
  let modified = [];
  for( let i = 0; i < colors.length; i++) {
      modified[i] = Math.max( 0, colors[i] - step );
  }
  return modified;
}

function doTick() {
  for( let i = 0; i < history.length; i++ ) {
    history[i].colors = darken( history[i].colors );
  }

  history.unshift( {
    position: current.position,
    colors: darken( current.colors )
  } );

  history = history.slice( 0, historyLength );

  tick++;
  if ( tick >= timeline.length ) {
    tick = 0;
  }

  const apply = timeline[tick];
  if ( apply.x ) {
    current.position += apply.x;
    if ( current.position >= 44 ) {
      current.position = 0;
    }
  }

  if ( apply.color ) {
    for ( let color = 0; color < 3; color++ ) {
      current.colors[color] += ( apply.color[color] * colorDirection[color] );
      if ( current.colors[color] > 148 ) {
        colorDirection[color] = -1;
      }

      if ( current.colors[color] < 0 ) {
        colorDirection[color] = 1;
      }
      current.colors[color] = Math.min( 148, Math.max( 0, current.colors[color] ) );
    }
  }
}

function draw(frame, rows, cols) {
  const lineSize = cols * 3;
  for (let i = 0; i < rows; i++) {

    let colors = [0,0,0];

    // Apply history.
    for ( let h = 0; h < history.length; h++ ) {
        if ( history[h].position === i ) {
          colors = history[h].colors;
          break;
        }
    }

    // Apply current.
    if ( i === current.position ) {
        colors = current.colors;
    }

    // Set the pixels in the frame.
    const line = frame.subarray(lineSize * i, lineSize * (i + 1));
      for (let j = 0; j < cols; j++) {
      line[j * 3] = colors[0];
      line[j * 3 + 1] = colors[1];
      line[j * 3 + 2] = colors[2];
    }
  }
}

export function transform(buffer, rows, cols, frameCount, fps, isFirst) {
  const frameSize = 3 * rows * cols;
  for (let i = 0; i < frameCount; i++) {
    const frame = new Uint8Array(buffer, frameSize * i, frameSize);
    doTick();
    draw(frame, rows, cols);
  }
}

export default function () {
  return Promise.resolve({
    transform,
  })
}