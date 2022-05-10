var c = document.querySelector("canvas");
var ctx = c.getContext('2d');

WebAssembly.instantiateStreaming(
  fetch('../out/main.wasm'),
  {},
)
.then((result) => {
  let {memory, get_size, get_offset, fill, colorBlack, colorWhite} = result.instance.exports;
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
  drawImage();
  for (let x=0; x<size; x++) {
    for (let y=0; y<size; y++) {
      colorBlack(x, y);
    }
  }
  setTimeout(drawImage, 2000);
})
.catch((err) => {
  console.log("Error" + err);
});

function drawImage() {
  ctx.putImageData(imageData, 0, 0);
}
