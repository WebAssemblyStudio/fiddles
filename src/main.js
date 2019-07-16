const byteColorDepth = 4,
      sbOffset = 0,
      width = 200, 
      height = 200;

const global = new WebAssembly.Global({value: "i32", mutable: false}, 111);

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

  
  var res = delay = segtimer = 0;
  var seg = 2;
  var start = null;

  // res = module.main();

  function step(timestamp) {
    if (!start) start = timestamp;
    var progress = timestamp - start;

    if (segtimer+5000 < progress) { seg++; if (seg > 5) seg = 3; segtimer = progress; }

    if(delay+150 < progress){
      res = module.main(seg);
      ctx.putImageData(img, 0, 0);
      delay = progress;
    }

    if (progress < 20000) {
      window.requestAnimationFrame(step);
    }
  }

  window.requestAnimationFrame(step);

  
  // Debug
  // console.log(width*height*byteColorDepth);
  // console.log(imageDataArray);
  // console.log(ctx);
  // console.log(res);
  // console.log(global.value);

  document.getElementById("container").textContent = module.add(1,1);
}).catch(console.error);

