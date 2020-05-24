function generate_sieve_js(n) {
	let isPrime = new Array(n + 1).fill(true);

	isPrime[0] = false;
	isPrime[1] = false;
	isPrime[2] = true;

	for (let i = 2; i <= n; i++) {
		if (isPrime[i]) {
			for (let j = 2; i * j <= n; j ++) {
				isPrime[i * j] = false;
			}
		}
	}
}


WebAssembly.instantiateStreaming(fetch("../out/main.wasm"), {
  main: {
    sayHello() {
      console.log("Hello from WebAssembly!");
    }
  },
  env: {
    abort(_msg, _file, line, column) {
      console.error("abort called at main.ts:" + line + ":" + column);
    }
  },
}).then(result => {
  const exports = result.instance.exports;

  const n = 9000000;

  generate_sieve_js(n);
  generate_sieve_js(n);

  console.time('generate_sieve js');
  generate_sieve_js(n);
  console.timeEnd('generate_sieve js');

  exports.generate_sieve(n);
  exports.generate_sieve(n);

  console.time('generate_sieve wasm');
  exports.generate_sieve(n);
  console.timeEnd('generate_sieve wasm');

  console.log('done!');
}).catch(console.error);
