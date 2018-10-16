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

fn cols() -> usize {
    ArcModule::get_instance().cols
}

fn rows() -> usize {
    ArcModule::get_instance().rows
}

fn pos(x: usize, y: usize) -> usize {
    x * cols() + y
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
    clear(animation, Rgb::new(0, 255, 255));
    for (index, frame) in animation.chunks_mut(rows * cols).enumerate() {
        let complex_mul = |(a,b),(c, d)| ((a*c-b*d),(a*d+b*c));
        let complex_abs = |(a,b)| (a*a)+(b*b);
        for y in 0..rows {
          for x in 0..cols {
            
            
            frame[pos(0,0)] = Rgb::new(255, 0, 0);
            
          }
        }
    }
}
