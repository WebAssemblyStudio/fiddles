const memory = new WebAssembly.Memory({ initial: 1 });
const floats = new Float64Array(memory.buffer);
for (let i = 0; i < 10; i++) {
  floats[i] = 1;
}

WebAssembly.instantiateStreaming(fetch("../out/main.wasm"), {
  env: {
    memory,

    abort(_msg, _file, line, column) {
      console.error("abort called at main.ts:" + line + ":" + column);
    }
  },
}).then(result => {
  const exports = result.instance.exports;

  console.log(exports.sum(0, 10));
  document.getElementById("container").textContent = "Result: " + exports.sum(0, 10);

}).catch(console.error);
