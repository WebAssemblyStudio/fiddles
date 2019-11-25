let x = '../out/main.wasm';

let instance = null;

function syscall(instance, n, args) {
  switch (n) {
    default:
      // console.log("Syscall " + n + " NYI.");
      break;
    case /* writev */ 4:
      return instance.exports.writev_c(args[0], args[1], args[2]);
  }
}

let s = "";
fetch(x).then(response =>
  response.arrayBuffer()
).then(bytes =>
  WebAssembly.instantiate(bytes, {
    env: {
      __syscall: function __syscall(n) { return syscall(instance, n, []); },
      putc_js: function (c) {
          //var a = String.fromCharCode(c)
          console.log(String.fromCharCode(c));
        }
      }
    }
  )
).then(results => {
  instance = results.instance;
  document.getElementById("container").innerText = instance.exports.main();
});
