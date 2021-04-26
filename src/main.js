// https://webassembly.studio/?f=v0zzkevi5y8
let instance;
let memoryPoolStart;

const SYSCALL_TABLE = {
  BRK: 45,
  MMAP_2: 192,
};

function syscallDispatcher(syscall_id, ...args) {
  const [
    arg1,
    arg2,
    arg3,
    arg4,
    arg5,
    arg6,
  ] = args;

  switch (syscall_id) {
    case SYSCALL_TABLE.BRK:
      return 0;

    case SYSCALL_TABLE.MMAP_2:
      const currentMemoryAmount = instance.exports.memory.buffer.byteLength;
      const needsToGrow = memoryPoolStart + arg2 > currentMemoryAmount;

      if (needsToGrow) {
        const newPageCountNeeded = Math.ceil((currentMemoryAmount - arg2) / currentMemoryAmount);
        instance.exports.memory.grow(newPageCountNeeded);
      }
  
      const freshMemoryStartAddress = memoryPoolStart;
      memoryPoolStart += arg2;

      return freshMemoryStartAddress;
    

    default:
      console.error(`Syscall ID ${n} is not defined`);
      break;
  }
}

fetch("../out/main.wasm")
  .then((response) => response.arrayBuffer())
  .then((bytes) =>
    WebAssembly.instantiate(bytes, {
      env: {
        __syscall1: syscallDispatcher,
        __syscall2: syscallDispatcher,
        __syscall3: syscallDispatcher,
        __syscall4: syscallDispatcher,
        __syscall5: syscallDispatcher,
        __syscall6: syscallDispatcher,
        add_js: (a, b) => a + b,
      },
    })
  )
  .then((results) => {
    instance = results.instance;
    memoryPoolStart = instance.exports.memory.buffer.byteLength;

    const vecA = instance.exports.vec2(10, 20);
    const vecB = instance.exports.vec2(30, 40);
    const vecC = instance.exports.vec3(50, 60, 70);
    const vecD = instance.exports.vec3(80, 90, 100);

    printVec2AtAddress(instance.exports.memory.buffer, vecA);
    printVec2AtAddress(instance.exports.memory.buffer, vecB);
    printVec3AtAddress(instance.exports.memory.buffer, vecC);
    printVec3AtAddress(instance.exports.memory.buffer, vecD);
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

const printVec3AtAddress = (buffer, address, numberFormatSize = 8) => {
  const start = address;
  const end = address + numberFormatSize * 3;

  const snipedVec3 = new DataView(buffer.slice(start, end));

  console.log(`Vec3@${address} {
  x: ${snipedVec3.getFloat64(0 * numberFormatSize, true)},
  y: ${snipedVec3.getFloat64(1 * numberFormatSize, true)},
  z: ${snipedVec3.getFloat64(2 * numberFormatSize, true)},
}`);
};
