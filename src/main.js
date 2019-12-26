fetch('../out/main.wasm').then(response =>
  response.arrayBuffer()
).then(bytes => WebAssembly.instantiate(bytes)).then(({module, instance}) => {
  const canvas = document.getElementById("canvas");
  instance.exports.render();
  const ctx = canvas.getContext("2d");
  //const imageData = ctx.createImageData(canvas.width, canvas.height);
  const membuf = instance.exports.memory.buffer;
  const view = new DataView(membuf);
  console.log(`dimensions: (${canvas.width}, ${canvas.height})`);
  console.log(`max index: ${255 + 255 * canvas.width * 4}`);
  console.log(`length: ${view.byteLength}`);
  console.log(`first byte: ${view.getUint8(0)}`);

  const arr = new Uint8ClampedArray(65536 * 4);
  for (let x = 0; x < canvas.width; x++) {
    for (let y = 0; y < canvas.height; y++) {
      const i = (x + y * canvas.width) * 4;
      arr[i] = view.getUint8(i);
      arr[i + 1] = view.getUint8(i + 1);
      arr[i + 2] = view.getUint8(i + 2);
      arr[i + 3] = 255;
    }
  }

  const imageData = new ImageData(arr, canvas.width, canvas.height);
  ctx.putImageData(imageData, 0, 0);
}).catch(console.error);

