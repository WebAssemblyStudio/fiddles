const { greet, drawFrame } = wasm_bindgen;

const canvas = document.getElementById('screen');
const context = canvas.getContext('2d');

function fake(msg) {
  console.log(msg);
}

function runApp() {
  /*
  let pixeldata = new Uint8ClampedArray(128*128*4);
  for (let i = 0; i < pixeldata.length; i += 4) {
    pixeldata[i + 0] = 0;    // R value
    pixeldata[i + 1] = 190;  // G value
    pixeldata[i + 2] = 0;    // B value
    pixeldata[i + 3] = 255;  // A value
  }

  createImageBitmap(new ImageData(pixeldata, 128,128)).then((imageBitmap) => {
    context.drawImage(imageBitmap, 0, 0);
    greet('World');
  });
  */
  drawFrame();
}

function updateFrame(arr) {
  let pixeldata = new Uint8ClampedArray(arr);

  createImageBitmap(new ImageData(pixeldata, 128,128)).then((imageBitmap) => {
    context.drawImage(imageBitmap, 0, 0);
  });
}

// Load and instantiate the wasm file, and we specify the source of the wasm
// file here. Once the returned promise is resolved we're ready to go and
// use our imports.
wasm_bindgen('../out/main_bg.wasm').then(runApp).catch(console.error);
