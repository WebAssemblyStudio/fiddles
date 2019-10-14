function is_prime(number) {
  for (let divisor = 2; divisor < number; divisor++) {
    if (number % divisor == 0) {
      return 0;
    }
  }
  return 1;
}

function find_primes(arr, length) {
  let tested_number = 2;
  let primes_found = 0;
  while (primes_found < length) {
    if (is_prime(tested_number)) {
      arr[primes_found] = tested_number;
      primes_found++;
    }
    tested_number++;
  }
}



fetch('../out/main.wasm').then(response =>
  response.arrayBuffer()
).then(bytes => WebAssembly.instantiate(bytes)).then(results => {
  const length = 5000;
  const exports = results.instance.exports;

  let offset = exports.__heap_base;
  let primes = new Int32Array(exports.memory.buffer, offset, length);

  exports.find_primes(offset, length);
  exports.find_primes(offset, length);
  exports.find_primes(offset, length);

  console.time('wasm primes');
  exports.find_primes(offset, length);
  console.timeEnd('wasm primes');

  let arr = new Int32Array(length);

  find_primes(arr, length);
  find_primes(arr, length);
  find_primes(arr, length);

  console.time('js primes');
  find_primes(arr, length);
  console.timeEnd('js primes');

}).catch(console.error);
