export function fibonacci(sequenceFor: i32): i32 {
  if (sequenceFor <= 1) return 1;
  return fibonacci(sequenceFor - 1) + fibonacci(sequenceFor - 2);
}
