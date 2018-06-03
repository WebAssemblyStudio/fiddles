class ArcModule {
  constructor(wasm) {
      this.initialized = false;

      if (typeof wasm === 'string') {
        if (!WebAssembly.instantiateStreaming) {
          this.wasmPromise = fetchAndInstantiateFallback(wasm);
        } else {
          this.wasmPromise = WebAssembly.instantiateStreaming(fetch(wasm));
        }
      } else {
          this.wasmPromise = WebAssembly.instantiate(wasm);
      }

      this.wasmPromise = this.wasmPromise.then(result => {
          this.wasmInstance = result.instance;
          this.wasmExports = result.instance.exports;
      });
  }

  get ready() {
      return this.wasmPromise;
  }

  init(rows, cols, frameCount, fps, isFirst) {
      if (!this.wasmInstance) {
          throw new Error("Wasm module not loaded");
      }

      try {
        this.bufferSize = rows * cols * frameCount * 3;
        this.wasmExports.init(rows, cols, frameCount, fps, isFirst);
        this.initialized = true;
      } catch (e) {
        console.log(e.stack);
      }
  }

  transform(input) {
      if (!this.initialized) {
          throw new Error("Wasm module not initialized");
      }

      let bufferOffset = this.wasmExports.getAnimationBuffer();
      let animationBuffer = new Uint8Array(this.wasmExports.memory.buffer, bufferOffset, this.bufferSize);

      animationBuffer.set(input);
      this.wasmExports.apply();
      return animationBuffer;
  }
}

async function fetchAndInstantiateFallback(url, imports) {
  const response = await fetch(url);
  const buffer = await response.arrayBuffer();
  return WebAssembly.instantiate(buffer, imports);
}

function loadImage(url) {
  return new Promise((resolve, reject) => {
    const image = document.createElement("img");
    image.onload = () => resolve(image);
    image.onerror = reject;
    image.src = url;
  })
}

async function loadResources() {
  const image = await loadImage("data:image/png;base64,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");
  const canvas = document.createElement("canvas");
  canvas.width = canvas.height = 44;
  const context = canvas.getContext("2d");
  context.drawImage(image, 0, 0);
  const rgbaData = canvas.getImageData(0, 0, canvas.width, canvas.height).data;
  const rgbData = 
  return imageData.data;
}

export default async function () {
  let module = new ArcModule("../out/lib.wasm");
  await module.ready;

  return {
    transform(buffer, rows, cols, frameCount, fps, isFirst) {
      module.init(rows, cols, frameCount, fps, isFirst);
      let input = new Uint8Array(buffer);
      let output = module.transform(input);
      input.set(output);
    }
  }
}
