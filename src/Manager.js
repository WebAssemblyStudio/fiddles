
class Manager{
  constructor(size,watFile){
    this.watFile = watFile;
    this.flowers = [];
    this.size = size;
    this.createWorkers();
    this.worldMap = new WorldMap(size);
    this.initUI();
  }
  initUI(){
    this.$ = document.createElement('div');
    this.$.appendChild(this.worldMap.getUI());
    this.startButton = document.createElement('button');
    var self = this;
    this.startButton.onclick = function(){
      self.multipleChunkCanvasTester();
    };
    this.$.appendChild(this.startButton);
    this.startButton.textContent = 'Start';
  }
  getUI(){
    return this.$;
  }
  addFlower(orientation,x,z){
    this.flowers.push([x,z,orientation]);
  }
  rotateFlower(flower,rotation){
    //const blockRotations = [[0,1,2,3],[1,3,0,2],[3,2,1,0],[2,0,3,1]];
    const blockRotations = [[0,2,1,3],[2,3,0,1],[3,1,2,0],[1,0,3,2]];
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
  testChunkRotation(x,z,rotation,callback = function(){}){
    this.workers[rotation].callFunction('testChunk',[x,z,this.flowers.length],callback);
  }
  fillMemory(){
    for(var rotation = 0; rotation < 4; rotation ++){
      for(var index in this.flowers){
        var rotatedFlower = this.rotateFlower(this.flowers[index],rotation);
        this.workers[rotation].callFunction('setFlowerPosition',[index,rotatedFlower[0],rotatedFlower[1],rotatedFlower[2]]);
      }
    }
  }
  testChunk(x,z,workers,callback = function(){}){
    var r = 0;
    var found = false;
    var self = this;
    for(var i = 0; i < 4; i++){
      let o = i;
      this.testChunkRotation(x,z,i,function(result){
        if(result == 1){
          found = true;
        }
        console.log(o);
        r++;
        if(r == 4){
          self.worldMap.setFound(x,z,found);
          callback(found);
        }
      });
    }
  }
  createWorkers(){
    var workers = [];
    for(var i = 0; i < 4;i++){
      workers[i] = this.spawnWorker();
    }
    this.workers = workers;
  }
  multipleChunkTester(x_start,x_end,z_start,z_end){
    var workers = this.workers;
    this.fillMemory();
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
    });
    return p;
  }
  multipleChunkCanvasTester(){
    this.fillMemory();
    var starter = {};
    var self = this;
    var p = new Promise(function(resolve){
      starter.start = function(){
        log('start');
        resolve();
      };
    });
    var next = function(result){
      var p = new Promise(function(resolve){
        var nextPlace = self.worldMap.getNextChunk();
        if(!nextPlace){
          setTimeout(function(){
            resolve(true);
          },10);
          return;
        }
        self.testChunk(nextPlace[0],nextPlace[1],self.workers,function(result){
          if(result){
          }
          resolve(false);
        })
      });
      if(result){
        starter.end();
        return true;
      }else{
        return p.then(next);
      }
    }
    p.then(next);
    starter.start();
    return new Promise(function(resolve){
      starter.end = function(){
        console.log('ready');
        resolve()
      }
    })
  }
} 
