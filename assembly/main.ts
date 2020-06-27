export function clamp(value: f32, min: f32, max: f32): f32 {
  if (value >= max) return max;
  if (value <= min) return min;
  return value;
}

export function clamp1(value: f32, min: f32, max: f32): f32 {
  return select(max, select(min, value, value <= min), value >= max);
}

export function clamp2(value: f32, min: f32, max: f32): f32 {
  return Mathf.min(Mathf.max(value, min), max);
}
