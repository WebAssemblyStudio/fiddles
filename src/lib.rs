static mut module_instance: *mut ArcModule = 0 as *mut ArcModule;

// `mod` is how Rust pulls in code from other files.
// They contain some boilerplate and helper code to 
// make it a bit easier for you to get up and running.
// You can take a look at them (they're in the sidebar)!
mod arc_module;
mod color;
mod utils;

use arc_module::ArcModule;
use color::Rgb;

pub use utils::getAnimationBuffer;
pub use utils::init;

// We'll modify this apply function to create our animation.

#[no_mangle]
pub extern "C" fn apply() {

    let data = [
      [0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,1,1,0,0,0,0,0,0,0,0],
      [0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,1,1,0,0,0,0,0,0,0,0],
      [0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,1,1,0,0,0,0,0,0,0,0],
      [0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,1,1,0,0,0,0,0,0,0,0,0],
      [0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,1,1,0,0,0,0,0,0,0,0,0],
      [1,1,1,0,1,1,1,0,1,1,0,0,0,0,0,1,1,1,1,0,0,0,0,1,1,1,1,1,1,0,0,1,1,0,0,0,0,1,1,0,0,0,1,1,0,0,0,1,1,1,1,0,0],
      [0,1,1,1,0,1,1,1,0,1,1,0,0,0,1,1,0,0,1,1,0,0,0,1,1,0,0,1,1,0,0,1,1,0,0,0,1,1,0,0,0,1,1,0,0,0,1,1,0,0,1,1,0],
      [0,1,1,0,0,1,1,0,0,1,1,0,0,1,1,0,0,0,0,1,1,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,1,1,0,0,0,1,1,0,0,0,0,0,0,0,1,1,0],
      [0,1,1,0,0,1,1,0,0,1,1,0,0,1,1,0,0,0,0,1,1,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,1,1,0,0,0,1,1,0,0,0,1,1,1,1,1,1,0],
      [0,1,1,0,0,1,1,0,0,1,1,0,0,1,1,0,0,0,0,1,1,0,0,0,1,1,0,0,0,0,0,0,0,0,0,1,1,0,0,0,1,1,0,0,0,1,1,0,0,0,1,1,0],
      [0,1,1,0,0,1,1,0,0,1,1,0,0,0,1,1,0,0,1,1,0,0,0,1,1,0,0,1,1,0,0,1,1,0,0,1,1,0,0,0,1,1,0,0,0,1,1,0,0,1,1,1,0],
      [1,1,1,1,0,1,1,1,0,1,1,1,0,0,0,1,1,1,1,0,0,0,0,1,1,1,1,1,1,0,0,1,1,0,0,1,1,0,0,0,1,1,0,0,0,0,1,1,1,1,0,1,1]
    ];
    let dw = 53;
    let dh = 12;

    // To create our animation we'll first create a module. We'll
    // mutate this to create our animation.
    let mut module = ArcModule::get_instance();

    // There are 44 rows
    let rows = module.rows;

    // There are 36 columns
    let cols = module.cols;

    // This is our animation.
    let animation = module.get_animation().as_mut_slice();
    for (index, frame) in animation.chunks_mut(rows * cols).enumerate() {
        for row in 0..rows {
            for col in 0..cols {
                frame[row * cols + col] = Rgb::new(
                  0, 0, 0
                );
                let x = (col + (index / 2)) % dw * 2;
                let y = row - 4;
                if x >= 0 && x < dw {
                  if y >= 0 && y < dh {
                    if data[y][x] == 1 {
                      frame[row * cols + col] = Rgb::new(
                          255, 255, 255
                      );
                    }
                  }
                }
            }
        }
    }
}
