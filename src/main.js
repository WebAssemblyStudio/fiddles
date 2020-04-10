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
const manager = new Manager(150,'f-small100000.wasm');
document.getElementById('canvas_container').appendChild(manager.getUI());
/**
 * Add flower positions here:
 */
//Currently loaded: https://www.youtube.com/watch?v=B6TU38E5_rs
manager.addFlower(3,20,38);
manager.addFlower(1,18,34);
manager.addFlower(3,17,30);
manager.addFlower(0,14,24);
manager.addFlower(0,13,19);
manager.addFlower(3,14,18);
manager.addFlower(3,14,17);
manager.addFlower(3,14,15);
manager.addFlower(2,16,11);
manager.addFlower(3,18,11);
manager.addFlower(2,15,8);
manager.addFlower(2,16,8);
manager.addFlower(1,9,14);
manager.addFlower(3,9,8);
manager.addFlower(3,9,7);
manager.addFlower(3,8,6);
manager.addFlower(1,3,22);
manager.addFlower(1,6,20);
manager.addFlower(3,7,20);
manager.addFlower(1,8,19);
manager.addFlower(2,12,30);
manager.addFlower(1,13,32);
manager.addFlower(1,11,33);
manager.addFlower(0,5,22);