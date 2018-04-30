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
  let module = new ArcModule("../out/main.wasm", 44, 36, 1050, 35, true);
  await module.ready;
  let input = new Uint8Array(module.bufferSize);
  let output;
  try {
    output = module.transform(input);
  } catch (e) {
    console.log(e, '\n', e.stack)
  }
  console.log(input.slice(0, 3), output.slice(0, 3));
}

run();
