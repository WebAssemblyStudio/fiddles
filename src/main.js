// This is our recommended way of loading WebAssembly.
// https://developers.google.com/web/updates/2018/04/loading-wasm

let i = 0;

async function loadWasm() {
  const fetchPromise = fetch('../out/fibonacci.wasm');
  const { instance } = await WebAssembly.instantiateStreaming(fetchPromise);
  const result = instance.exports.fibonacci(42);
  document.querySelector('main').textContent = `The 42nd Fibonacci number is ${ result }. ${i++}`;
}

async function run() {
  const promises = [];
  for (let i = 0; i < 1000; i++) {
    try {
      await loadWasm();
    } catch (err) {
      console.error(err);
    }
  }
}

run()