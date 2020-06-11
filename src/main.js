WebAssembly.instantiateStreaming(fetch('../out/main.wasm'))
.then(results => {
  let instance = results.instance;
  let etape = 0;

  //fonction d'initialisation
  instance.exports.init();

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

  // on fait calculer l'image par le code WASM
  // NB: les changements effectués par fill_image() dans le tableau IMAGE du C
  // sont immédiatement visible dans l'objet imageData du JS

  instance.exports.fill_image();

  let loop = instance.exports.loop;
  let x = instance.exports.get_x;
  let y = instance.exports.get_y;
  //loop();
  //setInterval(instance.exports.loop(), 3000);
  //window.requestAnimationFrame(loop());
  console.log("go !")
  let id = setInterval(function() {
    // la boucle de jeu
    loop();
    
    console.log("x: " + x(), " y: " + y());

    //debug du nombre d'étape
    document.getElementById("score").innerHTML = etape;
    etape++;

    //on dessine l'image dans le canvas, à la position (0,0)
    ctx.putImageData(imageData, 0, 0);
  }, 1);

  //fonction du boutton qui permet d'arreter la simulation
  document.getElementById("myBtn").addEventListener("click", () => {
    console.log("interval stoppé");
    console.log("la fourmie s'est déplacée: " + etape + " fois");
    clearInterval(id);
    document.getElementById("myBtn").disabled = true;
  });

  // on dessine l'image dans le canvas, à la position (0,0)
  //ctx.putImageData(imageData, 0, 0);

  //});
}).catch(console.error);

