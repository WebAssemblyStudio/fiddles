
async function getWasm() {
  const response = await fetch('../out/main.wasm');
  const arrayBuffer = await response.arrayBuffer();
  const prog = new Uint8Array(arrayBuffer);
  const results = await WebAssembly.instantiate(arrayBuffer);
  const instance = await results.instance;
  return [instance, prog];
}

getWasm().then((data)=>{
  document.getElementById("container").innerHTML = data[0].exports.logx(2.718281828) + '<hr>' + data[1];
})

