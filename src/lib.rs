extern crate wasm_bindgen;
use wasm_bindgen::prelude::*;

mod ext;

mod random;

#[wasm_bindgen]
extern {
    #[wasm_bindgen(js_namespace = Math)]
    fn random() -> f64;

    #[wasm_bindgen(js_namespace = console)]
    fn log(a: &str);
}

macro_rules! println {
    ($($t:tt)*) => (log(&format_args!($($t)*).to_string()))
}

const MAX_SIZE: usize = 640000;

#[repr(u8)]
#[derive(Clone, Copy, Debug, PartialEq, Eq)]
pub enum Tile {
    Closed = 0,
    Open = 1,
}

#[wasm_bindgen]
pub struct Grid {
    tiles: Box<[Tile; MAX_SIZE]>,
    data: Box<[u8; MAX_SIZE]>
}

/// Public methods, exported to JavaScript.
#[wasm_bindgen]
impl Grid {
    pub fn new() -> Grid {
        let mut tiles = Box::new([Tile::Closed; MAX_SIZE]);
        let mut data = Box::new([0_u8; MAX_SIZE]);

        let mut rand_gen = random::SeedableRandom::new();
        rand_gen.seed(123456);
        
        for (i, slot) in tiles.iter_mut().enumerate() {
            *slot = if i % 2 == 0 || i % 7 == 0 {
                Tile::Open
            } else {
                Tile::Closed
            };

            data[i] = rand_gen.next_int(0, 255) as u8;
        }

        Grid {
            tiles,
            data
        }
    }

    pub fn tiles(&self) -> *const Tile {
        self.tiles.as_ptr()
    }

    pub fn data(&self) -> *const u8 {
        self.data.as_ptr()
    }
}

#[wasm_bindgen]
pub fn get_max_size() -> usize {
  return MAX_SIZE;
}