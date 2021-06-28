

const arr100K = new Array<f64>(100_000);
const arr10M  = new Array<f64>(10_000_000);

export function randomize(): void {
  for (let i = 0, len = arr100K.length; i < len; i++) {
    arr100K[i] = Math.random();
  }

  for (let i = 0, len = arr10M.length; i < len; i++) {
    arr10M[i] = Math.random();
  }
}

export function testASSort100K(): void {
  arr100K.sort((a, b) => i32(a > b) - i32(a < b));
}

export function testASSort10M(): void {
  arr10M.sort((a, b) => i32(a > b) - i32(a < b));
}
