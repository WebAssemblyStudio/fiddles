const { sum_from_one_to_n } = wasm_bindgen;

function runApp() {
}

function clickBtn() {
  const t1 = document.form1.text1.value;
	document.getElementById("container").textContent = sum_from_one_to_n(t1);
}

// Load and instantiate the wasm file, and we specify the source of the wasm
// file here. Once the returned promise is resolved we're ready to go and
// use our imports.
wasm_bindgen('../out/main_bg.wasm').then(runApp).catch(console.error);
