export function conv(x: f64): u32 {
  if (x != x) return 0;
  else if (x >= 4294967295.0) return <u32>4294967295;
  else if (x <= 0) return <u32>0;
  else return <u32>x;
}

export function conv2(x: f64): u32 {
  return <u32>min(max(x, 0), 4294967295);
}

export function conv3(x: f64): u32 {
  var t = x + 4294967295 - abs(x - 4294967295);
  // return (t + (2.0 * 0) + abs(t-(2.0 * 0))) * 0.25;
  return <u32>((t + abs(t)) * 0.25);
}

export function bench(): u32 {
  var acc: u32 = 0;
  for (let f = -10000000.0; f < 10000000.0; f += 1.0) {
    acc += conv(f);
  }
  return acc;
}

export function bench2(): u32 {
  var acc: u32 = 0;
  for (let f = -10000000.0; f < 10000000.0; f += 1.0) {
    acc += conv2(f);
  }
  return acc;
}

export function bench3(): u32 {
  var acc: u32 = 0;
  for (let f = -10000000.0; f < 10000000.0; f += 1.0) {
    acc += conv3(f);
  }
  return acc;
}

