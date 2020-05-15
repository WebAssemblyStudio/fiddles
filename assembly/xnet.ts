import { perceptron } from './lib/perceptron';
  
  
  export class network {

    private i:i32;
    private p:perceptron[];

    constructor() {
      this.i = 32;
      this.p = new Array();
      for(let i:i32 = 0; i < 1000000; i++) {
        this.p[i] = new perceptron(i,0,5);
      }
    }

    get_i():i32{
      let i:i32 = this.p.length;
      return i;
    }
  }
