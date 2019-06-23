function fib(n) {
  let a = 0.0, b = 1.0
	for (let i = 0; i < n; i++) {
		let c = a + b;
		a = b;
		b = c;
	}
	return a;
}

WebAssembly.instantiateStreaming(fetch("../out/main.wasm"), {
  env: {
    abort(_msg, _file, line, column) {
      console.error("abort called at main.ts:" + line + ":" + column);
    }
  },
}).then(result => {
  const exports = result.instance.exports;
  
  console.time('fib (JS)');
  const jsres = fib(1e9);
  console.timeEnd('fib (JS)');
  console.log('fib JS (1e9):', jsres);

  console.time('fib (Wasm)');
  const asres = exports.fib(1e9);
  console.timeEnd('fib (Wasm)');
  console.log('fib Wasm (1e9):', asres);

}).catch(console.error);
