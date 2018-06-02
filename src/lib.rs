static mut module_instance: *mut ArcModule = 0 as *mut ArcModule;

mod browser;
mod color;
mod arc_module;
mod utils;
// mod drop;

use color::Rgb;
use arc_module::ArcModule;

pub use utils::init;
pub use utils::getAnimationBuffer;
use utils::Drop;

// we need to import all functions
use browser::random;

#[no_mangle]
pub extern fn apply() {
  // let's implement a game of life!
  // https://en.wikipedia.org/wiki/Conway%27s_Game_of_Life
  // Contributed by @finnpauls

  let mut module = ArcModule::get_instance();
  let rows = module.rows;
  let cols = module.cols;
  let frame_count = module.frame_count;
  let frame_size = rows * cols;
  let mut animation = module.get_animation().as_mut_slice();

  // start with 20 rain drops
  let mut raindrops = vec![Drop::new(); 20];
  let drop_color = Rgb::new(78, 127, 206);

  for frame in 0 .. frame_count {
    for drop in raindrops.iter_mut() {
      let (x, y) = drop.get_coords();
      let pixel = frame_size * frame + y * cols + x;
      animation[pixel] = drop_color;
      drop.next_frame();
    }
    raindrops.retain(|&x| x.still_falling());
    raindrops.push(Drop::new());
  }
}
