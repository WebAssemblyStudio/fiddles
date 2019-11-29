// This is our recommended way of loading WebAssembly.
// https://developers.google.com/web/updates/2018/04/loading-wasm
(async () => {
  const fetchPromise = fetch('../out/fibonacci.wasm');
  const { instance } = await WebAssembly.instantiateStreaming(fetchPromise);
  const num = 18;
  const numberArray = [...Array(50000).keys()]
  console.time('fibWASM')
  const factorialWASM = instance.exports.factorial;
  const fibonacciWASM = instance.exports.fibonacci;
  for(let num in numberArray){
    fibonacciWASM(num);
  }
  console.timeEnd('fibWASM');
  // document.querySelector('main').textContent = `The ${num} Factorial number is ${ result }.`;
  console.time('fibJS')
  for(let num in numberArray){
    fibonacci(num);
  }
  // console.log(`The ${num} factorial number is ${ resultJS }`);
  console.timeEnd('fibJS');
})();

function factorial(n){
  if(n<0) return 0;
  if (n == 0)
    return 1;
  else
    return(n * factorial(n-1));
}

function fibonacci(n) {
  let i, t, a = 0, b = 1;
  for (i = 0; i < n; i++) {
    t = a + b;
    a = b;
    b = t;
  }
  return b;
}