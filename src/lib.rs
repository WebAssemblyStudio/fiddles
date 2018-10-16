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
              frame[pos(x,y)] =  Rgb::new(0xe1, 0x00, 0x79);
            }
        }
        let complex_mul = |(a,b),(c, d)| ((a*c-b*d),(a*d+b*c));
        let complex_abs = |(a,b)| (a*a)+(b*b);
        for y in 0..rows {
          for x in 0..cols {
            println!("----------------------")
            println!("hello friends");
            let mut pixel = 1.0;
            let z = (x as f32/cols as f32,y as f32 / rows as f32);
            pixel -= 0.1;
            if complex_abs(z) < 2.0 {
              println!("hello friends")
              let z2 = complex_mul(z, z);
              pixel -= 0.1;
              if complex_abs(z) < 2.0 {
                println!("hello friends")
                let z3 = complex_mul(z2, z2);
                pixel -= 0.1;
              }
            }
            
            frame[pos(x, y)] = Rgb::new((255.0 * pixel) as u8, (255.0 * pixel) as u8, (255.0 * pixel ) as u8);
            
          }
        }
    }
}
