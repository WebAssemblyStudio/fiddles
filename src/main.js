fetch('../out/main.wasm').then(response =>
  response.arrayBuffer()
).then(bytes => WebAssembly.instantiate(bytes)).then(results => {
  instance = results.instance;

  const {long2tilex, lat2tiley} = instance.exports;

  const sub = 'a';
  const z = 15;
  const x = long2tilex(35.1190898, z);
  const y = lat2tiley(47.8478448, z);
  const url = `https://${sub}.tile.openstreetmap.org/${z}/${x}/${y}.png`
  
  const canvas = document.getElementById("container");
  const ctx = canvas.getContext('2d');

  var image = new Image();
  image.onload = function() {
    canvas.width = this.width * 3;
    canvas.height = this.height * 2;

    for (let i = 0; i < 3; i++) {
      for (let j = 0; j < 2; j++) {
        ctx.drawImage(this, i*this.width, j*this.height);
      }
    }
  };

  image.src = url;

}).catch(console.error);
