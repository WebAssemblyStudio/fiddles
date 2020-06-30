fetch('../out/main.wasm').then(response =>
    response.arrayBuffer()
).then(bytes => WebAssembly.instantiate(bytes)).then(results => {
    let exports = results.instance.exports;
    document.getElementById("container").textContent = exports.main();
    document.getElementById("title").textContent = exports.title();
}).catch(console.error);
