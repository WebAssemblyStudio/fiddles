const memory = new WebAssembly.Memory({ initial:32, maximum:64 })
let x = '../out/main.wasm';
let instance = null;
let memoryStates = new WeakMap();

function syscall(instance, n, args) {
  switch (n) {
    default:
      // console.log("Syscall " + n + " NYI.");
      break;
    case /* brk */ 45: return 0;
    case /* writev */ 146:
      return instance.exports.writev_c(args[0], args[1], args[2]);
    case /* mmap2 */ 192:
      debugger;
      const memory = instance.exports.memory;
      let memoryState = memoryStates.get(instance);
      const requested = args[1];
      if (!memoryState) {
        memoryState = {
          object: memory,
          currentPosition: memory.buffer.byteLength,
        };
        memoryStates.set(instance, memoryState);
      }
      let cur = memoryState.currentPosition;
      if (cur + requested > memory.buffer.byteLength) {
        const need = Math.ceil((cur + requested - memory.buffer.byteLength) / 65536);
        memory.grow(need);
      }
      memoryState.currentPosition += requested;
      return cur;
  }
}

let s = "";
fetch(x).then(response =>
  response.arrayBuffer()
).then(bytes =>
  WebAssembly.instantiate(bytes, {
    env: {
      memory:memory,
      __syscall0: function __syscall0(n) { return syscall(instance, n, []); },
      __syscall1: function __syscall1(n, a) { return syscall(instance, n, [a]); },
      __syscall2: function __syscall2(n, a, b) { return syscall(instance, n, [a, b]); },
      __syscall3: function __syscall3(n, a, b, c) { return syscall(instance, n, [a, b, c]); },
      __syscall4: function __syscall4(n, a, b, c, d) { return syscall(instance, n, [a, b, c, d]); },
      __syscall5: function __syscall5(n, a, b, c, d, e) { return syscall(instance, n, [a, b, c, d, e]); },
      __syscall6: function __syscall6(n, a, b, c, d, e, f) { return syscall(instance, n, [a, b, c, d, e, f]); },
      putc_js: function (c) {
        c = String.fromCharCode(c);
        if (c == "\n") {
          console.log(s);
          s = "";
        } else {
          s += c;
        }
      }
    }
  })
).then(results => {
  instance = results.instance;
  instance.exports.main();
  let pointer = instance.exports.getData()
  const heap = new Uint8Array(instance.exports.memory.buffer,pointer,64)
  let dv = new DataView(new ArrayBuffer(14))
    dv.setUint32(0,12,true)
    dv.setUint32(4,12,true)
    dv.setUint16(8,250,true)
    dv.setUint16(10,250,true)
    dv.setUint16(12,45,true)

  let arr = [ ...new Uint8Array(dv.buffer) ]
  arr.forEach((x,i) => heap[i] = x)
  instance.exports.test(0);

  console.log('-----\nAfter:')
  console.log('x:',dv.getUint32(0,true))
  console.log('y:',dv.getUint32(4,true))
  console.log('width:',dv.getUint16(8,true))
  console.log('height:',dv.getUint16(10,true))
  console.log('rotation:',dv.getUint16(12,true))

});
