static mut module_instance: *mut ArcModule = 0 as *mut ArcModule;

mod color;
mod arc_module;
mod utils;

use color::Rgb;
use arc_module::ArcModule;

pub use utils::init;
pub use utils::getAnimationBuffer;

#[no_mangle]
pub extern fn apply() {
  let mut module = ArcModule::get_instance();
  let rows = module.rows;
  let cols = module.cols;
  let ref mut animation = module.get_animation().as_mut_slice();
  for (index, frame) in animation.chunks_mut(rows * cols).enumerate() {
    frame[0] = Rgb::new(0xff, 0, 0);
    frame[1] = Rgb::new(0xff, 0, 0);
    frame[cols - 1] = Rgb::new(0, 0xff, 0);
    frame[rows * cols - 1] = Rgb::new(0, 0, 0xff);
  }
}
