const LOGF_TABLE_BITS = 4;

@lazy const logf_data_tab: f64[] = [
  reinterpret<f64>(0x3FF661EC79F8F3BE), reinterpret<f64>(0xBFD57BF7808CAADE), // 0x1.661ec79f8f3bep+0, -0x1.57bf7808caadep-2,
  reinterpret<f64>(0x3FF571ED4AAF883D), reinterpret<f64>(0xBFD2BEF0A7C06DDB), // 0x1.571ed4aaf883dp+0, -0x1.2bef0a7c06ddbp-2,
  reinterpret<f64>(0x3FF49539F0F010B0), reinterpret<f64>(0xBFD01EAE7F513A67), // 0x1.49539f0f010bp+0 , -0x1.01eae7f513a67p-2,
  reinterpret<f64>(0x3FF3C995B0B80385), reinterpret<f64>(0xBFCB31D8A68224E9), // 0x1.3c995b0b80385p+0, -0x1.b31d8a68224e9p-3,
  reinterpret<f64>(0x3FF30D190C8864A5), reinterpret<f64>(0xBFC6574F0AC07758), // 0x1.30d190c8864a5p+0, -0x1.6574f0ac07758p-3,
  reinterpret<f64>(0x3FF25E227B0B8EA0), reinterpret<f64>(0xBFC1AA2BC79C8100), // 0x1.25e227b0b8eap+0 , -0x1.1aa2bc79c81p-3  ,
  reinterpret<f64>(0x3FF1BB4A4A1A343F), reinterpret<f64>(0xBFBA4E76CE8C0E5E), // 0x1.1bb4a4a1a343fp+0, -0x1.a4e76ce8c0e5ep-4,
  reinterpret<f64>(0x3FF12358F08AE5BA), reinterpret<f64>(0xBFB1973C5A611CCC), // 0x1.12358f08ae5bap+0, -0x1.1973c5a611cccp-4,
  reinterpret<f64>(0x3FF0953F419900A7), reinterpret<f64>(0xBFA252F438E10C1E), // 0x1.0953f419900a7p+0, -0x1.252f438e10c1ep-5,
  reinterpret<f64>(0x3FF0000000000000), 0,                                    // 0x1p+0,                0,
  reinterpret<f64>(0x3FEE608CFD9A47AC), reinterpret<f64>(0x3FAAA5AA5DF25984), // 0x1.e608cfd9a47acp-1,  0x1.aa5aa5df25984p-5,
  reinterpret<f64>(0x3FECA4B31F026AA0), reinterpret<f64>(0x3FBC5E53AA362EB4), // 0x1.ca4b31f026aap-1 ,  0x1.c5e53aa362eb4p-4,
  reinterpret<f64>(0x3FEB2036576AFCE6), reinterpret<f64>(0x3FC526E57720DB08), // 0x1.b2036576afce6p-1,  0x1.526e57720db08p-3,
  reinterpret<f64>(0x3FE9C2D163A1AA2D), reinterpret<f64>(0x3FCBC2860D224770), // 0x1.9c2d163a1aa2dp-1,  0x1.bc2860d22477p-3 ,
  reinterpret<f64>(0x3FE886E6037841ED), reinterpret<f64>(0x3FD1058BC8A07EE1), // 0x1.886e6037841edp-1,  0x1.1058bc8a07ee1p-2,
  reinterpret<f64>(0x3FE767DCF5534862), reinterpret<f64>(0x3FD4043057B6EE09), // 0x1.767dcf5534862p-1,  0x1.4043057b6ee09p-2
];

// const logf_data_ln2 = reinterpret<f64>(0x3FE62E42FEFA39EF); // 0x1.62e42fefa39efp-1;
// const logf_data_poly: f64[] = [
//   reinterpret<f64>(0xBFD00EA348B88334), // -0x1.00ea348b88334p-2
//   reinterpret<f64>(0x3FD5575B0BE00B6A), //  0x1.5575b0be00b6ap-2
//   reinterpret<f64>(0xBFDFFFFEF20A4123)  // -0x1.ffffef20a4123p-2
// ];

/*
ULP error: 0.818 (nearest rounding.)
Relative error: 1.957 * 2^-26 (before rounding.)
*/
export function logf_lut(x: f32): f32 {
  const Ox1p23f = reinterpret<f32>(0x4B000000); // 0x1p23f;
  const N_MASK  = (1 << LOGF_TABLE_BITS) - 1;

  const Ln2 = reinterpret<f64>(0x3FE62E42FEFA39EF); // 0x1.62e42fefa39efp-1;
  const A0  = reinterpret<f64>(0xBFD00EA348B88334); // -0x1.00ea348b88334p-2
  const A1  = reinterpret<f64>(0x3FD5575B0BE00B6A); //  0x1.5575b0be00b6ap-2
  const A2  = reinterpret<f64>(0xBFDFFFFEF20A4123); // -0x1.ffffef20a4123p-2

  var ux = reinterpret<u32>(x);
  /* Fix sign of zero with downward rounding when x==1.  */
  // if (WANT_ROUNDING && ux == 0x3f800000) return 0;
  if (ux - 0x00800000 >= 0x7F800000 - 0x00800000) {
    /* x < 0x1p-126 or inf or nan. */
    if (ux * 2 == 0) return -Infinity;
    if (ux == 0x7F800000) return x; // /* log(inf) == inf.  */
    if ((ux & 0x80000000) || ux * 2 >= 0xFF000000) return (x - x) / (x - x);
    /* x is subnormal, normalize it.  */
    ux = reinterpret<u32>(x * Ox1p23f);
    ux -= 23 << 23;
  }
  /* x = 2^k z; where z is in range [OFF,2*OFF] and exact.
     The range is split into N subintervals.
     The ith subinterval contains z and c is near its center.  */
  var tmp = ux - 0x3F330000;
  var i   = (tmp >> (23 - LOGF_TABLE_BITS)) & N_MASK;
  var k   = <i32>tmp >> 23; /* arithmetic shift */
  var iz  = ux - (tmp & 0x1FF << 23);

  var tab = logf_data_tab.dataStart as usize;

  var invc = load<f64>(tab + (i << (1 + alignof<f64>())), 0 << alignof<f64>());
  var logc = load<f64>(tab + (i << (1 + alignof<f64>())), 1 << alignof<f64>());

  var z = <f64>reinterpret<f32>(iz);

  /* log(x) = log1p(z/c-1) + log(c) + k*Ln2 */
  var r = z * invc - 1;
  var y0 = logc + <f64>k * Ln2;

  /* Pipelined polynomial evaluation to approximate log1p(r).  */
  var r2 = r * r;
  var y  = A1 * r + A2;
  y += A0 * r2;
  y = y * r2 + (y0 + r);

  return <f32>y;
}