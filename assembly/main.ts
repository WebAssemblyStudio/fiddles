/*
const zero: u8 = 48
const dash: u8 = 45

export function itoa(dest: i32, i: i32): void {
    // i32.MIN_VALUE can't be negated, so we just hardcode the output for simplicity
    if (i === i32.MIN_VALUE) {
        store<u64>(dest, 0x3431322d0000000b)
        store<u64>(dest + 8, 0x0038343633383437)
        return;
    }

    let offset: i32 = dest + 4
    store<u8>(offset, zero)

    let minus: boolean = i < 0
    i = abs<i32>(i)

    while (i > 0) {
        store<u8>(offset, zero + <u8>(i % 10))
        offset += 1
        i /= 10
    }

    // just put the minus on the end before we reverse
    if (minus) {
        store<u8>(offset, dash)
        offset += 1
    }

    // length is at least 1 for the 0
    let length: i32 = (offset - dest - 4) || 1

    // reverse the string
    let swap: i32 = length / 2
    while (swap > 0) {
        let a: i32 = dest + 4 + swap - 1
        let b: i32 = dest + 4 + length - swap
        let temp: u8 = load<u8>(a)
        store<u8>(a, load<u8>(b))
        store<u8>(b, temp)
        swap -= 1
    }

    store<i32>(dest, length)
}
*/

import { itoa_buffered } from 'util/number';

export function itoa(dest: usize, value: i32): void {
  itoa_buffered(dest, value);
}