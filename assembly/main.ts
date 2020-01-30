
@inline
function clamp(x: i32): i32 {
  return min(max(x, 0), 255);
}

export function hue2Rgb(hue: i32): u32 {
  hue *= 6 << 8;
	let r = abs(hue - (3 << 16)) - (1 << 16);
	let g = (2 << 16) - abs(hue - (2 << 16));
	let b = (2 << 16) - abs(hue - (4 << 16));
	r = clamp(r >> 8);
	g = clamp(g >> 8);
	b = clamp(b >> 8);
  return r << 16 | g << 8 | b;
}
