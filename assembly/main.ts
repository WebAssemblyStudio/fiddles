export function s3tcblend_1(a: u32, b: u32): u8 {
    // return (a*3 + b*5) / 8;
    let tmp = (((a << 1) + a) + ((b << 2) + b)) >>> 3;
    return <u8>tmp;
}

export function s3tcblend_2(a: u32, b: u32): u8 {
    // return (a*3 + b*5) / 8;
    let tmp: u32 = (((a << 1) + a) + ((b << 2) + b)) >>> 3;
    return <u8>tmp;
}