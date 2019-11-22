
const width = 100;
const height = 100;

WebAssembly.instantiateStreaming(fetch('../out/main.wasm')).then(results => {
  instance = results.instance;
  document.getElementById("container").textContent = instance.exports.main();

  memory = instance.exports.memory;

  const ctx = document.getElementById('screen').getContext('2d');
  const pointer = instance.exports.render();
  const data = new Uint8ClampedArray(memory.buffer, pointer, width * height * 4);
  const img = new ImageData(data, width, height);
  ctx.putImageData(img, 0, 0);

}).catch(console.error);
