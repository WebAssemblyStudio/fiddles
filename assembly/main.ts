export function fromHexString(hex: string): Uint8Array {
  assert(hex.length % 2 == 0, 'input ' + hex + ' has odd length')
  // Skip possible `0x` prefix.
  if (hex.length >= 2 && hex[0] == '0' && hex[1] == 'x') {
    hex = hex.substr(2)
  }
  let output = new Uint8Array(hex.length / 2);
  for (let i = 0; i < hex.length; i += 2) {
    output[i / 2] = I8.parseInt(hex.substr(i, 2), 16)
  }
  return output;
}

let zero = fromHexString("0x00");
assert(zero[0] == 0);

let one = fromHexString("0x01");
assert(one[0] == 1);
