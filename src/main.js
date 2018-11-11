const { hash_str } = wasm_bindgen;



let hash_p = document.getElementById('hash');
function show_hash(hash) {
  hash_p.innerHTML = hash;
}

let textareaID = document.getElementById('input');
textareaID.addEventListener('keyup', function(e) {
  hash_str(textareaID.value);
});

function runApp() {
    hash_str(textareaID.value);
}

// Load and instantiate the wasm file, and we specify the source of the wasm
// file here. Once the returned promise is resolved we're ready to go and
// use our imports.
wasm_bindgen('../out/main_bg.wasm').then(runApp).catch(console.error);
