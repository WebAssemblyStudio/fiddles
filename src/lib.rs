#![feature(proc_macro, wasm_custom_section, wasm_import_module)]

extern crate wasm_bindgen;

use std::iter;
use std::mem;

use wasm_bindgen::prelude::*;

#[wasm_bindgen]
extern {
    #[wasm_bindgen(js_namespace = Math)]
    fn random() -> f64;
}

#[repr(u8)]
#[derive(Clone, Copy, Debug, PartialEq, Eq)]
pub enum Cell {
    Dead = 0,
    Alive = 1,
}

impl Cell {
    fn toggle(&mut self) {
        *self = match *self {
            Cell::Dead => Cell::Alive,
            Cell::Alive => Cell::Dead,
        };
    }
}

const WIDTH: u32 = 64;
const HEIGHT: u32 = 64;

#[wasm_bindgen]
pub struct Universe {
    cells: Box<[Cell; (WIDTH * HEIGHT) as usize]>,
    next: Box<[Cell; (WIDTH * HEIGHT) as usize]>,
    alive: Box<[u8; (WIDTH * HEIGHT) as usize]>,
}

/// Public methods, exported to JavaScript.
#[wasm_bindgen]
impl Universe {
    pub fn new() -> Universe {
        let mut cells = Box::new([Cell::Alive; (WIDTH * HEIGHT) as usize]);
        let next = Box::new([Cell::Alive; (WIDTH * HEIGHT) as usize]);

        for (i, slot) in cells.iter_mut().enumerate() {
            *slot = if i % 2 == 0 || i % 7 == 0 {
                Cell::Alive
            } else {
                Cell::Dead
            };
        }

        Universe {
            next,
            cells,
            alive: Box::new([0; (WIDTH * HEIGHT) as usize]),
        }
    }

    pub fn width(&self) -> u32 {
        WIDTH
    }

    pub fn height(&self) -> u32 {
        HEIGHT
    }

    pub fn cells(&self) -> *const Cell {
        self.cells.as_ptr()
    }

    pub fn tick(&mut self) {
        self.update_alive();

        for idx in 0..self.cells.len() {
            let cell = self.cells[idx];
            // let live_neighbors = self.live_neighbor_count(row, col);
            let live_neighbors = self.alive[idx];

            let next_cell = match (cell, live_neighbors) {
                // Rule 1: Any live cell with fewer than two live neighbours
                // dies, as if caused by underpopulation.
                (Cell::Alive, x) if x < 2 => Cell::Dead,
                // Rule 2: Any live cell with two or three live neighbours
                // lives on to the next generation.
                (Cell::Alive, 2) | (Cell::Alive, 3) => Cell::Alive,
                // Rule 3: Any live cell with more than three live
                // neighbours dies, as if by overpopulation.
                (Cell::Alive, x) if x > 3 => Cell::Dead,
                // Rule 4: Any dead cell with exactly three live neighbours
                // becomes a live cell, as if by reproduction.
                (Cell::Dead, 3) => Cell::Alive,
                // All other cells remain in the same state.
                (otherwise, _) => otherwise,
            };

            self.next[idx] = next_cell;
        }

        mem::swap(&mut self.next, &mut self.cells)
    }

    fn update_alive(&mut self) {
        for i in self.alive.iter_mut() {
            *i = 0;
        }

        // NB: this is super funky but it gets LLVM to avoid bounds checks 100%
        // of the time.

        macro_rules! i {
            ($a:expr, $b:expr) => {
                ($a as usize) * (HEIGHT as usize) + ($b as usize)
            }
        }

        let zero = 0;
        let one = 1;
        let width = WIDTH as usize;
        let height = HEIGHT as usize;
        let width_minus_one = width - 1;
        macro_rules! update {
            (@cell $r:ident $ri:ident $c:ident $n:ident $e:ident $s:ident $w:ident) => ({
                if let Cell::Alive = self.cells[i!($ri, $c)] {
                    $n[$w] += 1;
                    $n[$c] += 1;
                    $n[$e] += 1;
                    $r[$w] += 1;
                    $r[$e] += 1;
                    $s[$w] += 1;
                    $s[$c] += 1;
                    $s[$e] += 1;
                }
            });

            (@row $r:ident $ri:ident $n:ident $s:ident) => ({
                update!(@cell $r $ri zero $n one $s width_minus_one);
                for i in 0..(width - 2) {
                    let w = i;
                    let e = i + 2;
                    let c = i + 1;
                    update!(@cell $r $ri c $n e $s w);
                }
                let width_minus_two = width - 2;
                update!(@cell $r $ri width_minus_one $n zero $s width_minus_two);
            })
        }
        let height_minus_one = height - 1;
        {
            let (r, rest) = self.alive.split_at_mut(width);
            let (s, rest) = rest.split_at_mut(width);
            let (_rest, n) = rest.split_at_mut(width * height - 3 * width);
            assert_eq!(n.len(), width);
            update!(@row r zero n s);
        }
        for i in 0..(height - 2) {
            let (rest, s) = self.alive.split_at_mut((i + 2) * width);
            let (s, _) = s.split_at_mut(width);
            let (rest, r) = rest.split_at_mut((i + 1) * width);
            let (_rest, n) = rest.split_at_mut(i * width);
            let ri = i + 1;
            update!(@row r ri n s);
        }
        {
            let (s, rest) = self.alive.split_at_mut(width);
            let (_x, rest) = rest.split_at_mut(width * height - 3 * width);
            let (n, r) = rest.split_at_mut(width);
            update!(@row r height_minus_one n s);
        }
    }

    pub fn toggle_cell(&mut self, row: u32, column: u32) {
        let idx = self.get_index(row, column);
        if let Some(cell) = self.cells.get_mut(idx) {
            cell.toggle();
        }
    }

    pub fn clear(&mut self) {
        for slot in self.cells.iter_mut() {
            *slot = Cell::Dead;
        }
    }

    pub fn randomize(&mut self) {
        let bits = iter::repeat(())
            .map(|()| (random() * ((1u64 << 32) as f64)).to_bits())
            .flat_map(|i| (0..32).map(move |j| (i & (1 << j)) != 0))
            .map(|b| if b { Cell::Dead } else { Cell::Alive });
        for (slot, value) in self.cells.iter_mut().zip(bits) {
            *slot = value;
        }
    }

    pub fn add_glider(&mut self, r: u32, c: u32) {
        let x = [
            (r, c),
            (r, c + 1),
            (r, c + 2),
            (r, c + 3),
            (r, c + 4),
            (r, c + 5),
            (r + 1, c),
            (r + 1, c + 1),
            (r + 1, c + 2),
            (r + 1, c + 3),
            (r + 1, c + 4),
        ];
        for (r, c) in x.iter().cloned() {
            let i = self.get_index(r % HEIGHT, c % WIDTH);
            self.cells[i] = Cell::Alive;
        }
    }

    fn get_index(&self, row: u32, column: u32) -> usize {
        (row * WIDTH + column) as usize
    }
}
