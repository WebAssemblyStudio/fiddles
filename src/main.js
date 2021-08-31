const { greet } = wasm_bindgen;

function runApp() {

  const start = performance.now()
  var x = 0;
  let n = 3071*3072; // n = 17 × 5882353
  for (let i = 1; i< n ; i+=1){
    
    if(n % i === 0){
      x += i
    }
  }
  const end = performance.now()

  alert(`${end-start}ms ${x}`)


  const startWASM = performance.now()
  const u = greet('World');
  
  const endWASM = performance.now()

  alert(`${endWASM-startWASM}ms ${u}`)
}

// Load and instantiate the wasm file, and we specify the source of the wasm
// file here. Once the returned promise is resolved we're ready to go and
// use our imports.
wasm_bindgen('../out/main_bg.wasm').then(runApp).catch(console.error);
