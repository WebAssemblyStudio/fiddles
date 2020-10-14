fetch('../out/main.wasm').then(response =>
  response.arrayBuffer()
).then(bytes => WebAssembly.instantiate(bytes, {
  env: {
    getCanvasWidth: function() { return canvas.width; },
    getCanvasHeight: function() { return canvas.height; },
    jsSetInterval: function(callback, interval) {
      setInterval(function() {
        wasmInstance.exports.runCallback(callback);
      },interval);
    },
    jsFillRect: function(x,y,w,h) {
      ctx.fillRect(x,y,w,h);
    },
    jsClearRect: function(x,y,w,h) {
      ctx.clearRect(x,y,w,h);
    }
  }
})).then(results => {
  instance = results.instance;
  instance.exports.main();
}).catch(console.error);
