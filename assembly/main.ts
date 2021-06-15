class ChartPoint {
  index: i64;
  millis: i64;
  balance: i64 | null;
  equity: i64 | null;
  is_loop: boolean;
  isBalanceEmpty: boolean;
  isEquityEmpty: boolean;
}

class LastValues {
  balance: i64;
  equity: i64;
}

class ReturnValue {
  value: i64;
  loopValue: i64;
  unalteredGapValue: i64;
  lastValue: i64
}

export function getValues(
  isBalance: boolean,
  currentPoint: ChartPoint,
  prevPoint: ChartPoint | null,
  nextPoint: ChartPoint | null,
  lastValues: LastValues
): ReturnValue {
  // const valueKey = isBalance ? 'balance' : 'equity';
  const hasPrevPoint = !isNullable(prevPoint);
  const hasNextPoint = !isNullable(prevPoint);
  const isPrevPointWasLoop = hasPrevPoint ? prevPoint.is_loop : false;
  const isNextPointLoop = hasNextPoint ? nextPoint.is_loop : false;
  const currentValue = isBalance ? currentPoint.balance : currentPoint.equity;
  const isLoop = currentPoint.is_loop;
  let isNextPointValueEmpty = true;
  if (hasNextPoint) {
    if (isBalance) {
      isNextPointValueEmpty = !isNullable(nextPoint.balance);
    } else {
      isNextPointValueEmpty = !isNullable(nextPoint.equity);
    }
  }

  const isValueEmpty = isBalance ? currentPoint.isBalanceEmpty : currentPoint.isEquityEmpty;

  let value: i64 = null;
  let loopValue: i64 = null;
  let unalteredGapValue: i64 = null;

  if (isLoop) {
    const isFirstLoopPoint = !isPrevPointWasLoop;

    loopValue = currentValue;
    if (isFirstLoopPoint || !isNextPointLoop) {
      value = currentValue;
    }
    if (hasNextPoint && isNextPointValueEmpty && !isNextPointLoop) {
      unalteredGapValue = currentValue;
    }
  } else {
    if (isNullable(currentValue)) {
      unalteredGapValue = isBalance ? lastValues.balance : lastValues.equity;
      if (hasNextPoint && !isNextPointValueEmpty) {
        value = isBalance ? lastValues.balance : lastValues.equity;
      }
    } else {
      value = currentValue;
      if (isNextPointValueEmpty && hasNextPoint && !isNextPointLoop) {
        unalteredGapValue = currentValue;
      }
    }
  }

  return {
    value,
    loopValue,
    unalteredGapValue,
    lastValue: currentValue
  };
}