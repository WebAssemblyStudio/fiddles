declare function sayHello(): void;

sayHello();

export function add(x: i32, y: i32): i32 {
  return x + y;
}

var DAYS_IN_MONTH: number[] = [31, 28, 31];
var days = DAYS_IN_MONTH[1];


class Container {
  static MONTHS_IN_YEAR: i32 = 12;
  static DAYS_IN_MONTH: i32[] = [31, 28, 31];
}
var months = Container.MONTHS_IN_YEAR;
var _days =  Container.DAYS_IN_MONTH[1];

