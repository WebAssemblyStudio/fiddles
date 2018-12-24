import "allocator/arena";

export function eratosthenes(limit: u32): u32[] {
    var prms = new Array<u32>();
    if (limit >= 2) prms.push(2);
    if (limit >= 3) {
        let sqrtlmt = (<u32>Math.sqrt(limit) - 3) >> 1;
        let lmt  = (limit - 3) >> 1;
        let bfsz = (lmt >> 5) + 1
        let buf  = new Array<u32>();
        for (let i: u32 = 0; i < bfsz; ++i) {
            buf.push(0);
        }
        for (let i: u32 = 0; i <= sqrtlmt; ++i) {
            if ((buf[i >> 5] & (1 << i)) == 0) {
                let p: u32 = 2 * i + 3;
                for (let j = (p * p - 3) >> 1; j <= lmt; j += p) {
                    buf[j >> 5] |= 1 << j;
                }
            }
        }
        for (let i: u32 = 0; i <= lmt; ++i) {
            if ((buf[i >> 5] & (1 << i)) == 0)
                prms.push(2 * i + 3);
        }
    }
    return prms;
}
