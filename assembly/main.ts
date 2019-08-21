export function dtoi32_1(x: f64): i32 {
    let result = 0;
    let u = reinterpret<u64>(x);
    let e = (u >> 52) & 0x7ff;
    if (e <= (1023 + 30)) {
      result = <i32>x;
    } else if (e <= 1023 + 30 + 53) {
      let v = (u & ((<u64>1 << 52) - 1)) | (<u64>1 << 52);
      v = v << e - 1023 - 52 + 32;
      result = <i32>(v >> 32);
      result = select<i32>(-result, result, u >> 63);
    }
    return result;
}

export function dtoi32_2(x: f64): i32 {
    let result = 0;
    let u = reinterpret<u64>(x);
    let e = (u >> 52) & 0x7ff;
    if (e <= (1023 + 30)) {
      result = <i32>x;
    } else if (e <= 1023 + 30 + 53) {
      let v = (u & ((<u64>1 << 52) - 1)) | (<u64>1 << 52);
      v = v << e - 1023 - 52 + 32;
      result = <i32>(v >> 32);
      let flag = i32(u >> 63);
      result = (result ^ -flag) + flag;
    }
    return result;
}
