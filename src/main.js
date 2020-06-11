WebAssembly.instantiateStreaming(fetch('../out/main.wasm'),
    {
    env: {
      console_log(x, y, col, dir) {
        console.log('x: ' + x + ' y: ' + y + ' col: ' + col + ' dir: ' + dir);
      }
    }
  })
.then(results => {
  let instance = results.instance;

  // on récupère la balise Canvas du HTML,
  // et son contexte 2d qui nous permet de dessiner dedans.
  let canvas = document.querySelector('canvas');
  let size = instance.exports.get_size();
  canvas.height = size;
  canvas.width = size;
  let ctx = canvas.getContext("2d");

  // on fabrique l'objet ImageData qui nous donnera accès au tableau IMAGE du C
  let array = new Uint8ClampedArray( // tableau d'octets entre 0 et 255
    instance.exports.memory.buffer,  // le ArrayBuffer partagé par le module WASM
    instance.exports.get_image(),    // l'offset de IMAGE dans 'memory'
    size*size*4,                     // le nombre d'octets dans cette image
  );
  let imageData = new ImageData(array, size, size);

  instance.exports.init_image();

  setInterval(function() {
    instance.exports.update_image();
    ctx.putImageData(imageData, 0, 0);
  }, 1);

  //});
}).catch(console.error);

