enum PrimitiveRaw {
  Empty,
  Point,
  Line,
}

export function test2(tag: PrimitiveRaw, p0x: f32, p0y: f32, p1x: f32, p1y: f32): f32 {
  if (PrimitiveRaw.Point == tag) { return p0x + p0y }
  else if (PrimitiveRaw.Line == tag) { return p0x + p1x }
  else { return 0.0 }
}
