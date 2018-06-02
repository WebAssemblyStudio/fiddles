use color::Rgb;
use arc_module::ArcModule;

#[no_mangle]
pub extern fn init(rows: usize, cols: usize, frame_count: usize, fps: usize, is_first: bool) {
  ArcModule::create_instance(rows, cols, frame_count, fps, is_first);
}

#[no_mangle]
pub extern fn getAnimationBuffer() -> *const Rgb {
  ArcModule::get_instance().get_animation().as_ptr()
}

use browser::random;

#[derive(Copy)]
pub struct Drop {
  pub x: f32,
  pub y: f32,
  pub v: f32,
}

impl Drop {
  pub fn new() -> Drop {
    let rand = unsafe { random() };
    let x = (rand * 44.0) as f32;
    // 1.3s from top to bottom
    // 35fps -> 
    let (v, y) = if rand < 0.5 { (-0.24, 11.0) } else { (0.24, 25.0) };

    Drop { x, y, v }
  }

  pub fn next_frame(&mut self) {
    self.y -= self.v;
  }

  pub fn get_coords(self) -> (usize, usize) {
    (self.x as usize, self.y as usize)
  }

  pub fn still_falling(self) -> bool {
    if self.v < 0.0 {
      self.y > 0.5
    } else {
      self.y < 36.5
    }
  }
}

impl Clone for Drop {
  fn clone(&self) -> Drop { *self }
}
