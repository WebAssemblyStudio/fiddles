const M11 = 0
const M12 = 1
const M13 = 2
const M21 = 3
const M22 = 4
const M23 = 5
const X   = 6
const Y   = 7

export function skip(len: i32): void {
  const m11 = get(M11)
  const m12 = get(M12)
  const m13 = get(M13)
  const m21 = get(M21)
  const m22 = get(M22)
  const m23 = get(M23)

  for (let i = 0; i < len; i++) {
    let px = getX(i)
    let py = getY(i)

    let x = px * m11 + py * m12 + m13
    let y = px * m21 + py * m22 + m23

    setX(i, x)
    setY(i, y)
  }
}

function get(index: i32): f32 {
  return load<f32>(index << alignof<f32>())
}

function getX(index: i32): f32 {
  return load<f32>(index << alignof<f32>(), X * sizeof<f32>())
}

function getY(index: i32): f32 {
  return load<f32>(index << alignof<f32>(), Y * sizeof<f32>())
}

function setX(index: i32, value: f32): void {
  store<f32>(index << alignof<f32>(), value, X * sizeof<f32>())
}

function setY(index: i32,  value: f32): void {
  store<f32>(index << alignof<f32>(), value, Y * sizeof<f32>())
}


