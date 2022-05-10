var c = document.querySelector("canvas");
var ctx = c.getContext('2d');

fetch('../out/main.wasm').then(response =>
  response.arrayBuffer()
).then(bytes => WebAssembly.instantiate(bytes)).then(results => {
  let {memory, get_size, get_offset, initialize, move} = results.instance.exports;
  let size = get_size();
  c.width = size;
  c.height = size;
  let array = new Uint8ClampedArray(
    memory.buffer,
    get_offset(),
    size*size*4,
  );
  initialize();

  for(let i=0;i<15000;i++){
    imageData = new ImageData(array, size, size);
    move();
    ctx.putImageData(imageData, 0, 0);
  }
  

  



  //document.getElementById("container").textContent = instance.exports.main();
}).catch(console.error);
