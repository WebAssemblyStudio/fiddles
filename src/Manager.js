
class Manager{
  constructor(size,watFile){
    this.watFile = watFile;
    this.workers = [];
    this.flowers = [];
    this.size = size;
    this.worldMap = new WorldMap(size);
    this.initUI();
  }
  initUI(){
    this.$ = document.createElement('div');
    this.$.appendChild(this.worldMap.getUI());
    this.addWorkerButton = document.createElement('button');
    var self = this;
    this.addWorkerButton.onclick = function(){
      self.addWorker();
    };
    this.addWorkerButton.textContent = 'Add worker';
    this.workerContainer = document.createElement('div');
    this.$.appendChild(this.workerContainer);
    this.$.appendChild(this.addWorkerButton);
  }
  getUI(){
    return this.$;
  }
  addFlower(orientation,x,z){
    this.flowers.push([orientation,x,z]);
  }
  rotateFlower(flower,rotation){
    const blockRotations = [[0,1,2,3],[2,0,3,1],[1,3,0,2],[3,2,1,0]];
    const xRotations = [[1,0],[0,-1],[0,1],[-1,0]];
    const zRotations = [[0,1],[1,0],[-1,0],[0,-1]];
  	return [
      blockRotations[rotation][flower[0]],
      flower[1]*xRotations[rotation][0] + flower[2]*xRotations[rotation][1],
      flower[1]*zRotations[rotation][0] + flower[2]*zRotations[rotation][1],
    ];
  }
  spawnWorker(){
    return new WorkerWrapper(this.watFile);
  }
  centralizeOriginAtFirstFlower(){
    var newList = [];
    var baseFlower = this.flowers[0];
    for(var index = 1; index < this.flowers.length; index ++){
      var flower = this.flowers[index];
      //console.log(flower + "");
      newList.push(this.rotateFlower([flower[0],flower[1] - baseFlower[1],flower[2] - baseFlower[2]],baseFlower[0]));
    }
    this.centralizedFlowerList = newList;
  }
  fillMemory(workerIndex){
    this.centralizeOriginAtFirstFlower();
    var flowerList = this.centralizedFlowerList;
    console.log(flowerList);
    var l = [];
    for(var rotation = 0; rotation < 4; rotation ++){
      for(var index in flowerList){
        var rotatedFlower = this.rotateFlower(flowerList[index],[0,2,1,3][rotation]);
        this.workers[workerIndex].callFunction('setFlowerPosition',[Number(index) + rotation*flowerList.length,rotatedFlower[1],rotatedFlower[2],rotatedFlower[0]]);
      }
    }
    console.log(l);
  }
  testChunk(x,z,workerIndex){
    var self = this;
    return new Promise(function(resolve){
      self.worldMap.setTesting(x,z);
      self.workers[workerIndex].callFunction('testChunk',[x,z,self.flowers.length-1],function(result){
        var found = (result == 1);
        self.worldMap.setFound(x,z,found);
        resolve(found);
      });
    });
  }
  addWorker(){
    var self = this;
    var w = this.spawnWorker();
    var workerIndex = this.workers.length;
    var clickfn = start;
    w.workerButton = document.createElement('button');
    var start = function(){
      w.workerButton.textContent = 'Stop worker';
      clickfn = function(){
        w.stopRequest = true;
        w.workerButton.textContent = 'Stopping worker...';
        clickfn = function(){};
      }
      self.startWorker(workerIndex);
    };
    w.onStop = function(){
      w.workerButton.textContent = 'Start worker';
      clickfn = start;
    }
    clickfn = start;
    w.workerButton.onclick = function(){
      clickfn();
    };
    w.workerButton.textContent = 'Start worker';
    this.workerContainer.appendChild(w.workerButton);
    this.workers.push(w);
    return workerIndex;
  }
  startWorker(workerIndex){
    this.fillMemory(workerIndex);
    var self = this;
    var next = function(found){
      if(found || self.workers[workerIndex].stopRequest){
        self.workers[workerIndex].onStop();
        return found;
      }
      var [x,z] = self.worldMap.getNextChunk();
      console.log([x,z]);
      return self.testChunk(x,z,workerIndex).then(next);
    }
    return next(false);
  }
} 
