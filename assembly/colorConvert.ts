import {PixelVal} from './mainTypes';

declare function hsvToRgbEncoded(hue: u16, sat: u8, val: u8): u32;

export function hsvToRgb(hue: u16, sat: u8, val: u8): PixelVal {
	const encodedRgb = hsvToRgbEncoded(hue, sat, val);
	return {
		red: ((encodedRgb >> 0) & 0xFF) as u8,
		grn: ((encodedRgb >> 8) & 0xFF) as u8,
		blu: ((encodedRgb >> 16) & 0xFF) as u8,
	};
}
