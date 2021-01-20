function primes()
{
    let num1 = 1;
    let num2 = 100000;
    let isMod, i, j;
    let counter = 0;

    for (i = num1 + 1; i < num2; ++i)
    {
        isMod = 0;
        for (j = 2; j <= i / 2; ++j)
        {
            if (i % j == 0)
            {
                isMod = 1;
                break;
            }
        }
        if (isMod == 0)
        {
            counter += 1;
        }
    }
    return counter;
}

var t0 = performance.now()
console.log("Amount is: " + primes());
var t1 = performance.now()
console.log("Call to execute JS Primecounter took " + (t1 - t0) + " milliseconds.")