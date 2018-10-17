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
use std::f64;


pub use utils::getAnimationBuffer;
pub use utils::init;


// We'll modify this apply function to create our animation.

#[no_mangle]
pub extern "C" fn apply() {

    fn fmod(n:f64, p:f64) -> f64 {
      let d = (n / p) as i64;
      n - ((d as f64) * n)
    }

    // It's like sine, but bad
    fn sine(n: f64, p: f64) -> f64 {
      let w:f64 = fmod(n, p);
      let q:f64 = p / 4.0;
      let w2:f64 = fmod(w, q);
      if w < q {
        return w2 / q;
      } else if w < q * 2.0 {
        return 1.0 - (w2 / q);
      } else if w < q * 3.0 {
        return 0.0 - (w2 / q);
      }
      (w2 / q) - 1.0
    }

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
                let x = col as i32 - 18;
                let y = row as i32 - 22;
                let mut r = fmod(row as f64, 3.5) * 60;
                // let mut g = ((col + index / 3) % 6) * 50;
                // let mut b = ((col + index / 4) % 6) * 50;
              
                frame[row * cols + col] = Rgb::new(
                    r as u8,
                    r as u8,
                    r as u8,
                );
            }
        }
    }
}
