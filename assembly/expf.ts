@lazy export const EXP2F_TABLE_BITS = 5;
@lazy export const exp2f_data_tab: u64[] = [
  /* tab[i] = uint(2^(i/N)) - (i << 52-BITS)
    used for computing 2^(k/N) for an int |k| < 150 N as
    double(tab[k%N] + (k << 52-BITS)) */
  0x3ff0000000000000, 0x3fefd9b0d3158574, 0x3fefb5586cf9890f, 0x3fef9301d0125b51,
  0x3fef72b83c7d517b, 0x3fef54873168b9aa, 0x3fef387a6e756238, 0x3fef1e9df51fdee1,
  0x3fef06fe0a31b715, 0x3feef1a7373aa9cb, 0x3feedea64c123422, 0x3feece086061892d,
  0x3feebfdad5362a27, 0x3feeb42b569d4f82, 0x3feeab07dd485429, 0x3feea47eb03a5585,
  0x3feea09e667f3bcd, 0x3fee9f75e8ec5f74, 0x3feea11473eb0187, 0x3feea589994cce13,
  0x3feeace5422aa0db, 0x3feeb737b0cdc5e5, 0x3feec49182a3f090, 0x3feed503b23e255d,
  0x3feee89f995ad3ad, 0x3feeff76f2fb5e47, 0x3fef199bdd85529c, 0x3fef3720dcef9069,
  0x3fef5818dcfba487, 0x3fef7c97337b9b5f, 0x3fefa4afa2a490da, 0x3fefd0765b6e4540
];

export function expf_lut(x: f32): f32 {
  const N       = 1 << EXP2F_TABLE_BITS;
  const N_MASK  = N - 1;
  const shift   = reinterpret<f64>(0x4338000000000000);     // 0x1.8p+52
  const InvLn2N = reinterpret<f64>(0x3FF71547652B82FE) * N; // 0x1.71547652b82fep+0

  const C0 = reinterpret<f64>(0x3FAC6AF84B912394) / N / N / N; // 0x1.c6af84b912394p-5
  const C1 = reinterpret<f64>(0x3FCEBFCE50FAC4F3) / N / N;     // 0x1.ebfce50fac4f3p-3
  const C2 = reinterpret<f64>(0x3FE62E42FF0C52D6) / N;         // 0x1.62e42ff0c52d6p-1

  var xd = <f64>x;
  var ix = reinterpret<u32>(x);
  var ux = ix >> 20 & 0x7FF;
  if (ux >= 0x42B) {
    /* |x| >= 88 or x is nan.  */
    if (ix == 0xFF800000) return 0;                        // x == -Inf    -> 0
    if (ux >= 0x7F8) return x + x;                         // x == Inf/NaN -> Inf/NaN
    if (x > reinterpret<f32>(0x42B17217)) return Infinity; // x > log(0x1p128)  ~=  88.72 -> Inf (Owerflow)
    if (x < reinterpret<f32>(0xC2CFF1B4)) return 0;        // x < log(0x1p-150) ~= -103.97 -> 0 (Underflow)
  }

  /* x*N/Ln2 = k + r with r in [-1/2, 1/2] and int k.  */
  var z = InvLn2N * xd;

  /* Round and convert z to int, the result is in [-150*N, 128*N] and
     ideally ties-to-even rule is used, otherwise the magnitude of r
     can be bigger which gives larger approximation error.  */
  var kd = <f64>(z + shift);
  var ki = reinterpret<u64>(kd);
  var r  = z - (kd - shift);
  var s: f64, y: f64, t: u64;

  const tab = exp2f_data_tab.dataStart as usize;

  /* exp(x) = 2^(k/N) * 2^(r/N) ~= s * (C0*r^3 + C1*r^2 + C2*r + 1) */
  t  = load<u64>(tab + ((<usize>ki & N_MASK) << alignof<u64>()));
  t += ki << (52 - EXP2F_TABLE_BITS);
  s  = reinterpret<f64>(t);
  z  = C0 * r + C1;
  y  = C2 * r + 1;
  y += z * (r * r);
  y *= s;

  return <f32>y;
}