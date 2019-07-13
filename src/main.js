const byteColorDepth = 4,
      sbOffset = 0,
      width = 100, 
      height = 100;

fetch('../out/main.wasm').then(response =>
  response.arrayBuffer()
).then(bytes => WebAssembly.instantiate(bytes)).then(results => {
  var instance = results.instance,
      module = instance.exports,
      imageDataArray = new Uint8ClampedArray(module.screenbuf.buffer, sbOffset, width*height*byteColorDepth);
  
  var canvas = document.getElementById("screen");
  canvas.height = height;
  canvas.width = width; 
  var ctx = canvas.getContext('2d');
  var img = new ImageData(imageDataArray, width, height);

  
  res = module.main();
  
  ctx.putImageData(img, 0, 0);
  
  // Debug
  console.log(width*height*byteColorDepth);
  console.log(imageDataArray);
  console.log(ctx);
  console.log(res);

  document.getElementById("container").textContent = module.add(1,1);
}).catch(console.error);

