import {PixelVal, pixelValFromU32} from './mainTypes';

declare function hsvToRgbEncoded(hue: u16, sat: u8, val: u8): u32;

export function hsvToRgb(hue: u16, sat: u8, val: u8): PixelVal {
	return pixelValFromU32(hsvToRgbEncoded(hue, sat, val));
}
