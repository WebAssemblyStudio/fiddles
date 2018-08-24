let instance = null, exports = null;

WebAssembly.instantiateStreaming(fetch("../out/main.wasm"), {
    env: { lognum(n) { console.log(n + " is prime."); } },
}).then(result => {
  instance = result.instance;
  exports = result.instance.exports;

  console.time("run");
    exports.run(1000);
  console.timeEnd("run");
}).catch(console.error);
