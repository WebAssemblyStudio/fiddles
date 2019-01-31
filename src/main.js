// const memory = new WebAssembly.Memory({initial:10, maximum:100})

fetch('../out/main.wasm').then(response =>
  response.arrayBuffer()
).then(bytes => WebAssembly.instantiate(bytes)).then( async ({ module, instance }) => {

  const wasmInstance = new WebAssembly.Instance(module, {
    env: {
      consoleLog(offset, len) {
        const strBuf = new Uint8Array(wasmInstance.exports.memory.buffer, offset, len)
        console.log(strBuf)
      }
    }
  })

  const { memory, quickSort, rgb2gray } = instance.exports

  const inputArray = [12, 13, 8, 3, 29, 85]
  const i32 = new Int32Array(memory.buffer)
  i32.set(inputArray, 0)

  // console.log(memory.buffer)
  // console.log(i32)
  // console.log(inputArray.length * Int32Array.BYTES_PER_ELEMENT)

  // quickSort(0, inputArray.length - 1)
  quickSort(-3, inputArray.length + (-3) - 1)
  const resultArr = new Int32Array(memory.buffer, 0, inputArray.length)

  document.getElementById("container").textContent = resultArr

  const image = await loadImage('http://1.bp.blogspot.com/_RQoVsM1fUOA/TVFNiC8J6II/AAAAAAAAAAg/Swn7Eu3MlGw/w1200-h630-p-k-no-nu/mario.png');
  memory.grow(100)
  console.log(image.data.length)
  new Int32Array(memory.buffer).set(image.data)

  rgb2gray(-3, image.data.length - 4)
  const result = new Int32Array(memory.buffer, 0, image.data.length)
  console.log(result.length)

  const canvas = document.createElement('canvas')
  const ctx = canvas.getContext('2d')
  const imageData = ctx.createImageData(image.width, image.height);
  imageData.data.set(result)
  ctx.putImageData(imageData, 0, 0)
  document.getElementById("container").appendChild(canvas)
}).catch(console.error)

async function loadImage(src) {
  // Load image
  const img = document.createElement('img')
  img.src = src
  await new Promise(resolve => img.onload = resolve)
  // Make canvas same size as image
  const canvas = document.createElement('canvas');
  [canvas.width, canvas.height] = [img.width, img.height]
  // Draw image onto canvas
  const ctx = canvas.getContext('2d')
  ctx.drawImage(img, 0, 0)
  return ctx.getImageData(0, 0, img.width, img.height)
}
