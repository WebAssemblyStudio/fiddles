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
  let ctx = cvs.getContext("2d");

  (function update(){

    instance.exports.update();

    ctx.putImageData(data, 0, 0);

    requestAnimationFrame(update);
  })();

}).catch(console.error);
