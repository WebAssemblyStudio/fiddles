let intance

fetch('../out/main.wasm')
.then(response => response.arrayBuffer())
.then(buffer => WebAssembly.instantiate(buffer, {
    env: {
      env_random: Math.random,
    }
  })
)
.then(results => {
  instance = results.instance

  const canvas = document.getElementById('display')
  const height = canvas.height = Math.floor(canvas.clientHeight / 4)
  const width = canvas.width = Math.floor(canvas.clientWidth / 4)
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

function config(config) {
  const {
    count = 1024,
    radius = 32,
    repel = 120/10000,
    align = 120/10000,
    attract = 60/10000,
    lower_threshold = 20/100,
    higher_threshold = 75/100,
    max_vel = 300/100,
    min_vel = 2/100,
    center_pull = 1/10000,
    max_distance = 32,
  } = config

  instance.exports.config(
    count,
    radius,
    repel,
    align,
    attract,
    lower_threshold,
    higher_threshold,
    max_vel,
    min_vel,
    center_pull,
    max_distance
  )
}