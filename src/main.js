let begin;
fetch('../out/main.wasm').then(response =>
  response.arrayBuffer()
).then(bytes => {
  begin = Date.now();
  return WebAssembly.instantiate(bytes);
}).then(results => {
  instance = results.instance;
  document.getElementById("container").textContent = instance.exports.main();
  document.getElementById("container").textContent += ' ' + (Date.now() - begin);

  begin = Date.now()
  let j = 0;
  for(let i=0;i<1;i++) {
    j++;
  }
  document.getElementById("container").textContent += ' ' + j + ' ' + (Date.now() - begin);

}).catch(console.error);
