fetch('../out/main.wasm').then(response =>
  response.arrayBuffer()
).then(bytes => WebAssembly.instantiate(bytes)).then(results => {
  instance = results.instance;

  var lastTime = new Date().getTime();
  var loop = () => { // SETUP
    requestAnimationFrame(loop); // LOOP

    // DELTA CALCULATION
    var thisTime = new Date().getTime();
    var delta = (thisTime - lastTime) / 100;
    lastTime = thisTime;

    var i = 0, run = true;
    while (run) {
      var out = instance.exports.loop(delta, i);

      if (out == 1) run = false;
      i++;
    }
  };

  loop(); // START
}).catch(console.error);
