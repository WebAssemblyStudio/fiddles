fetch('../out/main.wasm', {
  main: {
    print: function (value) {
      console.log(`Got ${value} from WebAssembly`);
    }
  },
}).then(response =>
  response.arrayBuffer()
).then(bytes => WebAssembly.instantiate(bytes)).then(results => {
  results.instance.exports._main();
}).catch(console.error);
