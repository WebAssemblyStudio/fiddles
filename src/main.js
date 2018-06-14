var mymemory = new WebAssembly.Memory({initial:1, maximum:100});
var myObj = { imports: { i: arg => console.log(arg) }, mem: { m: mymemory }}

fetch('../out/main.wasm').then(response =>
  response.arrayBuffer()
).then(bytes => WebAssembly.instantiate(bytes, myObj)).then(results => {
  instance = results.instance;

  var i32 = new Uint32Array(mymemory.buffer);
        for (var i = 0; i < 10; i++) {
          i32[i] = i;
        }

  var sum = obj.instance.exports.accumulate(0, 10);
        console.log(sum);

  document.getElementById("container").innerText = instance.exports.add(1,1);
  instance.exports.schleife();
}).catch(console.error);

