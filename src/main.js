fetch('../out/main.wasm').then(response =>
  response.arrayBuffer()
).then(bytes => WebAssembly.instantiate(bytes)).then(results => {
  instance = results.instance;

  var add=instance.exports.add(7,6);
  var sub=instance.exports.sub(7,6);
  var mul=instance.exports.mul(7,6);
  var div=instance.exports.div(42,6);

  console.log(add);
  console.log(sub);
  console.log(div);
  console.log(mul);


}).catch(console.error);
