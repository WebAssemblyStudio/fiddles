var c = document.querySelector("canvas");
var ctx = c.getContext('2d');

WebAssembly.instantiateStreaming(
  fetch('../out/main.wasm'),
  {},
)
.then((result) => {
  let {memory, get_size, get_offset, fill, updateAll} = result.instance.exports;
  let size = get_size();
  c.width = size;
  c.height = size;
  let array = new Uint8ClampedArray(
    memory.buffer,
    get_offset(),
    size*size*4,
  );
  imageData = new ImageData(array, size, size);
  fill();
  updateAll();
  ctx.putImageData(imageData, 0, 0);
})
.catch((err) => {
  console.log("Error" + err);
});
