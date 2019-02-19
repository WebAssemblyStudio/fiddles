let intance

fetch('../out/main.wasm')
.then(response => WebAssembly.instantiateStreaming(response, {
    env: {
      env_random: Math.random,
    }
  })
)
.then(results => {
  instance = results.instance

  const canvas = document.getElementById('display')
  const height = canvas.height = canvas.clientHeight
  const width = canvas.width = canvas.clientWidth
  const ctx = canvas.getContext('2d')
  
  const byteSize = width * height * 4;
  const pointer = instance.exports.init(width, height)
  const data = new Uint8ClampedArray(instance.exports.memory.buffer, pointer, byteSize)
  const img = new ImageData(data, width, height)

  const loop = timestamp => {
    instance.exports.update(timestamp);
    data.fill(0, 0, byteSize);
    instance.exports.draw(width, height);
    ctx.putImageData(img, 0, 0);
    window.requestAnimationFrame(loop);
  };

  window.requestAnimationFrame(loop);
})
.catch(e => console.error(e));