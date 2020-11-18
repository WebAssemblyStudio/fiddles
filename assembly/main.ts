import { u128 } from 'as-bignum';

const MULT = u128.fromString('0x12e15e35b500f16e2e714eb2b37916a5');

class PRNG {
    private state: u128;

    constructor(seed: u64) {
        this.state = u128.fromU64(seed << 1 | 1);
    }

    public next(): u64 {
        this.state = u128.mul(this.state, MULT);
        return this.state.toU64();
    }

    public nextDouble(): f64 {
        return <f64>this.next() / i64.MAX_VALUE;
    }
}

export function test(): u64 {
    const rng = new PRNG(0);

    return rng.next();
}