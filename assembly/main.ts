// uses Math.exp() approximation from:
// https://www.musicdsp.org/en/latest/Other/222-fast-exp-approximations.html

// @ts-ignore: decorator
@inline
function fastexp9(x: f64): f64 {
    // prettier-ignore
    return (362880+x*(362880+x*(181440+x*(60480+x*(15120+x*(3024+x*(504+x*(72+x*(9+x)))))))))*2.75573192e-6;
}

// @ts-ignore: decorator
@inline
function sigmoidApprox(x: f64): f64 {
    return 1.0 / (1.0 + fastexp9(-x));
}

export function sigmoidApproxPtr(out: usize, src: usize, n: usize): usize {
    const res = out;
    while (n-- > 0) {
        f64.store(out, sigmoidApprox(f64.load(src)));
        out += sizeof<f64>(); // 8
        src += sizeof<f64>(); // 8
    }
    return res;
}

///////// native math + pointers

// @ts-ignore: decorator
@inline
function sigmoidNat(x: f64): f64 {
    return 1.0 / (1.0 + Math.exp(-x));
}

export function sigmoidNatPtr(out: usize, src: usize, n: usize): usize {
    const res = out;
    while (n-- > 0) {
        f64.store(out, sigmoidNat(f64.load(src)));
        out += sizeof<f64>(); // 8
        src += sizeof<f64>(); // 8
    }
    return res;
}
