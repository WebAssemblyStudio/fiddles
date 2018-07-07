#![feature(proc_macro, wasm_custom_section, wasm_import_module, js_globals)]

extern crate wasm_bindgen;
use wasm_bindgen::prelude::*;

use std::ops::Add;

#[derive(Clone, Copy, Debug)]
pub struct Complex {
  pub real: f64,
  pub imaginary: f64,
}

impl Complex {
  pub fn square(self) -> Complex {
    let real = (self.real * self.real) - (self.imaginary * self.imaginary);
    let imaginary = 2.0 * self.real * self.imaginary;
    Complex { real, imaginary }
  }

  pub fn norm(&self) -> f64 {
    (self.real * self.real) + (self.imaginary * self.imaginary)
  }
}

impl Add<Complex> for Complex {
  type Output = Complex;

  fn add(self, rhs: Complex) -> Complex {
    Complex { real: self.real + rhs.real, imaginary: self.imaginary + rhs.imaginary }
  }
}

fn f(z: Complex, c: Complex) -> Complex {
  z.square() + c
}

fn magic(z: Complex, c: Complex) -> u32 {
  let mut iter_index: u32 = 0;
  let mut z = z;
  while iter_index < 900 {
    if z.norm() > 2.0 {
      break
    }
    z = f(z, c);
    iter_index += 1;
  }
  iter_index
}

pub fn get_julia_set(width: u32, height: u32, c: Complex) -> Vec<u8> {
  let mut data: Vec<u8> = vec![];
    
  let param_i = 1.5;
  let param_r = 1.5;
  let scale = 0.005;

  for x in 0..width {
    for y in 0..height {
      let z = Complex { real: y as f64 * scale - param_r, imaginary: x as f64 * scale - param_i };
      let iter_index = magic(z, c);
      data.push((iter_index / 4) as u8);
      data.push((iter_index / 2) as u8);
      data.push(iter_index as u8);
      data.push(255);
    }
  }

  data
}

#[wasm_bindgen]
extern "C" {
    pub type ImageData;

    #[wasm_bindgen(constructor)]
    pub fn new(arr: &Uint8ClampedArray, width: u32, height: u32) -> ImageData;
}

#[wasm_bindgen]
extern "C" {
    pub type Uint8ClampedArray;

    #[wasm_bindgen(constructor)]
    pub fn new(arr: &[u8]) -> Uint8ClampedArray;
}

#[wasm_bindgen]
extern "C" {
    pub type CanvasRenderingContext2D;

    #[wasm_bindgen(method, js_name = putImageData)]
    pub fn put_image_data(this: &CanvasRenderingContext2D, image_data: &ImageData, _1: i32, p_2: i32);
}

#[wasm_bindgen]
pub fn draw(ctx: &CanvasRenderingContext2D, width: u32, height: u32, real: f64, imaginary: f64) {
    let c = Complex { real, imaginary };
    let data = get_julia_set(width, height, c);
    let uint8_array = Uint8ClampedArray::new(&data);

    ctx.put_image_data(&ImageData::new(&uint8_array, width, height), 0, 0);
}
