use std::mem;

static LAPLACIAN_KERNEL: [f32; 9] = [ 0.25,  0.5,  0.25, 
                                      0.5, -3.0,  0.5,
                                      0.25,  0.5,  0.25];
/*
static LAPLACIAN_KERNEL: [f32; 9] = [ 0.0,  1.0,  0.0, 
                                      1.0, -4.0,  1.0,
                                      0.0,  1.0,  0.0];
*/

//#[derive(Copy)]
pub struct ChemBuff {
    pub rows: usize,
    pub cols: usize,
    pub buffer: Vec<f32>
}

impl ChemBuff {
    pub fn new(rows: usize, cols: usize) -> ChemBuff {
        ChemBuff {
          rows,
          cols,
          buffer: vec![0.0; rows*cols] //Vec::with_capacity(rows * cols)
        }
    }

    pub fn get(&mut self, x: i32, y: i32) -> f32 {
      let c = self.cols as i32;
      let r = self.rows as i32;
      // horrible hack to deal with rust % returning negative values
      let ix = (((x % c) + c) % c) as usize;
      let iy = (((y % r) + r) % r) as usize;
      self.buffer[iy*self.cols + ix]
    }

    pub fn lap(&mut self, x: i32, y: i32) -> f32 {
      let mut offset = 0;
      let mut accum: f32 = 0.0;
      for dy in -1..=1 {
        for dx in -1..=1 {
          accum += LAPLACIAN_KERNEL[offset] * self.get(x + dx, y + dy);
          offset += 1;
        }
      }
      accum
    }

    pub fn init_point(&mut self, fg: f32, bg: f32, seed: u32) {

      let mut rstate = seed;
      // 1664525	1013904223

      let cx = (self.rows / 2) as i32;
      let cy = (self.cols / 2) as i32;
      let mut p: usize = 0;
      let rad: i32 = 5;
      for y in 0..self.rows {
        for x in 0..self.cols {
          let dy = (y as i32) - cy;
          let dx = (x as i32) - cx;
          let rand = ((rstate as f64) / (<u32>::max_value() as f64)) as f32;
          //let m: f32 = 0.5 + 0.5 * rand;
          let mut v = 0.0;
          if dy.abs() < rad && dx.abs() < rad {
            v = fg + rand*0.1;
          } else {
            v = bg + rand*0.1;
          }
          if v < 0.0 {
            v = 0.0;
          }
          if v > 1.0 {
            v = 1.0;
          }
          self.buffer[p] = v;
          // well since we can't import crates I guess we'll just use the world's
          // worst LCG here
          rstate = ((rstate as u64) * 1664525 + 1013904223) as u32;
          p += 1;
        }
      }
    }
}

//#[derive(Copy)]
pub struct RD {
    pub rows: usize,
    pub cols: usize,
    pub feed: f32,
    pub kill: f32,
    pub du: f32,
    pub dv: f32,
    pub u: ChemBuff,
    pub v: ChemBuff
}

impl RD {
    pub fn new(rows: usize, cols: usize, feed: f32, kill: f32, du: f32, dv: f32) -> RD {
        RD {
          rows,
          cols,
          feed,
          kill,
          du,
          dv,
          u: ChemBuff::new(rows, cols),
          v: ChemBuff::new(rows, cols)
        }
    }

    pub fn init_point(&mut self, u_fg: f32, u_bg: f32, v_fg: f32, v_bg: f32) {
      self.v.init_point(v_fg, v_bg, 1723);
      self.u.init_point(u_fg, u_bg, 9000);
    }

    pub fn step(&mut self, dt: f32) {
      let mut uprime = ChemBuff::new(self.rows, self.cols);
      let mut vprime = ChemBuff::new(self.rows, self.cols);

      for y in 0..self.rows {
        for x in 0..self.cols {
          let u = self.u.get(x as i32, y as i32);
          let v = self.v.get(x as i32, y as i32);
          let uv2 = u * v * v;
          let d2u = self.du * self.u.lap(x as i32, y as i32);
          let d2v = self.dv * self.v.lap(x as i32, y as i32);
          let du_dt = d2u - uv2 + self.feed * (1.0 - u);
          let dv_dt = d2v + uv2 - (self.feed + self.kill) * v;
          uprime.buffer[y*self.cols + x] = u + du_dt * dt;
          vprime.buffer[y*self.cols + x] = v + dv_dt * dt;
          //uprime.buffer[y*self.cols + x] = 0.0;
          //vprime.buffer[y*self.cols + x] = 0.0;
        }
      }

      mem::swap(&mut self.u, &mut uprime);
      mem::swap(&mut self.v, &mut vprime);
    }
}