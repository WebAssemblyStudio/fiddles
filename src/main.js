const { greet, addOne } = wasm_bindgen;

const button = document.getElementById("btnAddOne");
const input = document.getElementById("number");
const span = document.getElementById("result");


function runApp() {
  //greet('World');
  button.addEventListener('click', runAddOne);
}

function runAddOne() {
  let result = addOne(input.value);
  span.innerText = result;
}

// Load and instantiate the wasm file, and we specify the source of the wasm
// file here. Once the returned promise is resolved we're ready to go and
// use our imports.
wasm_bindgen('../out/main_bg.wasm').then(runApp).catch(console.error);
