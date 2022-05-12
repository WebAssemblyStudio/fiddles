var c = document.querySelector("canvas");
var ctx = c.getContext('2d');

let stop = 1
function a () {
WebAssembly.instantiateStreaming(
  fetch('../out/main.wasm'),
  {},
)
.then((result) => {
  let {memory, get_size, get_offset, fill, go} = result.instance.exports;
  let size = get_size();
  c.width = size;
  c.height = size;
  let array = new Uint8ClampedArray(
    memory.buffer,
    get_offset(),
    size*size*4,
  );
  go(stop)
  imageData = new ImageData(array, size, size);
  fill();
  console.log(stop);
  ctx.putImageData(imageData, 0, 0);


stop++
if(stop !== 100){
  setTimeout(a(), 1000);
}
  
})
.catch((err) => {
  console.log("Error" + err);
});
} 


  a()



