export class PixelVal {
	red: u8;
	grn: u8;
	blu: u8;
}

export class PixelLoc {
	x: f32;
	y: f32;
}

export class Pixel {
	val: PixelVal;
	loc: PixelLoc;
}

export function pixelValFromU32(encoded: u32): PixelVal {
	return {
		red: ((encoded >> 16) & 0xFF) as u8,
		grn: ((encoded >> 8) & 0xFF) as u8,
		blu: ((encoded >> 0) & 0xFF) as u8,
	};
}

export function pixelValToU32(val: PixelVal): u32 {
	return (
		((val.red as u32) << 16) |
		((val.grn as u32) << 8) |
		((val.blu as u32) << 0)
	);
}