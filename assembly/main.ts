  

var _lo1: u64 = -1 as u64;
var _hi1: u64 = 100000 as u64;

var _lo2: u64 = -1 as u64;
var _hi2: u64 = 100000 as u64;

@inline
function preDec1(): void {
  var tmp  = _lo1 - 1;
  _hi1 -= ((_lo1 ^ tmp) & tmp) >> 63;
  _lo1  = tmp;
}

@inline
function preDec2(): void {
  var lo = _lo2;
  var lo1 = lo - 1;
  _hi2 -= u64(lo1 > lo);
  _lo2 = lo1;
}

export function bench1(n: i32): void {
  for (let i = 0; i < n; i++) {
    preDec1();
  }
}

export function bench2(n: i32): void {
  for (let i = 0; i < n; i++) {
    preDec2();
  }
}
