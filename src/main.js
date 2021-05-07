(async() => {
  const promise = fetch('../out/main.wasm');
  const { instance } = await WebAssembly.instantiateStreaming(promise);

  /* Benchmark */
  let start;
  let end;
  benchmark = (start, end) => { return end-start; }

  /* Fibonacci */
  const formFibonacci = document.querySelector('#formFibonacci');
  const fieldFibonacci = document.querySelector('#fieldFibonacci');
  const fibJSres = document.querySelector('#fibJSres');
  const fibWASMres = document.querySelector('#fibWASMres');
  const fibJStime = document.querySelector('#fibJStime');
  const fibWASMtime = document.querySelector('#fibWASMtime');

  fibWASM = n => instance.exports.fibonacci(n);
  fibJS = n => {
    if (n <= 1)
        return n;
    return fibJS(n-1) + fibJS(n-2);
  }

  formFibonacci.onsubmit = (e) => {
    e.preventDefault();
    
    start = performance.now();
    fibJSres.textContent = fibJS(fieldFibonacci.value)
    end = performance.now();
    fibJStime.textContent = benchmark(start, end) + " ms";
    
    start = performance.now();
    fibWASMres.textContent = fibWASM(fieldFibonacci.value)
    end = performance.now();
    fibWASMtime.textContent = benchmark(start, end) + " ms";
  }

  /* Numeros Primos */
  const formPrimes = document.querySelector('#formPrimes');
  const fieldPrimes = document.querySelector('#fieldPrimes');
  const primeWASM = document.querySelector('#primeWASMres');
  const primeJSres = document.querySelector('#primeJSres');
  const primeJStime = document.querySelector('#primeJStime');
  const primeWASMtime = document.querySelector('#primeWASMtime');

  primeJS => x => {
    for (let i = 0; primes[i] * primes[i] <= x; ++i) {
        if (x % primes[i] == 0) {
            return false;
        }
    }
    return true;
}

})()