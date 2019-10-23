fetch('../out/main.wasm').then(response =>
  response.arrayBuffer()
).then(bytes => WebAssembly.instantiate(bytes, {
  env: {
    native() {
    }
  }
})).then(results => {
  instance = results.instance;
  console.log('start');
  instance.exports.test(2147483647);
  console.log('end');
  document.getElementById('container').textContent = 'ok';
}).catch(console.error);

