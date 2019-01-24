
var importObj = {
  env: {
    import1: (a, b) => console.log('this is test'),
    import2: () => console.log('this is my second try')
  }
}


fetch('../out/main.wasm').then(response =>
  response.arrayBuffer()
).then(bytes => WebAssembly.instantiate(bytes, importObj))
 .then(results => {
    instance = results.instance;
    var container = document.getElementById('container');
    var box = document.getElementsByClassName('box')[0];
    var add = instance.exports.add;
    var square = instance.exports.square;
    if (add && square) {
      container.textContent = add(10,1) + square(5)
    }
  }).catch(console.error);
