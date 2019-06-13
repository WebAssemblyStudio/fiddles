declare function log(f: f64): void;

export function test(): f64 {
  let t = new Int64Array(31 + 1);
  for (let i = 0; i < 16; ++i) {
    for (let j = 0; j < 16; ++j) {
      t[i + j] += 10;
    }
  }
  return <f64>(t[0] + t[31]);
}

log(test())
log(test())