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
        for y in 0..rows {
          for x in 0..cols {
            let pixel = x as f32 / cols as f32;
            let complex_mul = |(a,b),(c,d)| ((a*b-b*d),(a*c+b*d))
            let complex_abs = |(a,b)| (a*a+b*b).sqrt()

            let mut z = (x,y);
            let mut its = 0;
            for _ in 0..100 {
              its += 1;
              z = complex_mul(z,z);
              if complex_abs(z) > 2 {
                break
              }
            }
            let pixel = its as f32/100.0;
          
            frame[x+y*cols] = Rgb::new((255.0*pixel) as u8, 0, 0);
          }
        }
    }
}
