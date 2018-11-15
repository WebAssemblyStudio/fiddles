console.log("about to start IPFS.");
const Buffer = window.buffer.Buffer;
var peers;

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
   console.log(`ID: ${ipfsId.id}`);

  const topic = 'Taraxa';
  const receiveMsg = (msg) => console.log(msg)

ipfs.pubsub.subscribe(topic, receiveMsg, {discover:true}, (err) => {
  if (err) {
    return console.error(`failed to subscribe to ${topic}`, err)
  }
  console.log(`subscribed to ${topic}`)
  ipfs.pubsub.publish(topic, Buffer.from("hello! How are you?"))
})

function checkPeers(){
ipfs.pubsub.peers(topic, (err, peerIds) => {
  if (err) {
    return console.error(`failed to get peers subscribed to ${topic}`, err)
  }
  document.getElementById("container").textContent = `Peers: ${peerIds}`;
}) 
  setTimeout(checkPeers, 10000);
}
  checkPeers();

  var module;
  instantiateStreaming(fetch("../out/main.wasm"), {
    main: {
      getId() {
        return module.newString(ipfsId.id)
      }
    },
    env: {
      abort(msg, file, line, column) {
        console.error("abort called at main.ts:" + line + ":" + column);
      }
    },
  }).then(result => {
    module = result;
    // console.log(module.A(module.newString(ipfsId.id)));

  }).catch(console.error);
  })
;