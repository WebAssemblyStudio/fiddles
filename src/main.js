var canvas = document.getElementById("canvas");
var context = canvas.getContext("2d");

const HEIGHT = 32;

WebAssembly.instantiateStreaming(fetch("../out/main.wasm"), {
  main: {
    pixel(i, color) {
      var red = color >> 16 & 0xFF,
        green = color >> 8  & 0xFF,
        blue = color & 0xFF;
      

      context.fillStyle = "rgb(" + red + "," + green + "," + blue + ")";

      var y = i % HEIGHT,
        x = i - y;
      context.fillRect(x << 2, y << 4, 4, 4);
    }
  },
  env: {
    abort(message, filename, line, column) {
      console.error("Abort in " + filename + " (" + line + ":" + column + "): " + message);
    }
  },
}).then(result => {
  const exports = result.instance.exports;

  window.addEentListener("keydown", (event) => {
    if (     event.key == "ArrowLeft"  || event.key == "A")
      exports.key(0, true);
    else if (event.key == "ArrowUp"    || event.key == "W")
      exports.key(1, true);
    else if (event.key == "ArrowRight" || event.key == "D")
      exports.key(2, true);
    else if (event.key == "ArrowDown"  || event.key == "S")
      exports.key(3, true);
  });

  window.addEentListener("keyup", (event) => {
    if (     event.key == "ArrowLeft"  || event.key == "A")
      exports.key(0, false);
    else if (event.key == "ArrowUp"    || event.key == "W")
      exports.key(1, false);
    else if (event.key == "ArrowRight" || event.key == "D")
      exports.key(2, false);
    else if (event.key == "ArrowDown"  || event.key == "S")
      exports.key(3, false);
  });

  function draw() {
    exports.draw();

    requestAnimationFrame(draw);
  }

  setInterval(exports.update, 250);
  requestAnimationFrame(draw);
}).catch(console.error);
