// Common
const top: f32              = 1.0;
const right: f32            = 1.0;
const bottom: f32           = -1.0;
const left: f32             = -1.5;

const rSquareMax: f32 = 4.0;
const xWidth: f32     = right - left;
const yHeight: f32    = top - bottom;

// Things to test different types with
const maxIterationsU32: u32 = 4096;
const maxIterationsF32: f32 = <f32>maxIterationsU32;
const inverseMaxItertations = 1.0 / maxIterationsF32;

const canvasWidthU32: u32   = 1500;
const canvasHeightU32: u32  = 1000;
const canvasAreaU32: u32    = canvasWidthU32 * canvasHeightU32;
const canvasWidthF32: f32   = <f32>canvasWidthU32;
const canvasHeightF32: f32  = <f32>canvasHeightU32;
const canvasAreaF32: f32    = <f32>canvasAreaU32;


// Uses u32 for index and modulo
export function computeMandelbrotU32(): void
{
	for(let index: u32 = 0; index < canvasAreaU32; index += 4)
	{
		const xIndex: f32 = <f32>(index % canvasWidthU32);
		const yIndex: f32 = <f32>(index / canvasWidthU32);

		let xCoordinate: f32 = (xIndex / canvasWidthF32)  * xWidth + left;
		let yCoordinate: f32 = (yIndex / canvasHeightF32) * yHeight + bottom;

		let iteration: u32 = 0;
		let x: f32         = 0.0;
		let y: f32         = 0.0;
		let rSquare: f32   = 0.0;
		let iSquare: f32   = 0.0;
		let zSquare: f32   = 0.0;

		while(((rSquare + iSquare) < rSquareMax) && (iteration < maxIterationsU32))
		{
			x = rSquare - iSquare + xCoordinate;
			y = zSquare - rSquare - iSquare + yCoordinate;

			rSquare = x * x;
			iSquare = y * y;
			zSquare = (x + y) * (x + y);

			iteration++;
		}
	}

	return;
}

// Uses f32 for everything
export function computeMandelbrotF32(): void
{
	for(let index: f32 = 0; index < canvasAreaF32; index += 4)
	{
		const xIndex: f32 = index % canvasWidthF32;
		const yIndex: f32 = index / canvasWidthF32;

		let xCoordinate: f32 = (xIndex / canvasWidthF32)  * xWidth + left;
		let yCoordinate: f32 = (yIndex / canvasHeightF32) * yHeight + bottom;

		let iteration: f32 = 0;
		let x: f32         = 0.0;
		let y: f32         = 0.0;
		let rSquare: f32   = 0.0;
		let iSquare: f32   = 0.0;
		let zSquare: f32   = 0.0;

		while(((rSquare + iSquare) < rSquareMax) && (iteration < maxIterationsF32))
		{
			x = rSquare - iSquare + xCoordinate;
			y = zSquare - rSquare - iSquare + yCoordinate;

			rSquare = x * x;
			iSquare = y * y;
			zSquare = (x + y) * (x + y);

			iteration++;
		}
	}

	return;
}