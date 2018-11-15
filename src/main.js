console.log("about to start IPFS.");
const ipfs = new Ipfs({
  EXPERIMENTAL: {
      pubsub: true,
    },
    config: {
      Addresses: {
        Swarm: [
          '/dns4/spacestation.hopto.org/tcp/9090/wss/p2p-websocket-star',
        ],
      },
    },
});


// once the node is ready
console.log("about to hook ready.");
ipfs.once('ready', async () => {
   var ipfsId = await ipfs.id();
   console.log(`ID: ${ipfsId}`);
   debugger;
  
  
})


WebAssembly.instantiateStreaming(fetch("../out/main.wasm"), {
  main: {
    sayHello() {
      console.log("Hello from WebAssembly!");
    }
  },
  env: {
    abort(msg, file, line, column) {
      console.error("abort called at main.ts:" + line + ":" + column);
    }
  },
}).then(result => {
  const exports = result.instance.exports;
  document.getElementById("container").textContent = "Result: " + exports.add(19, 23);
}).catch(console.error);
