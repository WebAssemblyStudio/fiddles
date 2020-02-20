static mut INPUT : Option< Vec< u8 > > = None;
static mut OUTPUT : Option< Vec< u8 > > = None;

#[no_mangle]
pub extern "C" fn prepare( ) -> *const u8 {
  unsafe {
    let mut out = vec![ 0; 4 * 100 * 100 ];

    for y in 0..100 {
      for x in 0..100 {
        out[ ( y * 100 + x ) * 4 + 0 ] = 255;
        out[ ( y * 100 + x ) * 4 + 1 ] = 255;
        out[ ( y * 100 + x ) * 4 + 2 ] = 255;
        out[ ( y * 100 + x ) * 4 + 3 ] = 255;
      }
    }

    INPUT  = Some( vec![ 0; 100000 * 7 ] );
    OUTPUT = Some( out );

    if let Some( ref i ) = INPUT {
      i.as_ptr( )
    } else {
      panic!( "WUT" )
    }
  }
}

#[no_mangle]
pub extern "C" fn run( n : i32 ) -> *const u8 {
  unsafe {
    if let Some( ref input ) = INPUT {
      if let Some( ref mut output ) = OUTPUT {
        for k in 0..n as usize {
          let x = input[ k * 7 + 0 ] as u32;
          let y = input[ k * 7 + 1 ] as u32;
          let w = input[ k * 7 + 2 ] as u32;
          let h = input[ k * 7 + 3 ] as u32;
          let r = input[ k * 7 + 4 ];
          let g = input[ k * 7 + 5 ];
          let b = input[ k * 7 + 6 ];

          for vy in 0..h {
            for vx in 0..w {
              if y + vy < 100 && x + vx < 100 {
                let off = ( ( y + vy ) * 100 + ( x + vx ) ) * 4;
                output[ off as usize + 0 ] = r;
                output[ off as usize + 1 ] = g;
                output[ off as usize + 2 ] = b;
              }
            }
          }
        }
        output.as_ptr( )
      } else {
        panic!( "WUT" );
      }
    } else {
      panic!( "WUT" )
    }
  }
}
