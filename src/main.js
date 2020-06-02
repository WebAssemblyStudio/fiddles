let instance;
let ctx;
let imageData;
let array;

WebAssembly.instantiateStreaming(fetch('../out/main.wasm'))
.then(results => {
  instance = results.instance;

  // on récupère la balise Canvas du HTML,
  // et son contexte 2d qui nous permet de dessiner dedans.
  
  let canvas = document.querySelector('canvas');
  let size = instance.exports.get_size();
  canvas.height = size;
  canvas.width = size;
  ctx = canvas.getContext("2d");

  // on fabrique l'objet ImageData qui nous donnera accès au tableau IMAGE du C
  array = new Uint8ClampedArray( // tableau d'octets entre 0 et 255
    instance.exports.memory.buffer,  // le ArrayBuffer partagé par le module WASM
    instance.exports.get_image(),    // l'offset de IMAGE dans 'memory'
    size*size*4,                     // le nombre d'octets dans cette image
  );
  imageData = new ImageData(array, size, size);

  // on fait calculer l'image par le code WASM
  // NB: les changements effectués par fill_image() dans le tableau IMAGE du C
  // sont immédiatement visible dans l'objet imageData du JS
  instance.exports.fill_image();

  // on dessine l'image dans le canvas, à la position (0,0)
  ctx.putImageData(imageData, 0, 0);

    instance.exports.iteration();
    ctx.putImageData(imageData, 0, 0);

  //});
}).catch(console.error);



setInterval(function(){  
    instance.exports.iteration();
    ctx.putImageData(imageData, 0, 0);
}, 1);