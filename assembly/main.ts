declare function log(msg:i32): void;

/** Number of discrete color values on the JS side. */
const NUM_COLORS = 2048;

var w: i32, h: i32, s:i32;

export function init(width:i32, height:i32): void {
  w = width;
  h = height;
  s = w*h;
}

function setPixel(x:i32, y:i32, value:u16):void{
  if ((y >= h || x >= w)){
    return;
  }
  store<u16>((y * w + x)*2, load<u16>((y * w + x)*2) + value); //No idea why *2, maybe because this is u16 and image is u32?
}

export function drawLine(startx: f32, starty: f32, endx :f32, endy: f32, linewidth: i32, blur: i32): void {

  var intensity :u16 = 500;

  //draw the line itself.
  if (linewidth > 0){
    determineLDAAndDrawLine(startx, starty, endx, endy, intensity);
    var drawnWidth :i32 = 1;
    var offset :f32 = 0;


    while (drawnWidth < linewidth){
      offset++;
      determineLDAAndDrawLine(startx + offset, starty, endx + offset, endy, intensity);
      determineLDAAndDrawLine(startx - offset, starty, endx - offset, endy, intensity);
      drawnWidth++;
    } 
  }
  

  if (blur > 0){
    var drawnBlur: i32 = 0;
    var istep = ((intensity* 0.75)/ (blur + 1)) as u16;

    offset = linewidth == 0 ? 0 : offset++;

    while(drawnBlur < blur) {
      intensity = intensity - istep 

      determineLDAAndDrawLine(startx + offset, starty, endx + offset, endy, intensity);
      determineLDAAndDrawLine(startx - offset, starty, endx - offset, endy, intensity);

      drawnBlur++;
      
      offset++;

    }
  }

  
}

function determineLDAAndDrawLine(startx: f32, starty: f32, endx :f32, endy: f32, value: u16): void {
  var x0 = Math.round(startx) as i32;
  var y0 = Math.round(starty) as i32;
  var x1 = Math.round(endx) as i32;
  var y1 = Math.round(endy) as i32;

  if(x0 == x1){
    straightVerticalLine(x0, y0, x1, y1, value);
  } else if(y0 == y1) {
    straightHorizontalLine(x0, y0, x1, y1, value);
  } else if(Math.abs(x1-x0) >= Math.abs(y1-y0)){
    bresenhamhori(startx, starty, endx, endy, value);
  } else {
    bresenhamverti(startx, starty, endx, endy, value);
  }

}

function straightVerticalLine(x0 :i32, y0 :i32, x1 :i32, y1 :i32, value: u16): void {
  var sign = Math.sign(y1 - y0) as i32;
  for (var y = y0; y != y1; y += sign){
    setPixel(x0, y, value);
  }
  
}

function straightHorizontalLine(x0 :i32, y0 :i32, x1 :i32, y1 :i32, value: u16): void {
  var sign = Math.sign(x1 - x0) as i32;
  for (var x = x0; x != x1; x += sign){
    setPixel(x, y0, value);
  }
}

function bresenhamhori(startx: f32, starty: f32, endx :f32, endy: f32, value: u16): void {
  var endxi = Math.round(endx) as i32;
  var dx :f32 = endx - startx;
  var dy :f32 = endy - starty;
  var derr:f32 = Math.abs(dy / dx) as f32;
  var error:f32 = 0.0;
  var y :i32 = starty as i32;
  for (var x:i32 = (startx as i32); x < endxi; x++){
    setPixel(x,y,value);
    error = error + derr;
    while (error >= 0.5){
      y = y + (Math.sign(dy) as i32);
      error = error - 1.0;
    }
  }
}

function bresenhamverti(startx: f32, starty: f32, endx :f32, endy: f32, value: u16): void {
  var endyi = Math.round(endy) as i32;
  var dx :f32 = endx - startx;
  var dy :f32 = endy - starty;
  var derr:f32 = Math.abs(dx / dy) as f32;
  var error:f32 = 0.0;
  var x :i32 = startx as i32;
  for (var y:i32 = (starty as i32); y < endyi; x++){
    setPixel(x,y,value);
    error = error + derr;
    while (error >= 0.5){
      x = x + (Math.sign(dx) as i32);
      error = error - 1.0;
    }
  }
}