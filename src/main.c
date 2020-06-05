#define WASM_EXPORT __attribute__((visibility("default")))

WASM_EXPORT
int run1( int a ) {
  int c;
  if ( a == 5 ) {
    c = a * a * ( a + 5 ) * a + 3 * a;
  } else {
    c = a * a * ( a + 5 ) * ( a - 2 ) + 3 * a;
  }
  return c;
}

// (func (export "run2") (param $p0 i32) (result i32)
//   (i32.add
//     (i32.mul
//       (i32.mul
//         (i32.mul
//           (get_local $p0)
//           (get_local $p0)
//         )
//         (i32.add
//           (get_local $p0)
//           (i32.const 5)
//         )
//       )
//       (select
//         (get_local $p0)
//         (i32.sub
//           (get_local $p0)
//           (i32.const 2)
//         )
//         (i32.eq
//           (get_local $p0)
//           (i32.const 5)
//         )
//       )
//     )
//     (i32.mul
//       (i32.const 3)
//       (get_local $p0)
//     )
//   )
// )
