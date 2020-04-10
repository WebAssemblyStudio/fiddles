class WorkerWrapper{
  constructor(url){
    this.url = url;
    this.worker = new Worker(getFileURL('src/worker.js'));
    var self = this;
    fetch('./' + url).then(function(response){
      console.log(response);
      return response.arrayBuffer();
    }).then(function(bytes){
      console.log(bytes);
      self.worker.postMessage({bytes:bytes});
    });
    var self = this;
    this.worker.onmessage = function(e){
      if(e.data.log){
        log(...(e.data.log));
        return;
      }
      self.callBacks[e.data.id](e.data.result);
    };
    this.callBacks = [];
  }
  callFunction(name,data,callBack = function(){}){
    var id = this.callBacks.length;
    this.callBacks.push(callBack);
    this.worker.postMessage({name:name,data:data,id:id});
  }
}