import { HASH } from "util/hash";

// @ts-ignore: decorator
@inline const FNV_OFFSET: u32 = 2166136261;

// @ts-ignore: decorator
@inline const FNV_PRIME: u32 = 16777619;

// @ts-ignore: decorator
@inline
function hash16(key: u32, seed: u32 = FNV_OFFSET): u32 {
  var v = seed;
  v = (v ^ ( key        & 0xff)) * FNV_PRIME;
  v = (v ^ ( key >>  8        )) * FNV_PRIME;
  return v;
}

// @ts-ignore: decorator
@inline
function hash32(key: u32, seed: u32 = FNV_OFFSET): u32 {
  var v = seed;
  v = (v ^ ( key        & 0xff)) * FNV_PRIME;
  v = (v ^ ((key >>  8) & 0xff)) * FNV_PRIME;
  v = (v ^ ((key >> 16) & 0xff)) * FNV_PRIME;
  v = (v ^ ( key >> 24        )) * FNV_PRIME;
  return v;
}

// @ts-ignore: decorator
@inline
function hash64(key: u64, seed: u32 = FNV_OFFSET): u32 {
  var l = <u32> key;
  var h = <u32>(key >>> 32);
  var v = seed;
  v = (v ^ ( l        & 0xff)) * FNV_PRIME;
  v = (v ^ ((l >>  8) & 0xff)) * FNV_PRIME;
  v = (v ^ ((l >> 16) & 0xff)) * FNV_PRIME;
  v = (v ^ ( l >> 24        )) * FNV_PRIME;
  v = (v ^ ( h        & 0xff)) * FNV_PRIME;
  v = (v ^ ((h >>  8) & 0xff)) * FNV_PRIME;
  v = (v ^ ((h >> 16) & 0xff)) * FNV_PRIME;
  v = (v ^ ( h >> 24        )) * FNV_PRIME;
  return v;
}


function hashStr(key: string, seed: u32 = FNV_OFFSET): u32 {
  var v = seed;
  if (key !== null) {
    let len = key.length << 1;
    let off: usize = 0;
    while (len >= 8) {
      v = hash64(load<u64>(changetype<usize>(key) + off), v);
      off += 8; len -= 8;
    }
    if (len >= 4) {
      v = hash32(load<u32>(changetype<usize>(key) + off), v);
      off += 4; len -= 4;
    }
    if (len >= 2) {
      v = hash16(load<u16>(changetype<usize>(key) + off), v);
    }
    // "len" always even so don't need hash8
  }
  return v;
}


export function benchOld(): u32 {
  let acc: u32 = 0;
  for (let i = 0; i < 1000000; i++) {
    acc += HASH<string>(i.toString(2));
  }
  return acc;
}

export function benchNew(): u32 {
  let acc: u32 = 0;
  for (let i = 0; i < 1000000; i++) {
    acc += hashStr(i.toString(2));
  }
  return acc;
}