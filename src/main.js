// WebAssembly
fetch("../out/main.wasm").then(function(response) {
  // バイナリ
  return response.arrayBuffer();
}).then(function(bytes) {
  // コンパイル    
  return WebAssembly.compile(bytes);
}).then(function(module) {
  // インスタンス化    
  return WebAssembly.instantiate(module);
}).then(function(instance) {
    
   // バッファ
   var buffer = instance.exports.memory.buffer;
       
   // C言語のgetAddress()で開始アドレスを取得する
   var offset = instance.exports.getAddress();
   
   var list =new Uint8Array(buffer, offset, 100);
   list[4] = 123;   
   list[5] = 1;
   list[6] = 2;
   list[7] = 3;
   
   // C言語のtest()を実行する
   var result =instance.exports.test();
  
   console.log(list);
   console.log(result)
   adocument.getElementById("container").innerHTML = result;
});
