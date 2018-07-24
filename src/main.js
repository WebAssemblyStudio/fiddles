const ctx = document.querySelector('canvas').getContext('2d');
var importObject = { 
  env: {
    consoleLog: console.log,
    ctxClearRect: ctx.clearRect.bind(ctx),
    ctxBeginPath: ctx.beginPath.bind(ctx),
    ctxMoveTo: ctx.lineTo.bind(ctx),
    ctxLineTo: ctx.lineTo.bind(ctx),
    ctxStroke: ctx.stroke.bind(ctx),	
  }
};

fetch('../out/main.wasm').then(response =>
  response.arrayBuffer()
).then(bytes => WebAssembly.instantiate(bytes, importObject)).then(results => {
  instance = results.instance;  
  instance.exports.main();
  console.log(JSON.stringify(instance.exports));
  instance.exports._Z6updatei(0); 
  var f = function(timestamp){
    instance.exports._Z6updatei(timestamp);  
    requestAnimationFrame(f);
  };
  requestAnimationFrame(f);  
}).catch(console.error);
