var c = document.querySelector("canvas");
var ctx = c.getContext('2d');

WebAssembly.instantiateStreaming(
  fetch('../out/main.wasm'),
  {},
)
.then((result) => {
  let {memory, get_size, get_offset, init, progress} = result.instance.exports;
  let size = get_size();
  c.width = size;
  c.height = size;
  let array = new Uint8ClampedArray(
    memory.buffer,
    get_offset(),
    size*size*4,
  );
  imageData = new ImageData(array, size, size);
  init();
  const interval = setInterval(() => {
    console.log("interval called");
    progress();
    ctx.putImageData(imageData, 0, 0);
  },100)
  
})
.catch((err) => {
  console.log("Error" + err);
});
