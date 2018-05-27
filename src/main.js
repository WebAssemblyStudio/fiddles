// Note that for webassembly.studio we're using the CLI's `--no-modules` option
// which may not be what you're using locally (aka using ES modules/Webpack).
// Since we're using `--no-modules` the `wasm_bindgen` global is initialized 
// to the exports of our module, and then below initialization is slightly
// different.
//
// When using wasm-bindgen locally and a different bundler like Webpack (or 
// a different option like `--nodejs`) these integration points will be
// tweaked slightly, and you can consult https://github.com/rustwasm/wasm-bindgen
// for more information.

window.jslogger = function (msg) {
  console.log(msg);
}

const { hello, Cat } = wasm_bindgen;

function runApp() {
  // #1 - a simple use of rust function - returned string is appended to body
  const html = hello('hello', 21);
  document.body.innerHTML = html;

  // #2 - an example of rust struct available as a JS class
  const c = Cat.new('Kot', 5);
  console.log(c.describe());
}

// Load and instantiate the wasm file, and we specify the source of the wasm
// file here. Once the returned promise is resolved we're ready to go and
// use our imports.
wasm_bindgen('../out/main_bg.wasm').then(runApp);
