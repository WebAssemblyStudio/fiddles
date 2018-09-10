import "allocator/arena";

declare namespace console {
  function logi(value: i32): void;
  function logf(value: f64): void;
}

class Car {
  year: number;
  brand: string;

  constructor(year: number, brand:string) {
    if (brand == null){
      this.brand == "audi";
    }
    this.year = year;
    this.brand = brand;
  }
}

var car = {year:12, brand:"decode"} as Car;


class Computer {
  year: number;
  brand: string;

  constructor() {
 
    this.brand == "HP";
    this.year = 2018;
  }
}

var computer = {year:12, brand:"APPLE"} as Computer;
