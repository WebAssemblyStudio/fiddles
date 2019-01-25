declare function getCanvasWidth(): i32;
declare function getCanvasHeight(): i32;

class Pointer {
  constructor(offset: usize = 0) {
    return changetype<Pointer>(offset);
  }

  @inline @operator("[]") get(index: i32): i32 {
    return load<i32>(changetype<usize>(this) + (<usize>index << alignof<i32>()));
  }

  @inline @operator("[]=") set(index: i32, value: i32): void {
    store<i32>(changetype<usize>(this) + (<usize>index << alignof<i32>()), value);
  }
}

// Full int32 range is -0x80000000 to 0x7FFFFFFF. Use half.
@inline function applyCap(x: i32): i32 {
  return x < -0x40000000 ? -0x40000000 : (x > 0x3FFFFFFF ? 0x3FFFFFFF : x);
}

@inline function toRGB(x: i32): i32 {
  // Map negative values to red, positive to blue-green, zero to black
  var val = x >> 22;
  if (val < 0) return ((-(val + 1))  | 0xFF000000); // red
  return (((val << 8) | (val << 16)) | 0xFF000000); // cyan
}

export function step(): void {
  var width  = getCanvasWidth();
  var height = getCanvasHeight();
  var wh     = width * height;

  const image  = new Pointer(HEAP_BASE);
  const force  = new Pointer(HEAP_BASE + 4  * wh);
  const status = new Pointer(HEAP_BASE + 8  * wh);
  const u      = new Pointer(HEAP_BASE + 12 * wh);
  const vel    = new Pointer(HEAP_BASE + 16 * wh);

  for (let i = 0; i < height; ++i) {
    status[i * width] = 1;
    status[i * width + width - 1] = 1;
  }

  for (let i = 0; i < width; ++i) {
    status[i] = 1;
    status[wh - width + i] = 1;
  }

  for (let i = 0; i < wh; ++i) {
    if (!status[i]) {
      let uCen   = u[i];
      let uNorth = u[i - width];
      let uSouth = u[i + width];
      let uEast  = u[i + 1];
      let uWest  = u[i - 1];
    
      let uxx = (((uWest  + uEast)  >> 1) - uCen);
      let uyy = (((uNorth + uSouth) >> 1) - uCen);
    
      vel[i] = applyCap(vel[i] + (uxx >> 1) + (uyy >> 1));
    }
  }

  for (let i = 0; i < wh; ++i) {
    if (!status[i]) {
      let f = force[i];
      u[i] = applyCap(f + applyCap(u[i] + vel[i]));
      force[i] = f >> 1;
    }
  }

  for (let i = 0; i < wh; ++i) {
    image[i] = status[i] == 1 ? 0xFFFF0000 : toRGB(u[i]);
  }
}
