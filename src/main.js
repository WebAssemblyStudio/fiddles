const { greet, init_img } = wasm_bindgen;

function runApp() {
  console.log("runApp");
  let size = 256;
  let data = new Uint8ClampedArray(size*size*4);
  let imgData = new ImageData(data, size, size);
  /*
  init_img(imgData);
  */

  let c = document.querySelector("canvas");
  c.width = c.height = size;
  let ctx = c.getContext("2d");
  ctx.putImageData(imageData, 0, 0);
}

// Load and instantiate the wasm file, and we specify the source of the wasm
// file here. Once the returned promise is resolved we're ready to go and
// use our imports.
wasm_bindgen('../out/main_bg.wasm').then(runApp).catch(console.error);
