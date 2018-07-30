const { fib, greet, isFacebookStockGoingToGoUp } = wasm_bindgen;

function seeTheFuture() {
  const container = document.querySelector('#container');
  container.innerHTML = isFacebookStockGoingToGoUp() ? 'Yes' : 'No';
}

// Load wasm file
async function main() {
  const module = await wasm_bindgen('../out/main_bg.wasm');

  greet('Core Viz!');

  const button = document.querySelector('#future');
  button.addEventListener('click', seeTheFuture);
}

main();
