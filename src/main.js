const primes_up_to = max => {
    var sieve = new Array(max + 1), primes = [];
    for (let i = 2; i <= max; ++i) {
        if (!sieve[i]) {
            primes.push(i);
            for (let j = i << 1; j <= max; j += i) {
                sieve[j] = true;
            }
        }
    }
    return primes;
};


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

  primes_up_to(10000);
  primes_up_to(10000);

  console.time('js');
  primes_up_to(10000);
  console.timeEnd('js');


  exports.primes_up_to(10000);
  exports.primes_up_to(10000);

  console.time('as');
  exports.primes_up_to(10000);
  console.timeEnd('as');

}).catch(console.error);
