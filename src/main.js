WebAssembly.instantiateStreaming(fetch("../out/main.wasm"), {
  env: {
    sayHello: function() {
      console.log("Hello from WebAssembly!");
    },
    abort: function(msg, file, line, column) {
      console.error("abort called at main.ts:" + line + ":" + column);
    }
  }
}).then(result => {
  const mod = result.instance;
  debugger;
  const { add, getString, memory } = mod.exports;
  document.getElementById("container").innerText =
    `Result: ${add(19, 23)}
     ${readString(memory.buffer, getString())}
    `
}).catch(console.error);

function readString(buffer, strPointer) {
  const dv = new DataView(buffer, strPointer);
  const length = dv.getInt32(0, true); // littleEndian
  let result = "";
  for (var i = 0; i < length; i++) {
    result += String.fromCharCode(dv.getInt16((i * 2) + 4, true));
  }
  return result;
}