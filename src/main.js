WebAssembly.instantiateStreaming(fetch("../out/main.wasm"), {

  main: {print(value) {
    console.log("Got ", value, "from WebAssembly");
  }},
  env: {
    abort(_msg, _file, line, column) {
      console.error("abort called at main.ts:" + line + ":" + column);
    }
  },
}).then(result => {
  const exports = result.instance.exports;
  exports._main(1);
}).catch(console.error);
