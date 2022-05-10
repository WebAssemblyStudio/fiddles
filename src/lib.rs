#![feature(proc_macro, wasm_custom_section, wasm_import_module)]
extern crate wasm_bindgen;
use wasm_bindgen::prelude::*;

#[wasm_bindgen]
extern {
  fn alert(s: &str);
}

#[derive(Copy, Clone, Eq, PartialEq, Ord, PartialOrd)]
#[repr(C)]
pub struct Pixel {
  r: u8,
  g: u8,
  b: u8,
  a: u8,
}

impl Pixel {
  pub fn new_rgb(r: u8, g: u8, b: u8) -> Pixel {
    Pixel {
      r, g, b,
      a: 255
    }
  }
}

#[derive(Copy, Clone, Eq, PartialEq, Ord, PartialOrd)]
pub struct Pos {
  x: usize,
  y: usize
}

impl Pos {
  pub fn new(x: usize, y: usize) -> Self {
    Pos { x, y }
  }

  pub fn advance(self, orientation: Orientation, width: usize, height: usize) -> Pos {
    match orientation {
      UP => Pos::new(self.x, if self.y == 0 { height - 1 } else { self.y - 1 }),
      DOWN => Pos::new(self.x, if self.y == height - 1 { 0 } else { self.y + 1 }),
      LEFT => Pos::new(if self.x == 0 { width - 1 } else { self.x - 1}, self.y),
      RIGHT => Pos::new(if self.x == width - 1 { 0 } else { self.x + 1}, self.y),
    }
  }
}

#[derive(Copy, Clone, Eq, PartialEq, Ord, PartialOrd)]
pub enum Orientation {
  UP, LEFT, DOWN, RIGHT
}
use Orientation::*;

impl Orientation {
  pub fn to_u8(self) -> u8 {
    match self {
      UP => 0,
      LEFT => 1,
      DOWN => 2,
      RIGHT => 3
    }
  }
  pub fn from_u8(v: u8) -> Self {
    match v {
      0 => UP,
      1 => LEFT,
      2 => DOWN,
      3 => RIGHT,
      _ => panic!("Invalid orientation")
    }
  }

  pub fn rotate_cw(self) -> Self {
    match self {
      UP => RIGHT,
      LEFT => UP,
      DOWN => LEFT,
      RIGHT => DOWN
    }
  }
  pub fn rotate_ccw(self) -> Self {
    match self {
      UP => LEFT,
      LEFT => DOWN,
      DOWN => RIGHT,
      RIGHT => UP
    }
  }
}

#[derive(Copy, Clone, Eq, PartialEq, Ord, PartialOrd)]
pub enum Color {
  White,
  Red,
  Green,
  Blue,
}
use Color::*;

impl Color {
  pub fn to_u8(self) -> u8 {
    match self {
      Red => 0,
      Green => 1,
      Blue => 2,
      White => 255,
    }
  }
  pub fn from_u8(v: u8) -> Self {
    match v {
      0 => Red,
      1 => Green,
      2 => Blue,
      _ => White,
    }
  }

  pub fn to_pixel(self) -> Pixel {
    match self {
      White => Pixel::new_rgb(255, 255, 255),
      Red => Pixel::new_rgb(255, 0, 0),
      Green => Pixel::new_rgb(0, 255, 0),
      Blue => Pixel::new_rgb(0, 0, 255),
    }
  }
}

#[derive(Copy, Clone, Eq, PartialEq, Ord, PartialOrd)]
pub struct Ant {
  pos: Pos,
  orientation: Orientation,
  color: Color,
}

pub struct State {
  width: usize,
  height: usize,

  image: Vec<Pixel>,
  board: Vec<Color>,
  ants: Vec<Ant>,
}

impl State {
  pub fn new(width: usize, height: usize) -> State {
    let mut image = Vec::new();
    image.resize(width*height, White.to_pixel());

    let mut board = Vec::new();
    board.resize(width*height, White);

    let ants = Vec::new();

    State {
      width,
      height,

      image,
      board,
      ants,
    }
  }

  pub fn gen_img(&mut self) {
    for i in 0..self.board.len() {
      self.image[i] = self.board[i].to_pixel();
    }
  }

  pub fn tick(&mut self) {
    let width = self.width;
    let height = self.height;

    for ant in self.ants.iter_mut() {
      let currval = self.board[Self::offset(ant.pos, width)];
      if currval == ant.color {
        ant.orientation = ant.orientation.rotate_ccw();
        self.board[Self::offset(ant.pos, width)] = White;
      } else {
        ant.orientation = ant.orientation.rotate_cw();
        self.board[Self::offset(ant.pos, width)] = ant.color;
      }
      ant.pos = ant.pos.advance(ant.orientation, width, height);
    }
  }

  pub fn add_ant(&mut self, ant: Ant) {
    self.ants.push(ant)
  }

  fn offset(pos: Pos, width: usize) -> usize {
    pos.x + pos.y * width
  }
}

static mut state: Option<State> = None;

#[wasm_bindgen]
pub fn init(width: usize, height: usize) {
  unsafe {
    state = Some(State::new(width, height))
  }
}

#[wasm_bindgen]
pub fn get_img_addr() -> usize {
  (unsafe { state.as_ref().unwrap() }).image.as_ptr() as usize
}

#[wasm_bindgen]
pub fn get_img_len() -> usize {
  (unsafe { state.as_ref().unwrap() }).image.len() * 4
}

#[wasm_bindgen]
pub fn gen_img() {
  (unsafe { state.as_mut().unwrap() }).gen_img()
}

#[wasm_bindgen]
pub fn tick() {
  (unsafe { state.as_mut().unwrap() }).tick()
}

#[wasm_bindgen]
pub fn add_ant(x: usize, y: usize, orientation: u8, color: u8) {
  (unsafe { state.as_mut().unwrap() }).add_ant(Ant {
    pos: Pos {
      x, y
    },
    orientation: Orientation::from_u8(orientation),
    color: Color::from_u8(color)
  })
}
