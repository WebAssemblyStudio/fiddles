fetch('../out/main.wasm').then(response =>
  response.arrayBuffer()
).then(bytes => WebAssembly.instantiate(bytes)).then(results => {
  instance = results.instance;
  
  let width = instance.exports.getScreenWidth();
  let height = instance.exports.getScreenHeight();

  let data = new ImageData(
    new Uint8ClampedArray(
      instance.exports.memory.buffer,
      instance.exports.SCREEN_BUFFER.value,
      4 * width * height
    ),
    height
  );

  let cvs = document.getElementById("cvs");
  cvs.width = width;
  cvs.height = height;
  let ctx = cvs.getContext("2d");

  document.addEventListener("mousemove", e => {
    instance.exports.onmousemove(e.layerX, e.layerY);
    x = e.layerX;
    y = e.layerY;
  });

  let lastSync = Date.now();

  let fpsSum = 0;
  let frames = 1;
  let fpsSync = 60;

  let x = 0;
  let y = 0;

  (function update(){
    // ctx.clearRect(0, 0, width, height);

    fpsSum += Date.now()-lastSync;
    lastSync = Date.now();

    instance.exports.update();

    ctx.putImageData(data, 0, 0);

    if(frames%60 == 0){
      fpsSync = fpsSum/60;
      fpsSum = 0;
    }

    // ctx.fillStyle = "black";
    // ctx.fillRect(x, y, 32, 32);

    ctx.fillStyle = "red";
    ctx.fillText(Math.floor(1000/fpsSync), 10, 10);

    frames++;

    requestAnimationFrame(update);
  })();

}).catch(console.error);
