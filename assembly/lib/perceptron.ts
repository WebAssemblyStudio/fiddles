import {weight} from './interfaces';

export class perceptron {
  private id:i32 = 0;
  private inputPool:Float32Array;
  private actFuntion:i32 = 0;
  private weights:weight[];

  constructor(id:i32, actFunction:i8, inputPoolSize:i16) {
    this.id = id;
    this.actFuntion = actFunction;
    this.inputPool = new Float32Array(inputPoolSize);
    this.weights = [];
  }

  addWeight(weight:weight):void {
    this.weights.push(weight);
  }
}
