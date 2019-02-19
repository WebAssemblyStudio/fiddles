declare function sayHello(): void;

sayHello();

export function add(x: i32, y: i32): i32 {
  return x + y;
}

export function getSortedVariables(series: Float32Array[]): Int16Array[] {
  const templateIndexes = new Int16Array(series[0].length);
  for (let i = 0; i < templateIndexes.length; i++) {
    templateIndexes[i] = i;
  }

  const result: Int16Array[] = [];
  for (let variableIndex = 0; variableIndex < templateIndexes.length; variableIndex++) {
    const sortedIndexes = templateIndexes.slice(0);

    sortedIndexes.sort((a: number, b:number) => {
      const valueA = series[a][variableIndex];
      const valueB = series[b][variableIndex];
      if (valueA < valueB)
        return -1;
      if (valueA > valueB)
        return 1;
      return 0;
    });

    result.push(sortedIndexes);
  }
  return result;
}
