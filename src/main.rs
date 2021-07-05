

#![feature(const_vec_new)]

static mut ARR_100K: Vec<f64> = Vec::new();
static mut ARR_10M: Vec<f64> = Vec::new();

// #[link(wasm_import_module = "env", name = "rand")]
extern { fn rand() -> f64; }

#[no_mangle]
pub extern "C" fn randomize() -> bool {
  unsafe {
    for _ in 0..100_000 {
      ARR_100K.push(rand());
    }

    for _ in 0..10_000_000 {
      ARR_10M.push(rand());
    }
  }
  true
}

#[no_mangle]
pub extern "C" fn bench_sort_100k() -> usize {
  unsafe {
    ARR_100K.sort_by(|a, b| a.partial_cmp(b).unwrap());
    ARR_100K.len()
  }
}

#[no_mangle]
pub extern "C" fn bench_sort_10M() -> usize {
  unsafe {
    ARR_10M.sort_by(|a, b| a.partial_cmp(b).unwrap());
    ARR_10M.len()
  }
}