WebAssembly.instantiateStreaming(fetch("../out/main.wasm"), {
  env: {
    abort(_msg, _file, line, column) {
      console.error("abort called at main.ts:" + line + ":" + column);
    }
  },
}).then(result => {
  const exports = result.instance.exports;
  console.debug({ exports })
  const getValues = exports.getValues;
  const lastValues = {
    balance: null,
    equity: null,
  };

  function reducePoints(points) {
    const update = points.reduce(
      function reducerCallback(
        acc,
        currentPoint,
        index,
        array,
      ) {
        const prevPoint = index - 1 >= 0 ? array[index - 1] : undefined;
        const nextPoint =
          index + 1 <= array.length ? array[index + 1] : undefined;
        const ts = currentPoint.millis;
        const {
          value: balance,
          loopValue: balanceLoop,
          unalteredGapValue: balanceUnalteredGap,
          lastValue: lastBalanceValue,
        } = getValues(true, currentPoint, prevPoint, nextPoint, lastValues);
        const {
          value: equity,
          loopValue: equityLoop,
          unalteredGapValue: equityUnalteredGap,
          lastValue: lastEquityValue,
        } = getValues(false, currentPoint, prevPoint, nextPoint, lastValues);

        lastValues.balance = lastBalanceValue
        lastValues.equity = lastEquityValue;

        console.debug({
          balance,
          balanceLoop,
          balanceUnalteredGap,
          lastBalanceValue,
          equity,
          equityLoop,
          equityUnalteredGap,
          lastEquityValue,
        })

        acc.index.push(currentPoint.index);
        acc.ts.push(ts);
        acc.balance.push(balance);
        acc.balanceLoop.push(balanceLoop);
        acc.balanceUnalteredGap.push(balanceUnalteredGap);
        acc.equity.push(equity);
        acc.equityLoop.push(equityLoop);
        acc.equityUnalteredGap.push(equityUnalteredGap);

        return {
          index: acc.index,
          ts: acc.ts,
          balance: acc.balance,
          balanceLoop: acc.balanceLoop,
          balanceUnalteredGap: acc.balanceUnalteredGap,
          equity: acc.equity,
          equityLoop: acc.equityLoop,
          equityUnalteredGap: acc.equityUnalteredGap,
        };
      },
      {
        index: [],
        ts: [],
        balance: [],
        balanceLoop: [],
        balanceUnalteredGap: [],
        equity: [],
        equityLoop: [],
        equityUnalteredGap: [],
      },
    );

    // Clear temporary values.
    lastValues.balance = null;
    lastValues.equity = null;

    return update;
  }

  const sourceBEChartPoint = [
    { index: 0, millis: 1, balance: 100, equity: 100, is_loop: false },
    { index: 1, millis: 2, balance: 100, equity: 101, is_loop: false },
    { index: 2, millis: 3, balance: 101, equity: 102, is_loop: true },
    { index: 3, millis: 3, balance: 102, equity: 102, is_loop: true },
    { index: 4, millis: 3, balance: 103, equity: 102, is_loop: true },
    { index: 5, millis: 4, balance: 102, equity: 104, is_loop: false },
    { index: 6, millis: 5, balance: 100, equity: 104, is_loop: false },
    { index: 7, millis: 6, balance: null, equity: 105, is_loop: false },
    { index: 8, millis: 7, balance: null, equity: 105, is_loop: false },
    { index: 9, millis: 8, balance: null, equity: 105, is_loop: false },
    { index: 10, millis: 9, balance: 103, equity: 106, is_loop: false },
    { index: 11, millis: 10, balance: 102, equity: 106, is_loop: false },
    { index: 12, millis: 11, balance: 101, equity: 103, is_loop: true },
    { index: 13, millis: 11, balance: 100, equity: 105, is_loop: true },
    { index: 14, millis: 11, balance: 102, equity: 103, is_loop: true },
    { index: 15, millis: 12, balance: null, equity: 104, is_loop: false },
    { index: 16, millis: 13, balance: null, equity: 103, is_loop: false },
    { index: 17, millis: 14, balance: null, equity: 105, is_loop: false },
  ];

  console.log(reducePoints(sourceBEChartPoint))
  // document.getElementById("container").textContent = "Result: " + exports.add(19, 23);
}).catch(console.error);
