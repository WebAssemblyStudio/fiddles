

export function reverse(x: u32): u32 {
    x = (((x & 0xaaaaaaaa) >> 1) | ((x & 0x55555555) << 1));
    x = (((x & 0xcccccccc) >> 2) | ((x & 0x33333333) << 2));
    x = (((x & 0xf0f0f0f0) >> 4) | ((x & 0x0f0f0f0f) << 4));
    x = (((x & 0xff00ff00) >> 8) | ((x & 0x00ff00ff) << 8));
    return((x >> 16) | (x << 16));
}

export function reverse_knuth(a: u32): u32 {
    var t: u32;
    a = (a << 15) | (a >> 17);
    t = (a ^ (a >> 10)) & 0x003f801f; 
    a = (t + (t << 10)) ^ a;
    t = (a ^ (a >>  4)) & 0x0e038421; 
    a = (t + (t <<  4)) ^ a;
    t = (a ^ (a >>  2)) & 0x22488842; 
    a = (t + (t <<  2)) ^ a;
    return a;
}
