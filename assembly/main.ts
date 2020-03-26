let a = [1, 2, 3, 4, 5, 6, 7, 8] as StaticArray<i32>;
let b = StaticArray.fromArray([1, 2, 3, 4, 5, 6, 7, 8]);

export function one(): i32 {
  return a.length;
}

export function two(): i32 {
  return b.length;
}
