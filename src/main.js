//////////////////// SECTION 1 ///////////////////////
const {sum, subtraction, footer} = wasm_bindgen;

function runApp(operation){
  if(operation == 'sum'){
    document.getElementById('resultSum').value = sum(document.getElementById("sumA").value, document.getElementById("sumB").value)
  }

  if(operation == 'sub'){
    document.getElementById('resultSubtraction').value = subtraction(document.getElementById("subtractionA").value, document.getElementById("subtractionB").value)
  }
}

function showFooter(){
footer();
  alert()
}

// Load and instantiate the wasm file, and we specify the source of the wasm
// file here. Once the returned promise is resolved we're ready to go and
// use our imports.
wasm_bindgen('../out/main_bg.wasm')
.then(showFooter)
.catch(console.error);