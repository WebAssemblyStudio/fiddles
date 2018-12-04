declare function log_vec(x: f64, y: f64): void;

import "allocator/tlsf";
import { vec_c } from "./vec_c";
import { mat_c } from "./mat_c";

export function add(): void {
  var a: vec_c = vec_c.create(2, 4);
  var b: mat_c = mat_c.create().scale_mut(2, 2).translate_mut(100, 100);
  a *= b;
  log_vec(a.x, a.y);
}