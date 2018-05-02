static mut module_instance: *mut ArcModule = 0 as *mut ArcModule;

#[repr(C)]
#[derive(Copy)]
pub struct Rgb {
  r: u8,
  g: u8,
  b: u8,
}

impl Rgb {
  pub fn new(r: u8, g: u8, b: u8) -> Rgb {
    Rgb {r, g, b}
  }
}

impl Clone for Rgb {
  fn clone(&self) -> Rgb { *self }
}

struct ArcModule {
  rows: usize,
  cols: usize,
  frame_count: usize,
  fps: usize,
  is_first: bool,
  animation: Vec<Rgb>
}

impl ArcModule {
  pub fn create_instance(rows: usize, cols: usize, frame_count: usize, fps: usize, is_first: bool) -> &'static ArcModule {
    let buffer_size = rows * cols * frame_count;
    let mut module = ArcModule {
      rows,
      cols,
      frame_count,
      fps,
      is_first,
      animation: Vec::with_capacity(buffer_size)
    };
    module.animation.resize(buffer_size, Rgb::new(0, 0, 0));
    module.animation[0] = Rgb {r: 2, g: 4, b: 10};
    unsafe { module_instance = Box::into_raw(Box::new(module)) };
    ArcModule::get_instance()
  }

  pub fn get_instance<'a>() -> &'a mut ArcModule {
    unsafe { &mut *module_instance }
  }

  pub fn get_animation<'a>(&'a mut self) -> &'a mut Vec<Rgb> {
    &mut self.animation
  }
}

#[no_mangle]
pub extern fn init(rows: usize, cols: usize, frame_count: usize, fps: usize, is_first: bool) {
  ArcModule::create_instance(rows, cols, frame_count, fps, is_first);
}

#[no_mangle]
pub extern fn getAnimationBuffer() -> *const Rgb {
  ArcModule::get_instance().get_animation().as_ptr()
}

// moz://a

/*
const IMAGE : &[u8] = &[
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1, 1, 1, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 
1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 
1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1, 1, 1, 0, 0, 1, 0, 0, 0, 1, 1, 
1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 1, 0, 1, 1, 1, 0, 0, 1, 0, 0, 0, 0, 1, 1, 
1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 1, 1, 1, 0, 0, 1, 0, 0, 1, 1, 1, 1, 1, 
1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 0, 0, 1, 1, 
];
const IMAGE_ROWS : usize = 8;
const IMAGE_COLS : usize = 46;
*/

const IMAGE : &[u8] = &[
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 
0, 1, 1, 0, 1, 1, 0, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 1, 0, 0, 0, 1, 0, 0, 1, 0, 1, 1, 0, 
1, 0, 0, 1, 0, 0, 1, 0, 1, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 1, 
1, 0, 0, 1, 0, 0, 1, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 1, 1, 
1, 0, 0, 1, 0, 0, 1, 0, 1, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 
1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 1, 0, 1, 0, 0, 1, 0, 0, 0, 1, 1, 1, 
];
const IMAGE_ROWS : usize = 10;
const IMAGE_COLS : usize = 29;

fn image_pixel(row: usize, col: usize, col_offset: usize) -> Option<u8> {
  if row < IMAGE_ROWS && (col+col_offset) < IMAGE_COLS {
    Some(IMAGE[row * IMAGE_COLS + col + col_offset])
  } else {
    None
  }
}

#[no_mangle]
pub extern fn apply() {
  let mut module = ArcModule::get_instance();
  let rows = module.rows;
  let cols = module.cols;
  let ref mut animation = module.get_animation().as_mut_slice();
  let mut offset = 0;
  for (index, frame) in animation.chunks_mut(rows * cols).enumerate() {
    for row in 0 .. rows { 
      for col in 0 .. cols { 
        let pos = row * cols + col;
        let color = match image_pixel(row, col, offset) {
          Some(1) => Rgb::new(0, 0, 0),
          _  => Rgb::new(255, 255, 255),

        };
        frame[pos] = color;
      }
    }
    if index % 3 == 0 {  offset += 1; }
    /*for row in 0 .. rows {
      for col in 0 .. cols {
        frame[row * cols + col] = Rgb::new(row as u8 * 3, col as u8 * 3, (index % 0xffusize) as u8);
      }
    }*/
  }
}