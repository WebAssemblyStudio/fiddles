let x = '../out/main.wasm';

async function init() {
    const { instance } = await WebAssembly.instantiateStreaming(
      fetch(x)
    );
    console.log(instance.exports);
  }
  init();