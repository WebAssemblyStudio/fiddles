static mut module_instance: *mut ArcModule = 0 as *mut ArcModule;

mod color;
mod arc_module;
mod utils;
mod rd;

use color::Rgb;
use arc_module::ArcModule;
use rd::RD;

pub use utils::init;
pub use utils::getAnimationBuffer;

fn cols() -> usize {
    ArcModule::get_instance().cols
}

fn rows() -> usize {
    ArcModule::get_instance().rows
}

fn frames() -> usize {
    ArcModule::get_instance().frame_count
}

fn pos(x: usize, y: usize) -> usize {
    //y * cols() + x
    x * cols() + y
}

fn clear(buf: &mut [Rgb], color: Rgb) {
    for c in buf {
        *c = color;
    }
}

// feed = 0.0220, kill = 0.0590 // pulse?
// feed = 0.055, kill = 0.062 // maze?
// chaos_waves = {feed = 0.0220, kill = 0.0490}
const FEED: f32 = 0.0220;
const KILL: f32 = 0.0590;
const DU: f32 = 1.0 * 0.25;
const DV: f32 = 0.5 * 0.25; 

  // local b_u, b_v = 1.0, 0.0
  // local p_u, p_v = 0.8, 0.6

fn copy_frame(buf: &mut [Rgb], idx_src: usize, idx_dest: usize) {
  let r = rows();
  let c = cols();
  let ds = r*c;
  for p in 0..(ds) {
    buf[idx_dest*ds + p] = buf[idx_src*ds + p]; 
  }
}

#[no_mangle]
pub extern fn apply() {
    let mut module = ArcModule::get_instance();
    let cols = module.rows;
    let rows = module.cols;
    let ref mut animation = module.get_animation().as_mut_slice();
    clear(animation, Rgb::new(255, 255, 255));
    let mut reaction = RD::new(rows*1, cols*1, FEED, KILL, DU, DV);
    reaction.init_point(0.0, 1.0, 1.0, 0.0);
    let framecount = frames();
    for (index, frame) in animation.chunks_mut(rows * cols).enumerate() {
      if index <= framecount / 2 {
        for y in 0..rows {
          for x in 0..cols {
            let fu = reaction.u.get((x as i32) * 2, (y as i32) * 2);
            let fv = reaction.v.get((x as i32) * 2, (y as i32) * 2);
            let inv_v = 1.0 - fv;
            let v = ((1.0 - (inv_v * inv_v)) * 255.0) as u8;
            let u = (fu * fu * 255.0) as u8;
            frame[x*rows + y] = Rgb::new(v, 0, u/4 + v/2);
            //frame[y*cols + x] = Rgb::new(255, 0, 0);
          }
        } 
        for _ in 0..6 {
          reaction.step(0.9);
        }
      }
    }
    // why do I need to do this, the borrows should obviously end
    // before this point
    let mut module = ArcModule::get_instance();
    let ref mut animation = module.get_animation().as_mut_slice();
    for index in (framecount/2)..framecount {
      copy_frame(animation, framecount - index, index);
    }
}