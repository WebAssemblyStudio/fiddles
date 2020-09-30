declare function log(s: f64): void;


export function test(arg1: number, arg2: number): void {
  log(arg1);

  if(isNaN(arg2)) {
    arg2 = 0;
  }
  
  log(arg2);
}

function mul(s1: string, s2: string): f64 {

  let len1 = s1.length - (s1.indexOf(".") + 1);
  let len2 = s2.length - (s2.indexOf(".") + 1);

  let r1 = Number.parseInt(s1.replace(".", ""), 10);
  let r2 = Number.parseInt(s2.replace(".", ""), 10);

  return r1 * r2 / Math.pow(10, len1 + len2);
}

export function multiply(arg1: f64, arg2: f64): f64 {
  let s1 = arg1.toString();
  let s2 = arg2.toString();
  return mul(s1, s2);
}

export function add(arg1: number, arg2: number): number {
  let s1 = arg1.toString();
  let s2 = arg2.toString();

  let len1 = s1.length - (s1.indexOf(".") + 1);
  let len2 = s2.length - (s2.indexOf(".") + 1);

  let m = Math.pow(10, Math.max(len1, len2));
  return (multiply(arg1, m) + multiply(arg2, m)) / m;
}

export function subtract(arg1: number, arg2: number): number {
  let s1 = arg1.toString();
  let s2 = arg2.toString();

  let len1 = s1.length - (s1.indexOf(".") + 1);
  let len2 = s2.length - (s2.indexOf(".") + 1);

  let m = Math.pow(10, Math.max(len1, len2));
  return (multiply(arg1, m) - multiply(arg2, m)) / m;
}


export function divide(arg1: number, arg2: number): number {
  let s1 = arg1.toString();
  let s2 = arg2.toString();

  let len1 = s1.length - (s1.indexOf(".") + 1);
  let len2 = s2.length - (s2.indexOf(".") + 1);

  let r1 = Number.parseInt(s1.replace(".", ""), 10);
  let r2 = Number.parseInt(s2.replace(".", ""), 10);
  return multiply((r1 / r2), Math.pow(10, len2 - len1));
}

