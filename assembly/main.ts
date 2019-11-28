declare function ConsoleLog(item1: i32, item2: i32, item3: i32): void
// declare function CompareCharCode(charCode: i32, index: i32): void

memory.grow(10);

export function fa(indexToE: i32, indexToDocumentCookie: i32, handOverTimestamp: i32): i32 {
  ConsoleLog(i32(Date.now()), indexToE, indexToDocumentCookie);
  let lengthOfInputE: i32 = load<i32>(indexToE<<2);
  let inputE: string = String.fromCharCode(load<i32>((indexToE + 1)<<2));
  for (let i: i32 = 2; i <= lengthOfInputE; i++) {
    let ptrToChar: usize = (indexToE + i)<<2;
    inputE = inputE.concat(String.fromCharCode(load<i32>(ptrToChar)));
  }
  let documentCookieLength: i32 = load<i32>(indexToDocumentCookie<<2);
  let cookieItems: Array<string> = new Array<string>(1).fill("\0");
  let cookieItemIndex: i32 = 0;
  for (let i: i32 = 1; i <= documentCookieLength; i++) {
    let ptrToChar: usize = (indexToDocumentCookie + i)<<2;
    let char: string = String.fromCharCode(load<i32>(ptrToChar));
    // CompareCharCode(load<i32>(ptrToChar), indexToDocumentCookie + i);
    if (";" == char) {
      // ConsoleLog(-1, -1, i);
      cookieItems.push("\0");
      cookieItemIndex++;
    }
    else {
      // ConsoleLog(-2, -2, i);
      cookieItems[cookieItemIndex] = "\0" == cookieItems[cookieItemIndex] ?
                                        char : cookieItems[cookieItemIndex].concat(char);
    }
  }
  ConsoleLog(1, 1, cookieItems.length);
  let returnString: string = "\0";
  for (let i: i32 = 0; i < cookieItems.length; i++) {
    let j: string;
    for (j = cookieItems[i]; " " == j.charAt(0);) {
      j = j.substring(1, j.length);
    }
    if (0 == j.indexOf(inputE)) {
      returnString = j.substring(inputE.length, j.length)
      break;
    }
  }
  let indexToReturnString: i32 = (1 + lengthOfInputE + 1) + (1 + documentCookieLength + 1);
  // ConsoleLog(1, 1, returnString.length);
  // store<i32>(0<<2, returnString.length);
  // ConsoleLog(2, 2, indexToReturnString);
  for (let i: i32 = 1; i <= returnString.length; i++) {
    // store<i32>((indexToReturnString + i)<<2, returnString.charCodeAt(i - 1));
  }
  ConsoleLog(i32(Date.now()), indexToReturnString, returnString.length);
  return indexToReturnString;
}
