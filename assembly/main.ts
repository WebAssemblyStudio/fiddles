

export function testSin(): f64 {
  let acc = 0.0;
  for (let i = 0; i < 10000; i++) {
    acc += Math.sin(i * (0.125 / Math.PI));
  }
  return acc;
}

export function testSinf32(): f32 {
  let acc: f32 = 0.0;
  for (let i = 0; i < 10000; i++) {
    acc += Mathf.sin(<f32>(i * (0.125 / Math.PI)));
  }
  return acc;
}
