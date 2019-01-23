
var importObj = {
  js: {
    import1: () => console.log('this is my first try'),
    import2: () => console.log('this is my second try')
  }
}


fetch('../out/main.wasm').then(response =>
  response.arrayBuffer()
).then(bytes => WebAssembly.instantiate(bytes, importObj))
 .then(results => {
    instance = results.instance;
    // document.getElementById("container").textContent = instance.exports.main();
    var container = document.getElementById('container');
    var add = instance.exports.add;
    var square = instance.exports.square;
    // console.log(111, instance.exports)
    console.log(222, square && square(5) || 'none')
    if (add && square) {
      container.textContent = add(10,1) + square(5)
    }
  }).catch(console.error);
