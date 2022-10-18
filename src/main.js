let x = '../out/main.wasm';

// wasm関数のインポート設定
var importObject = { 
  wasi_snapshot_preview1: { proc_exit: arg => console.log(arg) } 
};

document.getElementById('add_num').addEventListener('click', () => {
  WebAssembly.instantiateStreaming(
    fetch(x), importObject
  ).then(obj => 
    document.getElementById("output").value = parseInt(document.getElementById("output").value) * 2);    
  }, false
);  