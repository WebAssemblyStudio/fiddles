function printPos(x,z){ 
  log('[',x,',',z,',',wasm.getOnBlockPos(x,z),']');
}
function log(){
  console.log(...arguments);
  t = [];
  for(var i of arguments){
    t.push(i);
  }
  document.getElementById('container').innerText += t.join('') + "\n";
}
const manager = new Manager();
manager.addFlower(0,1,2); 
manager.addFlower(0,1,1); 
//console.log(manager.testPosition(0,1,0));
manager.testChunk(0,0,0);