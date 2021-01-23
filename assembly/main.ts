export function isSpecialCharacter(code: u32): bool {
  switch (code) {
    case 0x24: /* $ */
    case 0x28: /* ( */
    case 0x29: /* ) */
    case 0x2a: /* * */
    case 0x2b: /* + */
    case 0x2e: /* . */
    case 0x3f: /* ? */
    case 0x5c: /* \ */
    case 0x5b: /* [ */
    case 0x5d: /* ] */
    case 0x5e: /* ^ */
    case 0x7c: /* | */
    case 0x7b: /* { */
    case 0x7d: /* } */
      return true;
  }
  return false;
}

export function isSpecialCharacter2(code: u32): bool {
  switch (code) {
    case 0x24: /* $ */
    case 0x28: /* ( */
    case 0x29: /* ) */
    case 0x2a: /* * */
    case 0x2b: /* + */
    case 0x2e: /* . */
      return true;
  }
  if (code == 0x3f) return true;
  switch (code) {
    case 0x5c: /* \ */
    case 0x5b: /* [ */
    case 0x5d: /* ] */
    case 0x5e: /* ^ */
      return true;
  }
  switch (code) {
    case 0x7c: /* | */
    case 0x7b: /* { */
    case 0x7d: /* } */
      return true;
  }
  return false;
}
