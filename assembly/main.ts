declare function log(msg:u32): void;

/** Number of discrete color values on the JS side. */
const NUM_COLORS = 2048;

var w: i32, h: i32, s:i32;

export function init(width:i32, height:i32): void {
  w = width;
  h = height;
  s = w*h;
}

export function rescale(maxvalue:u32): void {
  var maxval:u32 = 0;
  for (var x:i32 = 0; x < s; x += 4){
    var newval = load<u32>(x);
    if(newval > maxval){
      maxval = newval;
    }
  }

  //log(maxval);

  var scaler :f32 = (maxvalue as f32) / (maxval as f32);


  for (var i:i32 = 0; i < s; i += 4){
    var val = load<u32>(i) as f32;
    newval = (val*scaler) as u32;
    store<u32>(i, newval);
  }
}

function setPixel(x:i32, y:i32, value:u32):void{
  // Times 4 because we adress bytes.
  var newval: u32 = load<u32>((y * w + x)*4) + value
  store<u32>((y * w + x) * 4, newval as u32); 
}

function resetPixels(): void {
  for (var i:i32 = 0; i < s; i += 4){
    var val = load<u32>(i);
    store<u32>(i, 0);
  }
}

/*
*
* LINE DRAWING
*
*/

export function drawLine(startx: f32, starty: f32, endx :f32, endy: f32, linewidth: i32, blur: i32): void {

  var intensity :u32 = 100;

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

function determineLDAAndDrawLine(startx: f32, starty: f32, endx :f32, endy: f32, value: u32): void {
  var x0 = Math.round(startx) as i32;
  var y0 = Math.round(starty) as i32;
  var x1 = Math.round(endx) as i32;
  var y1 = Math.round(endy) as i32;

  if(x0 == x1){
    straightVerticalLine(x0, y0, x1, y1, value);
  } else if(y0 == y1) {
    straightHorizontalLine(x0, y0, x1, y1, value);
  } else {
    bresenham(x0, y0, x1, y1, value);
  }

}

function straightVerticalLine(x0 :i32, y0 :i32, x1 :i32, y1 :i32, value: u32): void {
  var sign = Math.sign(y1 - y0) as i32;
  for (var y = y0; y != y1; y += sign){
    setPixel(x0, y, value);
  }
  
}

function straightHorizontalLine(x0 :i32, y0 :i32, x1 :i32, y1 :i32, value: u32): void {
  var sign = Math.sign(x1 - x0) as i32;
  for (var x = x0; x != x1; x += sign){
    setPixel(x, y0, value);
  }
}

function bresenham(x0 :i32, y0: i32, x1:i32, y1:i32, value: u32): void {
  if (Math.abs(y1 - y0) < Math.abs(x1 - x0)){
    if (x0 > x1){
      plotLineLow(x1, y1, x0, y0, value)
    } else {
      plotLineLow(x0, y0, x1, y1, value)
    }
  } else {
    if (y0 > y1) {
      plotLineHigh(x1, y1, x0, y0, value)
    } else {
      plotLineHigh(x0, y0, x1, y1, value)
    }
  }
}

function plotLineLow(x0 :i32, y0: i32, x1:i32, y1:i32, value: u32): void {
  var dx = x1 - x0;
  var dy = y1 - y0;
  var yi :i32 = 1;
  if (dy < 0){
    yi = -1;
    dy = -dx;
  }
  var D = 2*dy - dx
  var y = y0;
  for (var x = x0; x <= x1; x++){
    setPixel(x, y, value);
    if (D > 0){
      y = y + yi;
      D = D - 2*dx;
    }
    
    D = D + 2*dy;
  }
}

function plotLineHigh(x0 :i32, y0: i32, x1:i32, y1:i32, value: u32): void {
  var dx = x1 - x0;
  var dy = y1 - y0;
  var xi :i32 = 1;
  if (dx < 0){
    xi = -1;
    dx = -dx;
  }
  var D = 2*dx - dy
  var x = x0;
  for (var y = y0; y <= y1; y++){
    setPixel(x, y, value);
    if (D > 0){
      x = x + xi;
      D = D - 2*dy;
    }
    
    D = D + 2*dx;
  }
}