const O_RDONLY   = 0x0000
const O_WRONLY   = 0x0001
const O_RDWR     = 0x0002
const O_ACCMOE   = 0x0003

const O_NONBLOCK = 0x0004
const O_APPEND   = 0x0008

const O_CREAT    = 0x0200
const O_TRUNC    = 0x0400
const O_EXCL     = 0x0800

// Virtual File Table
// This is a very simplistic and imperformat implementation.
// New files are appended to this array and file descriptors
// are appended to the array.
// Special file descriptors are predefined.
// Limitations:
//  - Since every call to open will 
const vftab = [
  {write: undefined,   read: undefined}
  {write: console.log, read: undefined}
]


let x = '../out/main.wasm';

let instance = null;
let memoryStates = new WeakMap();

function syscall(instance, n, args) {
  switch (n) {
    default:
      console.log("Syscall " + n + " NYI.");
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

const argv = ['CakeML', 'is', 'cool!']
const argc = argv.length

// Create an Uint8Array from memory once and keep this instance.
let cachedArray = null;
function memory() {
  if (cachedArray === null || cachedArray.buffer !== instance.exports.memory.buffer) {
    cachedArray = new Uint8Array(instance.exports.memory.buffer);
  }
  return cachedArray;
}

// Helper to get a Uint8Array backed by wasm memory.
const view = (ptr, len) => memory().subarray(ptr, ptr + len)

// Helper to group together ptrs and lens under the wasm function type.
const wrap = (f) => (ptr1, len1, ptr2, len2) => f({ptr: ptr1, len: len1}, {ptr: ptr2, len: len2})

// Create and keep coders for UTF-8 text.
const encoding = 'utf-8'
const text = {
  encoder: new TextEncoder(encoding),
  decoder: new TextDecoder(encoding)
}

// TODO: Note that the length of the string, i.e. how much memory
// is available for it is not considered, we might overwrite.
const storeString = (s, ptr) => {
  const buf = text.encoder.encode(s)
  console.log(buf, s)
  memory().set(buf, ptr)
  return {ptr, len: buf.byteLength}
}

// TODO: Note that the length of the string, i.e. how much memory
// is available for it is not considered, we might overwrite.
const storeString = (s, ptr) => {
  const buf = text.encoder.encode(s)
  console.log(buf, s)
  memory().set(buf, ptr)
  return {ptr, len: buf.byteLength}
}

const loadString = (ptr, len) => {
  return text.decoder.decode(memory().subarray(ptr, ptr + len))
}

const loadNulString = (ptr) => {
  const len = memory().subarray(ptr).indexOf(0)
  return text.decoder.decode(ptr, len)
}

let s = "";
fetch(x).then(response =>
  response.arrayBuffer()
).then(bytes =>
  WebAssembly.instantiate(bytes, {
    console: {
      logInt: console.log,
      logString: console.log
    },
    cake: {
      argc
    },
    basis: {
      get_arg_count: wrap((a, b) => {
        const dst = view(a.ptr, 2)
        console.log(dst)
        dst[0] = argc
        dst[1] = argc / 256
      }),
      get_arg_length: wrap((a, b) => {
        const buf = view(a.ptr, 2)
        console.log(buf)
        const i = buf[0] + (buf[1] * 256)
        if (i >= argv.length) {
          console.error('Index for get_arg_length out of bounds.')
        }
        const res = argv[i].length
        buf[0] = res
        buf[1] = res / 256
      }),
      get_arg: wrap((a, b) => {
        const buf = view(a.ptr, 2)
        const i = buf[0] + (buf[1] * 256)
        if (i >= argv.length) {
          console.error('Index for get_arg_length out of bounds.')
        }
        storeString(argv[i], a.ptr)
      }),
      // To open the file with name at fname (zero-terminated) as O_RDONLY
      // b[0] = 1 indicates error
      // b[0] = 0 indicates success
      // The file descriptor, an i64, should be written to b[1].
      open_in: wrap((fname, b) => {
        
      })
    },
    env: {
      __syscall: function() { console.log("STRANGE"); },
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
  document.getElementById("container").innerText = instance.exports.main(1, 0);
}).catch(console.error);
