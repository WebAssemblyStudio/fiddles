fetch('../out/main.wasm').then(response =>
  response.arrayBuffer()
).then(bytes => WebAssembly.instantiate(bytes)).then(results => {
  instance = results.instance;
  const stack = new Float64Array(
        instance.exports.memory.buffer,
        instance.exports.stkptr(),
        1024
    );

  instance.exports.push(432);
  instance.exports.push(589);
  instance.exports.add();
  instance.exports.push(111);
  instance.exports.sub();
  document.getElementById("container").textContent = stack;
}).catch(console.error);

