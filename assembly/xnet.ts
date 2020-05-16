import { weight } from './lib/interfaces';
import { perceptron } from './lib/perceptron';

  
  export class network {

    private i:i32;
    private p:perceptron[];
    private w:weight;

    constructor() {
      this.i = 32;
      this.p = new Array();
      this.w = new weight;
      for(let i:i32 = 0; i < 1000000; i++) {
        this.p[i] = new perceptron(i,0,5);
        for(let w = 0; w<25;w++) {
          let ww = new weight();
          ww.torow = 10;
          this.p[i].addWeight(ww);
        }
      }
    }

    get_i():i32{
      let i:i32 = this.p.length;
      return i;
    }
  }
