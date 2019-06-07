const { keyd, modl, cipher } = wasm_bindgen;

function runApp() {
  let p = 3557;
  let q = 2579;
  let e = 3;

  let n = modl(p,q);
  let d = keyd(p,q,e);

  alert("Open key = " + e + " " + n);
  alert("Close key = " + d + " " + n);

  cipher("test",e,n);
}

// Load and instantiate the wasm file, and we specify the source of the wasm
// file here. Once the returned promise is resolved we're ready to go and
// use our imports.
wasm_bindgen('../out/main_bg.wasm').then(runApp).catch(console.error);
