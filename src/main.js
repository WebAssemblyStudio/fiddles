const canvas = document.getElementById("canvas");
const ctx = canvas.getContext("2d");

fetch('../out/main.wasm').then(response =>
  response.arrayBuffer()
).then(bytes => WebAssembly.instantiate(bytes, {
  context: {
    fillRect: (x, y, width, height) => {
      ctx.fillRect(x, y, width, height);
    }
  }
})).then(results => {
  const game = results.instance.exports;

  var level = 0
  setInterval( () => {
    ctx.fillStyle = "#ddd"; ctx.fillRect(0,0,180,180);
    
    ctx.fillStyle = "black";
    game.draw(0,0,180, level)

    level = (level + 1) % 4
  }, 1000)
});