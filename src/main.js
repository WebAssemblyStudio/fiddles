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

const importObject = {
    env: {
        __syscall0: function __syscall0(n) { return syscall(instance, n, []); },
        __syscall1: function __syscall1(n, a) { return syscall(instance, n, [a]); },
        __syscall2: function __syscall2(n, a, b) { return syscall(instance, n, [a, b]); },
        __syscall3: function __syscall3(n, a, b, c) { return syscall(instance, n, [a, b, c]); },
        __syscall4: function __syscall4(n, a, b, c, d) { return syscall(instance, n, [a, b, c, d]); },
        __syscall5: function __syscall5(n, a, b, c, d, e) { return syscall(instance, n, [a, b, c, d, e]); },
        __syscall6: function __syscall6(n, a, b, c, d, e, f) { return syscall(instance, n, [a, b, c, d, e, f]); },
        'memory': new WebAssembly.Memory({ initial: 0, maximum: 62500 })
    }
};

fetch('../out/main.wasm').then(response =>
	response.arrayBuffer()
).then(bytes => WebAssembly.instantiate(bytes, importObject)).then(results => {
	instance = results.instance;

	function prime(n) {
		let asqrt = 0;
		let p = 0;
		let i = 0;
		let primes = 0;

		for (i = 2; i <= n; ++i) {
			asqrt = Math.sqrt(i);
			let aprime = true;

			for (p = 2; p <= asqrt; ++p) {
				if (i % p == 0) {
					aprime = false;
					break;
				}
			}

			if (aprime)
				++primes;
		}

		return primes;
	}

	function eratosthenes(n) {
		const sqrtn = Math.sqrt(n);
		let p = 0;
		let i = 0;
		let primes = 0;

		let aprime = new Array(n);
		for (p = 0; p <= n; ++p)
			aprime[p] = true;

		for (p = 2; p <= sqrtn; ++p) {
			if (aprime[p]) {
				for (i = p * 2; i <= n; i += p)
					aprime[i] = false;
			}
		}

		for (p = 2; p <= n; ++p)
			if (aprime[p])
				++primes;

		return primes;
	}


	// TEST CASES

	function wasmtest(id, afunction, n) {
		let start = performance.now();
		let result = afunction(n);
		let time = performance.now() - start;
		document.getElementById(id).innerText = "★ WebAssembly computed " + result + " in " + time + "ms";
	}

	function jstest(id, afunction, n) {
		let start = performance.now();
		let result = afunction(n);
		let time = performance.now() - start;
		document.getElementById(id).innerText = "☆ JavaScript computed " + result + " in " + time + "ms";
	}

	//const n = instance.exports.max();
	const n = Math.pow(2, 22);

	document.getElementById("primes").innerText = "Prime numbers less then " + n + ":";

	document.getElementById("prime").innerText = "Brute force";

	wasmtest("wasm-prime", instance.exports.prime, n);
	jstest("js-prime", prime, n);

	document.getElementById("eratosthenes").innerText = "Sieve of Eratosthenes";

	wasmtest("wasm-eratosthenes", instance.exports.eratosthenes, n);
	jstest("js-eratosthenes", eratosthenes, n);
});