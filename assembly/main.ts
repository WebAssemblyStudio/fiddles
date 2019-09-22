export function addLongNumbers(a: string, b: string): string {
  const aReversed = a.split("").reverse();
  const bReversed = b.split("").reverse();

  const maxLength = max(a.length, b.length);
  let resultArray = new Array<String | null>(maxLength + 1);
  let result = ""
  let carry = 0;
  for (let i = 0; i < maxLength; ++i) {
    let aDigit = (i < a.length) ? U32.parseInt(aReversed[i]) : 0;
    let bDigit = (i < b.length) ? U32.parseInt(bReversed[i]) : 0;
    let digitSum = aDigit + bDigit + carry;

    if (digitSum >= 10) {
      carry = 1;
      digitSum -= 10;
    } else {
      carry = 0;
    }
    resultArray[i] = digitSum.toString();
  }

  if (carry > 0) {
    resultArray[maxLength] = carry.toString();
  }
  let reversedResultArray = resultArray.reverse();
  return reversedResultArray.join("");
}
