export function hanoi(
        amount: i32 ,
        from: string,
        to: string,
        tmp: string
    ): string {
        if (amount == 1) {
            // this.showStack()
            // this.manageStack(from, to)
            // this.showStack()
        }
        else {
            hanoi(amount - 1, from, tmp, to);
            // this.manageStack(from, to)
            // this.showStack()
            hanoi(amount - 1, tmp, to, from);
        }
        return 'a'
    }