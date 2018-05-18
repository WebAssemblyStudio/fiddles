fetch('../out/main.wasm')
  .then(response => response.arrayBuffer())
  .then(bytes =>
    WebAssembly.instantiate(bytes, {
      func: {
        log: a => {
          alert(a);
        },
      },
    })
  )
  .then(results => {
    instance = results.instance;
    document.getElementById('container').innerText = instance.exports.add(
      42,
      58
    );
  });
