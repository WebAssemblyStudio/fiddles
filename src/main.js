const DIMENSIONS = 50;

const rand = () => Math.floor(Math.random() * DIMENSIONS);

fetch('../out/main.wasm').then(response =>
  response.arrayBuffer()
).then(bytes => WebAssembly.instantiate(bytes, {
  console: {
    log: (x, y) => console.log(x, y)
  }
})).then(results => {
  const game = results.instance.exports;

  console.log(results);

  for (let i = 0; i < 400; i++) {
    game.setCell(rand(), rand(), 1);
  }

  const canvas = document.getElementById("canvas");
  const ctx = canvas.getContext("2d");

  const render = () => {
    ctx.fillStyle = "black";
    ctx.fillRect(0, 0, DIMENSIONS, DIMENSIONS);

    ctx.fillStyle = "green";
    for (let y = 0; y < DIMENSIONS; y++) {
      for (let x = 0; x < DIMENSIONS; x++) {
        if (game.getCell(x, y) > 0) {
          ctx.fillRect(x, y, 1, 1);
        }
      }
    }
  };

  setInterval(() => {
    game.tick();
    render();
  }, 100);

});
