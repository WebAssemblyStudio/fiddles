WebAssembly.instantiateStreaming(fetch("../out/main.wasm"), {
  main: {
    console_log(val) {
      console.log(String.fromCodePoint(val));
    },
    console_i32(x) {
      console.log(x);
    }
  },
  env: {
    abort(_msg, _file, line, column) {
      console.error("abort called at main.ts:" + line + ":" + column);
    }
  },
}).then(result => {
  const exports = result.instance.exports;
  document.getElementById("container").textContent = "Result: " + exports.add(19, 23);
}).catch(console.error);
