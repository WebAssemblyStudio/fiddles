export function t1(x: i32, swap: i32): i32 {
    return x << (swap ? 0 : 8);
}

export function t2(x: i32, swap: i32): i32 {
    return x << (i32(swap == 0) << 3);
}
