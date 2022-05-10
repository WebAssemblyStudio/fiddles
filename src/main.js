var c = document.querySelector("canvas");
var ctx = c.getContext('2d');

const timer = ms => new Promise(res => setTimeout(res, ms))

WebAssembly.instantiateStreaming(
  fetch('../out/main.wasm'),
  {},
)
.then((result) => {
  let {memory, get_size, get_offset, fill,move_ant} = result.instance.exports;
  let size = get_size();
  c.width = size;
  c.height = size;
  

  function draw() {
    let array = new Uint8ClampedArray(
      memory.buffer,
      get_offset(),
      size*size*4,
    );
    imageData = new ImageData(array, size, size);
    ctx.putImageData(imageData, 0, 0);
  }
  fill();

  async function startAnt() {
    let iteration = 0;
    while (true) {
      console.log("itération", iteration++);
      move_ant();
      draw();
      await timer(1);
    }
  }

  draw();
  startAnt();
})
.catch((err) => {
  console.log("Error" + err);
});
