class WorldMap{
  constructor(radius){
    this.radius = radius;
    this.initUI();
  }
  initUI(){
    this.$ = document.createElement('div');
    this.canvas = document.createElement('canvas');
    this.canvas.width = this.canvas.height = this.radius*2+1;
    this.ctx = this.canvas.getContext("2d");
    this.image_id = this.ctx.createImageData(1,1);
    this.image_d  = this.image_id.data; 
    this.ctx.fillStyle ='black';
    this.ctx.fillRect(0, 0, this.radius*2+1, this.radius*2+1);
    this.$.appendChild(this.canvas);
    this.fileUploadInput = document.createElement('input');
    this.$.appendChild(this.fileUploadInput);
    var self = this;
    this.fileUploadInput.oninput = function(event){
      var files = this.files;
      if(files && files.length > 0){
        self.uploadFile(files[0]);
      }
    };
    this.fileUploadInput.type = 'file';
  }
  getUI(){
    return this.$;
  }
  drawPixel(x,z,r,g,b,a){
    this.image_d[0]   = r;
    this.image_d[1]   = g;
    this.image_d[2]   = b;
    this.image_d[3]   = a;
    this.ctx.putImageData( this.image_id,  z+this.radius, -x+this.radius);   
  }
  uploadFile(file){
    var reader = new FileReader();
    reader.readAsDataURL(file);
    var ctx = this.ctx;
    reader.onload = function(e) {
      var img = new Image();
      img.onload = function() {
        ctx.drawImage(img, 0,0)
      }
      img.src = e.target.result;
    }
  }
  setFound(x,z,found){
    if(found){
      this.drawPixel(x,z,0,255,0,255);
    }else{
      this.drawPixel(x,z,255,0,0,255);
    }
  }
  getNextChunk(){
    var data = this.ctx.getImageData(0, 0, this.radius*2+1, this.radius*2+1).data;
    var i_best = -1;
    var b_best = -1;
    for (var i = 0; i < data.length; i += 4) {
      if(data[i+2] > b_best && !data[i+1] && !data[i]){
        i_best = i;
        b_best = data[i+2];
        if(b_best == 255){
          break;
        }
      }
    }
    if(i_best == -1){
      return false;
    }
    i_best = i_best/4;
    var x = i_best%(this.radius*2+1);
    var y = (i_best-x)/(this.radius*2+1);
    return [this.radius-y,x-this.radius];
  }
}