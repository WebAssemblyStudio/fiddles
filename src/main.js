(async function () {
  const result = await WebAssembly.instantiateStreaming(fetch("../out/main.wasm"), {
    env: {
      sayHello: function() {
        console.log("Hello from WebAssembly!");
      },
      abort: function(msg, file, line, column) {
        console.error("abort called at main.ts:" + line + ":" + column);
      }
    }
  })
  const memory = new Uint8Array(result.instance.exports.memory.buffer);
  const encoder = new TextEncoder();
  let ptr = 0;
  const writeString = (str) => {
    let buffer = encoder.encode(str);
    memory.set(buffer);
    // Null-terminate string.
    // memory.set([0], buffer.byteLength);
  }
  const ZERO = '0'.codePointAt(0);
  console.log('ZERO', ZERO);
  const writeFlush = () => {
    memory.set([ZERO, ZERO, ZERO, ZERO], ptr);
    ptr += 4;
  }
  writeString('Hello world!');
  writeString('Hello');
  writeFlush();
  writeFlush();
  const exports = result.instance.exports;
  // exports.GitPktLine_flush(20);
  exports.GitPktLine_hex(20, 16);
  console.log(memory);
  console.log(result.instance);
  exports.saysay();
  console.log(exports.readMemory(0), exports.readMemory(1));
})();