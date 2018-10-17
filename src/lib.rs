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
    clear(animation, Rgb::new(255, 255, 255));
    let x = 2;
    let y = 5;
    let square = (x, y, 30, 30);
    let heart = (x+2, y+12, 17, 17);
    let mut heart_color = Rgb::new(255, 255, 255);
    for (index, frame) in animation.chunks_mut(rows * cols).enumerate() {
        for y in (square.1)..(square.1+square.3) {
            for x in (square.0)..(square.0+square.2) {
              frame[pos(x,y)] =  Rgb::new(237, 64, 64);
            }
        }
        // Dots around square
        frame[pos(square.0, square.1)] = Rgb::new(100, 100, 100);
        frame[pos(square.0, square.1+square.3-1)] = Rgb::new(255, 255, 255);
        frame[pos(square.0+square.2-1, square.1)] = Rgb::new(255, 255, 255);
        frame[pos(square.0+square.2-1, square.1+square.3-1)] = Rgb::new(255, 255, 255);

        //Seahorse, hopefully
        frame[(pos(heart.0, heart.1)] = Rgb::new(237, 64, 64);


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
