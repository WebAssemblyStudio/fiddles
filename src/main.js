var libWasm = null;
(async () => {
  const fetchPromise = fetch('../out/add.wasm');
  const obj = await WebAssembly.instantiateStreaming(fetchPromise);
  libWasm = obj.instance.exports;
  const result = libWasm.add(1,6);
  console.log(`result: ${result}`);
})();

function onAdd() {
  var a = document.getElementById('num1').value;
  var b = document.getElementById('num2').value;
  document.getElementById("container").textContent = libWasm.add(a,b);
}