fetch('../out/main.wasm').then(response =>
  response.arrayBuffer()
).then(bytes => WebAssembly.instantiate(bytes)).then(results => {
  instance = results.instance;
  var ptr = allocate(intArrayFromString("玄魂"), 'i8', ALLOC_NORMAL);


  var retPtr = instance.exports.outName(ptr);

            var resValue = Pointer_stringify(retPtr);
            console.log(resValue);

            _free(ptr);

 // document.getElementById("container").textContent = instance.exports.outName("hahaha");
}).catch(console.error);
