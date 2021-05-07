(async() => {
  const promise = fetch('../out/main.wasm');
  const { instance } = await WebAssembly.instantiateStreaming(promise);

  /* Benchmark */
  let start;
  let end;
  benchmark = (start, end) => { console.log(start); return end-start; }

  /* Fibonacci */
  const formFibonacci = document.querySelector('#formFibonacci');
  const fibonacci = document.querySelector('#fibonacci');
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
    fibJSres.textContent = fibJS(fibonacci.value)
    end = performance.now();
    fibJStime.textContent = result;
    
    start = performance.now();
    fibWASMres.textContent = fibWASM(fibonacci.value)
    end = performance.now();
    fibWASMtime.textContent = end-start;
  }

  /* Numeros Primos */
  const formPrimes = document.querySelector('#formPrimes');
  const primeWASM = document.querySelector('#primeWASM');
  const primeJS = document.querySelector('#primeJS');

})()