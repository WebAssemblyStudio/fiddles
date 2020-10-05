
// compare f32 NaNs in integer representations
// and return stringify answer
function check(fn1, fn2) {
  return fn1() === fn2() ? "Yes" : "No!";
}

fetch('../out/main.wasm')
.then(response => response.arrayBuffer())
.then(bytes    => WebAssembly.instantiate(bytes))
.then(results  => {

  const {
    pos_aNaN_sub_neg_0,
    neg_aNaN_sub_neg_0,
    pos_aNaN_sub_neg_0_opt,
    neg_aNaN_sub_neg_0_opt,
  
    pos_NaN_sub_neg_0,
    neg_NaN_sub_neg_0,
    pos_NaN_sub_neg_0_opt,
    neg_NaN_sub_neg_0_opt,
  
    pos_sNaN_sub_neg_0,
    neg_sNaN_sub_neg_0,
    pos_sNaN_sub_neg_0_opt,
    neg_sNaN_sub_neg_0_opt,
  
    pos_ncNaN_sub_neg_0,
    neg_ncNaN_sub_neg_0,
    pos_ncNaN_sub_neg_0_opt,
    neg_ncNaN_sub_neg_0_opt,

  } = results.instance.exports;

  console.log("opt arith '+NaN - (-0)' -> '+NaN + 0' is valid? " + check(pos_aNaN_sub_neg_0, pos_aNaN_sub_neg_0_opt));
  console.log("opt arith '-NaN - (-0)' -> '-NaN + 0' is valid? " + check(pos_aNaN_sub_neg_0, pos_aNaN_sub_neg_0_opt));

  console.log("opt quiet '+NaN - (-0)' -> '+NaN + 0' is valid? " + check(pos_NaN_sub_neg_0, pos_NaN_sub_neg_0_opt));
  console.log("opt quiet '-NaN - (-0)' -> '-NaN + 0' is valid? " + check(pos_NaN_sub_neg_0, pos_NaN_sub_neg_0_opt));

  console.log("opt signal '+NaN - (-0)' -> '+NaN + 0' is valid? " + check(pos_sNaN_sub_neg_0, pos_sNaN_sub_neg_0_opt));
  console.log("opt signal '-NaN - (-0)' -> '-NaN + 0' is valid? " + check(pos_sNaN_sub_neg_0, pos_sNaN_sub_neg_0_opt));

  console.log("opt non-canon '+NaN - (-0)' -> '+NaN + 0' is valid? " + check(pos_ncNaN_sub_neg_0, pos_ncNaN_sub_neg_0_opt));
  console.log("opt non-canon '-NaN - (-0)' -> '-NaN + 0' is valid? " + check(neg_ncNaN_sub_neg_0, neg_ncNaN_sub_neg_0_opt));

}).catch(console.error);

