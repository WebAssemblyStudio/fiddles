//https://jsfiddle.net/mityok/7Lvbwucn/2/
//https://wasdk.github.io/WasmFiddle//?b60v4
//https://compile.fi/canvas-filled-three-ways-js-webassembly-and-webgl/

/*
    r: colorValue >> 16,
    g: (colorValue >> 8) & 255,
    b: colorValue & 255
*/

fetch('../out/main.wasm').then(response =>
  response.arrayBuffer()
).then(bytes => WebAssembly.instantiate(bytes)).then(results => {
  instance = results.instance;
  //
let memory = instance.exports.memory;
const squareEach= instance.exports.squareEach;
const imgs=[
  {w:2,h:2,src:'https://i.imgur.com/Km26JoT.png',scale:20},
  {w:3840,h:2160,src:'https://i.imgur.com/gC1cnlu.jpg',scale:0.2}
  ];
const d= document.createElement('div')
document.body.appendChild(d);
const img = imgs[1];
d.textContent = (memory.buffer.byteLength); // 1 page.
const wid = img.w;
const hgt = img.h;
const channels = 4;
const PAGE = 65536;
const limit= wid*hgt*channels;
const pageSize = Math.ceil(limit/PAGE)
console.log(pageSize)
memory.grow(pageSize);
console.log('len',memory.buffer); 
const p = pageSize;
const pArray = new Uint8ClampedArray(memory.buffer, p, limit);
let canvas = document.createElement("canvas");
canvas.setAttribute('style',`transform-origin:0 0;transform:scale(${img.scale})`)
document.body.appendChild(canvas);
canvas.width = wid;
canvas.height = hgt;
let ctx = canvas.getContext("2d");
const image = new Image();
image.addEventListener("load", () => {
  ctx.drawImage(image, 0, 0);
  const imageData = ctx.getImageData(0, 0, wid, hgt);
  const array = imageData.data;
  console.log(array.length, 'pArr length:',pArray.length,'p',p,'limit',limit);
  pArray.set(array, 0);
  console.time('t')
  squareEach(p, limit/4);
  array.set(pArray.slice(0, limit), 0);
  console.timeEnd('t');
	ctx.putImageData(imageData, 0, 0);
})
image.crossOrigin = "Anonymous";
image.src = img.src;
}).catch(console.error);
