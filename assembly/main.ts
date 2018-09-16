import "allocator/arena";

const arr: i32[] = [3, 2, 1];

export function sortTest(): i32 {
  arr.sort()
  return arr[0];
}
