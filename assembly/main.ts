declare function log(msg:number): void;
declare function cos(x:number): f32;
declare function sin(x:number): f32;

/** Number of discrete color values on the JS side. */
const NUM_COLORS = 2048;

var w: i32, h: i32, s:i32;
var sv: i32, lw: i32, b: i32;
var intensitystep:i32;

export function init(width:i32, height:i32): void {
  w = width;
  h = height;
  s = w*h*4; //So we have the bytesize, since 1 value = 4 bytes.
}

export function setStartValueLinewidthAndBlur(startvalue: i32, linewidth: i32, blur:i32):void {
  sv = startvalue;
  lw = linewidth;
  b = blur;
  if (b > 0)
    intensitystep = startvalue / blur;
  else 
    intensitystep = startvalue;
}

export function rescale(maxvalue:u32): void {
  var maxval:u32 = 0;
  for (var x:i32 = 0; x < s; x += 4){
    var newval = load<u32>(x);
    if(newval > maxval){
      maxval = newval;
    }
  }
  if (maxval == 0){
    return;
  }

  var scaler :f32 = (maxvalue as f32) / (maxval as f32);

  for (var i:i32 = 0; i < s; i += 4){
    var val = load<u32>(i) as f32;
    newval = (val*scaler) as u32;
    store<u32>(i, newval);
  }
}

function setPixel(x:i32, y:i32, value:u32):void{
  // Times 4 because we adress bytes.
  if (x < 0 || y < 0){
    return;
  }
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

export function drawLine(startx: f32, starty: f32, endx :f32, endy: f32): void {

  determineLDAAndDrawLine(startx, starty, endx, endy);
}

function determineLDAAndDrawLine(startx: f32, starty: f32, endx :f32, endy: f32): void {
  var x0 = Math.round(startx) as i32;
  var y0 = Math.round(starty) as i32;
  var x1 = Math.round(endx) as i32;
  var y1 = Math.round(endy) as i32;

  var drawnWidth:i32 = 1;
  var offset:i32 = 1;  

  var value = sv;

  if(x0 == x1){
    straightVerticalLine(x0, y0, x1, y1, sv);
    while (drawnWidth < lw){
      straightVerticalLine(x0 + offset, y0, x1 + offset, y1, sv);
      straightVerticalLine(x0 - offset, y0, x1 - offset, y1, sv);
      drawnWidth += 2;
      offset++;
    }

    drawnWidth = 0;

    while (drawnWidth < b){
      value -= intensitystep;
      straightVerticalLine(x0 + offset, y0, x1 + offset, y1, value);
      straightVerticalLine(x0 - offset, y0, x1 - offset, y1, value);
      drawnWidth += 1;
      offset++;
    }

  } else if(y0 == y1) {
    straightHorizontalLine(x0, y0, x1, y1, value);
    while (drawnWidth < lw){
      straightHorizontalLine(x0, y0 + offset, x1, y1  + offset, value);
      straightHorizontalLine(x0, y0 - offset, x1, y1  - offset, value);
      drawnWidth += 2;
      offset++;
    }

    drawnWidth = 0;
    while (drawnWidth < b){
      value -= intensitystep;
      straightHorizontalLine(x0, y0 + offset, x1, y1  + offset, value);
      straightHorizontalLine(x0, y0 - offset, x1, y1  - offset, value);
      drawnWidth += 1;
      offset++;
    }
  } else {

      if (lw > 1){
        var dist = lw/2 as f32;

        var dx = x1 - x0;
        var dy = y1 - y0;

        var angle = Math.atan2(dx, dy);

        var dist_x = dist * cos(angle);
        var dist_y = dist * sin(angle);
        
        var xr0 = Math.round(x0 as f32 + dist_x) as i32;
        var yr0 = Math.round(y0 as f32 + dist_y) as i32;
        var xr1 = Math.round(x1 as f32 + dist_x) as i32;
        var yr1 = Math.round(y1 as f32 + dist_y) as i32;
        var xr2 = Math.round(x1 as f32 - dist_x) as i32;
        var yr2 = Math.round(y1 as f32 - dist_y) as i32;
        var xr3 = Math.round(x0 as f32 - dist_x) as i32;
        var yr3 = Math.round(y0 as f32 - dist_y) as i32;

        log(xr0);
        log(yr0);
        log(xr1);
        log(yr1);
        log(xr2);
        log(yr2);
        log(xr3);
        log(yr3);

        rectangle(xr0, yr0, xr1, yr1, xr2, yr2, xr3, yr3, value);
      } else if (lw == 1) {
        bresenhamDraw(x0, y0, x1, y1, value);
      }

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

function bresenhamDraw(x0 :i32, y0: i32, x1:i32, y1:i32, value: u32): void {
  if (Math.abs(y1 - y0) < Math.abs(x1 - x0)){
    if (x0 > x1){
      plotLineLowDraw(x1, y1, x0, y0, value)
    } else {
      
      plotLineLowDraw(x0, y0, x1, y1, value)
    }
  } else {
    if (y0 > y1) {
      plotLineHighDraw(x1, y1, x0, y0, value)
    } else {
      plotLineHighDraw(x0, y0, x1, y1, value)
    }
  }
}

function plotLineLowDraw(x0 :i32, y0: i32, x1:i32, y1:i32, value: u32): void {
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

function plotLineHighDraw(x0 :i32, y0: i32, x1:i32, y1:i32, value: u32): void {
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

function bresenham(x0 :i32, y0: i32, x1:i32, y1:i32): void {
  if (Math.abs(y1 - y0) < Math.abs(x1 - x0)){
    // if (x0 > x1){
    //   plotLineLow(x1, y1, x0, y0)
    // } else {
      
      plotLineLow(x0, y0, x1, y1)
    // }
  } else {
    //if (y0 > y1) {
      // plotLineHigh(x1, y1, x0, y0)
    //} else {
      plotLineHigh(x0, y0, x1, y1)
    // }
  }
}

function plotLineLow(x0 :i32, y0: i32, x1:i32, y1:i32): void {
  var dx = x1 - x0;
  var dy = y1 - y0;
  var ody = dy;
  var sign = Math.sign(dx) as i32;
  var yi :i32 = 1;
  if (dy < 0){
    yi = -1;
    dy = -dx;
  }
  var D = 2*dy - dx
  var y = y0;
  for (var x = x0; x != (x1+sign); x += sign){
    if (ody < 0){
      store_buffer(0, y, x);
    } else if (ody > 0) {
      store_buffer(1, y, x);
    }
    if (D > 0){
      y = y + yi;
      D = D - 2*dx;
    }
    
    D = D + 2*dy;
  }
}

function plotLineHigh(x0 :i32, y0: i32, x1:i32, y1:i32): void {
  var dx = x1 - x0;
  var dy = y1 - y0;
  var ody = dy;
  var sign = Math.sign(dy) as i32;
  var xi :i32 = 1;
  if (dx < 0){
    xi = -1;
    dx = -dx;
  }
  var D = 2*dx - dy
  var x = x0;
  for (var y = y0; y != (y1 + sign); y += sign){
    if (ody < 0){
      store_buffer(0, y, x);
    } else if (ody > 0) {
      store_buffer(1, y, x);
    }
    if (D > 0){
      x = x + xi;
      D = D - 2*dy;
    }
    
    D = D + 2*dx;
  }
}

function bufferLine(x0:i32, y0:i32, x1:i32, y1:i32): void{
  if (x0 == x1){
    for (var y = (Math.min(y0, y1) as i32); y <= (Math.max(y0, y1) as i32); y++){
      if (y0 < y1){
        store_buffer(1, y, x0);
      } else {
        store_buffer(0, y, x0);
      }    
    }
  } else if (y0 == y1){
    store_buffer(0, y0, x0);
    store_buffer(1, y0, x1);
  } else {
    bresenham(x0, y0, x1, y1);
  }
}

export function rectangle(x0 :i32, y0:i32, x1 :i32, y1:i32,x2 :i32, y2:i32,x3 :i32, y3:i32, value: u32) :void{
  bufferLine(x0, y0, x1, y1);
  bufferLine(x1, y1, x2, y2);
  bufferLine(x2, y2, x3, y3);
  bufferLine(x3, y3, x0, y0);

  var ymin = Math.min(Math.min(Math.min(y0, y1), y2),y3) as i32;
  var ymax = Math.max(Math.max(Math.max(y0, y1), y2),y3) as i32;

  for(var y = ymin; y <= ymax; y++){
    var xl = get_buffer(0, y);
    var xr = get_buffer(1, y);

    // log(y)
    // log(xl)
    // log(xr)
    // log(1111111)

    straightHorizontalLine(xl, y, xr, y, value);
  }
  clearbuffer(ymin, ymax);
}

function store_buffer(xi: i32, y: i32, x: u32): void{
  var startIndex :i32;
  if (xi == 0){
    startIndex = s;
  } else if (xi == 1){
    startIndex = 2*s;
  }
  store<u32>(startIndex + y*4, x);
}

function get_buffer(xi: i32, y: i32) :u32 {
  var startIndex :i32;
  if (xi == 0){
    startIndex = s;
  } else if (xi == 1){
    startIndex = 2*s;
  }
  return load<u32>(startIndex + y*4);
}

function clearbuffer(ymin:i32, ymax:i32):void {
  for (var y = ymin; y <= ymax; y++){
    store<u32>(s + 4*y, 0);
    store<u32>(2*s + 4*y, 0);
  }
}