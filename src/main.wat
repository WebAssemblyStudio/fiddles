(module
  (func $exp2 (param $x f32) (result f32)
      ;; Calculate pow(2, x)
      (local $xf f32)

      ;; Compute xf = fract(x)
      (get_local $x)                  ;; x
      (f32.floor (get_local $x))      ;; x, floor(x)
      (f32.sub)                       ;; x-floor(x)=fract(x)
      (set_local $xf)                 ;; xf = fract(x)

      ;; Compute polynomial.
      ;; These were based on Excel solver. I initially used Taylor series, but the solver gives better accuracy for a small number of terms.
      ;; 2 terms: 22743533, 5603139 : 16 cents error
      ;; 3 terms: 642218, 1911078, 5832153 : 0.6 cents error
      ;; 4 terms: 120819, 421063, 2035288, 5811427 : 0.05 cents error
      (f32.const 642218)
      (f32.add (f32.mul (get_local $xf)) (f32.const 1911078))
      (f32.add (f32.mul (get_local $xf)) (f32.const 5832153))
      (f32.mul (get_local $xf))
      (i32.trunc_u/f32)                 ;; Move to int form

      ;; Merge parts into IEEE 754 floating point form in an i32 variable
      ;; This allows direct access to exponent which makes powers of two trivial.
      (i32.trunc_s/f32 (f32.floor (get_local $x)))
      (i32.add (i32.const 127))
      (i32.shl (i32.const 23))
      (i32.add)

      ;; Parse result as a float bitfield
      f32.reinterpret/i32
  )
  (export "exp2" (func $exp2))
)