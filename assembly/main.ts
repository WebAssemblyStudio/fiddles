
export function test(): void {
  for (let i = 0; i < 10; i++) {
    for (let j = 0; j < 10; j++) {
      if (i == j) continue;
    }
  }
}