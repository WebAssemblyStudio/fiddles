let x = '../out/main.wasm';

let instance = null;
let memoryStates = new WeakMap();


function allocMem(size) {
  const memory = instance.exports.memory;
  let memoryState = memoryStates.get(instance);
  const requested = size;
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

function syscall(instance, n, args) {
  switch (n) {
    default:
      // console.log("Syscall " + n + " NYI.");
      break;
    case /* brk */ 45: return 0;
    case /* writev */ 146:
      return instance.exports.writev_c(args[0], args[1], args[2]);
    case /* mmap2 */ 192:
      return allocMem(args[1]);
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
  document.getElementById("container").textContent = instance.exports.main();
  var img = new Uint8Array(8*8);
  var mask = new Uint8Array(8*8);
  var width = 8;
  var height = 8;

  for(var i=0; i<8*8; ++i) {
    mask[i] = 0;
    img[i] = i;
  }
  mask[4*8 + 4] = 255;
  mask[1*8 + 1] = 255;
  console.log(mask);

// instance.exports.memory.buffer,
  
  var buffer = allocMem(img.length);
  var buffer2 = allocMem(mask.length);

  var view = new Uint8Array(instance.exports.memory.buffer, buffer);
  var view2 = new Uint8Array(instance.exports.memory.buffer, buffer2);
  for(var i=0; i<img.length; ++i) {
    view[i] = img[i];
    view2[i] = mask[i];
  }

 // var buffer = WebAssembly.Module._malloc(img.length * img.BYTES_PER_ELEMENT);
 // instance.HEAP8.set(img, buffer);
 // var buffer2 = WebAssembly.Module._malloc(mask.length * mask.BYTES_PER_ELEMENT);
 // instance.HEAP8.set(mask, buffer2);

  //var results = instance.exports.autoHighlight(img, mask, width, height, 0);
  var results2 = instance.exports.autoHighlight(buffer, buffer2, width, height, 0, 0);
  //instance.ccall("autoHighlight", "");
  console.log(results2);

//  instance.free();
}).catch(console.error);
