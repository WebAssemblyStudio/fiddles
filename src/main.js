
const width = 300;
const height = 200;

const memSize = 256;
//const memory = new WebAssembly.Memory({ initial: memSize });
let memory;
let canvas;
let canvasCtx;
let instance;


const consoleLog = (offset, len) => {
  const strBuf = new Uint8Array(memory.buffer, offset, len);
  console.log(new TextDecoder().decode(strBuf));
}
const consoleLogNum = (num) => {
  console.log(num);
}

const mainLoop = (module) => {
  const pointer = module.exports.nextFrame();
  const data = new Uint8ClampedArray(memory.buffer, pointer, width * height * 4);
  const img = new ImageData(data, width, height);
  canvasCtx.putImageData(img, 0, 0);
  window.requestAnimationFrame(() => mainLoop(instance));
}

const imports = {
  env: {
    memoryBase: 0,
    tableBase: 0,
    //memory: new WebAssembly.Memory({ initial: memSize }),
    table: new WebAssembly.Table({
      initial: 0,
      element: 'anyfunc'
    }),
    consoleLog, consoleLogNum
  }
};

const init = () => {
  canvas = document.createElement('canvas');
  canvas.width = width;
  canvas.height = height;
  document.body.appendChild(canvas);
  canvasCtx = canvas.getContext('2d');
  //var saw = new Wad({source : 'sawtooth', volume : .9})
  //saw.setVolume(0.5)
}

// const rom = '../out/main.wasm';
const rom = '../out/mandelbrot.wasm';

WebAssembly.instantiateStreaming(fetch(rom), imports).then(results => {
  instance = results.instance;
  memory = instance.exports.memory;
  init();
  instance.exports.init(width, height);
  window.requestAnimationFrame(() => mainLoop(instance));
}).catch(console.error);


const convertKeyCode = (keyCode) => {
  switch (keyCode) {
    case 65: return 0x01; // A  A
    case 85: return 0x02; // U  B
    case 73: return 0x04; // I  SELECT
    case 38: return 0x10; // ↑  ↑
    case 40: return 0x20; // ↓  ↓
    case 37: return 0x40; // ←  ←
    case 39: return 0x80; // →  →
  }
  return 0;
};

const onKeydown = (e) => {
  const button = convertKeyCode(e.keyCode)
  if (button){
    instance.exports.onKeyDown(convertKeyCode(e.keyCode));
  }
  e.stopPropagation();
  return false;
}

const onKeyup = (e) => {
  const button = convertKeyCode(e.keyCode)
  if (button){
    instance.exports.onKeyUp(convertKeyCode(e.keyCode));
  }
  e.stopPropagation();
  return false;
}

const setupKeyHandler = () => {
  if (typeof window !== 'undefined') {
    document.addEventListener('keydown', onKeydown);
    document.addEventListener('keyup', onKeyup);
  }
};

setupKeyHandler();