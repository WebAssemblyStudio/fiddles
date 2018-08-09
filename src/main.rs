#[no_mangle]
pub extern "C" fn dec2mbin(dec: i32) -> u32 {
    let mut mbin: u32 = 0;
    let mut rest: i32 = dec;
    for i in 0..32 {
        let j = 31 - i;
        if j == 0 {
            assert!(rest == 0 || rest == 1);
            mbin = mbin + rest as u32;
            rest = 0;
        } else if j % 2 == 0 {
            // (-2)^j >= 0
            if rest > mbin_positive_max(j - 1 + 1) {
                mbin = mbin + pow2u32(j);
                rest = rest - pow2u32(j) as i32;
            }
        } else {
            // (-2)^j < 0
            if rest < mbin_negative_min(j - 1 + 1) {
                mbin = mbin + pow2u32(j);
                rest = rest + pow2u32(j) as i32;
            }
        }
    }
    mbin
}

#[inline]
fn pow2u32(exp: u32) -> u32 {
    1 << exp
}

fn mbin_positive_max(l: u32) -> i32 {
    let mut val = 0;
    for i in 0..l {
        if i % 2 == 0 {
            val = val + pow2u32(i) as i32;
        }
    }
    val
}

fn mbin_negative_min(l: u32) -> i32 {
    let mut val = 0;
    for i in 0..l {
        if i % 2 == 1 {
            val = val - pow2u32(i) as i32;
        }
    }
    val
}

// TEST CODE

#[cfg(test)]
fn mbin2dec(mbin: u32) -> i32 {
    let mut dec = 0;
    for i in 0..32 {
        let exp = powi32(-2, i);
        dec = dec + ((mbin >> i) & 1) as i32 * exp;
    }
    dec
}

#[cfg(test)]
fn powi32(base: i32, exp: usize) -> i32 {
    let mut val = 1;
    for _ in 0..exp {
        val = val * base;
    }
    val
}

#[cfg(test)]
mod tests {
    use dec2mbin;
    use mbin2dec;

    use mbin_negative_min;
    use mbin_positive_max;

    #[test]
    fn mbin2dec_works() {
        assert_eq!(mbin2dec(0b000), 0);
        assert_eq!(mbin2dec(0b001), 1);
        assert_eq!(mbin2dec(0b010), -2);
        assert_eq!(mbin2dec(0b011), -1);
        assert_eq!(mbin2dec(0b100), 4);
        assert_eq!(mbin2dec(0b0101_0101_0101_0101_0101_0101_0101_0101u32), 1431655765);
        //assert_eq!(mbin2dec(0b1010_1010_1010_1010_1010_1010_1010_1010u32), -2863311530); // Out of range of u32 error
        //assert_eq!(mbin2dec(0b1111_1111_1111_1111_1111_1111_1111_1111u32), -1431655765); // Out of range of u32 error
    }

    #[test]
    fn mbin_positive_max_works() {
        assert_eq!(mbin_positive_max(1), 1);
        assert_eq!(mbin_positive_max(2), 1);
        assert_eq!(mbin_positive_max(3), 1 + 4);
        assert_eq!(mbin_positive_max(4), 1 + 4);
        assert_eq!(mbin_positive_max(31), 1431655765);
        assert_eq!(mbin_positive_max(32), 1431655765);
    }

    #[test]
    fn mbin_negative_min_works() {
        assert_eq!(mbin_negative_min(1), 0);
        assert_eq!(mbin_negative_min(2), -2);
        assert_eq!(mbin_negative_min(3), -2);
        assert_eq!(mbin_negative_min(4), -2 - 8);
        assert_eq!(mbin_negative_min(31), -715827882);
        //assert_eq!(mbin_negative_min(32), -2863311530); // Out of range of i32 error
    }

    #[test]
    fn dec2mbin_works() {
        assert_eq!(dec2mbin(0), 0);
        assert_eq!(dec2mbin(1431655765), 0b0101_0101_0101_0101_0101_0101_0101_0101u32);
        //assert_eq!(dec2mbin(-2863311530), 0b1010_1010_1010_1010_1010_1010_1010_1010u32); // Out of range of i32 error
        //assert_eq!(dec2mbin(-1431655765), 0b1111_1111_1111_1111_1111_1111_1111_1111u32); // Out of range of i32 error
        for i in 0..0xff {
            let j = i;
            assert_eq!(mbin2dec(dec2mbin(j)), j);
            let j = -i;
            assert_eq!(mbin2dec(dec2mbin(j)), j);
        }
    }
}
