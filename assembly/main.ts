declare function log(s: f64): void;

export function add(arg1: number, arg2: number): number {

  let r1 = arg1.toString().split(".")[1].length;
  let r2 = arg2.toString().split(".")[1].length;
  let m = Math.pow(10, Math.max(r1, r2));

  return (mul(arg1, m) + mul(arg2, m)) / m;
}

function mul(arg1: f64, arg2: f64): f64 {
  let s1 = arg1.toString();
  let s2 = arg2.toString();
  
  let t1 = s1.split(".")[1].length;
  let t2 = s2.split(".")[1].length;

  let r1 = Number.parseInt(s1.toString().replace(".", ""), 10);
  let r2 = Number.parseInt(s2.toString().replace(".", ""), 10);
  return r1 * r2 / Math.pow(10, t1 + t2);
}