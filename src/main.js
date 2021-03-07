fetch('../out/main.wasm').then(response =>
  response.arrayBuffer()
).then(bytes => WebAssembly.instantiate(bytes, {
  'env' : {
    'printchar' : function (pointer) {
      document.getElementById("container").textContent += String.fromCharCode(pointer);
    }
  }
})).then(results => {
  instance = results.instance;
  //document.getElementById("container").textContent = instance.exports.main();
  instance.exports.main()
}).catch(console.error);
