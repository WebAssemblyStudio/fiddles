
const width = 150;
const height = 100;

const memSize = 256;
//const memory = new WebAssembly.Memory({ initial: memSize });
let memory;
let canvas;
let canvasCtx;


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
    height, consoleLog, consoleLogNum
  }
};

const init = () => {
  canvas = document.createElement('canvas');
  canvas.width = width;
  canvas.height = height;
  document.body.appendChild(canvas);
  canvasCtx = canvas.getContext('2d');
}

init();

WebAssembly.instantiateStreaming(fetch('../out/main.wasm'), imports).then(results => {
  instance = results.instance;
  memory = instance.exports.memory;
  instance.exports.init(width, height);
  mainLoop(instance);
}).catch(console.error);