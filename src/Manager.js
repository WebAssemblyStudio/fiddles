
class Manager{
  constructor(size,watFile){
    this.watFile = watFile;
    this.flowers = [];
    this.canvas = document.createElement('canvas');
    this.size = size;
    this.canvas.width = this.canvas.height = this.size;
    this.ctx = this.canvas.getContext("2d");
    this.image_id = this.ctx.createImageData(1,1); // only do this once per page
    this.image_d  = this.image_id.data; 
    this.ctx.fillRect(0, 0, this.size, this.size);
  }
  getUI(){
    return this.canvas;
  }
  drawPixel(x,y,r,g,b,a){
    this.image_d[0]   = r;
    this.image_d[1]   = g;
    this.image_d[2]   = b;
    this.image_d[3]   = a;
    this.ctx.putImageData( this.image_id, x+Math.floor(this.size/2), y+Math.floor(this.size/2));   
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
    return new WorkerWrapper(this.watFile);
  }
  testChunkRotation(x,z,w,callback = function(){}){
    w.callFunction('testChunk',[x,z,this.flowers.length],callback);
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
  testChunk(x,z,workers,callback = function(){}){
    var r = 0;
    var found = false;
    var self = this;
    for(var i = 0; i < 4; i++){
      this.testChunkRotation(x,z,workers[i],function(result){
        if(result == 1){
          found = true;
        }
        r++;
        if(r == 4){
          if(found){
            self.drawPixel(x,z,0,255,0,255);
          }else{
            self.drawPixel(x,z,255,0,0,255);
          }
          callback(found);
        }
      });
    }
  }
  createWorkers(){
    var workers = [];
    for(var i = 0; i < 4;i++){
      var w = this.spawnWorker();
      this.fillMemory(i,w);
      workers[i] = w;
    }
    return workers;
  }
  multipleChunkTester(x_start,x_end,z_start,z_end){
    var workers = this.createWorkers();
    var starter = {};
    var self = this;
    var p = new Promise(function(resolve){
      starter.start = function(){
        log('start');
        resolve();
      };
    });
    for(var currentX = x_start;currentX < x_end;currentX++){
      for(var currentZ = z_start;currentZ < z_end;currentZ++){
        let x = currentX;
        let z = currentZ;
        p = p.then(function(){
          return new Promise(function(resolve){
            self.testChunk(x,z,workers,function(result){
              if(result){
              }
              resolve();
            })
          })
        })
      }
    }
    setTimeout(function(){
      starter.start();
    },10);
    p.then(function(){
      log('ready')
    })
  }
} 
