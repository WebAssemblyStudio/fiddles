var getArray = function(instance, size) {
    return new Uint8ClampedArray( // tableau d'octets entre 0 et 255
        instance.exports.memory.buffer,  // le ArrayBuffer partagé par le module WASM
        instance.exports.get_image(),    // l'offset de IMAGE dans 'memory'
        size*size*4,                     // le nombre d'octets dans cette image
    );
}

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
        let array = getArray(instance, size)
        let imageData = new ImageData(array, size, size);

        // on fait calculer l'image par le code WASM
        // NB: les changements effectués par fill_image() dans le tableau IMAGE du C
        // sont immédiatement visible dans l'objet imageData du JS
        instance.exports.fill_image();

        // on dessine l'image dans le canvas, à la position (0,0)
        ctx.putImageData(imageData, 0, 0);

        var step = 22000;
        var current_step = 0;
        var speed = 0;

        for(current_step = 0; current_step < step; current_step++) {
                instance.exports.next_step();
                let imageData = new ImageData(getArray(instance, size), size, size);
                ctx.putImageData(imageData, 0, 0);
                current_step++;
                document.getElementById("stepVal").textContent = current_step;
        }

          //});
    }).catch(console.error);

