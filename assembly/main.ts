export function toString<T>(v: T): string {
  return v.toString()
}

let str1 = toString(true)
let str2 = toString(false)
let str3 = true.toString()
let str4 = (true).toString()

