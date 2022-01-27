// Current prelude for using `wasm_bindgen`, and this'll get smaller over time!
#![feature(proc_macro, wasm_custom_section, wasm_import_module)]
extern crate wasm_bindgen;
use wasm_bindgen::prelude::*;

// Here we're importing the `alert` function from the browser, using
// `#[wasm_bindgen]` to generate correct wrappers.
#[wasm_bindgen]
extern {
    fn alert(s: &str);
}

// Here we're exporting a function called `greet` which will display a greeting
// for `name` through a dialog.


#[wasm_bindgen]
pub struct screen_vec { 
  pixel_set : Vec<Vec<f32>>,
  return_array : Vec<bool>,
}

impl screen_vec {
  pub fn new() -> screen_vec {
    let pixel_set = Vec::<Vec<f32>>::new();
    let return_array = Vec::<bool>::new();
    screen_vec {
      pixel_set,
      return_array,
    }
  }
  pub fn new_pixel_set(&mut self, width : i32, height : i32, scale : f32) {
    self.pixel_set = Vec::<Vec<f32>>::new();
    for x in -width/2..width/2 {
        for y in -height/2..height/2 {
            let scaled_x = (x as f32)/scale;
            let scaled_y = (y as f32)/scale;
            self.pixel_set.push(vec![scaled_x, scaled_y]);
        }
    }
  }

  pub fn mandelbrot(&mut self, max_iter : i32) {
    let mut return_array : Vec<bool> = Vec::new();
    for i in &self.pixel_set {
        let mut x = i[0];
        let mut y = i[1];
        let mut x2 = 0.0;
        let mut y2 = 0.0;
        let mut counter = 0;
        while x2 + y2 <= 4.0 && counter < max_iter {
            y = 2_f32 * x * y + i[1];
            x = x2 - y2 + i[0];
            x2 = x * x;
            y2 = y * y;
            counter += 1;
        }
        if counter < max_iter {
            return_array.push(false);
        } else {
            return_array.push(true);
        }
    }
    self.return_array = return_array;
  }

  pub fn render(&self) -> String {
    self.to_string()
  }
}

use std::fmt;

impl fmt::Display for screen_vec {
  fn fmt(&self, f: &mut fmt::Formatter) -> fmt::Result {
    for line in self.return_array.chunks(100) {
      for pixel in line {
        let symbol = if *pixel { '◻' } else { '◼' };
        write!(f, "{}", pixel)?;
      }
      write!(f, "\n")?;
    }
    Ok(())
  }
}

