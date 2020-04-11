var wasm = false;
var queue = [];
function doQueue(){
  if(!wasm || queue.length == 0)return;
  action = queue.shift();
  console.time(action.name + ' '+ action.id);
  var result = wasm[action.name](...action.data);
  console.timeEnd(action.name + ' '+ action.id);
  postMessage({id:action.id,result:result});
  doQueue();
}
function log(){
  var t = [];
  for(var i of arguments){
    t.push(i);
  }
  console.log(arguments);
  postMessage({log:t});
}
function init(bytes){
  WebAssembly.instantiate(bytes,{
    console: {
      log: (x) => log(x) ,
      found: (x,z) => log('x:',x,' z:',z),
      line:() => log('---')
    }
  }).then(results => {
    instance = results.instance;
    wasm = instance.exports;
    doQueue();
  }).catch(console.error);
}
onmessage = function(e){
  if(e.data.bytes){
    init(e.data.bytes);
    return;
  }
  this.queue.push(e.data);
  doQueue();
}