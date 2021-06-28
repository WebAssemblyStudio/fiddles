
function bench(fn, name, container) {
  let t = performance.now();
  fn();
  t = performance.now() - t;
  container.textContent += `${name}: ${t} ms\n`;
}

const arr100K = new Array(100_000);
const arr10M = new Array(10_000_000);

function js_randomize() {
  for (let i = 0, len = arr100K.length; i < len; i++) {
    arr100K[i] = Math.random();
  }

  for (let i = 0, len = arr10M.length; i < len; i++) {
    arr10M[i] = Math.random();
  }
}

function testJSSort100K() {
  arr100K.sort((a, b) => (a > b) - (a < b));
}

function testJSSort10M() {
  arr10M.sort((a, b) => (a > b) - (a < b));
}


WebAssembly.instantiateStreaming(fetch("../out/main.wasm"), {
  env: {
    abort(_msg, _file, line, column) {
      console.error("abort called at main.ts:" + line + ":" + column);
    },
    seed() { return 111 }
  },
}).then(result => {
  const container = document.getElementById("container");
  const { 
    randomize: as_randomize, 
    testASSort100K, 
    testASSort10M
  } = result.instance.exports;

  as_randomize();

  bench(testASSort100K, 'AS sort 100_000 doubles   ', container);
  bench(testASSort10M, 'AS sort 10_000_000 doubles', container);

  js_randomize();

  bench(testJSSort100K, 'JS sort 100_000 doubles   ', container);
  bench(testJSSort10M, 'JS sort 10_000_000 doubles', container);

}).catch(console.error);
