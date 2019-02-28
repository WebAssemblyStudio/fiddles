//Import funtion from  Rust to JavaScript
const {sum} = wasm_bindgen;

function runApp(){
  document.getElementById('resultSum').value = 
    sum(
      document.getElementById("sumA").value, 
      document.getElementById("sumB").value
    )
}

// Load and instantiate the wasm file, and we specify the source of the wasm
// file here. Once the returned promise is resolved we're ready to go and
// use our imports.
wasm_bindgen('../out/main_bg.wasm')
.catch(console.error);
