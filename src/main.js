var c = document.querySelector("canvas");
var ctx = c.getContext('2d');
let interv;
let step = 0;

WebAssembly.instantiateStreaming(
  fetch('../out/main.wasm'),
  {},
)
.then((result) => {
  let {memory, get_size, get_offset, fill, avancer, getXPos, getYPos, getDirection} = result.instance.exports;
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
  interv = setInterval(() => {
    avancer();
    drawImage();
    console.log(getXPos(), getYPos(), getDirection());
    step += step + 1;
    console.log(step);
  }, 50);
})
.catch((err) => {
  console.log("Error" + err);
});

function drawImage() {
  ctx.putImageData(imageData, 0, 0);
}


function stop() {
  clearInterval(interv);
}