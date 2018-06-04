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


fn iter(x: usize, y: usize, r: usize, dirX: i8, dirY: i8) -> (usize, usize, usize, usize) {
  let (_x, _dirX) = if x + dirX < r { (_x + 1, 1i8) } else { (_x - 1, -1i8) };
  let (_y, _dirY) = if y + dirY < r { (_y + 1, 1i8) } else { (_y - 1, -1i8) };
  (_x as usize, _y as usize, _dirX, _dirY)
}

// We'll modify this apply function to create our animation.

#[no_mangle]
pub extern "C" fn apply() {

    // To create our animation we'll first create a module. We'll
    // mutate this to create our animation.
    let mut module = ArcModule::get_instance();

    // There are 44 rows
    let rows = module.rows;

    // There are 36 columns
    let cols = module.cols;

    // This is our animation.
    let mut x = 20usize;
    let mut y = 20usize;
    let mut dirX = 1i8;
    let mut dirY = 1i8;
    let r = 5usize;

    let animation = module.get_animation().as_mut_slice();
    for (index, frame) in animation.chunks_mut(rows * cols).enumerate() {
        let (x, y, dirX, dirY) = iter(x, y, r, dirX, dirY);
        for row in 0..rows {
            for col in 0..cols {
                let diffX = ((row as f64) - (x as f64)) as f64;
                let diffY = ((col as f64) - (y as f64)) as f64;
                if (diffX.powi(2) + diffY.powi(2)).sqrt() < (r as f64) {
                  frame[row * cols + col] = Rgb::new(255u8, 220u8, 0u8);
                } else {
                  frame[row * cols + col] = Rgb::new(0u8, 0u8, 0u8);
                }
            }
        }
    }
}
