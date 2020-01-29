
@inline
function clamp(x: i32): i32 {
  return min(max(x, 0), 255);
}

export function hue2Rgb(hue: i32): u32 {
	let r = (abs(hue * (6 << 8) - (3 << 16)) - (1 << 16)) >> 8;
	let g = ((2 << 16) - abs(hue * (6 << 8) - (2 << 16))) >> 8;
	let b = ((2 << 16) - abs(hue * (6 << 8) - (4 << 16))) >> 8;
	r = clamp(r);
	g = clamp(g);
	b = clamp(b);
  return (r << 16) | (g << 8) | b;
}
