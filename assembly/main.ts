
var sincosf_s: f32;
var sincosf_c: f32;

export function test(n: i32, s: f32, c: f32): void {
    switch (n & 3) {
    case 0: {
      sincosf_s = s;
      sincosf_c = c;
      break;
    }
    case 1: {
      sincosf_s =  c;
      sincosf_c = -s;
      break;
    }
    case 2: {
      sincosf_s = -s;
      sincosf_c = -c;
      break;
    }
    case 3:
    default: {
      sincosf_s = -c;
      sincosf_c =  s;
      break;
    }
  }
}

export function test2(n: i32, s: f32, c: f32): void {
    switch (n & 3) {
    case 0: {
      sincosf_s = s;
      sincosf_c = c;
      return;
    }
    case 1: {
      sincosf_s =  c;
      sincosf_c = -s;
      return;
    }
    case 2: {
      sincosf_s = -s;
      sincosf_c = -c;
      return;
    }
    default: {
      sincosf_s = -c;
      sincosf_c =  s;
      return;
    }
  }
}
