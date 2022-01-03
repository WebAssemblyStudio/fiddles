const wasm = await fetch('../out/main.wasm')
const { instance } = await WebAssembly.instantiate(await wasm.arrayBuffer())
const { _update, memory } = instance.exports

const canvas = document.getElementById('canvas')
const ctx = canvas.getContext('2d')

let last = null
const update = timestamp => {
  const deltatime = timestamp - (last ?? timestamp)

  const { width, height } = canvas
  const length = width * height
  const buf = new Uint8ClampedArray(memory.buffer, 0, length * 4)
  const img = ctx.createImageData(width, height)
  _update(buf.byteOffset, width, height, deltatime)
  img.data.set(buf)
  ctx.putImageData(img, 0, 0);

  console.log(deltatime)
  console.log(buf)
  console.log(img)

  last = timestamp
  //requestAnimationFrame(update)
}

requestAnimationFrame(update)