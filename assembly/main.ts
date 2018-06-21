declare function logi(v: i32): void;
declare function logu(v: u32): void;

var t1 = 0x80000000; // resolves as u32
var t2 =-0x80000000; // resolves as i32

function log<T>(val: T): void {
  if (val instanceof i32) {
    logi(<i32>val);
  } else if (val instanceof u32) {
    logu(<u32>val);
  }
}

log(t1 >> 10);
log(t2 >> 10);
