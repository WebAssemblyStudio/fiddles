fetch('../out/main.wasm').then(response =>
  response.arrayBuffer()
).then(bytes => WebAssembly.instantiate(bytes)).then(results => {
  instance = results.instance;
  
  var offset = instance.exports.getData();
  var linearMemory = new Float32Array(instance.exports.memory.buffer, offset, 2);
  

  function vec2add(xa, ya, xb, yb){
    return [
      xa + xb, 
      ya + yb
    ]
  }

  function vec2addWasm(xa, ya, xb, yb){
    instance.exports.vec2add(xa, ya, xb, yb);
    return [ linearMemory[0],  linearMemory[1] ];
  }


  console.time();
  console.log("Js");
  for(var i=0; i<10000000;i++){
    vec2add(Math.random(), Math.random(), Math.random(), Math.random());
  }
  console.timeEnd();

  console.time();
  console.log("Wasm");
  for(var i=0; i<10000000;i++){
    vec2addWasm(Math.random(), Math.random(), Math.random(), Math.random());
  }
  console.timeEnd();

}).catch(console.error);
