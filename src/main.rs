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

fn cols() -> usize {
    ArcModule::get_instance().cols
}

fn rows() -> usize {
    ArcModule::get_instance().cols
}

fn pos(x: usize, y: usize) -> usize {
    y * cols() + x
}

fn clear(buf: &mut [Rgb], color: Rgb) {
    for c in buf {
        *c = color;
    }
}

#[no_mangle]
pub extern fn apply() {
    let mut module = ArcModule::get_instance();
    let rows = module.rows;
    let cols = module.cols;
    let ref mut animation = module.get_animation().as_mut_slice();
    clear(animation, Rgb::new(255, 255, 255));
    let square = (5, 5, 30, 30);
    let heart = (15, 15, 17, 17);
    let mut heart_color = Rgb::new(255, 255, 255);
    for (index, frame) in animation.chunks_mut(rows * cols).enumerate() {
        for y in (square.1)..(square.1+square.3) {
            for x in (square.0)..(square.0+square.2) {
              frame[pos(x,y)] =  Rgb::new(0xe1, 0x00, 0x79);
            }
        }
        // Dots around square
        frame[pos(square.0, square.1)] = Rgb::new(255, 255, 255);
        frame[pos(square.0, square.1+square.3-1)] = Rgb::new(255, 255, 255);
        frame[pos(square.0+square.2-1, square.1)] = Rgb::new(255, 255, 255);
        frame[pos(square.0+square.2-1, square.1+square.3-1)] = Rgb::new(255, 255, 255);

        // Heart
        for i in 0..9 {
            frame[pos(heart.0+(heart.2/2)-i, heart.1+heart.3-(i+1))] = heart_color;
            frame[pos(heart.0+(heart.2/2)+i, heart.1+heart.3-(i+1))] = heart_color;
            for x in (heart.0+(heart.2/2)-i)..(heart.0+(heart.2/2)+i) {
                frame[pos(x, heart.1+heart.3-(i+1))] = heart_color;
            }
        }
        for i in 1..4 {
            frame[pos(heart.0+(heart.2/2)-8, heart.1+heart.3-9-i)] = heart_color;
            for x in (heart.0+(heart.2/2)-8)..(heart.0+(heart.2/2)) {
              frame[pos(x, heart.1+heart.3-9-i)] = heart_color;
            }
            for x in (heart.0+(heart.2/2)+1)..(heart.0+(heart.2/2)+8) {
              frame[pos(x, heart.1+heart.3-9-i)] = heart_color;
            }
            frame[pos(heart.0+(heart.2/2)+8, heart.1+heart.3-9-i)] = heart_color;
        }
        for i in 1..4 {
            frame[pos(heart.0+(heart.2/2)-(8-i), heart.1+heart.3-12-i)] = heart_color;
            frame[pos(heart.0+(heart.2/2)-(8-i-1), heart.1+heart.3-12-i)] = heart_color;

            frame[pos(heart.0+(heart.2/2)+(8-i), heart.1+heart.3-12-i)] = heart_color;
            frame[pos(heart.0+(heart.2/2)+(8-i-1), heart.1+heart.3-12-i)] = heart_color;
        }
        frame[pos(heart.0+(heart.2/2)-4, heart.1+heart.3-15)] = heart_color;
        frame[pos(heart.0+(heart.2/2)+4, heart.1+heart.3-15)] = heart_color;

        for i in 1..5 {
            frame[pos(heart.0+(heart.2/2)-(4-i), heart.1+heart.3-15+i)] = heart_color;
            frame[pos(heart.0+(heart.2/2)-(4-i+1), heart.1+heart.3-15+i)] = heart_color;

            frame[pos(heart.0+(heart.2/2)+(4-i), heart.1+heart.3-15+i)] = heart_color;
            frame[pos(heart.0+(heart.2/2)+(4-i+1), heart.1+heart.3-15+i)] = heart_color;
        }
        frame[pos(heart.0+(heart.2/2)-4, heart.1+heart.3-13)] = heart_color;
        frame[pos(heart.0+(heart.2/2)-5, heart.1+heart.3-13)] = heart_color;
        frame[pos(heart.0+(heart.2/2)+4, heart.1+heart.3-13)] = heart_color;
        frame[pos(heart.0+(heart.2/2)+5, heart.1+heart.3-13)] = heart_color;
        frame[pos(heart.0+(heart.2/2), heart.1+heart.3-15+5)] = heart_color;

        match index%40 {
          0 => heart_color = Rgb::new(255, 255, 255),
          4 => heart_color = Rgb::new(0xe6, 0xd3, 0xf6),
          8 => heart_color = Rgb::new(0xe2, 0xa2, 0xdd),
          12 => heart_color = Rgb::new(0xe4, 0x69, 0xb3),
          16 => heart_color = Rgb::new(0xe1, 0x00, 0x79),
          20 => heart_color = Rgb::new(0xe1, 0x00, 0x79),
          24 => heart_color = Rgb::new(0xe4, 0x69, 0xb3),
          28 => heart_color = Rgb::new(0xe2, 0xa2, 0xdd),
          32 => heart_color = Rgb::new(0xe6, 0xd3, 0xf6),
          36 => heart_color = Rgb::new(255, 255, 255),
          _ => {},
        }
    }
}

