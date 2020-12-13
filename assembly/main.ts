





import { MapNew } from "./MapNew";


let map1: Map<string, i32>;
let map2: MapNew<string, i32>;

export function init(): void {
  map1 = new Map();
  for (let i = 0; i < 2000000; i++) {
    map1.set((i & 63).toString(), i);
  }

  map2 = new MapNew();
  for (let i = 0; i < 2000000; i++) {
    map2.set((i & 63).toString(), i);
  }
}

export function benchOriginalMapLookup(): i32 {
  let acc = 0;
  for (let i = 2000000 - 1; i >= 0; i--) {
    acc ^= i32(map1.has(i.toString()));
  }
  return acc;
}

export function benchNewMapLookup(): i32 {
  let acc = 0;
  for (let i = 2000000 - 1; i >= 0; i--) {
    acc ^= i32(map2.has(i.toString()));
  }
  return acc;
}