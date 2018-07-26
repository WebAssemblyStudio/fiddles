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
  var canvas = document.getElementById('canvas');
  var ctx = canvas.getContext('2d');
  var width = 512;
  var height =512;
  let buffersize = width * height * 4;
  var p = instance.exports.walloc(buffersize);
  var array = new Uint8ClampedArray(instance.exports.memory.buffer,p,buffersize);

  var img = new ImageData(array, width, height);
  instance.exports.fillbox(p,width,height,0x000000);
  ctx.putImageData(img, 0, 0);

    var start = null;
    function step(timestamp) {
      var progress;
      if (start === null) start = timestamp;
      progress = timestamp - start;
      if (progress > 10) {
        instance.exports.fillrandomrect(p, width, height);
        start = timestamp;

        window.requestAnimationFrame(draw);
      } else {
        window.requestAnimationFrame(step);
      }
    }

    function draw() {
      ctx.putImageData(img, 0, 0)
      window.requestAnimationFrame(step);
    }

  window.requestAnimationFrame(step);

  document.getElementById("container").innerText = instance.exports.main();
  instance.exports.wfree(p);
});
