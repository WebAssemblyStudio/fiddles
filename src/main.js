let x = '../out/main.wasm';



fetch(x).then(response =>
  response.arrayBuffer()
).then(bytes =>
  WebAssembly.instantiate(bytes)
).then(results => {
  instance = results.instance;
  const add = instance.exports.add//取出c里面的方法
            const square = instance.exports.square//取出c里面的方法
            console.log('10 + 20 =', add(10, 20))
            console.log('3*3 =', square(3))
            console.log('(2 + 5)*2 =', square(add(2 + 5)))
  document.getElementById("container").textContent = instance.exports.main();
}).catch(console.error);
