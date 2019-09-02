
export function benchInnerLoop(canvasWidth: i32, canvasHeight: i32, left: f32, bottom: f32): f32 {
  let xScale: f32 = 1.0;
  let yScale: f32 = 1.0;
  let total: f32 = 0;

  for (let yIndex = 0; yIndex < canvasHeight; yIndex++) {
    let stride = yIndex * canvasWidth;
    for (let xIndex = 0; xIndex < canvasWidth; xIndex++) {
      let xCoordinate: f32 = <f32>xIndex * xScale + left;
      let yCoordinate: f32 = <f32>yIndex * yScale + bottom;
      total += xCoordinate + yCoordinate;
    }
  }
  return total;
}

export function benchOneLoop(canvasWidth: f32, canvasHeight: f32, left: f32, bottom: f32): f32 {
  let canvasArea: f32 = canvasWidth * canvasHeight;

  const floatCanvasWidth: f32  = canvasWidth;
	const floatCanvasHeight: f32 = canvasHeight;

  const xWidth: f32 = canvasWidth;
	const yHeight: f32 = canvasHeight;

  let total: f32 = 0;

  for (let index: f32 = 0.0; index < canvasArea; index += 1.0)
	{
		const xIndex: f32 = index % canvasWidth;
		const yIndex: f32 = index / canvasWidth;

		let xCoordinate: f32 = (xIndex / floatCanvasWidth)  * xWidth + left;
		let yCoordinate: f32 = (yIndex / floatCanvasHeight) * yHeight + bottom;

    total += xCoordinate + yCoordinate;
  }

  return total;
}
