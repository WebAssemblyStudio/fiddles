WebAssembly.instantiateStreaming(fetch('../out/main.wasm'))
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
  let array = new Uint8ClampedArray(
    instance.exports.memory.buffer,
    instance.exports.get_image(),
    size*size*4,
  );
  let imageData = new ImageData(array, size, size);

  // on fait calculer l'image par le code WASM
  // NB: les changements effectués par fill_image() dans le tableau IMAGE du C
  // sont immédiatement visible dans l'objet imageData du JS
  instance.exports.fill_image();

  // on dessine l'image dans le canvas
  ctx.putImageData(imageData, 0, 0);

  //});
}).catch(console.error);

