(async() => {
  const promise = fetch('../out/fibonacci.wasm');
  const { fibInstance } = await WebAssembly.instantiateStreaming(promise);

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

  fibWASM = n => fibInstance.exports.fibonacci(n);
  fibJS = n => {
    if (n <= 1)
        return n;
    return fibJS(n-1) + fibJS(n-2);
  }

  formFibonacci.onsubmit = (e) => {
    e.preventDefault();
    
    start = performance.now();
    fibJSres.textContent = fibJS(fibonacci.value)
    end = performance.now();
    fibJStime.textContent = benchmark(start, end) + " ms";
    
    start = performance.now();
    fibWASMres.textContent = fibWASM(fibonacci.value)
    end = performance.now();
    fibWASMtime.textContent = benchmark(start, end) + " ms";
  }

  /* Numeros Primos */
  const formPrimes = document.querySelector('#formPrimes');
  const formPrimes = document.querySelector('#fieldPrimes');
  const primeWASM = document.querySelector('#primeWASMres');
  const primeJS = document.querySelector('#primeJSres');
  const fibJStime = document.querySelector('#primeJStime');
  const fibWASMtime = document.querySelector('#primeWASMtime');

})()