class ArcModule {
    constructor(wasm, rows, cols, frameCount, fps, isFirst) {
        this.bufferSize = rows * cols * frameCount * 3;
        if (typeof wasm === 'string') {
            this.wasmPromise = WebAssembly.instantiateStreaming(fetch(wasm));
        } else {
            this.wasmPromise = WebAssembly.instantiate(wasm);
        }

        this.wasmPromise = this.wasmPromise.then(result => {
            this.wasmInstance = result.instance;
            this.wasmExports = result.instance.exports;
            try {
              this.wasmExports.init(rows, cols, frameCount, fps, isFirst);
            } catch (e) {
              console.log(e.stack)
            }
        });
    }

    get ready() {
        return this.wasmPromise;
    }

    transform(input) {
        if (!this.wasmInstance) {
            throw new Error("Wasm module not initialized");
        }

        let bufferOffset = this.wasmExports.getAnimationBuffer();
        let animationBuffer = new Uint8Array(this.wasmExports.memory.buffer, bufferOffset, this.bufferSize);

        animationBuffer.set(input);
        this.wasmExports.apply();
        return animationBuffer;
    }
}

async function run() {
  let fps = 35;
  let frames = 105
  let module = new ArcModule("../out/main.wasm", 44, 36, frames, fps, true);
  await module.ready;
  let input = new Uint8Array(module.bufferSize);
  let output;
  try {
    output = module.transform(input);
  } catch (e) {
    console.log(e, '\n', e.stack)
  }
  showPreview(bufferToJSON(output, 44, 36, 175), false, 35);
}

function bufferToJSON(buffer, rows, cols, frameCount) {
  const output = [];
  let bufferIndex = 0;
  for (let frameIndex = 0; frameIndex < frameCount; frameIndex++) {
    const frame = output[frameIndex] = [];
    for (let rowIndex = 0; rowIndex < rows; rowIndex++) {
      const row = frame[rowIndex] = [];
      for (let colIndex = 0; colIndex < cols; colIndex++) {
        row[colIndex] = [buffer[bufferIndex++], buffer[bufferIndex++], buffer[bufferIndex++]];
      }
    }
  }
  return output;
}

run();
