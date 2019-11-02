export function fastexp(x: f64): f64 {
  return (362880+x*(362880+x*(181440+x*(60480+x*(15120+x*(3024+x*(504+x*(72+x*(9+x)))))))))*2.75573192e-6;
}


export function exp(x: f64): f64 {
  return Math.exp(x);
}

