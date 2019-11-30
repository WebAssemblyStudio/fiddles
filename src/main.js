// Question1
function add(a, b){
  var importObject = {
    console: {
      log: function(arg) {
        console.log(arg);
        return arg;
      }
    }
  };

  fetch('../out/q1.wasm').then(response =>
    response.arrayBuffer()
  ).then(bytes => WebAssembly.instantiate(bytes, importObject)).then(results => {
    instance = results.instance;
    document.getElementById("Q1").textContent = instance.exports.add(a,b);
  }).catch(console.error);
}

//Question2
function capitalizeString(str) {

  document.getElementById("Q2-a").textContent = str
  
  function consoleLogString(offset, length) {
    var bytes = new Uint8Array(memory.buffer, offset, length);
    var string = new TextDecoder('utf8').decode(bytes);
    console.log(string);
  }

  // create shared memory
  var memory = new WebAssembly.Memory({initial:10});
  // encode string
  var characterArray = new TextEncoder("utf-8").encode(str);
  var offset  = 0
  var length = characterArray.length
  // Assgin character array to shared memory buffer
  bytes = new Uint8Array(memory.buffer, offset, length)
  for (i = 0; i < length; i++) {
      bytes[i] = characterArray[i]
  }

  var importObject = { console: { log: consoleLogString }, js: { mem: memory } };

  // using WASM to captalize string
  WebAssembly.instantiateStreaming(fetch('../out/q2.wasm'), importObject)
  .then(obj => {
      obj.instance.exports.capitalize(offset,length);
      var bytes = new Uint8Array(memory.buffer, offset, length);
      var string = new TextDecoder('utf8').decode(bytes);
      console.log(string);
      document.getElementById("Q2-b").textContent = string
      return string
  }); 
  
}

var result = capitalizeString('abcdefghijMKJH')

add(10,100)

