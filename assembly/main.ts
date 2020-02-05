const chars = new Array<string>(0x10FFFF + 1);
for (let i = 0; i < chars.length; i++) {
  chars[i] = String.fromCodePoint(i);
}

export function toLowerCaseTest(): void {
  let res = 0;
  for (let i = 0; i <= 0x10FFFF; i++) {
    res += unchecked(chars[i].toLowerCase()).length;
  }
}

export function toUpperCaseTest(): void {
  let res = 0;
  for (let i = 0; i <= 0x10FFFF; i++) {
    res += unchecked(chars[i].toUpperCase()).length;
  }
}