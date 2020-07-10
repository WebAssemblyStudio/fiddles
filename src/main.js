
fetch('../out/thinning.wasm').then(response =>
  response.arrayBuffer()
).then(bytes => WebAssembly.instantiate(bytes,{})).then(results => {
  let main = results.instance.exports;
  var img = new Image();
  img.src = "data:image/png;base64,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"
  img.onload = function(){
    let [w,h] = [img.width,img.height];
    let ctx = document.createElement("canvas").getContext('2d');
    [ctx.canvas.width,ctx.canvas.height] = [w,h];
    ctx.drawImage(img,0,0);
    var imgdata = ctx.getImageData(0,0,w,h);
    for (var i = 0; i < h; i++){
      for (var j = 0; j < w; j++){
        main.set_pixel(w,j,i,imgdata.data[(i*w+j)*4]>128?1:0);
      }
    }
    main.thinning_zs(w,h);
    for (var i = 0; i < h; i++){
      for (var j = 0; j < w; j++){
        var v = main.get_pixel(w,j,i);
        if (v){
          imgdata.data[(i*w+j)*4+1]=0;
          imgdata.data[(i*w+j)*4+2]=0;
        }
      }
    }
    ctx.putImageData(imgdata,0,0);
    document.body.appendChild(ctx.canvas);
  }
}).catch(console.error);
