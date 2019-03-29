declare function externallyDeclaredPassThrough(input:i32): i32;

export function add(x: i32, y: i32): i32 {
  const z:i32 = externallyDeclaredPassThrough(y);
  return x + z;
}
