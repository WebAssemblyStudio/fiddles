class Manager{
  constructor(){
    this.flowers = [];
  }
  addFlower(x,z,orientation){
    this.flowers.push([x,z,orientation]);
  }
  rotateFlower(flower,rotation){
    const blockRotations = [[0,1,2,3],[1,3,0,2],[3,2,1,0],[2,0,3,1]];
    const xRotations = [[1,0],[0,1],[-1,0],[0,-1]];
    const zRotations = [[0,1],[-1,0],[0,-1],[1,0]];
  	return [
      flower[0]*xRotations[rotation][0] + flower[1]*xRotations[rotation][1],
      flower[0]*zRotations[rotation][0] + flower[1]*zRotations[rotation][1],
      blockRotations[rotation][flower[2]]
    ];
  }
  spawnWorker(){
    return new WorkerWrapper('f10000.wasm');
  }
  testChunk(x,z,rotation,callback = function(){}){
    var w = this.spawnWorker();
    this.fillMemory(rotation,w);
    w.callFunction('testChunk',[x,z,this.flowers.length],function(result){
      log(result);
      callback(result);
    });
  }
  testPosition(x,z,rotation){
  	this.fillMemory(rotation);
  	return 1==this.wasm.testPosition(x,z,this.flowers.length*12);
  }
  fillMemory(rotation,w){
  	for(var index in this.flowers){
      var rotatedFlower = this.rotateFlower(this.flowers[index],rotation);
      w.callFunction('setFlowerPosition',[index,rotatedFlower[0],rotatedFlower[1],rotatedFlower[2]]);
    }
  }
} 
