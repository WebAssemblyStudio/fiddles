export function test(b: bool): void {
  for (let i = 0; i < 10; i++) {
    if (b) {
      if (i % 4 == 3) {
        continue;
      }
    }
  }
}