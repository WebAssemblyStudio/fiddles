fetch('../out/main.wasm').then(response =>
  response.arrayBuffer()
).then(bytes => WebAssembly.instantiate(bytes)).then(results => {
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

  instance.exports.init();

  setInterval(function(){
    instance.exports.simulation();
    instance.exports.fill_image();
    ctx.putImageData(imageData, 0, 0);
    document.getElementById("iteration").textContent = instance.exports.get_nbIte();
  }, 1); 

}).catch(console.error);
