class PixelVal {
  red: u8;
  grn: u8;
  blu: u8;
}

class PixelLoc {
  x: f32;
  y: f32;
}

class Pixel {
  val: PixelVal;
  loc: PixelLoc;
}

let pixels: Pixel[][];

export function initLayout(nStrips: i32): void {
  pixels = new Array(nStrips);
}

export function initLayoutStrip(stripIdx: i32, length: i32): void {
  pixels[stripIdx] = new Array(length);
  for (let i = 0; i < length; i++) {
    pixels[stripIdx][i] = {
      val: {red: 255, grn: 255, blu: 255},
      loc: {x: 0.0, y: 0.0},
    };
  }
}

export function initLayoutPixel(stripIdx: i32, pixelIdx: i32, x: f32, y: f32): void {
  pixels[stripIdx][pixelIdx].loc = {x, y};
}

export function getPixelRed(stripIdx: i32, pixelIdx: i32): u8 {
  return pixels[stripIdx][pixelIdx].val.red;
}

export function getPixelGrn(stripIdx: i32, pixelIdx: i32): u8 {
  return pixels[stripIdx][pixelIdx].val.grn;
}

export function getPixelBlu(stripIdx: i32, pixelIdx: i32): u8 {
  return pixels[stripIdx][pixelIdx].val.blu;
}

export function tick(): void {
  // Fill this in
}

export function render(): void {
  // Fill this in
}