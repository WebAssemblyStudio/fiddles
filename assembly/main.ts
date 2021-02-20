
export function distance(x1: f64, y1: f64, x2: f64, y2: f64): f64 {
  let dx = x1 - x2;
  let dy = y1 - y2;
  return Math.sqrt(dx * dx + dy * dy);
}