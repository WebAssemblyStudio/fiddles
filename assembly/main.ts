import "allocator/arena";

var output: string = "Hello World!";

export function add(): string {
  return output;
}

export function reset(): void {
  memory.reset();
}
