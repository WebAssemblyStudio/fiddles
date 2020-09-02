const {sum, subtraction, footer} = wasm_bindgen;

function runApp(){
  if(operation == 'sum'){
    document.getElementById('resultSum').value = 
    sum(
      document.getElementById("sumA").value, 
      document.getElementById("sumB").value
      )
  }


wasm_bindgen('../out/main_bg.wasm')
.then(showFooter)
.catch(console.error);