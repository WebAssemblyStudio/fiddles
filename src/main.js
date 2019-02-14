const { run_alert, create_stuff, calculator, sumatory } = wasm_bindgen;

function runApp() {
  // run_alert('World');
  // create_stuff('');
  
  sumatory();
  printSum(calculator(document.getElementById("input_a").value, document.getElementById("input_b").value));
}

function printSum(result){
  document.getElementById('result').value = result;
}

// Load and instantiate the wasm file, and we specify the source of the wasm
// file here. Once the returned promise is resolved we're ready to go and
// use our imports.
wasm_bindgen('../out/main_bg.wasm').then(runApp).catch(console.error);
