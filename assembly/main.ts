const w = 640;
const h = 480;
  
export function run(): void {
  for ( let y = 1; y < h-1; y++ ) {
    for ( let x = 1; x < w-1; x++ ) {
      let vx: i32 = (-1) * at( x-1, y-1 )
                  + (-2) * at( x-1, y   )
                  + (-1) * at( x-1, y+1 )
                  +    1 * at( x+1, y-1 )
                  +    2 * at( x+1, y   )
                  +    1 * at( x+1, y+1 );
             
      let vy: i32 = (-1) * at( x-1, y-1 )
                  + (-2) * at( x  , y-1 )
                  + (-1) * at( x+1, y-1 )
                  +    1 * at( x-1, y+1 )
                  +    2 * at( x  , y+1 )
                  +    1 * at( x+1, y+1 );

      if ( Math.abs( vx ) + Math.abs( vy ) < 64 ) {
        // Toon shading
        let v = ( at( x-1, y-1 ) / 64 ) * 85;
        put( x-1, y-1, v );
      } else {
        put( x-1, y-1, 0 );
      }
    }
  }
}

function put( x: u32, y: u32, v: u32 ): void {
  const dst = w * h * 4;

  store<u8>( dst + 4 * ( y * (w-2) + x ) + 0, v );
  store<u8>( dst + 4 * ( y * (w-2) + x ) + 1, v );
  store<u8>( dst + 4 * ( y * (w-2) + x ) + 2, v );
  store<u8>( dst + 4 * ( y * (w-2) + x ) + 3, 255 );
}

@inline function at( x: u32, y: u32 ): u32 {
  return load<u8>( 4 * ( y * w + x ) );
}
