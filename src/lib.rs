#![feature(proc_macro, wasm_custom_section, wasm_import_module)]
extern crate wasm_bindgen;
use wasm_bindgen::prelude::*;

#[wasm_bindgen]
pub fn viewsFormatter(views: usize) -> String{
  let mut returnVal = String::new();

  if views < 1000 {
    returnVal =  views.to_string();
  }else if views < 1000000 && views > 999 {
    let a = (views / 1000) as i64;
    returnVal = a.to_string() + "K";
  }else if views < 1000000000 && views > 999999 {
    let a = (views / 1000000) as i64;
    returnVal = a.to_string() + "M";
  }else if views < 1000000000000 && views > 999999999 {
    let a = (views / 1000000000) as i64;
    returnVal = a.to_string() + "B";
  }else{
    returnVal = "".to_string();
  }
  return returnVal;
}

#[wasm_bindgen]
pub fn getTime(x: &str) -> i32{
  let string = x.replace(" ", "");

  if string.len() == 0 {
    return 0;
  }

  let split = string.split(":");
  let vector: Vec<&str> = split.collect();
  let vectorLen: usize = vector.len();
  let mut returnVal: i32 = 0;

  if vectorLen == 1 {
    returnVal = vector[0].parse().unwrap();
  }else if vectorLen == 2 {
    let a: i32 = vector[0].parse().unwrap();
    let b: i32 = vector[1].parse().unwrap();
    returnVal = (a * 60) + b;
  }else if vectorLen == 3 {
    let a: i32 = vector[0].parse().unwrap();
    let b: i32 = vector[1].parse().unwrap();
    let c: i32 = vector[2].parse().unwrap();
    returnVal = (a * 60 * 60) + (b * 60) + b;
  }
  return returnVal;
}
