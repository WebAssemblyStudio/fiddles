WebAssembly.instantiateStreaming(fetch("../out/main.wasm"), {
  main: {
    print(value) {
      console.log(`Got ${value} from WebAssembly`);
    }
  },
}).then(result => {
  const exports = result.instance.exports;
  exports._main(1);
}).catch(console.error);
