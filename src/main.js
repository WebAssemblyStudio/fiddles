WebAssembly.instantiateStreaming(fetch("../out/main.wasm"), {
  main: {
    log1(x) {
      console.log('main.log1:' + x);
    }
  },
  env: {
    log2(x) {
      console.log('env.log2:' + x);
    },
    abort(_msg, _file, line, column) {
      console.error("abort called at main.ts:" + line + ":" + column);
    }
  },
}).then(result => {
  const exports = result.instance.exports;
  document.getElementById("container").textContent = "Result: " + exports.add(19, 23);
}).catch(console.error);
