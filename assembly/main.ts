  export function sign1(x: f64): f64 {
    // return x > 0 ? 1 : x < 0 ? -1 : x;
    return abs<f64>(x) > 0 ? copysign<f64>(1, x) : x;
  }

  export function sign2(x: f64): f64 {
    return x > 0 ? 1 : x < 0 ? -1 : x;
  }

  export function sign3(x: f64): f64 {
    // return x > 0 ? 1 : x < 0 ? -1 : x;
    return select<f64>(copysign<f64>(1, x), x, abs<f64>(x) > 0);
  }
