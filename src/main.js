const { decode, kind_of } = wasm_bindgen;

function runApp() {
  const text = new TextEncoder().encode("world")
  const input = new Uint8Array(1 + text.byteLength)
  input.set([4], 0)
  input.set(text, 1)
  console.log('>>', input[0], kind_of(input))


  const view = decode(input);
  console.log('<<', view.kind(), view.as_string())
  return { view, kind: view.kind() }
}

// Load and instantiate the wasm file, and we specify the source of the wasm
// file here. Once the returned promise is resolved we're ready to go and
// use our imports.
wasm_bindgen('../out/main_bg.wasm').then(runApp).then(console.log, console.error);
