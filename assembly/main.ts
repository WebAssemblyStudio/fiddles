

class Contract {
  constructor(public address: i32){
    
  }

  public Name():string {
    return "Contract!";

  }
}
// // import { decodeBmp, getLastWidth, getLastHeight, getLastColorDepth, reset } from './index'
export function makeContract(address:i32): Contract {
  return new Contract(address);
}

