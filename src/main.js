fetch("../out/main.wasm")
  .then((response) => response.arrayBuffer())
  .then((bytes) =>
    WebAssembly.instantiate(bytes, {
      env: {
        __syscall1: (...args) => console.log('__syscall1', args),
        __syscall2: (...args) => console.log('__syscall2', args),
        __syscall3: (...args) => console.log('__syscall3', args),
        __syscall4: (...args) => console.log('__syscall4', args),
        __syscall5: (...args) => console.log('__syscall5', args),
        __syscall6: (...args) => console.log('__syscall6', args),
      },
    })
  )
  .then(({ instance }) => {
      const buffer = instance.exports.memory.buffer;

      const vecA = instance.exports.vec2(10.65, 0.5);
      const vecB = instance.exports.vec2(10.65, 0.5);
  
      printVec2AtAddress(buffer, vecA);
      printVec2AtAddress(buffer, vecB);
  })
  .catch(console.error);

const printVec2AtAddress = (buffer, address, numberFormatSize = 8) => {
  const start = address;
  const end = address + numberFormatSize * 2;

  const snipedVec3 = new DataView(buffer.slice(start, end));

  console.log(`Vec2@${address} {
  x: ${snipedVec3.getFloat64(0 * numberFormatSize, true)},
  y: ${snipedVec3.getFloat64(1 * numberFormatSize, true)},
}`);
};

