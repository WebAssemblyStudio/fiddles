fetch('../out/main.wasm').then(response =>
  response.arrayBuffer()
).then(bytes => WebAssembly.instantiate(bytes)).then(({module, instance}) => {
  document.getElementById("canvas").textContent = instance.exports.add(1,1);
  const ctx = canvas.getContext("2d");
  const imageData = ctx.createImageData(canvas.width, canvas.height);
  const mem = instance.exports.memory;

  for (let x = 0; x < canvas.width; x++) {
    for (let y = 0; y < canvas.height; y++) {
      const i = (x + y * canvas.width) * 4;
      imageData.data[i] = mem[i];
      imageData.data[i + 1] = mem[i];
      imageData.data[i + 2] = mem[i];
      imageData.data[i + 3] = 255;
    }
  }
  
  ctx.putImageData(imageData, 0, 0);
}).catch(console.error);

