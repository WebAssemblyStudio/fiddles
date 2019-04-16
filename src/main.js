let x = '../out/main.wasm';


function fib (n) {
    if (n < 2) {
      return 1
    }
    return fib(n - 2) + fib(n - 1)
  }




async function createWebAssembly() {
    const result = await window.fetch(x);
    const bytes = await result.arrayBuffer();
    return WebAssembly.instantiate(bytes, {env: {}});
}


(async () => {
  let count = 40;
  let t0 = performance.now();
  const wa = await createWebAssembly();
  let t1 = performance.now();
  console.log('load binary took time ' + (t1 - t0) + ' milliseconds');


  let t2 = performance.now();
  let rst1 = wa.instance.exports.fib(count);
  let t3 = performance.now() - t2;
  console.log('fib(40) with wasm took time ' + (t3) + ' milliseconds with rst ' + rst1);

  let t4 = performance.now();
  let rst2 = fib(40);
  let t5 = performance.now() - t4;
  console.log('fib(40) with js took time ' + (t5) + ' milliseconds with rst ' + rst2);

  console.log('wasm run ' + ((t5 - t4) / t4)  + 'x faster than js');
})();
// fetch(x).then(response =>
//   response.arrayBuffer()
// ).then(bytes =>
//   WebAssembly.instantiate(bytes, {
//     env: {
//       __syscall0: function __syscall0(n) { return syscall(instance, n, []); },
//       __syscall1: function __syscall1(n, a) { return syscall(instance, n, [a]); },
//       __syscall2: function __syscall2(n, a, b) { return syscall(instance, n, [a, b]); },
//       __syscall3: function __syscall3(n, a, b, c) { return syscall(instance, n, [a, b, c]); },
//       __syscall4: function __syscall4(n, a, b, c, d) { return syscall(instance, n, [a, b, c, d]); },
//       __syscall5: function __syscall5(n, a, b, c, d, e) { return syscall(instance, n, [a, b, c, d, e]); },
//       __syscall6: function __syscall6(n, a, b, c, d, e, f) { return syscall(instance, n, [a, b, c, d, e, f]); },
//       putc_js: function (c) {
//         c = String.fromCharCode(c);
//         if (c == "\n") {
//           console.log(s);
//           s = "";
//         } else {
//           s += c;
//         }
//       }
//     }
//   })
// ).then(results => {
//   instance = results.instance;
//   document.getElementById("container").textContent = instance.exports.main();
// }).catch(console.error);
