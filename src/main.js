fetch('../out/main.wasm').then(response =>
  response.arrayBuffer()
).then(bytes => WebAssembly.instantiate(bytes)).then(results => {
  instance = results.instance;
  //
let memory = instance.exports.memory;
const squareEach= instance.exports.squareEach;

const d= document.createElement('div')
document.body.appendChild(d)
d.textContent = (memory.buffer.byteLength); // 1 page.
const wid = 384;
const hgt = 216;
const channels = 4;
const PAGE = 65536;
const limit= wid*hgt*channels;
const pageSize = Math.ceil(limit/PAGE)
console.log(pageSize)
memory.grow(pageSize);
console.log('len',memory.buffer.byteLength); // 11 pages.
const p = 16;
const pArray = new Uint8Array(memory.buffer, p, limit);
  //
  document.getElementById("container").textContent = instance.exports.main();
  //
  let canvas = document.createElement("canvas");
  document.body.appendChild(canvas)
canvas.width = wid;
canvas.height = hgt;
let ctx = canvas.getContext("2d");
  //
const image = new Image();
image.addEventListener("load", () => {

  ctx.drawImage(image, 0, 0);
  const imageData = ctx.getImageData(0, 0, wid, hgt);
  const array = imageData.data;
  console.log(array.length, pArray.length);
  for (let i = 0; i < array.length; ++i) {
    pArray[i] = array[i];
  }
console.log(p,limit)
squareEach(p, limit);
})

image.crossOrigin = "Anonymous";
image.src = "https://i.imgur.com/gC1cnlu.jpg";
  //
}).catch(console.error);
