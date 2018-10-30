export function testBreak(): void {
        var item:i32 =0;

        for (let idx:i32=0; idx < 32; ++idx) {
            if (idx == 12) {
                item = idx + 32;
                break;
            }
        }
        assert(item == 44);
    }

    testBreak();