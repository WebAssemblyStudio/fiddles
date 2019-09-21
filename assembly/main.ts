

export function testSin(): f64 {
  let acc = 0.0;
  for (let i = 0; i < 100000000; i++) {
    acc += Math.sin(i * (0.125 / Math.PI));
  }
  return acc;
}
