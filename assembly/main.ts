export function squiggle(sequence: string, length: i32): Float64Array {
  let x = [0.0]
  let y = [0.0]
  let yCoord = 0.0
  let xCoord = 0.0

  for (let i = 0; i < length; i++) {
    let character = sequence.charAt(i)
    x.push(xCoord + 0.5)
    x.push(xCoord + 1.0)
    xCoord += 1.0
    if (character == "A") {
      y.push(yCoord + 0.5)
      y.push(yCoord)
    } else if (character == "C") {
      y.push(yCoord - 0.5)
      y.push(yCoord)
    } else if (character == "T") {
      y.push(yCoord - 0.5)
      y.push(yCoord - 1)
      yCoord -= 1.0
    } else if (character == "G") {
      y.push(yCoord + 0.5)
      y.push(yCoord + 1)
      yCoord += 1.0
    } else {
      y.push(yCoord)
      y.push(yCoord)
    }
  }

  let result = new Float64Array((2 * length) + 2)
  for (let i = 0; i < length; i++){
    result[i] = x[i]
    result[i] = y[i]
  }
  return result
}