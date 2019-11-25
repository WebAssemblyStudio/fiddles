let x = '../out/main.wasm';

let instance = null;

function syscall(instance, n, args) {
  switch (n) {
    default:
      console.log("Syscall " + n + " NYI." + args[0] + args[1] + args[2]);
      break;
    case 1: return 0;
  }
}

let s = "";
fetch(x).then(response =>
  response.arrayBuffer()
).then(bytes =>
  WebAssembly.instantiate(bytes, {
    env: {
      __syscall:  function __syscall(n){ return syscall(instance, n, []); },
      __syscall0: function __syscall0(n) { return syscall(instance, n, []); },
      __syscall1: function __syscall1(n, a) { return syscall(instance, n, [a]); },
      __syscall2: function __syscall2(n, a, b) { return syscall(instance, n, [a, b]); },
      __syscall3: function __syscall3(n, a, b, c) { return syscall(instance, n, [a, b, c]); },
      __syscall4: function __syscall4(n, a, b, c, d) { return syscall(instance, n, [a, b, c, d]); },
      __syscall5: function __syscall5(n, a, b, c, d, e) { return syscall(instance, n, [a, b, c, d, e]); },
      __syscall6: function __syscall6(n, a, b, c, d, e, f) { return syscall(instance, n, [a, b, c, d, e, f]); },
      putc_js: function (c) {
        console.log(c);
      }
    }
  })
).then(results => {
  instance = results.instance;
  document.getElementById("container").innerText = instance.exports.main();
});
