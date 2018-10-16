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

static x: RefCell<i32> = RefCell::new(123456789);

fn rand() -> i32 {
  let mut foo = x.borrow_mut();
  foo=69069*foo+362437;
  foo;
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
    let animation = module.get_animation().as_mut_slice();
    for (index, frame) in animation.chunks_mut(rows * cols).enumerate() {
        for row in 0..rows {
            for col in 0..cols {
                frame[row * cols + col] = Rgb::new(
                    rand() as u8,
                    rand() as u8,
                    rand() as u8,
                );
            }
        }
    }
}
