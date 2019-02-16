export function sin (x: f64):f64 { return Math.sin(x); };
function tan (x: f64):f64 { return Math.tan(x); };
function cos (x: f64):f64 { return Math.cos(x); };
function asin (x: f64):f64 { return Math.asin(x); };
function atan (x: f64):f64 { return Math.atan(x); };
function acos (x: f64):f64 { return Math.acos(x); };
function pow (base: f64, exponent: f64): f64{
    if(exponent % 1 != 0){
        for(let i = -7; i < 8; i = i + 2){
            if(exponent == 1/i && base < 0) return 0 - 1 * Math.pow(0 - base, exponent);     
        }
    }
    return Math.pow(base, exponent);
}
export function add(x: f64): f64 {
    return x + Math.sin(x);
}
