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
  const primeJSres = document.querySelector('#primeJSres');
  const primeWASMres = document.querySelector('#primeWASMres');
  const primeJStime = document.querySelector('#primeJStime');
  const primeWASMtime = document.querySelector('#primeWASMtime');

  primeWASM = function(n) { return instance.exports.is_prime(n); }

  formPrimes.onsubmit = (e) => {
    e.preventDefault();

    start = performance.now();
    //primeJSres.textContent = primeJS(fieldPrimes.value)
    end = performance.now();
    //primeJStime.textContent = benchmark(start, end) + " ms";
    
    start = performance.now();
    primeWASMres.textContent = primeWASM(fieldPrimes.value)
    end = performance.now();
    //primeWASMtime.textContent = benchmark(start, end) + " ms";
  }
})()