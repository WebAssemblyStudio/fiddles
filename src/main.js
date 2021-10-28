let i = 0;

let fibModule;
async function loadWasmReuseModule() {
  if (!fibModule) {
    const fetchPromise = fetch('../out/fibonacci.wasm');
    const { module } = await WebAssembly.instantiateStreaming(fetchPromise);
    fibModule = module;
  }
  const instance = new WebAssembly.Instance(fibModule);
  const result = instance.exports.fibonacci(42);
  document.querySelector('main').textContent = `The 42nd Fibonacci number is ${ result }. ${i++}`;
}

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
      await loadWasmReuseModule();
    } catch (err) {
      console.error(err);
    }
  }
}

run()