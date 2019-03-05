
const F64 = new Float64Array(1);
const U64 = new BigUint64Array(F64.buffer);

WebAssembly.instantiateStreaming(fetch("../out/main.wasm"), {
  main: {
    log(v) {
      F64[0] = v;
      console.log(U64.toString());
    }
  },
  env: {
    abort(msg, file, line, column) {
      console.error("abort called at main.ts:" + line + ":" + column);
    }
  },
}).then(result => {
  const exports = result.instance.exports;
  document.getElementById("container").textContent = "Result: " + exports.add(19, 23);
}).catch(console.error);
