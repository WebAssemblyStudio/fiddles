let x = '../out/main.wasm';
try{
  let c = await import('../src/imports/Vector2.js');
} catch(e)
{
  console.log(e);
}

//import Vector2_ from "./imports/Vector2.js"
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
var Vector2 = function(x,y)
{
  var pointer = Vector2.Vector2_new(x,y);
  this.x = () => {
    return Vector2.Vector2_get_x(pointer)
  }
  this.y = () => {
    return Vector2.Vector2_get_y(pointer);
  }
  this.destroy = () => {
    Vector2.Vector2_delete(pointer);
  }
}
Vector2.InicializeMethods = (exports) => {
  Vector2.Vector2_new = exports.Vector2_new;
  Vector2.Vector2_get_x = exports.Vector2_get_x;
  Vector2.Vector2_get_y = exports.Vector2_get_y;
  Vector2.Vector2_delete = exports.Vector2_delete;
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
  var {main,Vector2_new,Vector2_get_x,Vector2_get_y,Vector2_delete} = instance.exports;
  Vector2.InicializeMethods(instance.exports);
  var pos = new Vector2(3,4)
  document.getElementById("container").textContent = pos.y();
}).catch(console.error);
