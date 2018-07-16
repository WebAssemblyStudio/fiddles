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

let s = [[], [], []];
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
      putcs_js: function (fd, c, l) {
        let bytes = new Uint8Array(instance.exports.memory.buffer, c, l);
        let str = Array.from(bytes).map(e => String.fromCharCode(e)).join("");
        let nl = str.indexOf("\n");
        while (nl >= 0) {
          let line;
          if (s[fd].length > 0) {
            line = s[fd].join("")+str.substring(0, nl);
            s[fd] = [];
          } else {
            line = str.substring(0, nl);
          }
          let log = fd == 1 ? console.log : console.error;
          log.call(console, line);
          str = str.substring(nl + 1);
          nl = str.indexOf("\n");
        }
        if (str.length > 0) s[fd].push(str);
      },
      putc_js: function (fd, c) {
        c = String.fromCharCode(c);
        if (c == "\n") {
          let log = fd == 1 ? console.log : console.error;
          log.call(console, s[fd].join(""));
          s[fd] = [];
        } else {
          s[fd].push(c);
        }
      }
    }
  })
).then(results => {
  instance = results.instance;
  document.getElementById("container").innerText = instance.exports.main();
}).catch(console.error);
