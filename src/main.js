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
    radius = 64,
    repel = .00005,
    align = .005,
    attract = .005,
    lower_threshold = .2,
    higher_threshold = .6,
    center_pull = .00005,
    max_vel = 3,
    min_vel = .2,
    max_distance = 64,
  } = config

  instance.exports.config(
    radius,
    repel,
    align,
    attract,
    lower_threshold,
    higher_threshold,
    center_pull,
    max_vel,
    min_vel,
    max_distance
  )
}