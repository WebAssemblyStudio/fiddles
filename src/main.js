const { greet, sieve } = wasm_bindgen;

const { $, $$ } = {
  $: e => document.querySelector(e),
  $$: e => document.querySelectorAll(e),
};
const range = (min, max) => Array.from({ length: max - min + 1 }, (_, i) => min + i, min)

function init() {
  const greeting = greet('Sieve of Eratosthenes test');
  $("#app").innerText = greeting;

  jsEratosthenes(20);
  wasmEratosthenes(20);
}

async function jsEratosthenes(n) {
  const max = Math.sqrt(n);
  let arr = range(2, n);
  let cand = 2;
  while (cand < max) {
    arr = arr.map(i => i % cand === 0 && i !== cand ? 0 : i);
    cand = arr.find(i => i > cand) || cand + 1;
  }

  const res = arr.filter(i => i > 1);

  $("#js-eratosthenes").innerText = res.join(" ");
}

async function wasmEratosthenes(n) {
  const res = sieve(n);
  $("#wasm-eratosthenes").innerText = res.join(" ");
}

wasm_bindgen('../out/main_bg.wasm')
  .then(init)
  .catch(console.error);
