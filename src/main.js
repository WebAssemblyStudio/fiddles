var time = performance.now();
let wasm_obj = undefined;
fetch('../out/main.wasm').then(response =>
  response.arrayBuffer()
).then(bytes => WebAssembly.instantiate(bytes)).then(results => {
  wasm_obj = results.instance;
  //document.getElementById("container").textContent = wasm_obj.exports.main(12385);
  //document.getElementById("container2").textContent = wasm_obj.exports.test(668);
  let res = wasm_obj.exports.substract(7, 3);
  document.getElementById("container").textContent = res;
}).catch(console.error);


let timeW = performance.now() - time;
console.log('Время выполнения WASM = ', timeW);

//------------------------------------------------------
/*
time = performance.now();
let n = 0;
for(let i=0; i < 20000; i++) {
  n = n + i * 3.1415926535 / 12385 * 3.1415926535;
}

let timeJS = performance.now() - time;
console.log('Время выполнения JS = ', timeJS);
console.log("n=", n);

console.log(timeJS/timeW, "раз");*/