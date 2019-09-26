
class CanvasRenderer {
  constructor(height, width, scale) {
    this.canvas = document.getElementById("canvas");
    this.canvas.height = height * scale;
    this.canvas.width = width * scale;
    this.canvasContext = this.canvas.getContext('2d');
    this.scale = scale;
  }

  render(board) {
    var shadowCanvas = document.createElement('canvas');
    shadowCanvas.height = this.canvas.height;
    shadowCanvas.width = this.canvas.width;
    var offscreenContext = shadowCanvas.getContext('2d');
    offscreenContext.fillStyle = '#2a345f';
    offscreenContext.fillRect(0, 0, shadowCanvas.width, shadowCanvas.height);

    offscreenContext.fillStyle = 'white';
    for (let colIndex = 0; colIndex < board.length; colIndex++) {
      for (let rowIndex = 0; rowIndex < board.length; rowIndex++) {
        if (board[colIndex][rowIndex]) {
          offscreenContext.fillRect(colIndex * this.scale, rowIndex * this.scale, this.scale, this.scale);
        }
      }
    }

    this.canvasContext.drawImage(shadowCanvas, 0, 0);
  }
}

var renderer = new CanvasRenderer(100, 100, 5);

WebAssembly.instantiateStreaming(fetch("../out/main.wasm"), {
  main: {
    log(value) { console.log('as: ', value); },
    render(board) {
      renderer.render(board)
    }
  },
  env: {
    abort(_msg, _file, line, column) {
      console.error("abort called at main.ts:" + line + ":" + column);
    }
  },
}).then(result => {
  const exports = result.instance.exports;

  exports.gameOfLife(100, 100);
  // exports.tick();

}).catch(console.error);
