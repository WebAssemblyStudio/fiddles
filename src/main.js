(async () => {
  const width = 640;
  const height = 360;
  
  const response = await fetch('../out/main.wasm');
  const bytes = await response.arrayBuffer();
  const result = await WebAssembly.instantiate(bytes);
  const { memory, getData } = result.instance.exports;
  // Get 2d drawing context
  const ctx = document.getElementById('canvas').getContext('2d');
  const pointer = getData(60);
  const data = new Uint8ClampedArray(memory.buffer, pointer, width * height * 4);
  const img = new ImageData(data, width, height);
  console.log(data.some(item => item != 0));
  ctx.putImageData(img, 0, 0);
})();