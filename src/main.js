let exports = null;

WebAssembly.instantiateStreaming(fetch("../out/main.wasm"), {}).then(result => {
  exports = result.instance.exports;
  exports.foo();
}).catch(e => {
  if (e instanceof WebAssembly.RuntimeError) {
    if (e.message == "unreachable executed") {
      console.error(
        "Abort reason: " + exports.__lastAbortMsg + 
        " in line: "      + exports.__lastAbortLine
      );
    }
  }
});
