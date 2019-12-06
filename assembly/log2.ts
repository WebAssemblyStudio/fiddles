// @ts-ignore: decorator
@lazy const LOG2_TABLE_BITS = 6;

/* Algorithm:

  x = 2^k z
  log2(x) = k + log2(c) + log2(z/c)
  log2(z/c) = poly(z/c - 1)

where z is in [1.6p-1; 1.6p0] which is split into N subintervals and z falls
into the ith one, then table entries are computed as

  tab[i].invc = 1/c
  tab[i].logc = (double)log2(c)
  tab2[i].chi = (double)c
  tab2[i].clo = (double)(c - (double)c)

where c is near the center of the subinterval and is chosen by trying +-2^29
floating point invc candidates around 1/center and selecting one for which

  1) the rounding error in 0x1.8p10 + logc is 0,
  2) the rounding error in z - chi - clo is < 0x1p-64 and
  3) the rounding error in (double)log2(c) is minimized (< 0x1p-68).

Note: 1) ensures that k + logc can be computed without rounding error, 2)
ensures that z/c - 1 can be computed as (z - chi - clo)*invc with close to a
single rounding error when there is no fast fma for z*invc - 1, 3) ensures
that logc + poly(z/c - 1) has small error, however near x == 1 when
|log2(x)| < 0x1p-4, this is not enough so that is special cased.*/

// @ts-ignore: decorator
@lazy const log2_data_tab1: f64[] = [
  //            invc                  ,                logc
  reinterpret<f64>(0x3FF724286BB1ACF8), reinterpret<f64>(0xBFE1095FEECDB000),
  reinterpret<f64>(0x3FF6E1F766D2CCA1), reinterpret<f64>(0xBFE08494BD76D000),
  reinterpret<f64>(0x3FF6A13D0E30D48A), reinterpret<f64>(0xBFE00143AEE8F800),
  reinterpret<f64>(0x3FF661EC32D06C85), reinterpret<f64>(0xBFDEFEC5360B4000),
  reinterpret<f64>(0x3FF623FA951198F8), reinterpret<f64>(0xBFDDFDD91AB7E000),
  reinterpret<f64>(0x3FF5E75BA4CF026C), reinterpret<f64>(0xBFDCFFAE0CC79000),
  reinterpret<f64>(0x3FF5AC055A214FB8), reinterpret<f64>(0xBFDC043811FDA000),
  reinterpret<f64>(0x3FF571ED0F166E1E), reinterpret<f64>(0xBFDB0B67323AE000),
  reinterpret<f64>(0x3FF53909590BF835), reinterpret<f64>(0xBFDA152F5A2DB000),
  reinterpret<f64>(0x3FF5014FED61ADDD), reinterpret<f64>(0xBFD9217F5AF86000),
  reinterpret<f64>(0x3FF4CAB88E487BD0), reinterpret<f64>(0xBFD8304DB0719000),
  reinterpret<f64>(0x3FF49539B4334FEE), reinterpret<f64>(0xBFD74189F9A9E000),
  reinterpret<f64>(0x3FF460CBDFAFD569), reinterpret<f64>(0xBFD6552BB5199000),
  reinterpret<f64>(0x3FF42D664EE4B953), reinterpret<f64>(0xBFD56B23A29B1000),
  reinterpret<f64>(0x3FF3FB01111DD8A6), reinterpret<f64>(0xBFD483650F5FA000),
  reinterpret<f64>(0x3FF3C995B70C5836), reinterpret<f64>(0xBFD39DE937F6A000),
  reinterpret<f64>(0x3FF3991C4AB6FD4A), reinterpret<f64>(0xBFD2BAA1538D6000),
  reinterpret<f64>(0x3FF3698E0CE099B5), reinterpret<f64>(0xBFD1D98340CA4000),
  reinterpret<f64>(0x3FF33AE48213E7B2), reinterpret<f64>(0xBFD0FA853A40E000),
  reinterpret<f64>(0x3FF30D191985BDB1), reinterpret<f64>(0xBFD01D9C32E73000),
  reinterpret<f64>(0x3FF2E025CAB271D7), reinterpret<f64>(0xBFCE857DA2FA6000),
  reinterpret<f64>(0x3FF2B404CF13CD82), reinterpret<f64>(0xBFCCD3C8633D8000),
  reinterpret<f64>(0x3FF288B02C7CCB50), reinterpret<f64>(0xBFCB26034C14A000),
  reinterpret<f64>(0x3FF25E2263944DE5), reinterpret<f64>(0xBFC97C1C2F4FE000),
  reinterpret<f64>(0x3FF234563D8615B1), reinterpret<f64>(0xBFC7D6023F800000),
  reinterpret<f64>(0x3FF20B46E33EAF38), reinterpret<f64>(0xBFC633A71A05E000),
  reinterpret<f64>(0x3FF1E2EEFDCDA3DD), reinterpret<f64>(0xBFC494F5E9570000),
  reinterpret<f64>(0x3FF1BB4A580B3930), reinterpret<f64>(0xBFC2F9E424E0A000),
  reinterpret<f64>(0x3FF19453847F2200), reinterpret<f64>(0xBFC162595AFDC000),
  reinterpret<f64>(0x3FF16E06C0D5D73C), reinterpret<f64>(0xBFBF9C9A75BD8000),
  reinterpret<f64>(0x3FF1485F47B7E4C2), reinterpret<f64>(0xBFBC7B575BF9C000),
  reinterpret<f64>(0x3FF12358AD0085D1), reinterpret<f64>(0xBFB960C60FF48000),
  reinterpret<f64>(0x3FF0FEF00F532227), reinterpret<f64>(0xBFB64CE247B60000),
  reinterpret<f64>(0x3FF0DB2077D03A8F), reinterpret<f64>(0xBFB33F78B2014000),
  reinterpret<f64>(0x3FF0B7E6D65980D9), reinterpret<f64>(0xBFB0387D1A42C000),
  reinterpret<f64>(0x3FF0953EFE7B408D), reinterpret<f64>(0xBFAA6F9208B50000),
  reinterpret<f64>(0x3FF07325CAC53B83), reinterpret<f64>(0xBFA47A954F770000),
  reinterpret<f64>(0x3FF05197E40D1B5C), reinterpret<f64>(0xBF9D23A8C50C0000),
  reinterpret<f64>(0x3FF03091C1208EA2), reinterpret<f64>(0xBF916A2629780000),
  reinterpret<f64>(0x3FF0101025B37E21), reinterpret<f64>(0xBF7720F8D8E80000),
  reinterpret<f64>(0x3FEFC07EF9CAA76B), reinterpret<f64>(0x3F86FE53B1500000),
  reinterpret<f64>(0x3FEF4465D3F6F184), reinterpret<f64>(0x3FA11CCCE10F8000),
  reinterpret<f64>(0x3FEECC079F84107F), reinterpret<f64>(0x3FAC4DFC8C8B8000),
  reinterpret<f64>(0x3FEE573A99975AE8), reinterpret<f64>(0x3FB3AA321E574000),
  reinterpret<f64>(0x3FEDE5D6F0BD3DE6), reinterpret<f64>(0x3FB918A0D08B8000),
  reinterpret<f64>(0x3FED77B681FF38B3), reinterpret<f64>(0x3FBE72E9DA044000),
  reinterpret<f64>(0x3FED0CB5724DE943), reinterpret<f64>(0x3FC1DCD2507F6000),
  reinterpret<f64>(0x3FECA4B2DC0E7563), reinterpret<f64>(0x3FC476AB03DEA000),
  reinterpret<f64>(0x3FEC3F8EE8D6CB51), reinterpret<f64>(0x3FC7074377E22000),
  reinterpret<f64>(0x3FEBDD2B4F020C4C), reinterpret<f64>(0x3FC98EDE8BA94000),
  reinterpret<f64>(0x3FEB7D6C006015CA), reinterpret<f64>(0x3FCC0DB86AD2E000),
  reinterpret<f64>(0x3FEB20366E2E338F), reinterpret<f64>(0x3FCE840AAFCEE000),
  reinterpret<f64>(0x3FEAC57026295039), reinterpret<f64>(0x3FD0790AB4678000),
  reinterpret<f64>(0x3FEA6D01BC2731DD), reinterpret<f64>(0x3FD1AC056801C000),
  reinterpret<f64>(0x3FEA16D3BC3FF18B), reinterpret<f64>(0x3FD2DB11D4FEE000),
  reinterpret<f64>(0x3FE9C2D14967FEAD), reinterpret<f64>(0x3FD406464EC58000),
  reinterpret<f64>(0x3FE970E4F47C9902), reinterpret<f64>(0x3FD52DBE093AF000),
  reinterpret<f64>(0x3FE920FB3982BCF2), reinterpret<f64>(0x3FD651902050D000),
  reinterpret<f64>(0x3FE8D30187F759F1), reinterpret<f64>(0x3FD771D2CDEAF000),
  reinterpret<f64>(0x3FE886E5EBB9F66D), reinterpret<f64>(0x3FD88E9C857D9000),
  reinterpret<f64>(0x3FE83C97B658B994), reinterpret<f64>(0x3FD9A80155E16000),
  reinterpret<f64>(0x3FE7F405FFC61022), reinterpret<f64>(0x3FDABE186ED3D000),
  reinterpret<f64>(0x3FE7AD22181415CA), reinterpret<f64>(0x3FDBD0F2AEA0E000),
  reinterpret<f64>(0x3FE767DCF99EFF8C), reinterpret<f64>(0x3FDCE0A43DBF4000)
];

// @ts-ignore: decorator
@lazy const log2_data_tab2: f64[] = [
  //              chi                 ,                 clo
  reinterpret<f64>(0x3FE6200012B90A8E), reinterpret<f64>(0x3C8904AB0644B605),
  reinterpret<f64>(0x3FE66000045734A6), reinterpret<f64>(0x3C61FF9BEA62F7A9),
  reinterpret<f64>(0x3FE69FFFC325F2C5), reinterpret<f64>(0x3C827ECFCB3C90BA),
  reinterpret<f64>(0x3FE6E00038B95A04), reinterpret<f64>(0x3C88FF8856739326),
  reinterpret<f64>(0x3FE71FFFE09994E3), reinterpret<f64>(0x3C8AFD40275F82B1),
  reinterpret<f64>(0x3FE7600015590E10), reinterpret<f64>(0xBC72FD75B4238341),
  reinterpret<f64>(0x3FE7A00012655BD5), reinterpret<f64>(0x3C7808E67C242B76),
  reinterpret<f64>(0x3FE7E0003259E9A6), reinterpret<f64>(0xBC6208E426F622B7),
  reinterpret<f64>(0x3FE81FFFEDB4B2D2), reinterpret<f64>(0xBC8402461EA5C92F),
  reinterpret<f64>(0x3FE860002DFAFCC3), reinterpret<f64>(0x3C6DF7F4A2F29A1F),
  reinterpret<f64>(0x3FE89FFFF78C6B50), reinterpret<f64>(0xBC8E0453094995FD),
  reinterpret<f64>(0x3FE8E00039671566), reinterpret<f64>(0xBC8A04F3BEC77B45),
  reinterpret<f64>(0x3FE91FFFE2BF1745), reinterpret<f64>(0xBC77FA34400E203C),
  reinterpret<f64>(0x3FE95FFFCC5C9FD1), reinterpret<f64>(0xBC76FF8005A0695D),
  reinterpret<f64>(0x3FE9A0003BBA4767), reinterpret<f64>(0x3C70F8C4C4EC7E03),
  reinterpret<f64>(0x3FE9DFFFE7B92DA5), reinterpret<f64>(0x3C8E7FD9478C4602),
  reinterpret<f64>(0x3FEA1FFFD72EFDAF), reinterpret<f64>(0xBC6A0C554DCDAE7E),
  reinterpret<f64>(0x3FEA5FFFDE04FF95), reinterpret<f64>(0x3C867DA98CE9B26B),
  reinterpret<f64>(0x3FEA9FFFCA5E8D2B), reinterpret<f64>(0xBC8284C9B54C13DE),
  reinterpret<f64>(0x3FEADFFFDDAD03EA), reinterpret<f64>(0x3C5812C8EA602E3C),
  reinterpret<f64>(0x3FEB1FFFF10D3D4D), reinterpret<f64>(0xBC8EFADDAD27789C),
  reinterpret<f64>(0x3FEB5FFFCE21165A), reinterpret<f64>(0x3C53CB1719C61237),
  reinterpret<f64>(0x3FEB9FFFD950E674), reinterpret<f64>(0x3C73F7D94194CE00),
  reinterpret<f64>(0x3FEBE000139CA8AF), reinterpret<f64>(0x3C750AC4215D9BC0),
  reinterpret<f64>(0x3FEC20005B46DF99), reinterpret<f64>(0x3C6BEEA653E9C1C9),
  reinterpret<f64>(0x3FEC600040B9F7AE), reinterpret<f64>(0xBC7C079F274A70D6),
  reinterpret<f64>(0x3FECA0006255FD8A), reinterpret<f64>(0xBC7A0B4076E84C1F),
  reinterpret<f64>(0x3FECDFFFD94C095D), reinterpret<f64>(0x3C88F933F99AB5D7),
  reinterpret<f64>(0x3FED1FFFF975D6CF), reinterpret<f64>(0xBC582C08665FE1BE),
  reinterpret<f64>(0x3FED5FFFA2561C93), reinterpret<f64>(0xBC7B04289BD295F3),
  reinterpret<f64>(0x3FED9FFF9D228B0C), reinterpret<f64>(0x3C870251340FA236),
  reinterpret<f64>(0x3FEDE00065BC7E16), reinterpret<f64>(0xBC75011E16A4D80C),
  reinterpret<f64>(0x3FEE200002F64791), reinterpret<f64>(0x3C89802F09EF62E0),
  reinterpret<f64>(0x3FEE600057D7A6D8), reinterpret<f64>(0xBC7E0B75580CF7FA),
  reinterpret<f64>(0x3FEEA00027EDC00C), reinterpret<f64>(0xBC8C848309459811),
  reinterpret<f64>(0x3FEEE0006CF5CB7C), reinterpret<f64>(0xBC8F8027951576F4),
  reinterpret<f64>(0x3FEF2000782B7DCC), reinterpret<f64>(0xBC8F81D97274538F),
  reinterpret<f64>(0x3FEF6000260C450A), reinterpret<f64>(0xBC4071002727FFDC),
  reinterpret<f64>(0x3FEF9FFFE88CD533), reinterpret<f64>(0xBC581BDCE1FDA8B0),
  reinterpret<f64>(0x3FEFDFFFD50F8689), reinterpret<f64>(0x3C87F91ACB918E6E),
  reinterpret<f64>(0x3FF0200004292367), reinterpret<f64>(0x3C9B7FF365324681),
  reinterpret<f64>(0x3FF05FFFE3E3D668), reinterpret<f64>(0x3C86FA08DDAE957B),
  reinterpret<f64>(0x3FF0A0000A85A757), reinterpret<f64>(0xBC57E2DE80D3FB91),
  reinterpret<f64>(0x3FF0E0001A5F3FCC), reinterpret<f64>(0xBC91823305C5F014),
  reinterpret<f64>(0x3FF11FFFF8AFBAF5), reinterpret<f64>(0xBC8BFABB6680BAC2),
  reinterpret<f64>(0x3FF15FFFE54D91AD), reinterpret<f64>(0xBC9D7F121737E7EF),
  reinterpret<f64>(0x3FF1A00011AC36E1), reinterpret<f64>(0x3C9C000A0516F5FF),
  reinterpret<f64>(0x3FF1E00019C84248), reinterpret<f64>(0xBC9082FBE4DA5DA0),
  reinterpret<f64>(0x3FF220000FFE5E6E), reinterpret<f64>(0xBC88FDD04C9CFB43),
  reinterpret<f64>(0x3FF26000269FD891), reinterpret<f64>(0x3C8CFE2A7994D182),
  reinterpret<f64>(0x3FF2A00029A6E6DA), reinterpret<f64>(0xBC700273715E8BC5),
  reinterpret<f64>(0x3FF2DFFFE0293E39), reinterpret<f64>(0x3C9B7C39DAB2A6F9),
  reinterpret<f64>(0x3FF31FFFF7DCF082), reinterpret<f64>(0x3C7DF1336EDC5254),
  reinterpret<f64>(0x3FF35FFFF05A8B60), reinterpret<f64>(0xBC9E03564CCD31EB),
  reinterpret<f64>(0x3FF3A0002E0EAECC), reinterpret<f64>(0x3C75F0E74BD3A477),
  reinterpret<f64>(0x3FF3E000043BB236), reinterpret<f64>(0x3C9C7DCB149D8833),
  reinterpret<f64>(0x3FF4200002D187FF), reinterpret<f64>(0x3C7E08AFCF2D3D28),
  reinterpret<f64>(0x3FF460000D387CB1), reinterpret<f64>(0x3C820837856599A6),
  reinterpret<f64>(0x3FF4A00004569F89), reinterpret<f64>(0xBC89FA5C904FBCD2),
  reinterpret<f64>(0x3FF4E000043543F3), reinterpret<f64>(0xBC781125ED175329),
  reinterpret<f64>(0x3FF51FFFCC027F0F), reinterpret<f64>(0x3C9883D8847754DC),
  reinterpret<f64>(0x3FF55FFFFD87B36F), reinterpret<f64>(0xBC8709E731D02807),
  reinterpret<f64>(0x3FF59FFFF21DF7BA), reinterpret<f64>(0x3C87F79F68727B02),
  reinterpret<f64>(0x3FF5DFFFEBFC3481), reinterpret<f64>(0xBC9180902E30E93E)
];

export function log2_lut(x: f64): f64 {
  const N      = 1 << LOG2_TABLE_BITS;
  const N_MASK = N - 1;

  const Ox1p52   = reinterpret<f64>(0x4330000000000000); // 0x1p52
  const InvLn2hi = reinterpret<f64>(0x3FF7154765200000); // 0x1.7154765200000p+0
  const InvLn2lo = reinterpret<f64>(0x3DE705FC2EEFA200); // 0x1.705fc2eefa200p-33
  const LO: u64  = 0x3FEEA4AF00000000; // reinterpret<u64>(1.0 - 0x1.5b51p-5)
  const HI: u64  = 0x3FF0B55900000000; // reinterpret<u64>(1.0 + 0x1.6ab2p-5)

  const B0 = reinterpret<f64>(0xBFE71547652B82FE); // -0x1.71547652b82fep-1
  const B1 = reinterpret<f64>(0x3FDEC709DC3A03F7); //  0x1.ec709dc3a03f7p-2
  const B2 = reinterpret<f64>(0xBFD71547652B7C3F); // -0x1.71547652b7c3fp-2
  const B3 = reinterpret<f64>(0x3FD2776C50F05BE4); //  0x1.2776c50f05be4p-2
  const B4 = reinterpret<f64>(0xBFCEC709DD768FE5); // -0x1.ec709dd768fe5p-3
  const B5 = reinterpret<f64>(0x3FCA61761EC4E736); //  0x1.a61761ec4e736p-3
  const B6 = reinterpret<f64>(0xBFC7153FBC64A79B); // -0x1.7153fbc64a79bp-3
  const B7 = reinterpret<f64>(0x3FC484D154F01B4A); //  0x1.484d154f01b4ap-3
  const B8 = reinterpret<f64>(0xBFC289E4A72C383C); // -0x1.289e4a72c383cp-3
  const B9 = reinterpret<f64>(0x3FC0B32F285AEE66); //  0x1.0b32f285aee66p-3

  const A0 = reinterpret<f64>(0xBFE71547652B8339); // -0x1.71547652b8339p-1
  const A1 = reinterpret<f64>(0x3FDEC709DC3A04BE); //  0x1.ec709dc3a04bep-2
  const A2 = reinterpret<f64>(0xBFD7154764702FFB); // -0x1.7154764702ffbp-2
  const A3 = reinterpret<f64>(0x3FD2776C50034C48); //  0x1.2776c50034c48p-2
  const A4 = reinterpret<f64>(0xBFCEC7B328EA92BC); // -0x1.ec7b328ea92bcp-3
  const A5 = reinterpret<f64>(0x3FCA6225E117F92E); //  0x1.a6225e117f92ep-3

  var ix = reinterpret<u64>(x);
  if (ix - LO < HI - LO) {
    let r = x - 1.0;
// #if __FP_FAST_FMA
//     hi = r * InvLn2hi;
//     lo = r * InvLn2lo + __builtin_fma(r, InvLn2hi, -hi);
// #else
    let rhi = reinterpret<f64>(reinterpret<u64>(r) & 0xFFFFFFFF00000000);
    let rlo = r - rhi;
    let hi  = rhi * InvLn2hi;
    let lo  = rlo * InvLn2hi + r * InvLn2lo;
// #endif
    let r2 = r * r; // rounding error: 0x1p-62
    let r4 = r2 * r2;
    // Worst-case error is less than 0.54 ULP (0.55 ULP without fma)
    let p = r2 * (B0 + r * B1);
    let y = hi + p;
    lo += hi - y + p;
    lo += r4 * (B2 + r * B3 + r2 * (B4 + r * B5) +
          r4 * (B6 + r * B7 + r2 * (B8 + r * B9)));
    return y + lo;
  }
  var top = <u32>(ix >> 48);
  if (top - 0x0010 >= 0x7ff0 - 0x0010) {
    // x < 0x1p-1022 or inf or nan.
    if ((ix << 1) == 0) return -1.0 / 0.0;
    if (ix == 0x7FF0000000000000) return x; // log(inf) == inf
    if ((top & 0x8000) || (top & 0x7FF0) == 0x7FF0) return (x - x) / (x - x);
    // x is subnormal, normalize it.
    ix = reinterpret<u64>(x * Ox1p52);
    ix -= u64(52) << 52;
  }

  /* x = 2^k z; where z is in range [OFF,2*OFF) and exact.
     The range is split into N subintervals.
     The ith subinterval contains z and c is near its center.  */
  var tmp  = ix - 0x3FE6000000000000;
  var i    = <usize>((tmp >> (52 - LOG2_TABLE_BITS)) & N_MASK);
  var k    = <i64>tmp >> 52;
  var iz   = ix - (tmp & 0xFFF0000000000000);

  // @ts-ignore: cast
  const tab1 = log2_data_tab1.dataStart as usize;
  // @ts-ignore: cast
  const tab2 = log2_data_tab2.dataStart as usize;

  var invc = load<f64>(tab1 + (i << (1 + alignof<f64>())), 0 << alignof<f64>()); // T[i].invc;
  var logc = load<f64>(tab1 + (i << (1 + alignof<f64>())), 1 << alignof<f64>()); // T[i].logc;
  var z    = reinterpret<f64>(iz);
  var kd   = <f64>k;

  // log2(x) = log2(z/c) + log2(c) + k.
  // r ~= z/c - 1, |r| < 1/(2*N).
// #if __FP_FAST_FMA
// 	/* rounding error: 0x1p-55/N.  */
// 	r = __builtin_fma(z, invc, -1.0);
// 	t1 = r * InvLn2hi;
// 	t2 = r * InvLn2lo + __builtin_fma(r, InvLn2hi, -t1);
// #else
  // rounding error: 0x1p-55/N + 0x1p-65.
  var chi = load<f64>(tab2 + (i << (1 + alignof<f64>())), 0 << alignof<f64>()); // T[i].chi;
  var clo = load<f64>(tab2 + (i << (1 + alignof<f64>())), 1 << alignof<f64>()); // T[i].clo;

  var r = (z - chi - clo) * invc;
  var rhi = reinterpret<f64>(reinterpret<u64>(r) & 0xFFFFFFFF00000000);
  var rlo = r - rhi;
  var t1 = rhi * InvLn2hi;
  var t2 = rlo * InvLn2hi + r * InvLn2lo;
// #endif

  // hi + lo = r/ln2 + log2(c) + k
  var t3 = kd + logc;
  var hi = t3 + t1;
  var lo = t3 - hi + t1 + t2;

  // log2(r+1) = r/ln2 + r^2*poly(r)
  // Evaluation is optimized assuming superscalar pipelined execution
  var r2 = r * r; // rounding error: 0x1p-54/N^2
  /* Worst-case error if |y| > 0x1p-4: 0.547 ULP (0.550 ULP without fma).
     ~ 0.5 + 2/N/ln2 + abs-poly-error*0x1p56 ULP (+ 0.003 ULP without fma).*/
  var p = A0 + r * A1 + r2 * (A2 + r * A3) + (r2 * r2) * (A4 + r * A5);
  return lo + r2 * p + hi;
}