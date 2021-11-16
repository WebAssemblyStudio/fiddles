import {PixelAnimation} from './PixelAnimation';
import {Pixel} from './mainTypes';

let pixels: Pixel[][];
let animation: PixelAnimation;

export function initLayoutSetNumStrips(nStrips: i32): void {
	pixels = new Array(nStrips);
	for (let i = 0; i < nStrips; i++) {
		pixels[i] = [];
	}
}

export function initLayoutSetStripLen(stripIdx: i32, length: i32): void {
	pixels[stripIdx] = new Array(length);
	for (let i = 0; i < length; i++) {
		pixels[stripIdx][i] = {
			val: {red: 0, grn: 0, blu: 0},
			loc: {x: 0.0, y: 0.0},
		};
	}
}

export function initLayoutSetPixelLoc(stripIdx: i32, pixelIdx: i32, x: f32, y: f32): void {
	pixels[stripIdx][pixelIdx].loc = {x, y};
}

export function initLayoutDone(): void {
	animation = new PixelAnimation(pixels);
}

export function tick(): void {
	animation.tick();
}

export function getPixelRed(stripIdx: i32, pixelIdx: i32): u8 {
	return pixels[stripIdx][pixelIdx].val.red;
}

export function getPixelGrn(stripIdx: i32, pixelIdx: i32): u8 {
	return pixels[stripIdx][pixelIdx].val.grn;
}

export function getPixelBlu(stripIdx: i32, pixelIdx: i32): u8 {
	return pixels[stripIdx][pixelIdx].val.blu;
}
