(async function () {
  const result = await WebAssembly.instantiateStreaming(fetch("../out/main.wasm"), {
    env: {
      sayHello: function() {
        console.log("---Hello from WebAssembly!---");
      },
      abort: function(msg, file, line, column) {
        console.error("abort called at main.ts:" + line + ":" + column);
      }
    }
  })
  const memory = new Uint8Array(result.instance.exports.memory.buffer);
  const encoder = new TextEncoder();
  const decoder = new TextDecoder();
  const writeString = (offset, str) => {
    let buffer = encoder.encode(str);
    memory.set(buffer, offset);
    // Null-terminate string.
    // memory.set([0], buffer.byteLength);
  }
  writeString(0, 'Hello world!');
  const exports = result.instance.exports;
  exports.GitPktLine_flush(13);
  writeString(18, '0x');
  exports.GitPktLine_hex(20, 15);
  console.log(memory);
  console.log(decoder.decode(memory.slice(0,100)));
})();