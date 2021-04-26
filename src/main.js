let instance;
let memoryPoolStart;

// The only syscalls used in malloc
const SYSCALL_TABLE = {
  BRK: 45,
  MMAP_2: 192,
};

function syscallDispatcher(syscall_id, ...args) {
  const [
    // https://linux-kernel-labs.github.io/refs/heads/master/lectures/syscalls.html
    arg1,
    arg2,
    arg3,
    arg4,
    arg5,
    arg6,
  ] = args;

  switch (syscall_id) {
    // https://man7.org/linux/man-pages/man2/brk.2.html
    // It should try to allocate more memory for the program
    // but since the memory is already allocated (we can only grow the existing buffer)
    // we just return success here
    case SYSCALL_TABLE.BRK: {
      console.log('BRK called', {  arg1, arg2, arg3, arg4, arg5, arg6 });
      return 0;
    }

    // https://man7.org/linux/man-pages/man2/mmap2.2.html
    // Here it just updates the allocationHeadPointer
    // and grows the memory buffer if required.
    // ECX = requested size
    // Needs to return the start 
    case SYSCALL_TABLE.MMAP_2: {
      console.log('MMAP Called', {  arg1, arg2, arg3, arg4, arg5, arg6 });
  
      console.log('C code is requesting', arg2, 'bytes');

      const currentMemoryAmount = instance.exports.memory.buffer.byteLength;
      console.log('Current memory amount:', currentMemoryAmount, 'bytes.', ' Memory pool start:', memoryPoolStart);

      const needsToGrow = memoryPoolStart + arg2 > currentMemoryAmount;
      console.log('Needs to grow memory?', needsToGrow);

      if (needsToGrow) {
        const newPageCountNeeded = Math.ceil((currentMemoryAmount - arg2) / currentMemoryAmount);
        console.log('Amount of pages needed:', newPageCountNeeded);
        instance.exports.memory.grow(newPageCountNeeded);
        console.log('New memory amount: ', instance.exports.memory.buffer.byteLength);

        const freshMemoryStartAddress = memoryPoolStart;
        memoryPoolStart += arg2;

        console.log('Now there is ', arg2, ' bytes of fresh memory starting at', freshMemoryStartAddress);
        return freshMemoryStartAddress;
      }
  
      const freshMemoryStartAddress = memoryPoolStart;
      memoryPoolStart += arg2;

      console.log('No more memory is required, returning:', freshMemoryStartAddress);
      return freshMemoryStartAddress;
    }

    default: {
      console.error(`Syscall ID ${n} is not defined`);
      break;
    }
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
      },
    })
  )
  .then((results) => {
    instance = results.instance;
    memoryPoolStart = instance.exports.memory.buffer.byteLength;

    const vecA = instance.exports.vec2(10, 20);
    const vecB = instance.exports.vec2(30, 40);

    printVec2AtAddress(instance.exports.memory.buffer, vecA);
    printVec2AtAddress(instance.exports.memory.buffer, vecB);
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
