// WebAssembly.instantiateStreaming(fetch("../out/main.wasm"), {
//   main: {
//     sayHello(str) {
//       console.log(str);
//     }
//   },
//   // env: {
//   //   abort(_msg, _file, line, column) {
//   //     console.error("abort called at main.ts:" + line + ":" + column);
//   //   }
//   // },
// }).then(result => {
//   const exports = result.instance.exports;
//   document.getElementById("container").textContent = "Result: " + exports.add(19, 23);
// }).catch(console.error);

debugger;

// let getString;

loader.instantiate(fetch("../out/main.wasm").then(res => res.arrayBuffer()), {
  // main: {
  //   sayHello(strRef) {
  //     console.log(getString(strRef));
  //   }
  // },
  // env: {
  //   abort(_msg, _file, line, column) {
  //     console.error("abort called at main.ts:" + line + ":" + column);
  //   }
  // }
}).then(result => {
  const exports = result.instance.exports;
  // getString = exports.__getString;
  
  console.log(Object.keys(exports));
  const strRef = exports.test();
  console.log(strRef);
  console.log(exports.__getString(strRef));

  document.getElementById("container").textContent = "Result: " + exports.add(19, 23);
}).catch(console.error);