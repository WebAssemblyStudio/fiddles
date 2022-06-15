let x = '../out/main.wasm';

let instance = null;
let memoryStates = new WeakMap();

const bytesPerPage = 64 * 1024;
function toBytesInt32 (num) {
    arr = new Uint8Array([
         (num & 0x000000ff),
         (num & 0x0000ff00) >> 8,
         (num & 0x00ff0000) >> 16,
         (num & 0xff000000) >> 24
    ]);
    return arr.buffer;
}

var _appendBuffer = function(buffer1, buffer2) {
  var tmp = new Uint8Array(buffer1.byteLength + buffer2.byteLength);
  tmp.set(new Uint8Array(buffer1), 0);
  tmp.set(new Uint8Array(buffer2), buffer1.byteLength);
  return tmp.buffer;
};


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
  
  const argument = "password1";

  // Step 2: Allocate some more memory
  const oldPages = instance.exports.memory.grow(1);
  const oldMax = oldPages * bytesPerPage;
  
  let h = new Uint8Array(instance.exports.memory.buffer);
  
  // Step 3: Copy our arguments in
  let p = new TextEncoder().encode(argument);
  for(let i =0; i < p.length; i++) {
    h[oldMax +i] = p[i];
  }
  
  
  // Encode pointers for argv
  let pointers = new Uint8Array(_appendBuffer(toBytesInt32(0), toBytesInt32(oldMax)));
  
  // Step 4: Specify argv etc
  for(let i =0; i < pointers.length; i++) {
    h[oldMax + 0x200 +i] = pointers[i];
  }
  
  
  
  document.getElementById("container").textContent = instance.exports.main(2, oldMax + 0x200);

}).catch(console.error);
