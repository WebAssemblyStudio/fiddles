var ctx = canvas.getContext('2d');
fetch('../out/main.wasm').then(response => {
  return response.arrayBuffer();
}).then(bytes => {
  var v = WebAssembly.instantiate(bytes,{
    env: {
      drawRect:function(x, y, x2, y2) { ctx.strokeRect(x, y, x2-x, y2-y); },
      drawPoint:function(x, y, col) { 
        ctx.fillStyle='red';
        ctx.fillRect(x-2, y-2, 5, 5);
        console.log('pt', x, y, col);
      },
      drawFix: function(x, y, x2, y2) {
        ctx.beginPath();
        ctx.setLineDash([2,2]);
        ctx.moveTo(x, y);
        ctx.lineTo(x2, y2);
        ctx.stroke();
        ctx.setLineDash([]);
      },
      drawRay:function(x, y, x2, y2) { 
        var dx = x2-x, dy = y2-y;
        var sc = Math.hypot(dx, dy) / 5;
        dx /= sc;
        dy /= sc;
        var nx = -dy, ny = dx;
        ctx.beginPath();
        ctx.moveTo(x, y);
        ctx.lineTo(x2, y2);
        ctx.lineTo(x2 - dx + nx, y2 - dy + ny);
        ctx.moveTo(x2 - dx - nx, y2 - dy - ny);
        ctx.lineTo(x2, y2);
        ctx.stroke(); 
      },
    }
  });
  return v;
}).then(results => {
  ctx.clearRect(0, 0, canvas.width, canvas.height);
  results.instance.exports.main();
}).catch(console.error);
